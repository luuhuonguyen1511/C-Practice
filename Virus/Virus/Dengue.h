#pragma once
#include <vector>
#include "Virus.h"

class Dengue : public Virus
{
public:
	Dengue();
	Dengue(Dengue *den);
	virtual ~Dengue();

	void DoBorn() override;
	void DoDie() override;
	int InitResistance() override;
	std::vector<Virus*> DoClone() override;

private:
	char m_protein[4];
};