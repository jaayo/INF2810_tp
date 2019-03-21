#include "stdafx.h"
#pragma once

#define _GLIBCXX_USE_CXX11_ABI 0
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>


void afficherLeCheminParcouru() {


}

void afficherLeDernierEvenement(){
	bool siGrouffre; // "Cette porte n'est pas un gouffre", "Cette porte est un gouffre, retour à Porte1";
	cout << "Evenement " << Evenement << endl;
	cout << "a. Porte" << numeroPorte << endl <<

	cout <<	"b. "; 
	int i = 0;
	for (i; i < nbrPorte - 1, i++)
		cout << "{" << motDePasse << ", Porte" << i << "," << validation << "}, " << endl;
	cout << "{" << motDePasse << ", Porte" << i + 1  << "," << validation << "}" << endl;
	cout << "c. " << siGouffre << endl;


}

void ouvrirPorte() {


}

void genererAutomate() {


}

void affronterBoss() {
	genererAutomate();

}

void reinitialiseDonnees() {


}

void menu() {
	cout << "\n(a) Entrer dans le labyrinthe" << endl <<
			"(b) Ouvrir une porte" << endl <<
			"(c) Afficher le chemin parcouru" << endl <<
			"(d) Quitter" << endl << endl;
}


void lirePorte(string fichierPorte) {
	ifstream fichierPorte(fichierPorte, ios::in);
	if (fichierPorte) {
		if (!fichierPorte.fail()) {
			int i = 0;
			fichierPorte.getline();
			while (!ws(fichierPorte).eol())
				//sauvegarder regle pour automate;
			while (!ws(fichierPorte).eof()) {
				//Sauvegarder porte possible a ouvrir et leur mot de passe
				vector<pair<string, string>> portes;
				fichierPorte << porte[i].first << porte[i].second;
				i++;
			}
			
			cout << "Les fichiers ont ete lu correctement.\n";
			fichierPorte.close();
		}
	}
	else {
		string error = "On arrive pas a ouvrir le fichier \n";
		throw error;
	}
}


int main()
{
	string porteChoisi;
	string porteCourrante;
	string choixOption;
	bool a = false;
	while ((choixOption != "d") && (choixOption != "Quitter")) {
		menu();
		cin >> choixOption;
		cout << endl;
		if (choixOption == "a") {

			reinitialiseDonnees();

			a = true;
		}

		if (choixOption == "b" && a == true) {
			afficherLeDernierEvenement();
			cout << "Quelle porte voulez vous ouvrir?	(ex. Porte1)" << endl;
			cin >> porteChoisi;
			porteChoisi += ".txt";


			//	ouvrirPorte();
			//
		}
		else if (choixOption == "b" && a != true) { cout << "Il faut d'abord choisir l'option 'A' pour ouvrir une porte\n"; }
		
		if (choixOption == "c" && a == true) {
			afficherLeCheminParcouru();
		}
		else if (choixOption == "c" && a != true) {
			cout << "Il faut d'abord choisir l'option 'A' "; 
		}
		if (choixOption != "a" &&choixOption != "b" &&choixOption != "c" &&choixOption != "d") { cout << choixOption << " n'est pas une option valide\n"; }
		}
		
	}
	return 0;
}
