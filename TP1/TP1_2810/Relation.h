#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class Personnage;

#ifndef RELATION_H
#define RELATION_H
class Relation {
	public: 
		Relation();
		void ajouterRelation(pair<Personnage*, int> pair);
		const vector<pair<Personnage*, int>> getListe();
		const void afficherRelation();
	private:
		vector<pair<Personnage*, int>> listeDesRelations_;
};
#endif
