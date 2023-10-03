#include <iostream>
#include <string>

class Time {
private:
    int second, minute, hour;

public:
    Time(int second, int minute, int hour) : second(second), minute(minute), hour(hour) {}

    Time() : second(0), minute(0), hour(0) {}

    int getSecond() const {
        return this->second;
    }

    int getMinute() const {
        return this->minute;
    }

    int getHour() const {
        return this->hour;
    }

    void setSecond(int second) {
        this->second = second;
    }

    void setMinute(int minute) {
        this->minute = minute;
    }

    void setHour(int hour) {
        this->hour = hour;
    }

    std::string toString() const {
        return StringFormat("%02d:%02d:%02d", hour, minute, second);
    }

    void setTime(int second, int minute, int hour) {
        this->second = second;
        this->minute = minute;
        this->hour = hour;
    }

    Time nextSecond() {
        ++second;
        if (second >= 60) {
            second = 0;
            ++minute;
            if (minute >= 60) {
                minute = 0;
                ++hour;
                if (hour >= 24) {
                    hour = 0;
                }
            }
        }
        return *this;
    }

private:
    std::string StringFormat(const std::string& format, int h, int m, int s) const {
        char buf[10];
        snprintf(buf, sizeof(buf), format.c_str(), h, m, s);
        return std::string(buf);
    }
};

int main() {
    // Test Constructors and toString()
    Time t1(1, 2, 3);
    std::cout << t1.toString() << std::endl;
    //03:02:01

    Time t2; // The default constructor
    std::cout << t2.toString() << std::endl;
    //00:00:00

    // Test Setters and Getters
    t1.setHour(4);
    t1.setMinute(5);
    t1.setSecond(6);
    std::cout << t1.toString() << std::endl;
    //04:05:06
    std::cout << "Hour is: " << t1.getHour() << std::endl;
    //Hour is: 4
    std::cout << "Minute is: " << t1.getMinute() << std::endl;
    //Minute is: 5
    std::cout << "Second is: " << t1.getSecond() << std::endl;
    //Second is: 6

    // Test setTime()
    t1.setTime(58, 59, 23);
    std::cout << t1.toString() << std::endl;
    //23:59:58

    // Test nextSecond() and chaining
    std::cout << t1.nextSecond().toString() << std::endl;
    //23:59:59
    std::cout << t1.nextSecond().nextSecond().nextSecond().toString() << std::endl; // chaining
    //00:00:02

    return 0;
}
