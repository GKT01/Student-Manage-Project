#include <iostream>
#include <string>
#include <fstream>
#include "student.h"

#define LIM 100

Student add_to_student(std::fstream& fFile);
void print_everyone(std::fstream& fFile);

int main(int argc, char** argv){
    Student students[LIM];
    int i = 0;
    int option;

    std::fstream fFile{"students.txt"};
    if(!fFile.is_open()){
        std::
        cerr << "Sorry could not open the txt file terminating the program.."
        << std::endl;
        return 1;
    }
    
    do
    {
        std::cout << "Welcome to Student Managing System. " << std::endl;
        /*std::cout << "0: Add to System, 1: Delete from System, 2: Print Everyone"
        << ", 3: Quit" << std::endl;*/

        std::cout << "0: Add to System, 1: Print Everyone"
        << ", 2: Quit" << std::endl;
        
        std::cin >> option;
        switch (option){
        case 0:
            students[i] = add_to_student(fFile);
            i++;
            break;
        case 1:
            print_everyone(fFile);
            break;
        case 2:
            std::cout << "Quitting.." << std::endl;
            return 0;
        //case 3:
            
            //break;
        /* May add Delete option in the future. */
        default:
            std::cout << "Invalid Input please try again." << std::endl;
            break;
        }
    } while (option != 3);

    fFile.close();
    return 0;
}

Student add_to_student(std::fstream& fFile){
    std::string name;
    double gpa;
    int age;

    std::cout << "Please enter name: ";
    std::getline(std::cin >> std::ws, name);
    std::cout << "Please enter gpa and age: ";
    std::cin >> gpa;
    std::cin >> age;
    Student student_new(name, gpa, age);

    if(fFile.is_open()){
        fFile << student_new.full_name << " " << student_new.gpa << " "
        << student_new.age
        << std::endl; 
    }
    return student_new;
}

void print_everyone(std::fstream& fFile){
    std::string line;
    fFile.seekg(0, std::ios::beg);
    std::cout << std::endl;

    for(int i = 0; i <= 99; i++){
        std::getline(fFile, line);
        if(!line.empty())
            std::cout << i << ": "<< line << std::endl;
        if(fFile.eof()){
            std::cout << std::endl;
            return;
        }
    }
}