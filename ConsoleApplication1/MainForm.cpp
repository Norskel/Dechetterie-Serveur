// ConsoleApplication1.cpp : fichier projet principal.

#include "stdafx.h"
#include "MainForm.h"

using namespace System;


int main(array<System::String ^> ^args)
{
	Console::WriteLine(L"Client Décheterie V1");

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MainForm form;
	Application::Run(%form);

	return 0;
}
