#pragma once
#include "StructProtocolMsg.h"
#include "StructTypeMessage.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;

ref class Protocole
{
private:
	static Protocole^  _proto = nullptr;

	List<TypeMessage^>^ _listTypeMsg = gcnew List<TypeMessage^>;

	Protocole()
	{
		_listTypeMsg->Add(gcnew TypeMessage(1, 1, "Demande du poids"));
		_listTypeMsg->Add(gcnew TypeMessage(2, 2, "Retour du poids", "Poids", "int",6));
		_listTypeMsg->Add(gcnew TypeMessage(3, 1, "Ouvrir Barrière"));
		_listTypeMsg->Add(gcnew TypeMessage(4, 1, "Fermé Barrière"));
		_listTypeMsg->Add(gcnew TypeMessage(5, 1, "Demande de l'état de la barrière"));
		_listTypeMsg->Add(gcnew TypeMessage(6, 3, "Retour de l'état de la barrière", "Etat", "bool",1));
		_listTypeMsg->Add(gcnew TypeMessage(7, 4, "Demande d'accès", "ID RFID", "string",11));
		_listTypeMsg->Add(gcnew TypeMessage(8, 1, "Retour demande d'accès", "Autorisation", "bool",1));
		_listTypeMsg->Add(gcnew TypeMessage(9, 4, "Envoie des infos dechet + photo", "Type de dechet", "int",1, "Photo", "tableByte",120));
		_listTypeMsg->Add(gcnew TypeMessage(50, 0, "Ping"));
		_listTypeMsg->Add(gcnew TypeMessage(51, 0, "Retour Ping"));
	}
public:

	static Protocole^ getProtocole()
	{
		if (_proto == nullptr)
		{
			_proto = gcnew Protocole();
		}
		return _proto;
	}

	array<Byte>^ translate(int type, String^ data)
	{
		Encoding^ srv = Encoding::ASCII;
		array<Byte>^buffer = gcnew array<Byte>(srv->GetByteCount(data) + 2);
		buffer[1] = type;
		int i = 1;
		for each (Byte var in srv->GetBytes(data))
		{
			i++;
			buffer[i] = var;
		}
		buffer[0] = buffer->Length;
		return buffer;
	}

	array<Byte>^ GetBalancePoids()
	{
		return translate(1, "");
	}
	array<Byte>^ RetourGetBalancePoids(int poids)
	{
		return translate(2, Convert::ToString(poids));
	}

	array<Byte>^ OuvrirBarriere()
	{
		return translate(3, "");
	}
	array<Byte>^ FermerBarriere()
	{
		return translate(4, "");
	}
	array<Byte>^ GetEtatBarriere()
	{
		return translate(5, "");
	}
	array<Byte>^ RetourGetEtatBarriere(Boolean state)
	{
		if (state)
		{
			return translate(6, "1");
		}
		else
		{
			return translate(6, "0");
		}
	}

	array<Byte>^ RFIDAccesDemand(String^ RFID_ID)
	{
		return translate(7, RFID_ID);
	}
	array<Byte>^ RetourRFIDAccesDemand(Boolean state)
	{
		if (state)
		{
			return translate(8, "1");
		}
		else
		{
			return translate(8, "0");
		}
	}

	array<Byte>^ Ping()
	{
		return translate(50, "");
	}
	array<Byte>^ RetourPing()
	{
		return translate(51, "");
	}

	List<TypeMessage^>^  GetListTypeMessage()
	{
		return _listTypeMsg;
	}

	ProtocolMsg^ translateReceive(array<Byte>^t)
	{


		Console::WriteLine(" ");
		ProtocolMsg^ tPM = gcnew ProtocolMsg();
		tPM->lenght = t[0];
		tPM->type = t[1];
		TypeMessage^ tTM = gcnew TypeMessage();
		for each (TypeMessage^ var in _listTypeMsg)
		{
			if (var->ID == t[1])
			{
				tTM = var;
				break;
			}
		}

		if (tTM->NbBData1 != 0)
		{
			array<Byte>^ tt = gcnew array<Byte>(tTM->NbBData1);
			for (int i = 0; i < tTM->NbBData1; i++)
			{
	/*			if (t[2 + i] > t->Length)
				{
					break;
				}*/
				Console::WriteLine(t[2 + i]);
				tt[i] = t[2 + i];
			}
			tPM->data1 = tt;
			if (tTM->NbBData2 != 0)
			{
				array<Byte>^ tt = gcnew array<Byte>(tTM->NbBData2);
				for (int i = 0; i < tTM->NbBData2; i++)
				{
					tt[i] = t[2+ tTM->NbBData1 + i];
				}
				tPM->data2 = tt;
			}
		}
		tPM->raw = t;
		return tPM;
	}

	array<Byte>^ translateByID(int id, Boolean state, String^ txt,int n)
	{
		switch (id)
		{
		case 1:
			return GetBalancePoids();
			break;
		case 2:
			return RetourGetBalancePoids(n);
			break;
		case 3:
			return OuvrirBarriere();
			break;
		case 4:
			return FermerBarriere();
			break;
		case 5:
			return GetEtatBarriere();
			break;
		case 6:
			return RetourGetEtatBarriere(state);
			break;
		case 7:
			return RFIDAccesDemand(txt);
			break;
		case 8:
			return RetourRFIDAccesDemand(state);
			break;
		case 50:
			return Ping();
			break;
		case 51:
			return RetourPing();
			break;
		default:
			break;
		}
	}

	TypeMessage^ getTypeMessageByID(int id)
	{
		for each (TypeMessage^ var in _listTypeMsg)
		{
			if (var->ID == id)
			{
				return var;
				break;
			}
		}
	}



};
