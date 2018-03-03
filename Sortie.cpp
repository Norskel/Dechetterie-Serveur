#include "stdafx.h"
#include "Sortie.h"


Sortie::Sortie(IPAddress ^ listenip, int listenPort)
{
	_srv = gcnew Serveur(listenip, listenPort,2);
	_srv->Start();
	_tSortie = gcnew Thread(gcnew ThreadStart(this, &Sortie::ThreadSortie));
	_tSortie->Name = "Thread Sortie";
	_tSortie->Start();
	_bdd = DataBddProxy::getDataBddProxy();

}

void Sortie::ThreadSortie()
{
}
	