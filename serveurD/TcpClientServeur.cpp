#include "TcpClientServeur.h"




TcpClientServeur::TcpClientServeur()
{
	throw gcnew System::NotImplementedException();
}

TcpClientServeur::TcpClientServeur(Socket^ cl)
{
	_client = cl;
	_IP = ((IPEndPoint^)_client->RemoteEndPoint)->Address;
	_port = ((IPEndPoint^)_client->RemoteEndPoint)->Port;

	TR = gcnew Thread(gcnew ThreadStart(this, &TcpClientServeur::Receive));
	TR->Name = "Receive";
	TR->Start();

}

int TcpClientServeur::Send(String ^ msg)
{
	try
	{
		array<Byte>^buffer = gcnew array<Byte>(256);
		_client->Send(buffer, 0, buffer->Length, SocketFlags::None);
	}
	catch (Exception^ e)
	{
		Console::WriteLine("Error Client Send " + e);
		return 1;
	}
	return 0;

}
void TcpClientServeur::Receive()
{
	while (true)
	{
		try
		{
			array<Byte>^buffer = gcnew array<Byte>(256);
			_client->Receive(buffer, 0, buffer->Length, SocketFlags::None);

		}
		catch (Exception^e)
		{
			Console::WriteLine("Deconnexion de {0}", (_client->RemoteEndPoint)->ToString());
			Console::WriteLine(e);
			_client->Disconnect(true);
			break;
		}
	}
}

void TcpClientServeur::Deconnexion()
{
	Console::WriteLine("Deconnexion de {0}", this->GetIP()->ToString());
	TR->Abort();
	_client->Disconnect(true);
}

IPAddress ^ TcpClientServeur::GetIP()
{
	return _IP;
}
int TcpClientServeur::GetPort()
{
	return _port;
}

