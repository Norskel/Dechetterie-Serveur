#pragma once
using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::IO;
using namespace System::Text;
using namespace System::Threading;
using namespace System::ComponentModel;
using namespace System::Collections::Generic;

ref class TcpClientServeur
{
private:
	Socket^ _client;
	IPAddress^ _IP;
	int _port;
	void Receive();
	Thread^ TR;

public:
	TcpClientServeur();
	TcpClientServeur(Socket^ cl);
	IPAddress ^ GetIP();
	int GetPort();
	int Send(String^ msg);
	static event EventHandler<String^>^ ReceiveMsg;
	void Deconnexion();
};