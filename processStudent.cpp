///////////////////////////////////////////////////////////////////////////////
// File Name:      processStudent.cpp
//
// Author:         Haylee Jane Monteiro
// CS email:       haylee@cs.wisc.edu
//
// Description:    Methods to perform some processing on student objects.
///////////////////////////////////////////////////////////////////////////////

#include "processStudent.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>


void fillStudents(std::ifstream &inFile,
                  std::vector<GradStudent> &gstudents,
                  std::vector<UndergradStudent> &ugstudents) {
    int yob, i;
    double projectScore;
    std::string line, token, name, hallResearch, advisorYear;
    std::vector<std::string> tokens;
    std::vector<double> assignmentsScore;
    while(true) {
        getline(inFile, line);
        if(inFile.fail()) {
            break;
        }
        std::istringstream ss(line);
        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        name = tokens[1];
        yob = stoi(tokens[2]);
        for (i = 3; i < tokens.size()-3; i++) {
          assignmentsScore.push_back(stod(tokens[i]));
        }
        projectScore = stod(tokens[tokens.size()-3]);
        advisorYear = tokens[tokens.size()-1];
        hallResearch = tokens[tokens.size()-2];

        if (tokens[0].compare("U") == 0) {
            UndergradStudent ug1(name, yob, assignmentsScore, projectScore, hallResearch, advisorYear);
            ugstudents.push_back(ug1);
        } else {
            GradStudent g1(name, yob, assignmentsScore, projectScore, hallResearch, advisorYear);
            gstudents.push_back(g1);
        }
        tokens.clear();
    }
}

void printStudents(const std::vector<std::reference_wrapper<Student>> &students) {
    for (auto it = students.begin(); it != students.end(); it++) {
        it->get().printDetails();
        std::cout << std::endl;
    }
}

void computeStatistics(std::vector<std::reference_wrapper<Student>> &students) {
  for (auto it = students.begin(); it != students.end(); it++) {
      if (typeid(it->get()).name())
      std::cout << std::endl;
  }

    // compute the # of students based on the type of students.

    // compute the mean of the total score.

    // sort and print the students based on their total.
}
