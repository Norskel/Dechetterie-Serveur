#pragma once
using namespace System;
using namespace System::Drawing;

ref class Utilisateur
{
private:
	String^ _prenom = "";
	String^ _nom = "";
	array<Byte>^ _photo = gcnew array<Byte>(25);
	int _typeDechet;
	String^ _RFID_Card;
	DateTime _dtArrivée;
	int ID_User;
	int _poidsEntree;

public:
	Utilisateur(String^ nom, String^prenom, int tdechet, String^  rfid, int poids, array<Byte>^p);
	DateTime getDuree();
	String^ getRFIDID();
	String^ getNom();
	String^ getPrenom();



};

