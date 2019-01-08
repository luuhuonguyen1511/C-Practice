#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Virus.h"

Virus::Virus(){
	
}

Virus::~Virus() {
	delete m_dna;
}

Virus::Virus(Virus *v) 
{
	//this->m_dna = new char[255];// sửa lại nghe chưa 
	//this->m_dna[0] = 'a';
	this->m_dna = new char [50] ;
	this->m_dna = v->m_dna;
	
	this->m_resistance =v->m_resistance;
}

void Virus::LoadADNInformation()
{
	std::fstream file;
	file.open("ATGX.bin", std::ios::in);
	m_dna = new char[50];
	std::string line;
	file >> m_dna;
	
	file.close();
}

int Virus::ReduceResistance(int medicine_resistance)
{
	return m_resistance = m_resistance - medicine_resistance;
}

int Virus::GetResistance()
{
	return m_resistance;
}