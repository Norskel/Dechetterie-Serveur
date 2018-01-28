#include "client.h"


Client::Client(IPAddress^ ip, int port,int id)
{
	_ip = ip;
	_id = id;
	_port = port;
	_client = gcnew TcpClient();
	_serveur = gcnew IPEndPoint(_ip, _port);
	//TE = gcnew Thread(gcnew ThreadStart(this, &Client::TEd));
	TR = gcnew Thread(gcnew ThreadStart(this, &Client::TRd));
	//TE->Name = "Thread Reception Client " + _id;
	TR->Name = "Thread Envoie Client " + _id;

	
}
void Client::TRd()
{
	String^ data;
	while (true)
	{

		data = srClient->ReadLine();
		this->NewMessage(_id, data);
	}
}
void Client::Send(String^ msg)
{

	swClient->WriteLine(msg);
	swClient->Flush();
}




void Client::Start()
{
	_etat = true;
	_client->Connect(_serveur);
	swClient = gcnew StreamWriter(_client->GetStream(), Encoding::ASCII);
	srClient = gcnew StreamReader(_client->GetStream(), Encoding::ASCII);

	TR->Start();
	//TE->Start();
	
}

void Client::Stop()
{
	throw gcnew System::NotImplementedException();
}
