#include <iostream>
using namespace std;

class Weight
{
public:
	Weight();
	void setWeightPounds(int scale, double weight);
	double getWeightPounds() { return pound; }
	void setWeightKilograms(int scale, double weight);
	double getWeightKilograms() { return kilogram; }
	void setWeightOunces(int scale, double weight);
	double getWeightOunces() { return ounce; }
private:
	double pound;
	double kilogram;
	double ounce;
};

int main(){
	int scale;
	double weight;
	Weight user;

	cout << "1.pounds\n" << "2.kilograms\n" << "3.ounces\n";
	cout << "Which weight scale you want to use (enter the number) > ";
	cin >> scale;
	cout << "Enter your weight > ";
	cin >> weight;
	if (scale >= 1 && scale <= 3) {
		if (scale == 1) {
			user.setWeightPounds(scale, weight);
			user.setWeightKilograms(scale, weight);
			user.setWeightOunces(scale, weight);
		}
		else if (scale == 2) {
			user.setWeightOunces(scale, weight);
			user.setWeightPounds(scale, weight);
			user.setWeightKilograms(scale, weight);
		}
		else {
			user.setWeightKilograms(scale, weight);
			user.setWeightPounds(scale, weight);
			user.setWeightOunces(scale, weight);
		}
	}
	else {
		cout << "Wrong input!!" << endl;
		exit(1);
	}

	cout << "\nWeight:" << endl;
	cout << user.getWeightPounds() << " pounds" << endl;
	cout << user.getWeightKilograms() << " kilograms" << endl;
	cout << user.getWeightOunces() << " ounces" << endl;

	system("PAUSE");
	return(0);
}

Weight::Weight() :pound(0), kilogram(0), ounce(0)
{}

void Weight::setWeightPounds(int scale, double weight) {
	if (scale == 2) {
		pound = weight * 0.45;
	}
	else if (scale==3) {
		pound = weight * 16;
	}
	else {
		pound = weight;
	}
}

void Weight::setWeightKilograms(int scale, double weight) {
	if (scale == 1) {
		kilogram = weight * 2.21;
	}
	else if (scale==3) {
		kilogram = weight * 35.36;
	}
	else {
		kilogram = weight;
	}
}
void Weight::setWeightOunces(int scale, double weight) {
	if (scale == 1) {
		ounce = weight * 0.06;
	}
	else if (scale==2) {
		ounce = weight * 0.02;
	}
	else {
		ounce = weight;
	}
}