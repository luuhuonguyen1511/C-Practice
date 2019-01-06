#pragma once
#include <vector>
#include "Virus.h"

class FluVirus: public Virus
{
public:
	FluVirus();
	FluVirus(FluVirus *flu);
	virtual ~FluVirus();

	void DoBorn() override;
	void DoDie() override;
	int InitResistance() override;
	std::vector<Virus*> DoClone() override;

private:
	int m_color;
};

