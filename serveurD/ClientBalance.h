#pragma once
#include "ClientServeurTcp.h"
using namespace System;

ref class ClientBalance :public ClientServeurTcp
{
public:
	ClientBalance();
	float GetPoids();
};

