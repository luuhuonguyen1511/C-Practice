#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include "Dengue.h"
#include "Virus.h"

Dengue::Dengue()
{
	DoBorn();
	InitResistance();
}

Dengue::~Dengue()
{
	DoDie();
}

Dengue::Dengue(Dengue *den)
{
	this->m_dna = den->m_dna;
	this->m_resistance = den->m_resistance;
	for (int i = 0; i < 4; i++) {
		this->m_protein[i] = den->m_protein[i];
	}
}

void Dengue::DoBorn()
{
	this->LoadADNInformation();

	enum Type {
		NS3,
		NS5,
		E
	};
	
	std::string temp;
	
	Type protein = static_cast<Type>(rand() % E);
	switch (protein)
	{
	case 0: 
		temp = "NS3";
		strcpy_s(m_protein, temp.c_str());
		break;
	case 1: 
		temp = "NS5";
		strcpy_s(m_protein, temp.c_str());
		break;
	case 2: 
		temp = "E";
		strcpy_s(m_protein, temp.c_str());
		break;
	}
}

std::vector<Virus*> Dengue::DoClone()
{
	std::vector<Virus*> listVirus;
	Virus* denNo1 = new Dengue(this);
	Virus* denNo2 = new Dengue(this);
	listVirus.push_back(denNo1);
	listVirus.push_back(denNo2);
	return listVirus;
}

int Dengue::InitResistance()
{
	switch (m_protein[2])
	{
	case '3':
		this->m_resistance = 1 + (rand() % (int)(10 - 1) + 1);
		break;
	case '5':
		this->m_resistance = 11 + (rand() % (int)(20 - 11) + 1);
		break;
	case '0': this->m_resistance = 21 + (rand() % (int)(30 - 21) + 1);
		break;
	}
	return m_resistance;
}

void Dengue::DoDie() {
	delete this;
}