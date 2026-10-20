
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double fare(string zone, int hour) {
    double amount;

    if (zone == "Inner")
        amount = 10;
    else if (zone == "Middle")
        amount = 20;
    else if (zone == "Outer")
        amount = 30;
    else
        return -1;

    if ((hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20))
        amount *= 1.20;

    return amount;
}

bool canTravel(double balance, double cost) {
    return cost >= 0 && balance - cost >= 50;
}

int main() {
    double balance = 100;
    double cost;

    cost = fare("Inner", 11);
    if (canTravel(balance, cost)) {
        balance -= cost;
        cout << "Fare Rs " << fixed << setprecision(2)
             << cost << "  balance Rs " << defaultfloat
             << balance << '\n';
    }

    cost = fare("Outer", 9);
    if (canTravel(balance, cost)) {
        balance -= cost;
        cout << "Fare Rs " << fixed << setprecision(2)
             << cost << "  balance Rs " << defaultfloat
             << balance << '\n';
    }

    cost = fare("Middle", 11);
    if (canTravel(balance, cost)) {
        balance -= cost;
        cout << "Fare Rs " << fixed << setprecision(2)
             << cost << "  balance Rs " << defaultfloat
             << balance << '\n';
    } else {
        cout << "Denied (low balance)  balance Rs "
             << balance << '\n';
    }

    return 0;
}
