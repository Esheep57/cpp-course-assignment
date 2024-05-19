#include <iostream>
#include <string>
using namespace std;

class Subscriber {
public:
    Subscriber();
    void input();
    void output() const;
    void resetChannel();
    Subscriber& operator=(const Subscriber& rightSide);
    ~Subscriber();
private:
    string name;
    int numChannels;
    string* channelList;
};

Subscriber::Subscriber() {
    name = "";
    numChannels = 0;
    channelList = NULL;
}

void Subscriber::input() {
    resetChannel();
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter the number of channels: ";
    cin >> numChannels;
    cin.ignore(1, '\n'); // 清除換行符
    channelList = new string[numChannels];
    for (int i = 0; i < numChannels; i++) {
        cout << "Enter the name of channel " << i + 1 << ": ";
        getline(cin, channelList[i]);
    }
}

void Subscriber::output() const {
    cout << "Name: " << name << endl;
    cout << "The number of channels: " << numChannels << endl;
    for (int i = 0; i < numChannels; i++) {
        cout << "Channel " << i + 1 << ": " << channelList[i] << endl;
    }
    cout << endl;
}

void Subscriber::resetChannel() {
    if (channelList != NULL) {
        delete[] channelList;
        channelList = NULL;
    }
    numChannels = 0;
}

Subscriber& Subscriber::operator=(const Subscriber& rightSide) {
    if (this != &rightSide) { // 自我賦值檢查
        resetChannel();
        name = rightSide.name;
        numChannels = rightSide.numChannels;
        if (numChannels > 0) {
            channelList = new string[numChannels];
            for (int i = 0; i < numChannels; i++) {
                channelList[i] = rightSide.channelList[i];
            }
        }
    }
    return *this;
}

Subscriber::~Subscriber() {
    if (channelList != NULL) {
        delete[] channelList;
    }
}

int main() {
    Subscriber s1, s2;
    s1.input();
    cout << "Subscriber 1's data:\n";
    s1.output();
    cout << endl;

    s2 = s1;
    cout << "Subscriber 2's data after assignment from Subscriber 1:\n";
    s2.output();

    s1.resetChannel();
    cout << "Subscriber 1's data after reset:\n";
    s1.output();
    cout << "Subscriber 2's data (should still have original data):\n";
    s2.output();

    system("pause");
    return 0;
}
