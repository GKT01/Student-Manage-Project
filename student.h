#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
    public:
        Student() = default;
        Student(std::string full_name, double gpa, int age);


        std::string full_name {"Anonymous"};
        double gpa{2.0};
        int age {18};


};



#endif