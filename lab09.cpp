// Programmer: Michael Turner
// Student ID: 18229090
// Section: 305
// Date: 9/6/2023
// File: Lab09.cpp
// Purpose: Template function and Bug smashing

//this function takes 2 inputs of any type and swaps them
//pre: 2 inputs of any type
//swaps the inputs
template <typename T, typename U>
void swap(T& str1, U& str2);
//this function takes 2 inputs of any type and makes sure they do not contain certain characters
//pre: 2 inputs must be entered
//returns invalid if invalid character is found and returns nothing if valid
template <typename T, typename U>
bool validateInput(T str1, U str2);
#include <iostream>
#include <string>
using namespace std;

int main() {
  string str1, str2;
  do {
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;
  } while (validateInput(str1, str2) == false);
  swap(str1, str2);
  cout << "After swapping: " << str1 << " " << str2 << endl;
  return 0;
}

template <typename T, typename U>
void swap(T& str1, U& str2) {
  const T temp = str1;
  str1 = str2;
  str2 = temp;
  return;
}

template <typename T, typename U>
bool validateInput(T str1, U str2) {
  const string validString1 = str1;
  const string validString2 = str2;
  for (int i = 0; i < validString1.length(); i++) {
    if ((validString1[i] == '$') || (validString1[i] == '%') || (validString1[i] == '&')) {
      cout << "Invalid input, string contains  %, $, @" << endl;
      return false;
    }
  }

  for (int i = 0; i < validString2.length(); i++) {
    if ((validString2[i] == '$') || (validString2[i] == '%') || (validString2[i] == '&')) {
      cout << "Invalid input, string contains  %, $, @" << endl;
      return false;
    }
  }
  return true;
}