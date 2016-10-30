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
            UndergradStudent ug1(name, yob, assignmentsScore, projectScore,
              hallResearch, advisorYear);
            ugstudents.push_back(ug1);
        } else {
            GradStudent g1(name, yob, assignmentsScore, projectScore,
              hallResearch, advisorYear);
            gstudents.push_back(g1);
        }
        tokens.clear();
        assignmentsScore.clear();
    }
}

void printStudents(
    const std::vector<std::reference_wrapper<Student>> &students) {
    for (auto it = students.begin(); it != students.end(); it++) {
        it->get().printDetails();
        std::cout << std::endl;
    }
}

void computeStatistics(std::vector<std::reference_wrapper<Student>> &students) {
    int num;
    double totalOfTotals = 0.0;

    // compute the # of students based on the type of students.
    if (std::string(typeid(students[0].get()).name()).find("UndergradStudent")
         != std::string::npos) {
        num = UndergradStudent::getNumStudents();
    } else {
        num = GradStudent::getNumStudents();
    }

    // compute the mean of the total score.
    for (auto it = students.begin(); it != students.end(); it++) {
        totalOfTotals += it->get().getTotal();
    }

    // sort and print the students based on their total.
    std::sort(students.begin(), students.end(),
        [](Student &a, Student &b) -> bool {
           return a.getTotal() > b.getTotal();
     });

     // Display:
    std::cout << "Number of students = " << num << std::endl;
    std::cout << "The mean of the total score = " << totalOfTotals/(double)num;
    std::cout << std::endl;
    std::cout << "The sorted list of students (id, name, total, grade) in";
    std::cout << " descending order of total:" << std::endl;
    for (auto it = students.begin(); it != students.end(); it++) {
        std::cout << it->get().getId() << ", " << it->get().getName() << ", ";
        std::cout << it->get().getTotal() << ", " << it->get().getGrade();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
