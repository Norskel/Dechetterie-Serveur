#pragma once
using namespace System;

ref class TypeMessage
{
public:
	TypeMessage(){}
	TypeMessage(int id, int s, String^ nom, String^ data1, String^ typeData1, int nbBData1, String^ data2, String^ typeData2, int nbBData2)
	{
		ID = id;
		Sender = s;
		Nom = nom;
		Data1 = data1;
		TypeData1 = typeData1;
		NbBData1 = nbBData1;
		Data2 = data2;
		TypeData2 = typeData2;
		NbBData2 = nbBData2;
	}
	TypeMessage(int id, int s, String^ nom, String^ data1, String^ typeData1, int nbBData1)
	{
		ID = id;
		Sender = s;
		Nom = nom;
		Data1 = data1;
		TypeData1 = typeData1;
		NbBData1 = nbBData1;
	}
	TypeMessage(int id, int s, String^ nom)
	{
		ID = id;
		Sender = s;
		Nom = nom;
	}
	int ID;
	int Sender;
	String^ Nom;
	String^ Data1 = "";
	int NbBData1 = 0;
	String^ TypeData1 = "";
	String^ Data2 = "";
	int NbBData2 = 0;
	String^ TypeData2 = "";

	String^ ToString() override
	{
		return Nom;
	}
};