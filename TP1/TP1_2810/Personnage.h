#pragma once
#include <string>
#include <vector>
#include <iostream>


using namespace std;

class Relation;

#ifndef PERSONNAGE_H
#define PERSONNAGE_H
class Personnage {
	public:
		Personnage();
		Personnage(const string& nom, const string& cheveux,const string& yeux,const string& dept);

		const string& getNom();
		const string& getCheveux();
		const string& getYeux();
		const string& getDept();
		Relation* getRelation();
		const bool& getMystere();

		void setNom(const string& nom);
		void setMystere(const bool& mystere);
		vector<pair<int, Personnage>> operator()(pair<int, Personnage > pairAjouter, vector<pair<int, Personnage>> orderedList);

		const void afficherPersonnage();
	private:
		string nom_;
		string cheveux_;
		string yeux_;
		string dept_;
		Relation* relation_;
		bool estMystere_;

};
#endif
