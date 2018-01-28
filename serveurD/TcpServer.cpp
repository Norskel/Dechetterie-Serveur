#include "TcpServer.h"


TcpServer::TcpServer(IPAddress^ listenip, int listenPort)
{
	_listenIP = listenip;
	_listenPort = listenPort;

	_server = gcnew TcpListener(_listenIP, _listenPort);

}

void TcpServer::WaitClient()
{
	while (_isRunning)
	{
		if (_server->Pending())
		{
			
			TcpClient^ newClient = _server->AcceptTcpClient();
			_listClient->Add(gcnew ClientServeurTcp(newClient));
			NewClient(this, 5);
		}
		else
		{
			Thread::Sleep(100);
		}
	}
}

Boolean TcpServer::Start()
{
	try
	{
		Console::WriteLine("start");
		_isRunning = true;
		_server->Start();
		_tWC = gcnew Thread(gcnew ThreadStart(this, &TcpServer::WaitClient));
		_tWC->Start();
	}
	catch (Exception^ e)
	{
		Console::WriteLine(e->ToString());
		return false;
	}
	return true;
}

Boolean TcpServer::Stop()
{
	return Boolean();
}

int TcpServer::GetListenPort()
{
	return 0;
}

IPAddress ^ TcpServer::GetListenIP()
{
	throw gcnew System::NotImplementedException();
	// TODO: insérer une instruction return ici
}

Boolean TcpServer::GetState()
{
	return Boolean();
}

List<ClientServeurTcp^>^ TcpServer::GetListClient()
{
	return _listClient;
}
