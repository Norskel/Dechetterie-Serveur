#include "stdafx.h"
#include "Sortie.h"


Sortie::Sortie(IPAddress ^ listenip, int listenPort)
{
	Console::WriteLine("IP " + listenip + " Port " + listenPort);

	_srv = gcnew Serveur(listenip, listenPort,2);
	_srv->Start();
	_tSortie = gcnew Thread(gcnew ThreadStart(this, &Sortie::ThreadSortie));
	_tSortie->Name = "Thread Sortie";
	_tSortie->Start();
	_bdd = DataBddProxy::getDataBddProxy();
	protocole = Protocole::getProtocole();
}

void Sortie::ThreadSortie()
{
	Boolean connected = false;
	do
	{
		Console::WriteLine("[Sortie] Attente de la connection de tous les client;");
		Thread::Sleep(500);
		getClientFromList(Dechetterie::GetListClient());
		//connected = _ClientBalance->getState() && _ClientBarri�re->getState() && _ClientRFID->getState();
		connected = _ClientRFID->getState();
		//connected = _ClientBalance->getState();

	} while (!connected);


	while (true)
	{
		getClientFromList(Dechetterie::GetListClient());
		try
		{
			//===================================== Attente de Demande d'acc�s ========================================================================
			String^ rfid_id = WaitAccesDemand(_ClientRFID);
			Console::WriteLine("[Sortie] Demande d'acc�s avec l'id RFID " + rfid_id);
			//===================================== Demande d'acc�s ====================================================================================
			try
			{
				//Console::WriteLine("[Entree] Demande d'acc�s avec l'id RFID " + Encoding::Default->GetString(msgRev->data1));
				DataUser^ user = _bdd->getUserByIdRFID(rfid_id);
				Console::WriteLine("[Sortie] Acc�s autoris�");
				_ClientRFID->Send(protocole->RetourRFIDAccesDemand(true));

				

				int poids = getPoids(_ClientBalance);
				
				Dechetterie::deleteUtilisateur(rfid_id);

				_ClientBarri�re->Send(protocole->OuvrirBarriere());
				Thread::Sleep(2000);
				_ClientBarri�re->Send(protocole->FermerBarriere());


			}
			catch (Exception^ e)
			{
				if (Dechetterie::Debug)
				{
					Console::WriteLine("[Sortie] " + e);
				}
				Console::WriteLine("[Sortie] Acc�s Refus�");
				_ClientRFID->Send(protocole->RetourRFIDAccesDemand(false));
			}


		}
		catch (...)
		{

		}
		Console::WriteLine("[Sortie] Fin de proc�dure");
	}
}


String^ Sortie::WaitAccesDemand(Client^ cl)
{
	ProtocolMsg^ msgRev = gcnew ProtocolMsg();
	do
	{

		msgRev = protocole->translateReceive(cl->Receive());
		Console::WriteLine("Type = " + msgRev->type);

	} while (msgRev->type != protocole->GetTypeProtocoleByID("RfDAcces"));

	return msgRev->getData1String();
}

int Sortie::getPoids(Client^ cl)
{
	cl->Send(protocole->GetBalancePoids());
	ProtocolMsg^ msgRev = gcnew ProtocolMsg();
	do
	{

		msgRev = protocole->translateReceive(cl->Receive());
		Console::WriteLine("Type = " + msgRev->type);



	} while (msgRev->type != protocole->GetTypeProtocoleByID("baRDPoids"));
	return msgRev->getData1Int();
}
void Sortie::getClientFromList(List<Client^>^ l)
{
	for each (Client^ var in l)
	{
		if (var->getGroupe() == 2)
		{
			if (var->getType() == 1)
			{
				_ClientBarri�re = var;
			}
			else
			{
				if (var->getType() == 2)
				{
					_ClientBalance = var;
				}
				else
				{
					if (var->getType() == 3)
					{
						_ClientRFID = var;
					}
				}
			}
		}
	}
}