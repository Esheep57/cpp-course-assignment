#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

void picture(vector<int> gradeVlue, vector<int> sumValue);

int main() {
	int next;
	vector<int> grade;
	vector<int> sum;

	cout << "Enter student's grade (input -1 to stop) : ";
	cin >> next;

	while (next != -1) {
		grade.push_back(next);
		cin >> next;
	}

	for (int i = 0; i < grade.size(); i++) {
		sum.push_back(i);
		sum[i] = 1;
	}

	for (int j = 0; j < grade.size(); j++) {
		for (int k = 0; k < grade.size(); k++) {
			if (j < k) {
				if (grade[j] == grade[k]) {
					sum[j]++;
					sum.erase(sum.begin() + k);
					grade.erase(grade.begin() + k);
					k--;
				}
			}
		}
		cout << sum[j] << " grade of " << grade[j] << endl;
	}
	picture(grade, sum);

}

void picture(vector<int> gradeVlue, vector<int> sumValue) {
	cout << endl;
	for (int i = 0; i < gradeVlue.size(); i++) {
		cout << gradeVlue[i] << " : ";
		for (int j = 0; j < sumValue[i]; j++) {
			cout << " * ";
		}
		cout << endl;
	}
}