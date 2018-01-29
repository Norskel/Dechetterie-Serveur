#include "stdafx.h"
#include "Groupe.h"


Groupe::Groupe()
{
	_id = nbGroupe;
	Groupe::nbGroupe++;
}

Groupe::~Groupe()
{
	Groupe::nbGroupe--;
}

int Groupe::GetNb()
{
	return nbGroupe;
}

ClientBalance ^ Groupe::GetClientBalance()
{
	return _clBa;
}
ClientBarriere ^ Groupe::GetClientBarriere()
{
	return _clBr;
}
ClientNfc ^ Groupe::GetClientNfc()
{
	return _clNfc;
}

int Groupe::GetId()
{
	return _id;
}
String ^ Groupe::GetNom()
{
	return _nom;
}

void Groupe::SetClientBalance(ClientBalance ^ c)
{
	_clBa = c;
}
void Groupe::SetClientBarriere(ClientBarriere ^ c)
{
	_clBr = c;
}
void Groupe::SetClientNfc(ClientNfc ^ c)
{
	_clNfc = c;
}

void Groupe::SetNom(String ^ n)
{
	_nom = n;
}
