#include "stdafx.h"
#include "Utilisateur.h"




Utilisateur::Utilisateur(String ^ nom, String ^ prenom, int tdechet)
{
	_nom = nom;
	_prenom = prenom;
	_typeDechet = tdechet;
	_dtArrivée = DateTime::Now;
}

Utilisateur::Utilisateur(String ^ nom, String ^ prenom, int tdechet, String ^ rfid)
{
	_nom = nom;
	_prenom = prenom;
	_typeDechet = tdechet;
	_RFID_Card = rfid;
}

Utilisateur::Utilisateur(String ^ nom, String ^ prenom, int tdechet, String ^ rfid, array<Byte>^ p)
{
	_nom = nom;
	_prenom = prenom;
	_typeDechet = tdechet;
	_RFID_Card = rfid;
	_photo = p;
}

DateTime Utilisateur::getDuree()
{
	return _dtArrivée;
}
