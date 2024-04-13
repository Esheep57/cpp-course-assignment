#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

class BoxOfProduce
{
public:
	BoxOfProduce();
	void output();
	string getFood1();
	void setFood1(string Food1);
	string getFood2();
	void setFood2(string Food2);
	string getFood3();
	void setFood3(string Food3);
	void exchange();
private:
	string food1;
	string food2;
	string food3;
};

int main()
{
	BoxOfProduce Box1;
	char change;

	Box1.output();
	cout << endl << "contents of the box:" << endl;
	cout << "1." << Box1.getFood1() << endl;
	cout << "2." << Box1.getFood2() << endl;
	cout << "3." << Box1.getFood3() << endl;
	cout << endl << "Do you want to change the contents of the box ? (enter 'y'(yes) or 'n'(no))";
	cin >> change;
	if (change == 'n')
	{
		cout << endl << "The final contents of the box:" << endl;
		cout << Box1.getFood1() << endl;
		cout << Box1.getFood2() << endl;
		cout << Box1.getFood3() << endl;
	}
	else
	{
		while (change == 'y')
		{
			Box1.exchange();
			cout << "Do you want to change the contents of the box ? (enter 'y'(yes) or 'n'(no):";
			cin >> change;
		}
		cout << endl << "The final contents of the box:" << endl;
		cout << Box1.getFood1() << endl;
		cout << Box1.getFood2() << endl;
		cout << Box1.getFood3() << endl;
	}

	system("PAUSE");
	return(0);
}

BoxOfProduce::BoxOfProduce() :food1("Broccoli"), food2("Tomato"), food3("Kiwi")
{}

void BoxOfProduce::output()
{
	string food[5], line;
	ifstream input;
	input.open("text.txt");
	srand((unsigned)time(NULL));

	if (input.fail())
	{
		cout << "Input file opening failed" << endl;
		exit(1);
	}
	else
	{
		cout << "list:" << endl;
		for (int i = 0; i < 5; i++)
		{
			getline(input, line);
			food[i] = line;
			cout << i + 1 << "." << food[i] << endl;
		}
	}
	setFood1(food[rand() % 5]);
	setFood2(food[rand() % 5]);
	setFood3(food[rand() % 5]);

	input.close();
}

string BoxOfProduce::getFood1()
{
	return food1;
}
void BoxOfProduce::setFood1(string Food1)
{
	food1 = Food1;
}

string BoxOfProduce::getFood2()
{
	return food2;
}
void BoxOfProduce::setFood2(string Food2)
{
	food2 = Food2;
}

string BoxOfProduce::getFood3()
{
	return food3;
}
void BoxOfProduce::setFood3(string Food3)
{
	food3 = Food3;
}

void BoxOfProduce::exchange()
{
	int giveUp, wantChange;
	string food[5], line;
	ifstream input;
	input.open("text.txt");

	cout << "Which content of the box you do not want(1, 2 or 3):";
	cin >> giveUp;
	cout << "Choose a fruit or vegetable you want(1, 2, 3, 4 or 5):";
	cin >> wantChange;
	for (int i = 0; i < 5; i++)
	{
		getline(input, line);
		food[i] = line;
	}
	switch (giveUp)
	{
	case 1:
		setFood1(food[wantChange - 1]);
		break;
	case 2:
		setFood2(food[wantChange - 1]);
		break;
	case 3:
		setFood3(food[wantChange - 1]);
		break;
	default:
		break;
	}
}