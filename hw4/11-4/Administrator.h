#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream>
using namespace std;
#include "security.h"

class Administrator
{
public:
	static int Login(string username, string password);
};

#endif //ADMINISTRATOR_H