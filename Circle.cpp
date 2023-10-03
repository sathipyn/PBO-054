#include <iostream>
#include <string>
#include <sstream> // Sertakan header ini untuk std::stringstream
#include <cmath>

class Circle {
private:
    static const double DEFAULT_RADIUS;
    static const std::string DEFAULT_COLOR;
    double radius;
    std::string color;

public:
    Circle() : radius(DEFAULT_RADIUS), color(DEFAULT_COLOR) {}
    Circle(double radius) : radius(radius), color(DEFAULT_COLOR) {}
    Circle(double radius, const std::string& color) : radius(radius), color(color) {}

    double getRadius() const {
        return radius;
    }

    void setRadius(double radius) {
        this->radius = radius;
    }

    std::string getColor() const {
        return color;
    }

    void setColor(const std::string& color) {
        this->color = color;
    }

    std::string toString() const {
        std::stringstream ss; // Membuat objek std::stringstream
        ss << "Circle[radius=" << radius << ", color=" << color << "]";
        return ss.str(); // Mengembalikan string hasil dari std::stringstream
    }

    double getArea() const {
        return M_PI * radius * radius;
    }

    double getCircumference() const {
        return 2.0 * M_PI * radius;
    }
};

const double Circle::DEFAULT_RADIUS = 1.0;
const std::string Circle::DEFAULT_COLOR = "red";

int main() {
    // Test all constructors and toString()
    Circle c1(1.1, "blue");
    std::cout << c1.toString() << std::endl;
    //Circle[radius=1.1, color=blue]
    Circle c2(2.2);
    std::cout << c2.toString() << std::endl;
    //Circle[radius=2.2, color=red]
    Circle c3;
    std::cout << c3.toString() << std::endl;
    //Circle[radius=1.0, color=red]

    // Test Setters and Getters
    c1.setRadius(3.3);
    c1.setColor("green");
    std::cout << c1.toString() << std::endl;
    //Circle[radius=3.3, color=green]
    std::cout << "The radius is: " << c1.getRadius() << std::endl;
    //The radius is: 3.3
    std::cout << "The color is: " << c1.getColor() << std::endl;
    //The color is: green

    // Test getArea() and getCircumference()
    std::cout << "The area is: " << c1.getArea() << std::endl;
    //The area is: 34.211
    std::cout << "The circumference is: " << c1.getCircumference() << std::endl;
    //The circumference is: 20.7862

    return 0;
}
