#include <iostream>
using namespace std;

int main()
{
	int arr[6] = { 0,0,0,0,0,0 };
	int input;

	cout << "Enter grade > ";
	for (int i = 0; i < 10; i++)
	{
		cin >> input;

		if (input == 0)
		{
			arr[0]++;
		}
		else if (input == 1)
		{
			arr[1]++;
		}
		else if (input == 2)
		{
			arr[2]++;
		}
		else if (input == 3)
		{
			arr[3]++;
		}
		else if (input == 4)
		{
			arr[4]++;
		}
		else if (input == 5)
		{
			arr[5]++;
		}
	}

	for (int j = 0; j < 6; j++)
	{
		cout << arr[j] << " grade(s) of " << j << endl;
	}

	system("PAUSE");
	return(0);
}