#include "point.h"

namespace ABTAHI_CSC212
{   
    point::point(double x, double y)
    {
        mx=x;
        my=y;
    }

    void point::shift(double dx, double dy)
    {
        mx+=dx;
        my+=dy;
    }

    void point::dilate(double c)
    {
        mx*=c;
        my*=c;
    }

    double point::x() const
    {
        return mx;
    }

    double point::y() const
    {
        return my;
    }

    point operator+(const point& p1, const point& p2)
    {
        return point(p1.x()+p2.x() , p1.y()+p2.y());
    }

    point operator-(const point& p1, const point& p2)
    {
        return point(p1.x()-p2.x() , p1.y()-p2.y());
    }

    bool operator==(const point& p1, const point& p2)
    {
        return (p1.x() == p2.x() && p1.y() == p2.y() );
    }

    bool operator!=(const point& p1, const point& p2)
    {
        return (!(p1 == p2));
    }

    std::ostream& operator<<(std::ostream& outs, const point& p)
    {
        outs<<p.x()<<" "<<p.y();
        return outs;
    }

    std::istream& operator>>(std::istream& ins, point& p)
    {
        ins>>p.mx>>p.my;
        return ins;
    }
}
