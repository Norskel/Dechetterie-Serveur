#include "stdafx.h"
#include "Serveur.h"
#include "Dechetterie.h"



Serveur::Serveur(IPAddress ^ listenip, int listenPort,int groupe)
{
	_interface = listenip;
	_port = listenPort;
	_groupe = groupe;

	_socketServeur = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
	IPEndPoint^ local = gcnew IPEndPoint(listenip, listenPort);
	_socketServeur->Bind(local);
}

Boolean Serveur::Start()
{
	try
	{
		Console::WriteLine("start");
		this->_socketServeur->Listen(1);
		this->_isRunning = true;
		this->_tWC = gcnew Thread(gcnew ThreadStart(this, &Serveur::WaitClient));
		this->_tWC->Name = "Thread TCP SERVEUR PORT " + _port;
		this->_tWC->Start();
	}
	catch (Exception^ e)
	{
		Console::WriteLine(e->ToString());
		return false;
	}
	return true;
}

void Serveur::WaitClient()
{
	while (_isRunning)
	{
		try
		{
			Socket^ cliSocket;
			cliSocket = _socketServeur->Accept();
			int i = 0;
			_listClient = Dechetterie::GetListClient();
			Console::WriteLine(_listClient->Count);



			IPAddress^ ipAdresseClient = (IPAddress^)(((IPEndPoint^)cliSocket->RemoteEndPoint)->Address);
			for (i = 0; i < _listClient->Count; i++)

			{
				IPAddress^ IPAdresseList = _listClient[i]->getIP();
				Console::Write("List : " + _listClient[i]->getIP());
				Console::WriteLine("Address : " + ipAdresseClient);
				// if ((IPAddress^)(((IPEndPoint^)cliSocket->RemoteEndPoint)->Address) == _listClient[i]->getIPAdresse())

				if (ipAdresseClient->ToString() == IPAdresseList->ToString())
				{
					_listClient[i]->setSocket(cliSocket);
					_listClient[i]->setState(true);
					Console::WriteLine("HEY");
					Dechetterie::SetListClient(_listClient);
					break;

				}
			}

			if (i == _listClient->Count)
			{
				cliSocket->Close();
			}
			Console::WriteLine("NewClient {0}", (cliSocket->RemoteEndPoint)->ToString());


		}
		catch (Exception^ e)
		{

		}

	}
}

List<Client^>^ Serveur::getClientList()
{
	return _listClient;
}
