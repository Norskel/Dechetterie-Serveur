#include "TcpServer.h"
#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;



int main(array<System::String ^> ^args)
{

	Console::WriteLine(L"Serveur Décheterie V1");

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MainForm form;
	Application::Run(%form);


    Console::WriteLine(L"Hello World");
    return 0;


}
