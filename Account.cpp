#include <iostream>
#include <iomanip>
#include <sstream> // Include this header for stringstream

class Account {
private:
    int number;
    double balance;

public:
    Account(int number) : number(number), balance(0.0) {}

    Account(int number, double balance) : number(number), balance(balance) {}

    int getNumber() const {
        return number;
    }

    double getBalance() const {
        return balance;
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << "Account[number=" << number << ",balance=$" << std::fixed << std::setprecision(2) << balance << "]";
        return oss.str();
    }

    void credit(double amount) {
        balance += amount;
    }

    void debit(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "amount exceeded" << std::endl;
        }
    }

    void transferTo(double amount, Account& another) {
        if (balance >= amount) {
            balance -= amount;
            another.balance += amount;
        } else {
            std::cout << "amount exceeded" << std::endl;
        }
    }
};

int main() {
    Account a1(5566);
    std::cout << a1.toString() << std::endl;

    Account a2(1234, 99.9);
    std::cout << a2.toString() << std::endl;

    std::cout << "The account Number is: " << a2.getNumber() << std::endl;
    std::cout << "The balance is: $" << std::fixed << std::setprecision(2) << a2.getBalance() << std::endl;

    a1.credit(11.1);
    std::cout << a1.toString() << std::endl;

    a1.debit(5.5);
    std::cout << a1.toString() << std::endl;

    a1.debit(500); // Test debit() error

    Account a3(7890);
    a2.transferTo(1.0, a3);

    std::cout << a1.toString() << std::endl;
    std::cout << a2.toString() << std::endl;
    std::cout << a3.toString() << std::endl;

    return 0;
}
