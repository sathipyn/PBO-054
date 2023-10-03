#include <iostream>
#include <cmath>
#include <string>

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {}

    Point(int x, int y) : x(x), y(y) {}

    int getX() const {
        return x;
    }

    void setX(int x) {
        this->x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        this->y = y;
    }

    void setXY(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int* getXY() {
        static int xy[2];
        xy[0] = x;
        xy[1] = y;
        return xy;
    }

    double distance(int x, int y) const {
        int xDiff = this->x - x;
        int yDiff = this->y - y;
        return sqrt(xDiff * xDiff + yDiff * yDiff);
    }

    double distance(const Point& another) const {
        int xDiff = x - another.x;
        int yDiff = y - another.y;
        return sqrt(xDiff * xDiff + yDiff * yDiff);
    }

    double distance() const {
        return sqrt(x * x + y * y);
    }

    std::string toString() const {
        return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }
};

int main() {
    Point p1(1, 2);
    std::cout << p1.toString() << std::endl;

    Point p2;
    std::cout << p2.toString() << std::endl;

    p1.setX(3);
    p1.setY(4);
    std::cout << p1.toString() << std::endl;
    std::cout << "X is: " << p1.getX() << std::endl;
    std::cout << "Y is: " << p1.getY() << std::endl;

    p1.setXY(5, 6);
    std::cout << p1.toString() << std::endl;
    int* xy = p1.getXY();
    std::cout << "X is: " << xy[0] << std::endl;
    std::cout << "Y is: " << xy[1] << std::endl;

    Point p3(10, 11);
    std::cout << "Distance is: " << p1.distance(10, 11) << std::endl;
    std::cout << "Distance is: " << p1.distance(p3) << std::endl;
    std::cout << "Distance is: " << p3.distance(p1) << std::endl;
    std::cout << "Distance is: " << p1.distance() << std::endl;

    return 0;
}
