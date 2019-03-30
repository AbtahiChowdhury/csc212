#ifndef ABTAHI_STUDENT
#define ABTAHI_STUDENT

#include <iostream>

class student
{
    public:
        student(std::string namein, int agein, int gradein);
        std::string getName() const {return name;}
        int getAge() const {return age;}
        int getGrade() const {return grade;}
        void incrementGrade();
    private:
        std::string name;
        int age;
        int grade;
};

std::ostream& operator<<(std::ostream& outs, const student& s);

#endif // !ABTAHI_STUDENT 
