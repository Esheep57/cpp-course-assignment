#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int movie_column(int movie);
int nearest_neighbor(int a, int b, int c, int movie1_rate, int movie2_rate, int movie3_rate);

int main()
{
	int review[4][6] = { { 3,1,5,2,1,5 },
						 { 4,2,1,4,2,4 },
						 { 3,1,2,4,4,1 },
						 { 5,1,4,2,4,2 } };
	int movie1, movie2, movie3;
	int movie1_rate, movie2_rate, movie3_rate;
	int a, b, c;
	int review_row;

	cout << "Enter the movie you want to rate > ";
	cin >> movie1;
	a = movie_column(movie1);
	cout << "Rating > ";
	cin >> movie1_rate;
	cout << "Enter the movie you want to rate > ";
	cin >> movie2;
	b = movie_column(movie2);
	cout << "Rating > ";
	cin >> movie2_rate;
	cout << "Enter the movie you want to rate > ";
	cin >> movie3;
	c = movie_column(movie3);
	cout << "Rating > ";
	cin >> movie3_rate;

	review_row = nearest_neighbor(a, b, c, movie1_rate, movie2_rate, movie3_rate);
	cout << "\nPredict:" << endl;
	for (int z = 0; z < 6; z++)
	{
		cout << "rating of " << review[review_row][z] << "for movie 10" << z << endl;
	}

	system("PAUSE");
	return(0);
}

int movie_column(int movie)
{
	int movies[6] = { 100,101,102,103,104,105 };

	for (int j = 0; j < 6; j++)
	{
		if (movies[j] == movie)
		{
			return(j);
		}
	}
}

int nearest_neighbor(int a, int b, int c, int movie1_rate, int movie2_rate, int movie3_rate)
{
	int review[4][6] = { { 3,1,5,2,1,5 },
						 { 4,2,1,4,2,4 },
						 { 3,1,2,4,4,1 },
						 { 5,1,4,2,4,2 } };
	int distance[4], min, min_row = 0;

	for (int i = 0; i < 4; i++)
	{
		distance[i] = pow(movie1_rate - review[i][a], 2) + pow(movie2_rate - review[i][b], 2) + pow(movie3_rate - review[i][c], 2);
	}

	min = distance[0];
	for (int p = 0; p < 4; p++)
	{
		if (distance[p] <= min)
		{
			min = distance[p];
			min_row = p;
		}
	}
	return(min_row);
}