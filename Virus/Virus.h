#pragma once
#include <vector>

class Virus {
public:
	Virus();
	virtual ~Virus();
	Virus(Virus *v);
	void LoadADNInformation();
	int ReduceResistance(int);
	int GetResistance() {
		return m_resistance;
	}

	virtual void DoBorn() = 0;
	virtual std::vector<Virus*> DoClone() = 0;
	virtual void DoDie() = 0;
	virtual int InitResistance() = 0;
protected:
	char* m_dna;
	int m_resistance;
};

