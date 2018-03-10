//
// Created by mwypych on 10.03.18.
//
#include <string>
#include "ExampleLibrary.h"

using std::string;

int ExampleAddition(int x, int y) {
  return x+y+1;
}
string ExampleConcatenation(const string &left, const string &right) {
  return left + " " + right;
}
