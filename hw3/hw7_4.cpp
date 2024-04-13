#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class HotDogStand
{
public:
	HotDogStand();
	void setID(int ID) { this->ID = ID; }
	int getID() { return ID; }
	void setSold(int sold) { this->sold = sold; }
	int getSold() { return sold; }
	void JustSold();
	static int getTotal() { return total; }
private:
	int ID;
	int sold;
	static int total;
};
int HotDogStand::total = 0;

int main() {
	HotDogStand stand1, stand2, stand3;
	char check, standSold;
	int ID1, ID2, ID3;

	cout << "A stand's ID > ";
	cin >> ID1;
	stand1.setID(ID1);
	cout << "B stand's ID > ";
	cin >> ID2;
	stand2.setID(ID2);
	cout << "C stand's ID > ";
	cin >> ID3;
	stand3.setID(ID3);
	cout << endl;

	cout << "A stand's ID : " << stand1.getID() << endl;
	cout << "B stand's ID : " << stand2.getID() << endl;
	cout << "C stand's ID : " << stand3.getID() << endl;

	do {
		cout << "Had the hot dog been sold ? (enter y or n) > ";
		cin >> check;
		if (check == 'y' || check == 'Y') {
			cout << "Which stand sold the hot dog ? (A, B or C) > ";
			cin >> standSold;
			switch (standSold) {
			case'A':
			case'a':
				stand1.JustSold();
				break;
			case'B':
			case'b':
				stand2.JustSold();
				break;
			case'C':
			case'c':
				stand3.JustSold();
				break;
			default:
				break;
			}
		}
	} while (check == 'y' || check == 'Y');

	cout << "\nStand A (ID:" << stand1.getID() << ") sold " << stand1.getSold() << " hot dogs.";
	cout << "\nStand B (ID:" << stand2.getID() << ") sold " << stand2.getSold() << " hot dogs.";
	cout << "\nStand C (ID:" << stand3.getID() << ") sold " << stand3.getSold() << " hot dogs.\n";
	cout << "The total numbers have been sold by three stands are " << HotDogStand::getTotal() << ".\n";

	system("PAUSE");
	return(0);
}
HotDogStand::HotDogStand():ID(0), sold(0)
{}

void HotDogStand::JustSold() {
	this->sold += 1;
	total += 1;
}