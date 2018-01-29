#pragma once
#include "ClientServeurTcp.h"
#include "ClientBalance.h"
#include "ClientBarriere.h"
#include "ClientNfc.h"

using namespace System;
using namespace System;

ref class Groupe
{
private:
	static int nbGroupe = 1;
	int _id;
	String^ _nom;
	ClientBalance^ _clBa;
	ClientBarriere^ _clBr;
	ClientNfc^ _clNfc;
public:
	Groupe();
	~Groupe();
	static int GetNb();
	ClientBalance^ GetClientBalance();
	ClientBarriere^ GetClientBarriere();
	ClientNfc^ GetClientNfc();
	int GetId();
	String^ GetNom();

	void SetClientBalance(ClientBalance^ c);
	void SetClientBarriere(ClientBarriere^ c);
	void SetClientNfc(ClientNfc^ c);
	void SetNom(String^ n);

};

