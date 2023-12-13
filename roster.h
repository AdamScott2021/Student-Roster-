#pragma once
#include "student.h"
class Roster
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* studentRosterArray[numStudents];
public:
	void parse(string row);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, double daysinCourse1, double daysinCourse2, double daysinCourse3, DegreeProgram degreeProgram);

	void printAll();
	void printByDegreeProgram(DegreeProgram dt);
	void printByEmailAddress();
	void printAverageDays(string ID);
	void removeStudentBystudentID(string studentID);
	~Roster();
};