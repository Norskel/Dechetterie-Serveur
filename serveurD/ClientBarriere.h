#pragma once
#include "TcpClientServeur.h"
using namespace System;

ref class ClientBarriere :public TcpClientServeur
{
public:
	ClientBarriere();
	int Open();
	int Close();
	bool GetState();
};
