#pragma once
#include "Relation.h"
#include "personnage.h"

Relation::Relation()
{
}

void Relation::ajouterRelation(pair<Personnage*, int> pair)
{
	listeDesRelations_.push_back(pair);
}

const vector<pair<Personnage*, int>> Relation::getListe() 
{
	return listeDesRelations_;
}

const void Relation::afficherRelation()
{
	for (int i = 0; i < listeDesRelations_.size(); i++)
	{
		cout << "\t" << listeDesRelations_[i].first->getNom() << " (" << listeDesRelations_[i].second << ")" << endl << "\t";
	}
}
