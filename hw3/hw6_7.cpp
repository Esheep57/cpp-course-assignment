#include <iostream>
using namespace std;

class Pizza {
public:
    Pizza();
    Pizza(int type, int size, int topping);
    void setType(int type);
    int getType() { return type; }
    void setSize(int size);
    int getSize() { return size; }
    void setTopping(int topping) { this->topping = topping; }
    int getTopping() { return topping; }
    void outputDescription();
    double computePrice();
private:
    int type;
    int size;
    int topping;
};

int main() {
    int type, size, topping;

    cout << "1.deep dish\n" 
         << "2.hand tossed\n" 
         << "3.pan\n"
         << "Which type of pizza you want(enter the number):";
    cin >> type;

    cout << "\n1.small\n" 
         << "2.medium\n" 
         << "3.large\n"
         << "Which size of pizza you want(enter the number):";
    cin >> size;

    cout << "\nHow many toppings you want($2 per topping) > ";
    cin >> topping;

    Pizza customer(type, size, topping);
    customer.computePrice();
    customer.outputDescription();
    cout << endl;

    system("PAUSE");
    return(0);
}

Pizza::Pizza() : type(1), size(1), topping(0) {}

Pizza::Pizza(int type, int size, int topping) : type(type), size(size), topping(topping) {}

void Pizza::setType(int type) {
    if (type > 0 && type <= 3) {
        this->type = type;
    }
    else {
        cout << "Wrong input!!" << endl;
        exit(1);
    }
}

void Pizza::setSize(int size) {
    if (size > 0 && size <= 3) {
        this->size = size;
    }
    else {
        cout << "Wrong input!!" << endl;
        exit(1);
    }
}

void Pizza::outputDescription() {
    cout << "\nType: ";
    switch (type) {
    case 1:
        cout << "Deep Dish" << endl;
        break;
    case 2:
        cout << "Hand Tossed" << endl;
        break;
    case 3:
        cout << "Pan" << endl;
        break;
    default:
        cout << "Unknown" << endl;
    }

    cout << "Size: ";
    switch (size) {
    case 1:
        cout << "Small" << endl;
        break;
    case 2:
        cout << "Medium" << endl;
        break;
    case 3:
        cout << "Large" << endl;
        break;
    default:
        cout << "Unknown" << endl;
    }

    double price = computePrice();
    cout << "Price: $" << price << endl;
}

double Pizza::computePrice() {
    double basePrice = (size == 1) ? 10 : (size == 2) ? 14 : 17;
    return basePrice + 2 * topping;
}