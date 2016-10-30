///////////////////////////////////////////////////////////////////////////////
// File Name:      UndegradStudent.cpp
//
// Author:         Haylee Jane Monteiro
// CS email:       haylee@cs.wisc.edu
//
// Description:    UndergradStudent class
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "UndergradStudent.hpp"

int UndergradStudent::numUndergradStudents = 0;

UndergradStudent::UndergradStudent(std::string name,
                 int yearOfBirth,
                 const std::vector<double> &assignmentsScore,
                 double projectScore,
                 std::string residenceHall,
                 std::string yearInCollege) :
                 Student(name, yearOfBirth, assignmentsScore, projectScore) {

    UndergradStudent::residenceHall = residenceHall;
    UndergradStudent::yearInCollege = yearInCollege;
    ++UndergradStudent::numUndergradStudents;
}

std::string UndergradStudent::getResidenceHall() {
    return residenceHall;
}

std::string UndergradStudent::getYearInCollege() {
    return yearInCollege;
}

int UndergradStudent::getNumStudents() {
    return UndergradStudent::numUndergradStudents;
}

void UndergradStudent::printDetails() {
    Student::printDetails();
    std::cout << "Type = Undergraduate Student" << std::endl;
    std::cout << "Residence Hall = " << getResidenceHall() << std::endl;
    std::cout << "Year in College = " << getYearInCollege() << std::endl;
}

double UndergradStudent::getTotal() {
    double assignmentsTotal = 0.0;
    std::vector<double> assignmentsScore = Student::getAssignmentsScore();
    for (int i =0; i < assignmentsScore.size(); i++) {
        assignmentsTotal += assignmentsScore[i];
    }
    return (((assignmentsTotal/(double)assignmentsScore.size()) * 0.7) +
      (Student::getProjectScore() * 0.3));
}

std::string UndergradStudent::getGrade() {
  if (getTotal() >= 70) {
      return "CR";
  } else {
    return "N";
  }
}
