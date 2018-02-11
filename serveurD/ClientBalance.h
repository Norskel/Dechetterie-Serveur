#pragma once
#include "TcpClientServeur.h"
using namespace System;

ref class ClientBalance :public TcpClientServeur
{
public:
	ClientBalance();
	float GetPoids();
};

