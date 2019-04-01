#include "MotDePasse.h"



MotDePasse::MotDePasse()
{
	source_ = ' ';
	destination_ = nullptr;
	terminal_ = ' ';
	loop_ = false;
}

MotDePasse::MotDePasse(char source, MotDePasse* destination, char terminal) : source_(source), destination_(destination), terminal_(terminal)
{
	loop_ = false;
}

char MotDePasse::getSource()
{
	return source_;
}

MotDePasse* MotDePasse::getDestination()
{
	return destination_;
}

char MotDePasse::getTerminal()
{
	return terminal_;
}

bool MotDePasse::isInfinite()
{
	return loop_;
}

bool MotDePasse::isFinished()
{
	return end_;
}

void MotDePasse::setSource(char source)
{
	source_ = source;
}

void MotDePasse::setDestination(MotDePasse* destination)
{
	destination_ = destination;
}

void MotDePasse::setTerminal(char terminal)
{
	terminal_ = terminal;
}

void MotDePasse::setLoop(bool loop)
{
	loop_ = loop;
}

void MotDePasse::setStatus(bool end)
{
	end_ = end;
}


MotDePasse::~MotDePasse()
{
}
