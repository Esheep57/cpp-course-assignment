#include <iostream>
#include <string>
using namespace std;

class Television {
public:
    Television(string type, double size, string* a, int num);
    Television(const Television& input);
    ~Television();

    string getType() const;
    double getDimension() const;
    string* getConnectivity() const;
    int getObject() const;
    void setObject(int o);
    void showData() const;

private:
    string displayType;
    double dimension;
    string* ConnectivitySupport;
    int used;
};

int main(void) {
    int num;
    string type;
    double inch;

    cout << "Enter the number of the televisions>";
    cin >> num;
    cin.ignore(); // ┛菠传︽才

    string* connectivity = new string[num];

    cout << "Enter your display type>";
    getline(cin, type);
    cout << "Enter the dimension in inches>";
    cin >> inch;
    cin.ignore(); // ┛菠传︽才

    for (int i = 0; i < num; i++) {
        cout << "Enter the NO." << i + 1 << " connectivity support: ";
        getline(cin, connectivity[i]);
    }

    Television user(type, inch, connectivity, num);
    Television copy(user);

    cout << "Your data:\n";
    copy.showData();

    delete[] connectivity; // 睦笆篈癘拘砰

    system("pause");
    return 0;
}

Television::Television(string type, double size, string* a, int num)
    : displayType(type), dimension(size), used(num) {
    ConnectivitySupport = new string[used];
    for (int i = 0; i < used; i++) {
        ConnectivitySupport[i] = a[i];
    }
}

Television::Television(const Television& input)
    : displayType(input.displayType), dimension(input.dimension), used(input.used) {
    ConnectivitySupport = new string[used];
    for (int i = 0; i < used; i++) {
        ConnectivitySupport[i] = input.ConnectivitySupport[i];
    }
}

Television::~Television() {
    delete[] ConnectivitySupport;
}

string Television::getType() const {
    return displayType;
}

double Television::getDimension() const {
    return dimension;
}

string* Television::getConnectivity() const {
    return ConnectivitySupport;
}

int Television::getObject() const {
    return used;
}

void Television::setObject(int o) {
    used = o;
}

void Television::showData() const {
    cout << "The display type is> " << displayType << endl;
    cout << "The dimension is> " << dimension << endl;
    for (int i = 0; i < used; i++) {
        cout << "The NO " << i + 1 << ". ConnectivitySupport is " << ConnectivitySupport[i] << endl;
    }
}
