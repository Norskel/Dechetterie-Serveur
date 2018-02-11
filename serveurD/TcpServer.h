#pragma once
#include "TcpClientServeur.h"

using namespace System;
using namespace System::Net;
using namespace System::Net::NetworkInformation;
using namespace System::Net::Sockets;
using namespace System::IO;
using namespace System::Text;
using namespace System::Threading;
using namespace System::ComponentModel;
using namespace System::Collections::Generic;

using namespace System::Xml;
using namespace System::Xml::Serialization;

ref class TcpServer
{
private:

	IPAddress^ _listenIP;
	List<TcpClientServeur^>^ _listClient = gcnew List<TcpClientServeur^>;
	Socket^ _server;
	Boolean _isRunning;
	
	int _listenPort;
	int _id;

	void WaitClient();
	Thread^ _tWC;

public:
	TcpServer(IPAddress^ listenip, int id);
	Boolean Start();
	Boolean Stop();

	int GetListenPort();
	IPAddress^ GetListenIP();
	Boolean GetState();
	List<TcpClientServeur^>^ GetListClient();

	event EventHandler<int>^ NewClient;
	
};

