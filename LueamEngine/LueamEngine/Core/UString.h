#pragma once
#include <iostream>

class String
{
	char* data = nullptr;
	unsigned long len = 0;
	
public : 
	String();
	String(const char*& value);
	String(const char value[]);

	operator const char* ();
};
