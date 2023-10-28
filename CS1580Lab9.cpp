// Programmer: Michael Turner
// Student ID: 18229090
// Section: 305
// Date: 10/27/23
// File: CS1580Lab9.cpp 

#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

//this function takes 2 inputs and swaps them
//pre: 2 inputs of int type
//swaps the inputs
void swap(int& position1, int& position2);

//this function takes the guess and returns true of false based on the range of 0-10
//pre: guess is string
//returns false if Not between 0-10 and returns true if valid
bool validateInput(string guess);

//This function obtains the number of students in the program from 1-10
//must be int data type
//outputs number of student
int getNumberOfStudents();

//This function takes the number of students and for each student obtains user inputed data for each variable
//Pre: Number of students
//Outputs average, score, max score, min score, student names,number of students passed and failed.
void getStudentData(int students, double& avg, double& score, double& max, double& min, string& name, string& minName, string& maxName, int& passed, int& failed, double &sum);

//This function takes the data from getStudentData and outputs in a neat format
//pre: avgerage, score, max, min, name, minName, maxName, passed, failed
//returns class statistincs which include the max and min score with each student that got them, the average score, and how many students passed or failed.
void displayStatistics(double avg, double score, double max, double min, string name, string minName, string maxName, int passed, int failed);

//This function gets the user's name
//Pre: input must be string
//returns name
void getUserName(string& userName);

//This function takes the user password and makes sure it is 5 characters long
//pre: 5 characters long and char type
// returns password
void getUserId(string& pass);

//This function takes the fist 3 inserted characters of the password and sums their char/ASCII value
//Pre: password
//returns the sum of the char/ASCII values
int calculateASCIISum(string& pass, int& sumASCII);

//This function takes the sum of the ascii to determin whether or not to welcome a student or a teacher. Additionall>
//pre: sumASCII and Ctime
// returns greating of teacher or student and displays the current date and time
void greetUser(string& userName, int& sumASCII);

//This function ends the program gracefully
//pre: none
//returns 0
int exitProgram(string userName);

//this function generates a random number 1-10 for the position of the bug
//Pre: none
// returns postion of bug in a number 1-10
int positionOfBug();

//This function gets the user's guess for the position of the bug
//pre: Should be value 1-10, but will reask if not
//returns the guess value
int getUserGuess();

//This function compares the guess to the random generated position
//pre: position and guess
// returns weather the guess was  greater than or less thean the position
void catchTheBug(int position, int guess);

int main() {
	int students;
	string name;
	double score;
	double sum = 0;
	double avg;
	int passed = 0;
	int failed = 0;
	double min = 100;
	double max = 0;
	string maxName;
	string minName;
	char again;
	string pass;
	char ch;
	string userName;
	int sumASCII = 0;
	int position1;
	int position2;
	int guess;
	int attempts = 1;
	getUserName(userName);
	getUserId(pass);
	calculateASCIISum(pass, sumASCII);
	greetUser(userName, sumASCII);
	if (sumASCII >= 150) {
		char choice;
		do {
			cout << "\n1. Calculate student statistics \n2. Display statistics \n3. Exit" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice) {
			case '1':
				students = getNumberOfStudents();
				getStudentData(students, avg, score, max, min, name, minName, maxName, passed, failed, sum);
				break;
			case '2':
				displayStatistics(avg, score, max, min, name, minName, maxName, failed, passed);
				break;
			case '3':
				break;
			default:
				cout << "invalid input" << endl;
			}
		} while (choice != '3');

	}
	else if (sumASCII < 150) {
		char choice;
		do {
			cout << "\nMenu 1: Play Bug Smash game \nMenu 2: Exit program" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice) {
			case '1':
				attempts = 1;
				cout << "On a straight line, there exist 2 bugs laughing at you. Your objective is to smash the bug by guessing which position the bug is. If you guess the exact postion you smash the bug." << endl;
				position1 = positionOfBug();
				position2 = positionOfBug();
				guess = getUserGuess();
				while (guess != position1) {
					catchTheBug(position1, guess);
					guess = getUserGuess();
					attempts++;
					if (attempts % 3 == 0) {
						swap(position1, position2);
						cout << "The bugs have swapped positions! The other bug is laughing at you now." << endl;
					}
				}
				cout << "Congratulations! You smashed the bug in " << attempts << " attempts" << endl;
				break;
			case '2':
				break;
			default:
				cout << "Invalid input" << endl;
			}
		} while (choice != '2');
	}
	exitProgram(userName);

}


