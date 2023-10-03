#include <iostream>
#include <iomanip>
#include <sstream> // Sertakan header <sstream> untuk std::stringstream

class Date {
private:
    int year, month, day;

public:
    // Constructor
    Date(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    // Getter methods
    int getYear() {
        return year;
    }

    int getMonth() {
        return month;
    }

    int getDay() {
        return day;
    }

    // Setter methods
    void setYear(int year) {
        this->year = year;
    }

    void setMonth(int month) {
        this->month = month;
    }

    void setDay(int day) {
        this->day = day;
    }

    // toString method
    std::string toString() {
        // Gunakan std::stringstream untuk memformat tanggal
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(2) << month << "/"
           << std::setw(2) << day << "/" << std::setw(4) << year;
        return ss.str();
    }

    // setDate method
    void setDate(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }
};

int main() {
    // Test constructor and toString()
    Date d1(2020, 2, 8);
    std::cout << d1.toString() << std::endl;  // toString()
    //02/08/2020

    // Test Setters and Getters
    d1.setYear(2012);
    d1.setMonth(12);
    d1.setDay(23);
    std::cout << d1.toString() << std::endl;
    //12/23/2012
    std::cout << "Year is: " << d1.getYear() << std::endl;
    //Year is: 2012
    std::cout << "Month is: " << d1.getMonth() << std::endl;
    //Month is: 12
    std::cout << "Day is: " << d1.getDay() << std::endl;
    //Day is: 23

    // Test setDate()
    d1.setDate(2988, 1, 2);
    std::cout << d1.toString() << std::endl;
    //01/02/2988

    return 0;
}