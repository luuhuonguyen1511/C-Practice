#pragma once
#include <vector>
#include "Virus.h"

class Patient {
public:
	Patient();
	virtual ~Patient();
	void DeleteListVirus();
	
	int InitResistance();
	void DoStart();
	void TakeMedicine(int medicine_resistance);

	void DoDie();
	int GetState();

private:
	std::vector<Virus*> m_virusList;
	int m_resistance;
	int m_state;
};