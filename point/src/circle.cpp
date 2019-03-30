#include "circle.h"

circle::circle(double radius)
{
    m_radius = radius;
}

double circle::get_diameter()
{
    return (2*m_radius);
}

double circle::get_curcumfrence()
{
    return (2*m_radius*3.14);
}

double circle::get_area()
{
    return (m_radius*m_radius*3.14);
}

std::ostream& operator<<(std::ostream& outs, const circle& c)
{
    outs<<"Circle of radius "<<c.get_radius();
    return outs;
}

std::istream& operator>>(std::istream& ins,circle& c)
{
    ins>>c.m_radius;
    return ins;
}
