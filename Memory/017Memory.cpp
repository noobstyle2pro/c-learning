// 017Memory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Person.h"
#include <string>

using namespace std;

int main()
{
	Person William("William", "Tansil", 123);
	William.AddResource();
	William.SetFirstName("William2");
	William.AddResource();
    return 0;
}

