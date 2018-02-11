#include "TcpServer.h"


TcpServer::TcpServer(IPAddress^ listenip, int listenPort)
{
	_listenIP = listenip;
	_listenPort = listenPort;

	_server = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
	IPEndPoint^ local = gcnew IPEndPoint(listenip, listenPort);
	_server->Bind(local);
	
}

void TcpServer::WaitClient()
{
	while (_isRunning)
	{
		Socket^ cliSocket;
		cliSocket = _server->Accept();

		Console::WriteLine("NewClient {0}", (cliSocket->RemoteEndPoint)->ToString());
		TcpClientServeur^ cST = gcnew TcpClientServeur(cliSocket);
		_listClient->Add(cST);
		NewClient(this, 5);

	}
}

Boolean TcpServer::Start()
{
	try
	{
		Console::WriteLine("start");
		_server->Listen(1);
		_isRunning = true;
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
	return _listenIP;
}

Boolean TcpServer::GetState()
{
	return Boolean();
}

List<TcpClientServeur^>^ TcpServer::GetListClient()
{
	return _listClient;
}
