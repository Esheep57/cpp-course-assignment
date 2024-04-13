#include <iostream>
#include<cmath>
#include<string>
using namespace std;

class zipCode {
public:
	zipCode(int zipcode);
	zipCode(string barcode);
	zipCode() {};
	string returnbarcode();
	int returnzipcode();
private:
	int zipcode;
	string barcode;
	int getzipcode();
};


int main(void) {
	int format, zipcode;
	string barcode;

	cout << "choose the format you want to enter(1 for zipcode,2 for barcode): ";
	cin >> format;
	if (format == 1) {
		cout << "enter the zipcode: ";
		cin >> zipcode;
		zipCode user(zipcode);
		cout << "zipcode: " << zipcode << endl;
		cout << "barcode:1" << user.returnbarcode() << "1" << endl;
	}
	else {
		cout << "enter the barcode: ";
		cin >> barcode;
		zipCode user(barcode);
		cout << "zipcode: " << user.returnzipcode() << endl;
		cout << "barcode: " << barcode << endl;
	}


	system("PAUSE");
	return 0;
}

zipCode::zipCode(int zipcode) {
	this->zipcode = zipcode;
};

zipCode::zipCode(string barcode) {
	this->barcode = barcode;
}


int zipCode::returnzipcode() {
	return getzipcode();
}

int zipCode::getzipcode() {
	string v(barcode, 1, barcode.length() - 2);
	int num[25], sum = 0, value[5], j = 0, total = 0;

	for (int i = 1; i < 26; i++) {
		if (i % 5 == 1) {
			num[i - 1] = (((int)v[i - 1]) - (int)'0') * 7;
			sum += num[i - 1];
		}
		else if (i % 5 == 2) {
			num[i - 1] = (((int)v[i - 1]) - (int)'0') * 4;
			sum += num[i - 1];
		}
		else if (i % 5 == 3) {
			num[i - 1] = (((int)v[i - 1]) - (int)'0') * 2;
			sum += num[i - 1];
		}
		else if (i % 5 == 4) {
			num[i - 1] = (((int)v[i - 1]) - (int)'0') * 1;
			sum += num[i - 1];
		}
		else if (i % 5 == 0) {
			num[i - 1] = (((int)v[i - 1]) - (int)'0') * 0;
			sum += num[i - 1];
			value[j] = sum;
			if (value[j] == 11) {
				value[j] = 0;
			}
			++j;
			sum = 0;
		}
	}
	for (int i = 0; i < 5; i++) {
		if (i == 0) {
			total += value[i] * 10000;
		}
		else if (i == 1) {
			total += value[i] * 1000;
		}
		else if (i == 2) {
			total += value[i] * 100;
		}
		else if (i == 3) {
			total += value[i] * 10;
		}
		else {
			total += value[i];
		}
	}
	return total;
}

string zipCode::returnbarcode() {
	int num[5], value[5] = { 7,4,2,1,0 };
	int i, j, x;
	bool find = false;
	string a;

	for (x = 0; x < 5; x++) {
		num[x] = zipcode / (int)pow(10, 4 - x) % 10;
		find = false;
		if (num[x] == 0)
			num[x] = 11;
		for (i = 0; i < 5; i++) {
			for (j = 1; j < 5; j++) {
				if (value[i] + value[j] == num[x]) {
					a = to_string((int)pow(10, 4 - i) + (int)pow(10, 4 - j));
					while (a.length() != 5) {
						a = "0" + a;
					}
					barcode += a;
					find = true;
					break;
				}
			}
			if (find)break;
		}
	}
	return barcode;
}