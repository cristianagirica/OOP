#include <iostream>
#include <string>
using namespace std;

class Student
{
	string nume = "";
	string facultate = "";
	int grupa = 0;
public:
	const int id = 0;

	virtual void print()
	{
		cout << endl << "Studentul " << this->nume <<
			" este inmatriculat la " << this->facultate <<
			", grupa " << this->grupa;
	}

	Student(string nume, string facultate, int grupa) :nume(nume), facultate(facultate), grupa(grupa) {}

	Student(){}

	void operator =(Student& s)
	{
		this->nume = s.nume;
		this->grupa = s.grupa;
		this->facultate = s.facultate;
	}
};

class Masterand : public Student
{
	string program;
	string facultate;
public:
	Masterand():Student("","",0) {}
	Masterand(string nume, string facultate, int grupa, string program, string facultateMasterat):Student(nume, facultate, grupa),
		program(program), facultate(facultateMasterat) {}
	Masterand(Student student, string program, string facultate) : Student(student), program(program), facultate(facultate) {}

	void printMasterand()
	{
		this->print();
		cout << endl << "Masterat " << this->program << " din facultatea " << this->facultate;
	}

	void print()
	{
		this->Student::print();
		cout << endl << "Masterat " << this->program << " din facultatea " << this->facultate;
	}
};
int main()
{
	Student student("Gigel", "CSIE", 1001);
	cout << endl << "ID student " << student.id;
	student.print();

	Masterand masterand;
	cout << endl << "ID masterand: " << masterand.id;

	Masterand masterand2(student, "Info", "CSIE");

	Student stud;
	stud = masterand2;

	Student* pStud = &masterand2;

	Masterand ana("Ana", "CSIE", 1002, "Info", "CSIE");
	Student* studenti[3];
	studenti[0] = &student;
	studenti[1] = &masterand2;
	studenti[2] = &ana;

	for (int i = 0; i < 3; i++)
	{
		studenti[i]->print();
	}
}
