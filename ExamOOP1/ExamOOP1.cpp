#include <iostream>
#include <string>

using namespace std;

class Print
{
public:
	virtual void print() = 0;
};

class Character : Print
{
protected:
	char* name = nullptr;
	int XP = 0;
	string* powers = nullptr;
	bool villain = false;
	int noPowers = 0;
public:
	static int CHARACTERS_COUNT;

	Character(const char* name, bool villain) :villain(villain)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		Character::CHARACTERS_COUNT++;
	}

	Character() {}

	~Character()
	{
		delete[] name;
		delete[] powers;
		Character::CHARACTERS_COUNT--;
	}

	void setXP(int xp)
	{
		if (xp > 0)
		{
			this->XP = xp;
		}	
	}

	int getXP()
	{
		return this->XP;
	}

	void addPower(string power)
	{
		
		string* pow = new string[this->noPowers + 1];
		for (int i = 0; i < noPowers; i++)
		{
			pow[i] = this->powers[i];
		}
		pow[this->noPowers] = power;
		delete[] powers;
		this->powers = pow;
		this->noPowers++;
	}

	string* getPowers()
	{
		return this->powers;
	}

	void operator += (int xp)
	{
		this->XP = this->XP + xp;
	}

	bool operator >= (const Character& character)
	{
		if (this->noPowers >= character.noPowers)
		{
			return true;
		}
		return false;
	}

	virtual void print() override
	{
		cout << endl << "Character " << this->name << ", XP: " << this->XP;
		cout << endl << "Powers: ";
		for (int i = 0; i < this->noPowers; i++)
		{
			cout << this->powers[i] << " ";
		}
	}
};

enum Rank
{
	COMMON,
	RARE,
	EPIC
};
class ExperiencedCharacter : public Character
{
	static const int MIN_XP = 1000;

	Rank rank = Rank::COMMON;
public:
	ExperiencedCharacter() {
		this->setXP(1000);
	}

	ExperiencedCharacter(const char* name, bool villain, Rank rank):Character(name, villain)
	{
		this->setXP(MIN_XP);
		this->setRank(rank);
	}

	void setRank(Rank rank)
	{
		this->rank = rank;
		if (this->rank == Rank::RARE)
		{
			this->XP += 300;
		}
		if (this->rank == Rank::EPIC)
		{
			this->XP += 500;
		}
	}

	void print() override
	{
		Character::print();
		string r = "Common";
		if (this->rank == Rank::RARE)
		{
			r = "Rare";
		}
		if (this->rank == Rank::EPIC)
		{
			r = "Epic";
		}
		cout << endl << "Rank: " << r;
	}
};

int Character::CHARACTERS_COUNT = 0;

int main()
{
	
	Character c1("Avatar", true);
	c1.addPower("Fire");
	c1.addPower("Invisibility");
	c1.addPower("Fast");
	c1.setXP(100);
	c1.print();
	cout << endl << Character::CHARACTERS_COUNT;

	ExperiencedCharacter xc1("Alana", false, Rank::EPIC);
	Character* c2 = &xc1;
	c2->addPower("Ice");
	c2->addPower("Fly");
	c2->print();

	//dangling pointer
	Character* c3 = new Character("Ana", false);
	delete[] c3;


}
