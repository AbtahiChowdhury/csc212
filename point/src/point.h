#ifndef ABTAHI_POINT_H
#define ABTAHI_POINT_H

#include <iostream>

namespace ABTAHI_CSC212
{
    class point 
    {
        friend std::istream& operator>>(std::istream& ins, point& p);
        
        public:
            point(double x = 0.0, double y = 0.0);
            void shift(double dx, double dy);
            void dilate(double c);
            double x() const;
            double y() const;

        private:
            double mx;
            double my;
    };

    point operator+(const point& p1, const point& p2);
    point operator-(const point& p1, const point& p2);
    bool operator==(const point& p1, const point& p2);
    bool operator!=(const point& p1, const point& p2);
    std::ostream& operator<<(std::ostream& outs, const point& p);
}
#endif
