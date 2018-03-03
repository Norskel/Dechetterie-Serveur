#pragma once
using namespace System;

ref struct ProtocolMsg
{
	int lenght;
	int type;
	array<Byte>^ data1;
	array<Byte>^ data2;
	array<Byte>^ raw;
};