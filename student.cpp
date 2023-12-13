#include "student.h"

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysArraySize; i++) this->daysinCourse[i] = 0;
	this->degreeProgram = DegreeProgram::Software;           
}
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, double daysinCourse[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++) this->daysinCourse[i] = daysinCourse[i];
	this->degreeProgram = degreeProgram;
}
Student::~Student() {}

string Student::getstudentID() {return this->studentID;}
string Student::getfirstName() { return this->firstName;}
string Student::getlastName() { return this->lastName;}
string Student::getemailAddress() { return this->emailAddress; }
int Student::getage() { return this->age; }                       
double* Student::getdaysinCourse() {return this->daysinCourse;}
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram;}

void Student::setstudentID(string studentID) { this->studentID = studentID;} 
void Student::setfirstName(string firstName) {this->firstName = firstName;}
void Student::setlastName(string lastName) { this->lastName = lastName;}
void Student::setemailAddress(string emailAddress) { this->emailAddress = emailAddress;}
void Student::setage(int age) {this->age = age;}
void Student::setdaysinCourse(double daysinCourse[])
{
	for (int i = 0; i < daysArraySize; ++i) this->daysinCourse[i] = daysinCourse[i];
}
void Student::setDegreeProgram(DegreeProgram dts) {this->degreeProgram = dts;}

void Student::printHeader() 
{
	cout << "Output format: ID Number|First Name|Last Name|Email|Age|Days in Course|Degree\n";
}

void Student::print()
{
	cout << studentID << '\t';
	cout << firstName << '\t';
	cout << lastName << '\t';
	cout << emailAddress << '\t';
	cout << age << '\t';
	cout << this->daysinCourse[0] << ',';
	cout << this->daysinCourse[1] << ',';
	cout << this->daysinCourse[2] << '\t'; //fix these instruction e3c
	cout << DegreeTypeStrings [degreeProgram] << '\n';
}
