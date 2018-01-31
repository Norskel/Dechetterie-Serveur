#include "ClientServeurTcp.h"



ClientServeurTcp::ClientServeurTcp()
{
	throw gcnew System::NotImplementedException();
}

ClientServeurTcp::ClientServeurTcp(TcpClient^ cl)
{
	_client = cl;
	_IP = ((IPEndPoint^)_client->Client->RemoteEndPoint)->Address;
	_port = ((IPEndPoint^)_client->Client->RemoteEndPoint)->Port;


	
}

IPAddress ^ ClientServeurTcp::GetIP()
{
	return _IP;
}

int ClientServeurTcp::GetPort()
{
	return _port;
}
