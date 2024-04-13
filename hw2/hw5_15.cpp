#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;

int main()
{
	int realPIN[5], NUM[10], PIN[10];
	int substitute[5], index[5];
	int correct = 0;
	srand(time(NULL));

	cout << "Enter the first number of an actual PIN number >";
	cin >> realPIN[0];
	cout << "Enter the second number of an actual PIN number >";
	cin >> realPIN[1];
	cout << "Enter the third number of an actual PIN number >";
	cin >> realPIN[2];
	cout << "Enter the fourth number of an actual PIN number >";
	cin >> realPIN[3];
	cout << "Enter the fifth number of an actual PIN number >";
	cin >> realPIN[4];

	for (int i = 0; i < 10; i++)
	{
		NUM[i] = rand() % 3 + 1;
		PIN[i] = i;
	}
	cout << "PIN:";
	for (int j = 0; j < 10; j++)
	{
		cout << PIN[j];
	}
	cout << endl;
	cout << "NUM:";
	for (int j = 0; j < 10; j++)
	{
		cout << NUM[j];
	}
	cout << endl;

	cout << "Enter the first number of an actual PIN number after protect >";
	cin >> substitute[0];
	cout << "Enter the second number of an actual PIN number after protect >";
	cin >> substitute[1];
	cout << "Enter the third number of an actual PIN number after protect >";
	cin >> substitute[2];
	cout << "Enter the fourth number of an actual PIN number after protect >";
	cin >> substitute[3];
	cout << "Enter the fifth number of an actual PIN number after protect >";
	cin >> substitute[4];

	for (int k = 0; k < 5; k++)
	{
		for (int z = 0; z < 10; z++)
		{
			if (realPIN[k] == PIN[z])
			{
				index[k] = z;
			}
		}
	}
	for (int a = 0; a < 5; a++)
	{
		if (substitute[a] == NUM[index[a]])
		{
			correct++;
		}
	}
	if (correct == 5)
	{
		cout << "correct password." << endl;
	}
	else
	{
		cout << "wrong password." << endl;
	}

	system("PAUSE");
	return(0);
}