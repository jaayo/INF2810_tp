#pragma once
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;

class MotDePasse
{
public:
	MotDePasse();
	MotDePasse(char source, MotDePasse* destination, char terminal);

	char getSource();
	MotDePasse* getDestination();
	char getTerminal();
	bool isInfinite();
	bool isFinished();

	void setSource(char source);
	void setDestination(MotDePasse* destination);
	void setTerminal(char terminal);
	void setLoop(bool loop);
	void setStatus(bool end);

	~MotDePasse();

private:
	char source_;
	MotDePasse* destination_;
	char terminal_;
	bool loop_;
	bool end_;
};

