#pragma once
#include "Serveur.h"
#include "DataBddProxy.h"



using namespace System;
using namespace System::Threading;

ref class Sortie
{
private:
	Serveur^ _srv;
	Thread^ _tSortie;
	void ThreadSortie();
	DataBddProxy^ _bdd;
public:
	Sortie(IPAddress ^ listenip, int listenPort);
};

