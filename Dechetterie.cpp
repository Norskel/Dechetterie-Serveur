#include "Dechetterie.h"


List<Client^>^ Dechetterie::GetListClient()
{
	return _listClient;
}

List<Utilisateur^>^ Dechetterie::GetListUtilisateur()
{
	return _listUtilisateur;
}

void Dechetterie::SetListClient(List<Client^>^ l)
{
	_listClient = l;
}

void Dechetterie::addUtilisateur(String ^ id_rfid,int tDechet)
{
	DataBddProxy^ bdd = DataBddProxy::getDataBddProxy();
	try
	{
		DataUser^ du = bdd->getUserByIdRFID(id_rfid);
		_listUtilisateur->Add(gcnew Utilisateur(du->Nom, du->Prenom, tDechet, id_rfid));
		Console::WriteLine("[ Utilisateur ] Nouvelle utilisateur dans la dechetterie : " + du->Nom + du->Prenom + " ID_RFID = " + id_rfid);

	}
	catch (...)
	{
		Console::WriteLine("[ Utilisateur ] Utilisateur avec id RFID " + id_rfid + " Inconnu ");
	}
	//
}

Dechetterie::Dechetterie(int portEntree, int portSortie, IPAddress^ interface)
{
	_bdd = DataBddProxy::getDataBddProxy("192.168.0.150", "", "Dechetterie", "root", "root");
	_entree = gcnew Entree(interface, portEntree);
	_sortie = gcnew Sortie(interface, portSortie);
}
