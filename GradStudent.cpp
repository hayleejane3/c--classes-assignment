///////////////////////////////////////////////////////////////////////////////
// File Name:      GradStudent.cpp
//
// Author:         Haylee Jane Monteiro
// CS email:       haylee@cs.wisc.edu
//
// Description:    GradStudent class
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "GradStudent.hpp"

int GradStudent::numGradStudents = 0;

GradStudent::GradStudent(std::string name,
            int yearOfBirth,
            const std::vector<double> &assignmentsScore,
            double projectScore,
            std::string researchArea,
            std::string advisor) :
            Student(name, yearOfBirth, assignmentsScore, projectScore),
            researchArea(researchArea), advisor(advisor) {
    ++GradStudent::numGradStudents;
}

std::string GradStudent::getResearchArea() {
    return researchArea;
}

std::string GradStudent::getAdvisor() {
    return advisor;
}

int GradStudent::getNumStudents() {
    return GradStudent::numGradStudents;
}

void GradStudent::printDetails() {
    Student::printDetails();
    std::cout << "Type = Graduate Student" << std::endl;
    std::cout << "Research Area = " << getResearchArea() << std::endl;
    std::cout << "Advisor = " << getAdvisor() << std::endl;
}

double GradStudent::getTotal() {
  double assignmentsTotal = 0.0;
  std::vector<double> assignmentsScore = Student::getAssignmentsScore();
  for (int i =0; i < assignmentsScore.size(); i++) {
      assignmentsTotal += assignmentsScore[i];
  }
  return (((assignmentsTotal/(double)assignmentsScore.size()) * 0.5) +
      (Student::getProjectScore() * 0.5));
}

std::string GradStudent::getGrade() {
    if (getTotal() >= 80) {
        return "CR";
    } else {
      return "N";
    }
}
