// 016FreeStore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Resource.h"
#include <string>
//#include <iostream>

using namespace std;

int main()
{
	{
		Resource localResource("local");
		string localString = localResource.GetName();
	}
	Resource* pResource = new Resource("created with new");
	string newString = pResource->GetName();
	
	int j = 3;					// Bad Possible Example 
	if (j == 3) { return 0; }	// The code will stop here
	
	Resource* p2 = pResource;
	string string2 = p2->GetName();	// If pResource never deleted
	delete pResource;				// it'll cause memory leak
								
	// Bad Memory Management Example
	//string string3 = pResource->GetName();
	//pResource = nullptr;
	//delete pResource;
	//delete p2;

    return 0;
}