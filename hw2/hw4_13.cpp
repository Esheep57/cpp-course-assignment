#include <iostream>
using namespace std;

// �N�@�^���ഫ����������v�`��
const double MILE_TO_KM = 1.61;

// ��ƭ쫬�ŧi
double convertToMPH(int minutes, int seconds);
double convertToMPH(double kph);

int main() {
    // ���ղĤ@�Ө��
    int minutes = 5;
    int seconds = 30;
    cout << "Pace " << minutes << ":" << seconds << " per mile is " << convertToMPH(minutes, seconds) << " mph" << endl;

    // ���ղĤG�Ө��
    double kph = 10.0;
    cout << kph << " kph is " << convertToMPH(kph) << " mph" << endl;

    system("pause");
    return 0;
}

// �ھڰt�t�p��mph
double convertToMPH(int minutes, int seconds) {
    double hours = minutes / 60.0 + seconds / 3600.0;
    return 1 / hours; // �]��1�^��/�p�ɴN�Omph
}

// �ھ�kph�p��mph
double convertToMPH(double kph) {
    return kph / MILE_TO_KM;
}