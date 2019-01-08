#include <iostream>
#include <time.h>
#include <vector>
#include "Patient.h"
#include "Virus.h"
#include "FluVirus.h"
#include "Dengue.h"



Patient::Patient() {
	InitResistance();
	DoStart();
}

Patient::~Patient() {
	DoDie();
}

int Patient::InitResistance()
{
	return this->m_resistance = 1000 + (rand() % (int)(9000 - 1000) + 1);
}

void Patient::DoStart()
{

	srand(time(0));
	this->m_state = 1;
	int virusNumber = 10 + (rand() % (int)(20 - 10) + 1);
	int randNum;

	for (int i = 0; i < virusNumber; i++) {
		randNum = rand() % 2;
		switch (randNum)
		{
		case 0:
		{

			Virus* flu = new FluVirus();
			this->m_virusList.push_back(flu);
			
			break;
		}

		case 1:
		{
			Virus* den = new Dengue();
			this->m_virusList.push_back(den);
			
			break;
		}

		}
	}
}

void Patient::TakeMedicine(int medicine_resistance)
{
	int total_virus_resistance = 0;
	int i = 0;
	if (m_state == 1) {
		int virus_resistance = 0;
		while (i != this->m_virusList.size() ) {
			virus_resistance = m_virusList[i]->ReduceResistance(medicine_resistance);
			if (virus_resistance < 1) {
				delete m_virusList[i];
				m_virusList.erase(m_virusList.begin() + i);
				i--;
			}
			i++;
		}
		if (!m_virusList.empty()) {
			i = 0;
			int size = this->m_virusList.size() - 1;
			while (i != size) {
				int j = 0;
				std::vector<Virus*> list ;
				list = m_virusList[i]->DoClone();
				for each (auto var in list)
				{
					m_virusList.push_back(var);
				}
				i++;
				//delete list;
			}

			i = 0;
			while (i != this->m_virusList.size() - 1)
			{
				total_virus_resistance += m_virusList[i]->GetResistance();
				if (this->m_resistance < total_virus_resistance)
				{
					this->DoDie();
					break;
				}
				i++;
			}

			std::cout << "Total virus resistance: " << total_virus_resistance << "\n";

			if (total_virus_resistance <= medicine_resistance)
			{
				std::cout << "All virus died:)))\n";
				this->DeleteListVirus();
			}
		}
		else this->DeleteListVirus();
	};
}

void Patient::DoDie()
{
	DeleteListVirus();
	this->m_state = 0;
	std::cout << "Patient died :)))\n";
}

int Patient::GetState()
{
	return m_state;
}

void Patient::DeleteListVirus()
{
	for (int i = 0; i < m_virusList.size(); i++) {
		delete m_virusList[i];
	}

	this->m_virusList.clear();

	std::cout << "Delete all virus\n";
}
