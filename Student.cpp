///////////////////////////////////////////////////////////////////////////////
// File Name:      Student.cpp
//
// Author:         Haylee Jane Monteiro
// CS email:       haylee@cs.wisc.edu
//
// Description:    Student class
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.hpp"

int Student::numStudents = 0;

Student::Student(std::string name,
        int yearOfBirth,
        const std::vector<double> &assignmentsScore,
        double projectScore) {

    Student::id = numStudents;
    Student::name = name;
    Student::yearOfBirth = yearOfBirth;
    Student::assignmentsScore = assignmentsScore;
    Student::projectScore = projectScore;
    ++Student::numStudents;
}

int Student::getId() {
    return id;
}

std::string Student::getName() {
    return name;
}

int Student::getYearOfBirth(){
    return yearOfBirth;
}

int Student::getAge() {
    return current_year - yearOfBirth;
}

const std::vector<double> &Student::getAssignmentsScore(){
    return assignmentsScore;
}

double Student::getProjectScore() {
    return projectScore;
}

int Student::getNumStudents() {
    return Student::numStudents;
}

void Student::printDetails() {
    std::cout << "STUDENT DETAILS:" << std::endl;
    std::cout << "Id = " << getId() << std::endl;
    std::cout << "Name = " << getName() << std::endl;
    std::cout << "Age = " << getAge() << std::endl;
    std::cout << "Assignments = [";
    for (int i =0; i < getAssignmentsScore().size()-1; i++) {
        std::cout << getAssignmentsScore()[i] << ", ";
    }
    std::cout << getAssignmentsScore()[getAssignmentsScore().size()-1] << "]";
    std::cout << std::endl;
    std::cout << "Project = " << getProjectScore();
    std::cout << "Total = " << getTotal();
    std::cout << "Grade = " << getGrade();
}
