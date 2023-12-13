#include "roster.h"
void Roster::parse(string studentData)
{
	int rhs = studentData.find(",");
	string ID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string FN = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string LN = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string EM = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs)); 

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double C1 = stod(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double C2 = stod(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double C3 = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string dts = studentData.substr(lhs, rhs - lhs);

	DegreeProgram dt = Software;
	if (dts == "SECURITY")
	{
		dt = Security;
	}
	if (dts == "NETWORK")
	{
		dt = Network;
	}

	add(ID, FN, LN, EM, age, C1, C2 ,C3, dt);
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, double daysinCourse1, double daysinCourse2, double daysinCourse3, DegreeProgram degreeProgram)
{
	double parr[3] = { daysinCourse1,daysinCourse2,daysinCourse3 };
	studentRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, parr, degreeProgram); 
}
void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		studentRosterArray[i]->print();
	}
}

void Roster::printByDegreeProgram(DegreeProgram dt)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::studentRosterArray[i]->getDegreeProgram() == dt) studentRosterArray[i]->print();
	}
	cout << std::endl;
}

void Roster::printByEmailAddress()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string emailAddress = (studentRosterArray[i]->getemailAddress());
		if (emailAddress.find('@') == string::npos || (emailAddress.find('.') == string::npos && emailAddress.find(" ") == string::npos))
		{
			any = true;
			cout << emailAddress << ": " << studentRosterArray[i]->getfirstName() << std::endl;
		}
	}
	if (!any) cout << "NONE" << std::endl;
}

void Roster::printAverageDays(string ID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (studentRosterArray[i]->getstudentID() == ID)
		{
			cout << studentRosterArray[i]->getstudentID() << ": ";
			cout << (studentRosterArray[i]->getdaysinCourse()[0]
				+ studentRosterArray[i]->getdaysinCourse()[1]
				+ studentRosterArray[i]->getdaysinCourse()[2]) / 3.0 << std::endl;
		}
	}
	cout << std::endl;
}

void Roster::removeStudentBystudentID(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (studentRosterArray[i]->getstudentID() == studentID)
		{
			if (i < numStudents - 1)
			{
				Student* temp = studentRosterArray[i];
				studentRosterArray[i] = studentRosterArray[numStudents - 1];
				studentRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << "ID number " << studentRosterArray[2] << " Was removed from Roster." << std::endl << std::endl;
		this->printAll();
	}
	else cout << "ID number " << "A3" << " was not found." << std::endl << std::endl;
}
Roster::~Roster()
{
	cout << "Calling Destructor" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Removing student " << i + 1 << " from roster." << std::endl;
		delete studentRosterArray[i];
		studentRosterArray[i] = nullptr;
	}
}