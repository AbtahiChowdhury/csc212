#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

class circle
{
    friend std::istream& operator>>(std::istream& ins,circle& c);
    public:
        circle(double radius=0);
        double get_radius() const {return m_radius;}
        double get_diameter();
        double get_curcumfrence();
        double get_area();

    private:
        double m_radius;
};

std::ostream& operator<<(std::ostream& outs, const circle& c);

#endif
