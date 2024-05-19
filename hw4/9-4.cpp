#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string str;
    bool check = false;

    while (!check) {
        cout << "Enter the string (if you want to leave, enter 'quit'): ";
        getline(cin, str);

        if (str == "quit") {
            check = true;
            break;
        }

        int start = 0;
        int length = str.length();

        while (start < length) {
            // Skip non-alphabetic characters
            while (start < length && !isalpha(str[start])) {
                start++;
            }

            int e = start;
            // Find the end of the word
            while (e < length && isalpha(str[e])) {
                e++;
            }

            // If the word length is 4, replace it with "love" or "Love"
            if (e - start == 4) {
                if (isupper(str[start])) {
                    str.replace(start, 4, "Love");
                }
                else {
                    str.replace(start, 4, "love");
                }
            }
            start = e;
        }
        cout << "Output: " << str << endl;
    }

    system("pause");
    return 0;
}
