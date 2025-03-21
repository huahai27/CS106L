/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>

std::string kYourName = "Huahai Liu"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::set<std::string> applicants;
  std::ifstream ifs(filename);
  std::string name;
  while (std::getline(ifs, name)) {
    applicants.insert(name);
  }
  ifs.close();

  return applicants;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */

bool checkInitial(const std::string& Myname, const std::string& Hername) {
  std::string MyFirst, MyLast, HerFirst, HerLast;
  std::stringstream ss;
  ss << Myname << Hername;
  ss >> MyFirst >> MyLast >> HerFirst >> HerLast;
  return MyFirst[0] == HerFirst[0] && MyLast[0] == HerLast[0];
}

std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> trueOnes;

  // must be const!
  for (const std::string& s : students) {
    if (checkInitial(name, s)) {
      trueOnes.push(&s); 
    }
  }

  return trueOnes;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  std::string theOne;
  if (matches.empty()) {
    theOne = "NO MATCHES FOUND.";
  } else {
    theOne = *(matches.front());
  }

  return theOne;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
