// Programmer: Michael Turner
// Student ID: 18229090
// Section: 305
// Date: 9/6/2023
// File: Lab09.cpp
// Purpose: Template function and Bug smashing

//
//
//
template <typename T, typename U>
void swap(T &str1, U &str2);

template <typename T, typename U>
bool validateInput(T str1, U str2);
#include <iostream>
#include <string>
using namespace std;

int main(){
	string str1, str2;
	bool valid;
	cout << "Enter the first string: ";
	cin>> str1;
	cout << "Enter the second string: ";
	cin>> str2;
	validateInput(str1, str2);
	while (valid == false){
		cout << "Enter the first string: ";
        	cin>> str1;
        	cout << "Enter the second string: ";
        	cin>> str2;
		validateInput(str1, str2);

	}
	swap(str1, str2);
	cout <<"After swapping: "<< str1 << " " << str2 << endl;
	return 0;
}

template <typename T, typename U>
void swap(T  &str1, U &str2){
	const T temp = str1;
	str1 = str2;
	str2 = temp;
	return;
}

template <typename T, typename U>
bool validateInput(T str1, U str2){
	const string validString1 = str1;
	const string validString2 = str2;
	bool valid;
	for(int i =0; i < validString1.length(); i++){
		if ((validString1[i] == '$') || (validString1[i] == '%')||(validString1[i] == '&')){
			cout << "Invalid input, string contains  %, $, @" << endl;
			return valid = false;
		}
	}

	 for(int i =0; i < validString2.length(); i++){
                if ((validString2[i] == '$') || (validString2[i] == '%')||(validString2[i] == '&')){
                        cout << "Invalid input, string contains  %, $, @" << endl;
			return valid = false;
                }
        }
	return valid = true;
}
