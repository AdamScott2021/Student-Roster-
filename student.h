#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
public:
	const static int daysArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	double daysinCourse [daysArraySize];
	DegreeProgram degreeProgram;
public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, double daysinCourse[], DegreeProgram degreeProgram);
	~Student();

	string getstudentID();
	string getfirstName();
	string getlastName();
	string getemailAddress();
	int getage();
	double* getdaysinCourse();
	DegreeProgram getDegreeProgram();

	void setstudentID(string studentID);
	void setfirstName(string firstName);
	void setlastName(string lastName);
	void setemailAddress(string emailAddress);
	void setage(int age);
	void setdaysinCourse(double daysinCourse[]);
	void setDegreeProgram(DegreeProgram dt);

	static void printHeader();

	void print();
};
