#include "student.h"

student::student(std::string namein, int agein, int gradein)
{
    name=namein;
    age=agein;
    grade=gradein;
}

void student::incrementGrade()
{
    grade++;
}

std::ostream& operator<<(std::ostream& outs, const student& s)
{
    outs<<s.getName()<<" age "<<s.getAge()<<" grade "<<s.getGrade();
    return outs;
}
