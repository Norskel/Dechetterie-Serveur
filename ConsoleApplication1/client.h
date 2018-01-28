#pragma once
using namespace System;
using namespace System::Text;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;
using namespace System::IO;
using namespace System::ComponentModel;

delegate void NewMessageDelegate(int id, String ^msg);



ref class Client
{
private:
	IPAddress^ _ip;
	int _port;
	TcpClient^ _client;
	Boolean _etat;
	Thread^ TE;
	Thread^ TR;
	IPEndPoint^ _serveur;
	void Send(String^ msg);
	void TRd();
	int _id;
	StreamReader^ srClient;
	StreamWriter^ swClient;

public:
	Client(IPAddress^ ip,int port,int id);
	void Start();
	void Stop();

	event NewMessageDelegate^ NewMessage;
	
};

