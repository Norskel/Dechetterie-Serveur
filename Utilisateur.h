#pragma once
using namespace System;
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
public:
	Utilisateur(String^ nom, String^prenom, int tdechet);
	Utilisateur(String^ nom, String^prenom, int tdechet, String^  rfid);
	Utilisateur(String^ nom, String^prenom, int tdechet, String^  rfid, array<Byte>^p);
	DateTime getDuree();

};

