#include <iostream>
#include <iomanip>
using namespace std;

// 函數原型宣告
bool getInput(int& hours, int& minutes);
void convertTime(int& hours, int& minutes, char& am_pm);
void displayTime(int hours, int minutes, char am_pm);

int main() {
    int hours, minutes;
    char am_pm, repeat;

    do {
        if (getInput(hours, minutes)) {
            convertTime(hours, minutes, am_pm);
            displayTime(hours, minutes, am_pm);
        }
        else {
            cout << "Invalid input. Please enter a correct 24-hour format time (00-23 for hours and 00-59 for minutes)." << endl;
        }

        cout << "Do you want to convert another time? (y/n): ";
        cin >> repeat;
        // 清理任何錯誤狀態，忽略之後的輸入直到遇到換行
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (repeat == 'y' || repeat == 'Y');

    system("pause");
    return 0;
}

// 輸入函數
bool getInput(int& hours, int& minutes) {
    cout << "Enter time in 24-hour notation (hh mm): ";
    cin >> hours >> minutes;

    // 檢查流是否進入失敗狀態（例如，由於輸入非整數）
    if (cin.fail()) {
        cin.clear(); // 清除失敗狀態
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略錯誤輸入後的字符
        return false;
    }

    // 檢查小時和分鐘數是否在正確的範圍內
    return hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60;
}

// 時間轉換函數
void convertTime(int& hours, int& minutes, char& am_pm) {
    am_pm = (hours < 12) ? 'a' : 'p';
    if (hours == 0) {
        hours = 12; // 午夜
    }
    else if (hours == 12) {
        am_pm = 'p'; // 正午
    }
    else if (hours > 12) {
        hours -= 12;
    }
}

// 輸出函數
void displayTime(int hours, int minutes, char am_pm) {
    cout << "The time in 12-hour notation is: "
        << setfill('0') << setw(2) << hours << ":"
        << setfill('0') << setw(2) << minutes << " "
        << (am_pm == 'a' ? "A.M." : "P.M.") << endl;
}