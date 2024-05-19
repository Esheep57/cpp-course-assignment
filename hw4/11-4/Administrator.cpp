#include <iostream>
using namespace std;
#include "Administrator.h"

int Administrator::Login(string username, string password) 
{
	if ((username == "costello") && (password == "tuesday"))return 1;
	return 0;
}