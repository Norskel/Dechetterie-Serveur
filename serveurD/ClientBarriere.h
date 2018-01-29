#pragma once
#include "ClientServeurTcp.h"
using namespace System;

ref class ClientBarriere :public ClientServeurTcp
{
public:
	ClientBarriere();
	int Open();
	int Close();
	bool GetState();
};
