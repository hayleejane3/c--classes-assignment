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

GradStudent(std::string name,
            int yearOfBirth,
            const std::vector<double> &assignmentsScore,
            double projectScore,
            std::string researchArea,
            std::string advisor) :
            Student(name, yearOfBirth, assignmentsScore, projectScore), researchArea(researchArea), advisor(advisor) {
//    GradStudent::researchArea = researchArea;
  //  GradStudent::advisor = advisor;
    ++GradStudent::numGradStudents;
}

std::string getResearchArea() {
    return researchArea;
}

std::string getAdvisor() {
    return advisor;
}

int getNumStudents() {
    return GradStudent::numGradStudents;
}

virtual void printDetails() {
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
  return (((assignmentsTotal/(double)assignmentsScore.size()) * 0.5) + (projectScore * 0.5));
}

std::string GradStudent::getGrade() {
    if (getTotal() >= 80) {
        return "CR";
    } else {
      return "N";
    }
}
