#pragma once
#include "Utilisateur.h"
#include "DataBddProxy.h"
#include "Entree.h"
#include "Sortie.h"
#include "Protocole\Protocole.h"
#include "Protocole\StructProtocolMsg.h"
#include "Protocole\StructTypeMessage.h"


using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Collections::Generic;

ref class Entree;
ref class Sortie;



ref class Dechetterie
{
private:
	static List<Utilisateur^>^ _listUtilisateur = gcnew List<Utilisateur^>;
	DataBddProxy^ _bdd;
	Sortie^ _sortie;
	static List<Client^>^ _listClient = gcnew List<Client^>;
	Entree^ _entree;
public:
	static Boolean Debug = true;
	static List<Client^>^ GetListClient();
	static List<Utilisateur^>^ GetListUtilisateur();

	static void SetListClient(List<Client^>^ l);
	
	static void addUtilisateur(String ^ id_rfid, int tDechet, int poids, array<Byte>^ photo);
	static void deleteUtilisateur(String ^ id_rfid);


	Dechetterie(int portEntree, int portSortie, IPAddress^ interface);

};

