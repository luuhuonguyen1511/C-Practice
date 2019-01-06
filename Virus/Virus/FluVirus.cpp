#include <iostream>
#include <vector>
#include "FluVirus.h"
#include "Virus.h"

FluVirus::FluVirus()
{
	DoBorn();
	InitResistance();
}
	
FluVirus::~FluVirus()
{
	DoDie();
}

FluVirus::FluVirus(FluVirus *flu)
{
	this->m_dna = flu->m_dna;
	this->m_resistance = flu->m_resistance;
	this->m_color = flu->m_color;
}

void FluVirus::DoBorn()
{
	this->LoadADNInformation();
	
	enum Color {
		RED,
		BLUE
	};

	this->m_color = rand() % 2;
}

std::vector<Virus*> FluVirus::DoClone()
{
	std::vector<Virus*> listVirus;
	Virus* flu = new FluVirus(this);
	
	listVirus.push_back(flu);
	return listVirus;
}

int FluVirus::InitResistance()
{
	switch (m_color)
	{
	case '0':
		this->m_resistance = 10 + (rand() % (int)(20 - 10) + 1);
		break;
	case '1':
		this->m_resistance = 10 + (rand() % (int)(15 - 10) + 1);
		break;
	}
	return m_resistance;
}

void FluVirus::DoDie() {
	delete this;
}