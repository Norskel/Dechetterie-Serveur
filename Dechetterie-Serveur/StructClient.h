#pragma once
#include "Enum.h"


using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Collections::Generic;

ref class Client
{
private:
	int _groupe; // 1 entree 2 sortie
	int _type; // 1 barriere 2 balance 3 rfid	
	IPAddress^ _ip;
	Boolean _isConnected = false;
	Socket^ _clientSocket;
public:
	Client(int groupe, int type, IPAddress^ip) { _groupe = groupe; _type = type; _ip = ip; }

	int getGroupe() { return _groupe; }
	int getType() { return _type; }
	IPAddress^ getIP() { return _ip; }
	Boolean getState() { return _isConnected; }
	Socket^ getSocket() { return _clientSocket; }

	void setGroupe(int i) { _groupe = i; }
	void setType(int i) { _type = i; }
	void setIP(IPAddress^ i) { _ip = i; }
	void setState(Boolean i) { _isConnected = i; }
	void setSocket(Socket^ s) { _clientSocket = s; }

	Boolean Send(array<Byte>^ data)
	{
		try
		{
			if (_clientSocket->Connected)
			{
				_clientSocket->Send(data);
				return true;
			}
			else
			{
				Console::WriteLine("[ Serveur " + id_groupe(_groupe).ToString() + " ] " + id_client(_type).ToString() + " viens de ce déconnectée");
				_isConnected = false;
				_clientSocket->Close();
				return false;
			}

		}
		catch (Exception^e)
		{

				Console::WriteLine("[ Client ][ Send ]" + e);
			
			return false;
		}
	}

	array<Byte>^ Receive()
	{
		array<Byte>^ data = gcnew array<Byte>(1024);
		try
		{
			if (_clientSocket->Connected)
			{
				_clientSocket->Receive(data);
				return data;
			}
			else
			{
				Console::WriteLine("[ Serveur " + id_groupe(_groupe).ToString() + " ] " + id_client(_type).ToString() + " viens de ce déconnectée");
				_isConnected = false;
				_clientSocket->Close();
			}
		}
		catch (Exception^e)
		{

				Console::WriteLine("[ Client ][ Receive ]" + e);
			
		}
	}
	


};