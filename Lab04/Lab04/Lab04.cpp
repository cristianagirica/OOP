#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

enum TipStudent { LICENTA = 10, MASTERAT = 20, DOCTORAT };

class Student
{
private:
	string nume = "Anonim";
	char universitate[100] = "ASE";
	char* facultate = nullptr;
	int varsta = 0;
	char gen = 'N';
	int* note = nullptr;
	int nrNote = 0;
	bool areBursa = false;
	TipStudent tip = TipStudent::LICENTA;

public:
	string getNume()
	{
		return this->nume;
	}

	int getVarsta()
	{
		return this->varsta;
	}

	char* getUniversitate()
	{
		char* copie = new char[strlen(this->universitate) + 1];
		strcpy_s(copie, strlen(this->universitate) + 1, this->universitate);
		return copie;
	}

	char* getFacultate()
	{
		if (this->facultate == nullptr)
		{
			return nullptr;
		}
		char* copie = new char[strlen(this->facultate) + 1];
		strcpy_s(copie, strlen(this->facultate) + 1, this->facultate);
		return copie;
	}

	int* getNote()
	{
		if (this->note == nullptr)
		{
			return nullptr;
		}
		int* copie = new int[this->nrNote];
		for (int i = 0; i < this->nrNote; i++)
		{
			copie[i] = this->note[i];
			//memcpy(copie, this->note, sizeof(int) * this->nrNote);
		}
		return copie;
	}
};

int main()
{
	Student student;
	Student Ana;

	cout << endl << "Numele este " << student.getNume();
	cout << endl << "Varsta este " << student.getVarsta();
	cout << endl << "Numele este " << Ana.getNume();
	cout << endl << "Universitatea este " << Ana.getUniversitate();

	char* univ = Ana.getUniversitate();

	strcpy_s(univ, 100, "Unibuc");

	cout << endl << "Universitatea este " << Ana.getUniversitate();
}
