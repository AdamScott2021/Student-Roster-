#include "roster.h"
using namespace std;
int main()
{
	const string studentData[] =
	{
	  "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickso,Erickso_1990@gmailcom,19,50,30,40,NETWORK", 
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Adam,Scott,adamscott2021@gmail.com,29,45,30,60,SOFTWARE"
	};
	const int numStudents = 5;
	Roster roster = Roster();

	cout << "|Name: Adam Scott|ID:001423886|Course: Scripting and Programming Applications (C867)|Language - C++|" << endl;
	cout << endl;

	for (int i = 0; i < numStudents; i++) {roster.parse(studentData[i]);}
	cout << "Showing all students in roster: " << std::endl;
	roster.printAll();
	cout << endl;
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Displaying by degree program: " << DegreeTypeStrings[i] << std::endl;
		cout << endl;
		roster.printByDegreeProgram((DegreeProgram)i);
	}
	
	cout << "Displaying invalid Email Addresses: " << endl;
	roster.printByEmailAddress();
	cout << endl;
	cout << "Displaying average days in courses: " << endl;

	for (int i = 0; i < numStudents; i++)
	{
		string ID = roster.studentRosterArray[i]->getstudentID();
		roster.printAverageDays(ID);
	}

	cout << "Removing student with ID Number A3: " << endl;
																
	roster.removeStudentBystudentID("A3");
	cout << endl;
		
	system("Pause");
	return(0);
}