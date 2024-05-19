#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;
#include "security.h"

class User
{
public:
	static int Login(string username, string password);
};

#endif //USER_H