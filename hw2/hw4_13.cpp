#include <iostream>
using namespace std;

// 將一英里轉換為公里的比率常數
const double MILE_TO_KM = 1.61;

// 函數原型宣告
double convertToMPH(int minutes, int seconds);
double convertToMPH(double kph);

int main() {
    // 測試第一個函數
    int minutes = 5;
    int seconds = 30;
    cout << "Pace " << minutes << ":" << seconds << " per mile is " << convertToMPH(minutes, seconds) << " mph" << endl;

    // 測試第二個函數
    double kph = 10.0;
    cout << kph << " kph is " << convertToMPH(kph) << " mph" << endl;

    system("pause");
    return 0;
}

// 根據配速計算mph
double convertToMPH(int minutes, int seconds) {
    double hours = minutes / 60.0 + seconds / 3600.0;
    return 1 / hours; // 因為1英里/小時就是mph
}

// 根據kph計算mph
double convertToMPH(double kph) {
    return kph / MILE_TO_KM;
}