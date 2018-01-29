#pragma once
using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::IO;
using namespace System::Text;
using namespace System::Threading;
using namespace System::ComponentModel;
using namespace System::Collections::Generic;

ref class ClientServeurTcp
{
private:
	TcpClient^ _client;
	IPAddress^ _IP;
	int _port;

public:
	ClientServeurTcp();
	ClientServeurTcp(TcpClient^ cl);
	IPAddress^ GetIP();
	int GetPort();
};

