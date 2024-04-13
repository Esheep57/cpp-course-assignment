#include <iostream>
using namespace std;

class Money
{
public:
    Money();
    int getDollars();
    void setDollars(int dollarsValue);
    int getCents();
    void setCents(int centsValue);
    void totalMoney();
private:
    int dollars;
    int cents;
};

int main()
{
    Money monetaryAmount1, monetaryAmount2;

    cout << "Your monetary amount:\n";
    monetaryAmount1.setDollars(100);
    monetaryAmount1.setCents(50);
    cout << "You have ";
    monetaryAmount1.totalMoney();
    cout << endl << endl;
    cout << "Your monetary amount:\n";
    monetaryAmount2.setDollars(0);
    monetaryAmount2.setCents(124);
    cout << "You have ";
    monetaryAmount2.totalMoney();
    cout << endl << endl;

    system("PAUSE");
    return(0);
}

Money::Money():dollars(0), cents(0)
{}

int Money::getDollars()
{
    return dollars;
}

void Money::setDollars(int dollarsValue)
{
    if (dollarsValue >= 0)
    {
        dollars = dollarsValue;
    }
    else
    {
        cout << "Illegal dollars value!!" << endl;
        exit(1);
    }
}

int Money::getCents()
{
    return cents;
}

void Money::setCents(int centsValue)
{
    if (centsValue >= 0)
    {
        cents = centsValue;
    }
    else
    {
        cout << "Illegal cents value!!" << endl;
        exit(1);
    }
}

void Money::totalMoney()
{
    double totalMoney;
    int dollars, cents;

    dollars = getDollars();
    cents = getCents();
    totalMoney = (double)dollars + (cents * 0.01);
    cout << totalMoney << " dollars.";
}