#include "Dechetterie.h"
#include "Entree.h"
using namespace System;
using namespace System::Collections::Generic;

int main(array<System::String ^> ^args)
{
	Entree^ r;
	List<Client^>^ listClient = gcnew List<Client^>;
	listClient->Add(gcnew Client(1, 1, IPAddress::Parse("192.168.245.128")));// 1 barriere 2 balance 3 rfid	
	//listClient->Add(gcnew Client(1, 2, IPAddress::Parse("192.168.245.130")));
	listClient->Add(gcnew Client(1, 2, IPAddress::Parse("192.168.0.5")));

	//listClient->Add(gcnew Client(1, 3, IPAddress::Parse("192.168.245.130")));
	listClient->Add(gcnew Client(1, 3, IPAddress::Parse("127.0.0.1")));

	listClient->Add(gcnew Client(2, 1, IPAddress::Parse("192.168.245.128")));// 1 barriere 2 balance 3 rfid	
																			 //listClient->Add(gcnew Client(1, 2, IPAddress::Parse("192.168.245.130")));
	listClient->Add(gcnew Client(2, 2, IPAddress::Parse("192.168.0.5")));

	//listClient->Add(gcnew Client(1, 3, IPAddress::Parse("192.168.245.130")));
	listClient->Add(gcnew Client(2, 3, IPAddress::Parse("127.0.0.1")));

	Dechetterie^ d = gcnew Dechetterie(2501, 2502, IPAddress::Any);
	Dechetterie::SetListClient(listClient);
	return 0;
}

//String^ convertDateTimeFormat()
//{
//
//}