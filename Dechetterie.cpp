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

void Dechetterie::addUtilisateur(String ^ id_rfid, int tDechet, int poids, array<Byte>^ photo)
{
	DataBddProxy^ bdd = DataBddProxy::getDataBddProxy();
	try
	{
		DataUser^ du = bdd->getUserByIdRFID(id_rfid);
		_listUtilisateur->Add(gcnew Utilisateur(du->Nom, du->Prenom, tDechet, id_rfid,poids,photo));
		DataEntree^ de = gcnew DataEntree();
		de->ID_Dechet = tDechet;
		de->ID_User = bdd->getUserByIdRFID(id_rfid)->ID;
		de->Poids = poids;
		de->dt = DateTime::Now;
		bdd->addEntree(de);
		Console::WriteLine("[ Utilisateur ] Nouvelle utilisateur dans la dechetterie : " + du->Nom +" "+ du->Prenom + " ID_RFID = " + id_rfid);

	}
	catch (...)
	{
		Console::WriteLine("[ Utilisateur ] Utilisateur avec id RFID " + id_rfid + " Inconnu ");
	}
	//
}

void Dechetterie::deleteUtilisateur(String ^ id_rfid)
{
	DataBddProxy^ bdd = DataBddProxy::getDataBddProxy();
	for (int i = 0; i < _listUtilisateur->Count; i++)
	{
		if (_listUtilisateur[i]->getRFIDID() == id_rfid)
		{
			Console::WriteLine("[ Utilisateur ] L'utilisateur quitte la dechetterie : " + _listUtilisateur[i]->getNom() + " " + _listUtilisateur[i]->getPrenom() + " ID_RFID = " + id_rfid);
			_listUtilisateur->RemoveAt(i);

			break;
		}
	}
	try
	{
		int iduser = bdd->getUserByIdRFID(id_rfid)->ID;
		Console::Write("[ Utilisateur ] Delete ID USER = " + iduser);
		int idEntree = bdd->getEntreeByUserID(iduser)->ID;
		Console::WriteLine(" ID Entree = " + idEntree);

		bdd->deleteEntreeByID(idEntree);
	}
	catch (Exception^ e)
	{
		Console::WriteLine(e);
	}


}

Dechetterie::Dechetterie(int portEntree, int portSortie, IPAddress^ interface)
{
	_bdd = DataBddProxy::getDataBddProxy("192.168.0.150", "", "Dechetterie", "root", "root");
	_entree = gcnew Entree(interface, portEntree);
	_sortie = gcnew Sortie(interface, portSortie);

	
}
