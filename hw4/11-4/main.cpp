#include <iostream>
using namespace std;
#include "security.h"
#include "administrator.h"
#include "user.h"

int main() {
	Security user;
	Administrator user1;
	User user2;
	string username, password;

	cout << "Enter your username : ";
	cin >> username;
	cout << "Enter password : ";
	cin >> password;

	if ((user.validate(username, password)) == 1) {
		if (user2.Login(username, password) == 1) {
			cout << "user or administrator" << endl;
		}
	}
	else if(user.validate(username, password)==2){
		if (user1.Login(username, password) == 1) {
			cout << "administrator" << endl;
		}
	}
	else {
		cout << "neither user nor administrator" << endl;
	}

	system("PAUSE");
	return(0);
}