#pragma once
#include "relation.h"
#include "personnage.h"


Personnage::Personnage()
{
	relation_ = new Relation();
}

Personnage::Personnage(const string& nom, const string& cheveux, const string& yeux, const string& dept)
{
	nom_ = nom;
	cheveux_ = cheveux;
	yeux_ = yeux;
	dept_=dept;
	relation_ = new Relation();
}
const string& Personnage::getNom()
{
	return nom_;
}

const string& Personnage::getCheveux() 
{
	return cheveux_;
}

const string& Personnage::getYeux() 
{
	return yeux_;
}

const string& Personnage::getDept() 
{
	return dept_;
}

Relation* Personnage::getRelation()
{
	return relation_;
}

const bool & Personnage::getMystere()
{
	return estMystere_;
}

void Personnage::setNom(const string& nom)
{
	nom_ = nom;
}

void Personnage::setMystere(const bool & mystere)
{
	estMystere_ = mystere;
}

const void Personnage::afficherPersonnage()
{
	cout << getNom() << " " << getCheveux() << " " << getYeux() << " " << getDept() << endl;
	if (relation_ != nullptr) {
		if (relation_->getListe().size() > 0) {
			cout << "Relations : ";
			getRelation()->afficherRelation();
		}
		cout << endl;
	}
}


vector<pair<int, Personnage>> Personnage::operator()(pair<int, Personnage> pairAjouter, vector<pair<int, Personnage>> orderedList) {
	vector <pair<int, Personnage>> temp;
	for (size_t i = orderedList.size(); i > 0; i--)
	{
		if (orderedList[i].first > pairAjouter.first) {
			temp.push_back(orderedList[i]);
			orderedList.pop_back();
		}
		else {
			orderedList.push_back(pairAjouter);
			for (size_t i = temp.size(); i > 0; i--)
			{
				orderedList.push_back(temp[i]);
			}
		}		
	}
	return orderedList;
}
