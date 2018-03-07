#include "stdafx.h"
#include "Utilisateur.h"


Utilisateur::Utilisateur(String ^ nom, String ^ prenom, int tdechet, String ^ rfid, int poids, array<Byte>^ photo)
{
	_nom = nom;
	_prenom = prenom;
	_typeDechet = tdechet;
	_RFID_Card = rfid;
	_poidsEntree = poids;
	_dtArrivée = DateTime::Now;
	_photo = photo;
}

DateTime Utilisateur::getDuree()
{
	return _dtArrivée;
}

String ^ Utilisateur::getRFIDID()
{
	return _RFID_Card;
}

String ^ Utilisateur::getNom()
{
	return _nom;
}

String ^ Utilisateur::getPrenom()
{
	return _prenom;
}
