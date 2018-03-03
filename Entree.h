#pragma once
#include "Serveur.h"
#include "DataBddProxy.h"
#include "Protocole.h"
#include "Dechetterie.h"


using namespace System;
using namespace System::Threading;
using namespace System::Text;


ref class Entree
{
private:
	Serveur^ _srv;
	Thread^ _tEntree;
	void ThreadEntree();
	DataBddProxy^ _bdd;

	Protocole^ protocole;

	Client^ _ClientBarrière;
	Client^ _ClientBalance;
	Client^ _ClientRFID;
	void getClientFromList(List<Client^>^ l);

public:
	Entree(IPAddress ^ listenip, int listenPort);

};

