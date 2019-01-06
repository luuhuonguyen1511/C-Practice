#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Virus.h"

Virus::Virus(){}

Virus::~Virus() {}

Virus::Virus(Virus *v) 
{
	this->m_dna = v->m_dna;
	this->m_resistance =v->m_resistance;
}

void Virus::LoadADNInformation()
{
	std::fstream file;
	file.open("ATGX.bin", std::ios::in);

	std::string line;

	while (!file.eof()) {
		getline(file, line);

		const char* str_convert = line.c_str();
		
		m_dna = const_cast<char*> (str_convert) ;
	}
	file.close();
}

int Virus::ReduceResistance(int medicine_resistance)
{
	return m_resistance = m_resistance - medicine_resistance;
}