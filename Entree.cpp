#include "stdafx.h"
#include "Entree.h"



Entree::Entree(IPAddress ^ listenip, int listenPort)
{
	_srv = gcnew Serveur(listenip, listenPort,1);
	_srv->Start();
	_tEntree = gcnew Thread(gcnew ThreadStart(this, &Entree::ThreadEntree));
	_tEntree->Name = "Thread Entree";
	_tEntree->Start();
	_bdd = DataBddProxy::getDataBddProxy();
	protocole = Protocole::getProtocole();

}

void Entree::ThreadEntree()
{
	Boolean connected = false;
	do
	{
		Console::WriteLine("[Entree] Attente de la connection de tous les client;");
		Thread::Sleep(500);
		getClientFromList(Dechetterie::GetListClient());
		//connected = _ClientBalance->getState() && _ClientBarrière->getState() && _ClientRFID->getState();
		connected = _ClientRFID->getState();
		
	}
	while (!connected);
	while (true)
	{
		getClientFromList(Dechetterie::GetListClient());
		try
		{
			//===================================== Attente de Demande d'accès ========================================================================
			ProtocolMsg^ msgRev = gcnew ProtocolMsg();
			do
			{
				msgRev = protocole->translateReceive(_ClientRFID->Receive());
				Console::WriteLine("Type = " + msgRev->type);

			} while (msgRev->type != 7);
			Console::WriteLine("[Entree] Demande d'accès avec l'id RFID " + Encoding::Default->GetString(msgRev->data1));
			//===================================== Demande d'accès ====================================================================================
			try
			{
				//Console::WriteLine("[Entree] Demande d'accès avec l'id RFID " + Encoding::Default->GetString(msgRev->data1));
				_bdd->getUserByIdRFID(Encoding::Default->GetString(msgRev->data1)); 
				Console::WriteLine("[Entree] Accès autorisé");
				_ClientRFID->Send(protocole->RetourRFIDAccesDemand(true));

				ProtocolMsg^ msgRev = gcnew ProtocolMsg();
				int i = 0;
				do
				{
					i++;
					msgRev = protocole->translateReceive(_ClientRFID->Receive());
					Console::WriteLine("Type = " + msgRev->type);
					if (i > 5)
					{
						break;
					}

				} while (msgRev->type != 9);
				


			}
			catch (...)
			{

				Console::WriteLine("[Entree] Accès Refusé");
				_ClientRFID->Send(protocole->RetourRFIDAccesDemand(false));
			}


		}
		catch (...)
		{
			Console::WriteLine("[Entree] Fin de procédure");
		}
	}
}

void Entree::getClientFromList(List<Client^>^ l)
{
	for each (Client^ var in l)
	{
		if (var->getGroupe() == 1)
		{
			if (var->getType() == 1)
			{
				_ClientBarrière = var;
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