void swap(int& position1, int& position2) {
	const int temp = position1;
	position1 = position2;
	position2 = temp;
	return;
}
bool validateInput(string guess) {
	const string validString1 = guess;
	for (int i = 0; i < validString1.length(); i++) {
		if ((validString1[i] == '1') || (validString1[i] == '2') || (validString1[i] == '3') ||(validString1[i] == '4') || (validString1[i] == '5') || (validString1[i] == '6') || (validString1[i] == '7') || (validString1[i] == '8') || (validString1[i] == '9') || (validString1[i] == '10')) {
			return true;
		}
	}
	return false;
}

int getNumberOfStudents() {
	int students;
	cout << "Enter the number of students (1 - 100): ";
	cin >> students;
	while (students < 0 || students > 100) {// getting a valid input
		cout << "Invalid range. Please enter range 0-100:" << endl;
		cin >> students;
	}
	return students;
}

void getStudentData(int students, double& avg, double& score, double& max, double& min, string& name, string& minName, string& maxName, int& passed, int& failed, double& sum) {
	
	for (int i = students; i > 0; i--) {//for loop to get information about each student
		cout << "Enter name of student " << i << ": ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter score of student " << name << ": ";
		cin >> score;
		while (score < 0 || score > 100) { //entering a valid score
			cout << "Invalid range. Please enter range 0-100:" << endl;
			cin >> score;
		}
		if (score > max) {//getting max value
			max = score;
			maxName = name;
		}
		if (score < min) {//getting min value
			min = score;
			minName = name;
		}
		sum += score; //gathering sum for later use in avg
		cout << name << ": " << score << endl;
		if (score > 60) {
			passed++;
		}
		else {
			failed++;
		}
		avg = sum / students; //Equation for avg
	}
}

int positionOfBug() {
	int position;
	position = (rand() % 10 +1);
	return position;
}
int getUserGuess() {
	string guessStr;
	do {
		cout << "Enter your guess (1-10): ";
		cin >> guessStr;
	}while (validateInput(guessStr) == false);
	int guessInt = stoi(guessStr);
	return guessInt;
}

void catchTheBug(int position1, int guess) {
	if (guess > position1) {
		cout << "The bug is to the Left of your guess. Try a lower number." << endl;
	}
	else if (guess < position1) {
		cout << "The bug is to the right of your guess. Try a higher number." << endl;
	}
	return;
}


void displayStatistics(double avg, double score, double max, double min, string name, string minName, string maxName, int passed, int failed) {
	cout << "Class Statistics:\n" << "Max:" << max << " (student: " << maxName << ")\n" << "Min: " << min << " (student: " << minName << ")" << endl;
	cout << "Average Score: " << avg << endl;
	cout << "Number of students failed: " << failed << endl;
	cout << "Number of students passed: " << passed << endl;
}

void getUserName(string& userName) {
	cout << "Enter your name: ";
	cin >> userName;

}

void getUserId(string& pass) {
	do { //do while loop for input validation
		cout << "Enter your 5-character ID:";
		cin >> pass;
		if (pass.size() != 5) { //getting an input of 5 characters
			cout << "Invalid input. Please enter 5 characters ";
			cin >> pass;
		}
	} while (pass.size() != 5);
}

int calculateASCIISum(string& pass, int& sumASCII) {
	for (int i = 0; i < 3; i++) { //for loop for each character inserted
		int asciiValue = int(pass[i]);
		sumASCII += asciiValue;
	}
	return sumASCII;

}

void greetUser(string& userName, int& sumASCII) {
	if (sumASCII >= 150) {
		cout << "welcome teacher " << userName << endl;
	}
	else {
		cout << "welcome student " << userName << endl;
	}
	//time_t now = time(0);
	//char* dt = ctime(&now);
	//cout << "you logged in at " << dt << endl;
}

int exitProgram(string userName) {
	cout << "Goodbye " << userName << endl;
	return 0;
}
