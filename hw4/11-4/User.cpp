#include <iostream>
using namespace std;
#include "User.h"

int User::Login(string username, string password)
{
	if ((username == "abbott") && (password == "monday"))return 1;
	if ((username == "costello") && (password == "tuesday"))return 1;
	return 0;
}