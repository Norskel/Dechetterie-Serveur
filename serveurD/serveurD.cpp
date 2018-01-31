#include "TcpServer.h"
#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;


void OnNewClient(System::Object ^sender, int e);
int main(array<System::String ^> ^args)
e{

	Console::WriteLine(L"Serveur Décheterie V1");

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MainForm form;
	Application::Run(%form);

	TcpServer ^ts = gcnew TcpServer(IPAddress::Any, 25525);

	ts->NewClient += gcnew System::EventHandler<int>(&OnNewClient);



	if (!ts->Start())
	{
		Console::WriteLine("Fail start");
	}
	
	while (true)
	{
		Thread::Sleep(100);
	}

    Console::WriteLine(L"Hello World");
    return 0;


}

void OnNewClient(System::Object ^sender, int e)
{
	TcpServer^ s = (TcpServer^)sender;

	ClientServeurTcp^ c = s->GetListClient()[s->GetListClient()->Count-1];
	IPAddress^ ip = c->GetIP();
	
	Console::WriteLine("Client cree avec l'ip " + ip->ToString() +"et le port " + c->GetPort().ToString());
}
