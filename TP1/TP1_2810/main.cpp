#pragma once

#define _GLIBCXX_USE_CXX11_ABI 0
#include "Relation.h"
#include "Personnage.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <queue>

vector<Personnage> listePersonnage;
string cheveux[4] = { "Noir", "Roux", "Blond", "Marron" };
string yeux[5] = { "Bleu","Noir","Vert","Gris","Marron" };
string genie[9] {"Genie Informatique","Genie Electrique","Genie Physique","Genie Chimique","Genie Aerospatial","Genie Mecanique","Genie Biomecanique","Genie Industriel","Genie Energetique"};
int nombreQuestion = 0;
bool aTrouverLesMysteres = true;

void afficherMystereRestant() {
	cout << "Les suspects encore sur la liste sont :\n";
	for (int i = 0; i < listePersonnage.size(); i++)
	{
		if (listePersonnage[i].getMystere()) {
			cout <<	listePersonnage[i].getNom() << endl;
		}
	}
}



void identifierIndividus() {
	string reponse;
	string couleur;
	string choixGenie;
	string posibiliteCheveux,posibiliteYeux,posibiliteGenie = "";
	bool cheveuxTrouver = false;
	bool yeuxTrouver = false;
	bool genieTrouver = false;
	bool personnage1 = false;
	bool personnage2 = false;
	int nombreMystere = 0;
	nombreQuestion = 0;
	aTrouverLesMysteres = true;

	for (int i = 0; i < listePersonnage.size(); i++)
	{
		listePersonnage[i].setMystere(true);
	}

	while (!cheveuxTrouver && !yeuxTrouver && !genieTrouver && !personnage1 && !personnage2) {
		for (int i = 0; i < 4; i++)
		{
			if (cheveuxTrouver != true) {
				nombreQuestion++;
				cout << "Est ce que les individus ont les cheveux " << cheveux[i] << endl;
				cin >> reponse;
				if (i == 0) couleur = "N";
				if (i == 1) couleur = "R";
				if (i == 2) couleur = "B";
				if (i == 3) couleur = "M";

				if (reponse == "o" && posibiliteCheveux == "") {
					for (int j = 0; j < listePersonnage.size(); j++)
					{
						if (listePersonnage[j].getCheveux() != couleur) {
							listePersonnage[j].setMystere(false);
						}
					}
					cheveuxTrouver = true;
				}
				else if (reponse == "o" && posibiliteCheveux != "") {
					cout << "Attention tu as repondu 'o', tu voulais dire 'u' ?\n";
					i--;
				}
				else if (reponse == "n") {
					for (int j = 0; j < listePersonnage.size(); j++)
					{
						if (listePersonnage[j].getCheveux() == couleur) {
							listePersonnage[j].setMystere(false);
						}
					}
				}
				else if (reponse == "u") {
					if (posibiliteCheveux != "") {
						for (int j = 0; j < listePersonnage.size(); j++)
						{
							if (listePersonnage[j].getCheveux() != couleur && listePersonnage[j].getCheveux() != posibiliteCheveux) {
								listePersonnage[j].setMystere(false);
							}
						}
						cheveuxTrouver = true;
					}
					posibiliteCheveux = couleur;
				}
				else if (reponse == "s") {
					afficherMystereRestant();
					i--;
				}
				else if (reponse != "o" && reponse != "u" && reponse != "n" && reponse != "s") {
					i--;
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			if (yeuxTrouver != true) {
				nombreQuestion++;
				cout << "Est ce que les individus ont les yeux " << yeux[i] << endl;
				cin >> reponse;
				if (i == 0) couleur = "B";
				if (i == 1) couleur = "N";
				if (i == 2) couleur = "V";
				if (i == 3) couleur = "G";
				if (i == 4) couleur = "M";

				if (reponse == "o" && posibiliteYeux == "") {
					for (int j = 0; j < listePersonnage.size(); j++)
					{
						if (listePersonnage[j].getYeux() != couleur) {
							listePersonnage[j].setMystere(false);
						}
					}
					yeuxTrouver = true;
				}
				else if (reponse == "o" && posibiliteYeux != "") {
					cout << "Attention tu as repondu 'o', tu voulais dire 'u' ?\n";
					i--;
				}
				else if (reponse == "n") {
					for (int j = 0; j < listePersonnage.size(); j++)
					{
						if (listePersonnage[j].getYeux() == couleur) {
							listePersonnage[j].setMystere(false);
						}
					}
				}
				else if (reponse == "u") {
					if (posibiliteYeux != "") {
						for (int j = 0; j < listePersonnage.size(); j++)
						{
							if (listePersonnage[j].getYeux() != couleur && listePersonnage[j].getYeux() != posibiliteYeux) {
								listePersonnage[j].setMystere(false);
							}
								
						}
						yeuxTrouver = true;
					}
					posibiliteYeux = couleur;
				}
				else if (reponse == "s") {
					afficherMystereRestant();
					i--;
				}
				else if (reponse != "o" && reponse != "u" && reponse != "n" && reponse != "s") {
					i--;
				}
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (genieTrouver != true) {
				nombreQuestion++;
				cout << "Est ce que les individus sont en  " << genie[i] << endl;
				cin >> reponse;
				if (i == 0) choixGenie = "GI";
				if (i == 1) choixGenie = "GE";
				if (i == 2) choixGenie = "GP";
				if (i == 3) choixGenie = "GC";
				if (i == 4) choixGenie = "GA";
				if (i == 5) choixGenie = "GM";
				if (i == 6) choixGenie = "GB";
				if (i == 7) choixGenie = "GInd";
				if (i == 8) choixGenie = "ER";

				if (reponse == "o" && posibiliteGenie == "") {
					for (int j = 0; j < listePersonnage.size(); j++)
					{
						if (listePersonnage[j].getDept() != choixGenie) {
							listePersonnage[j].setMystere(false);
						}
					}
					genieTrouver = true;
				}
				else if (reponse == "o" && posibiliteGenie != "") {
					cout << "Attention tu as repondu 'o', tu voulais dire 'u' ?\n";
					i--;
				}
				else if (reponse == "n") {
					for (int j = 0; j < listePersonnage.size(); j++)
					{
						if (listePersonnage[j].getDept() == choixGenie) {
							listePersonnage[j].setMystere(false);
						}
					}
				}
				else if (reponse == "u") {
					if (posibiliteGenie != "") {
						for (int j = 0; j < listePersonnage.size(); j++)
						{
							if (listePersonnage[j].getDept() != choixGenie && listePersonnage[j].getDept() != posibiliteGenie) {
								listePersonnage[j].setMystere(false);
							}	
						}
						genieTrouver = true;
					}
					posibiliteGenie = choixGenie;
				}
				else if (reponse == "s") {
					afficherMystereRestant();
					i--;
				}
				else if (reponse != "o" && reponse != "u" && reponse != "n" && reponse != "s") {
					i--;
				}
			}
		}
		for (int i = 0; i < listePersonnage.size(); i++)
		{
			if (listePersonnage[i].getMystere() == true) nombreMystere++;
		}
		string reponseMystere;
		for (int i = 0; i < listePersonnage.size(); i++)
		{
			if (listePersonnage[i].getMystere() == true && nombreMystere > 2) {
				nombreQuestion++;
				cout << "Ton personnage mystere est : " << listePersonnage[i].getNom() << " (o/n) ?\n";
				cin >> reponseMystere;
				if (reponseMystere == "o") {
					if (personnage1) { 
						for (int j = i+1; j < listePersonnage.size(); j++)
						{
							listePersonnage[j].setMystere(false);
						}
						personnage2 = true; 
						break; }
					else { personnage1 = true; }
				}
				else { listePersonnage[i].setMystere(false); nombreMystere--; }
			}
			else if (nombreMystere == 2) { 
				personnage1 = true; 
				personnage2 = true; 
				break; 
			}
		}
	}

	string reponseMystere;
	string nomMystere1, nomMystere2;
	afficherMystereRestant();
	cout << "Cette liste de reponses est-elle correcte (o/n)?\n";
	cin >> reponseMystere;
	if (reponseMystere == "o") { cout << "\nPense a afficher les resultats\n"; }
	else {
		aTrouverLesMysteres = false;
		cout << "Quels sont les noms des individus mysteres (nom1 nom2) ?\n";
		cin >> nomMystere1 >> nomMystere2;
		for (int i = 0; i < listePersonnage.size(); i++)
		{
			listePersonnage[i].setMystere(false);
			if (listePersonnage[i].getNom() == nomMystere1) {
				listePersonnage[i].setMystere(true);
			}
				
			if(listePersonnage[i].getNom() == nomMystere2) {
				listePersonnage[i].setMystere(true);
			}
		}
	}
}

void menu() {
	cout << "\n(a) Creer le reseau social" << endl <<
			"(b) Afficher le reseau social" << endl <<
			"(c) Jouer a Qui est - ce ?" << endl <<
			"(d) Afficher le resultat" << endl <<
			"(e) Quitter" << endl << endl;
}

void creerReseauSocial(string fichierPerso, string fichierRelation) {
	ifstream FichierPersonnage(fichierPerso, ios::in);
	ifstream FichierRelation(fichierRelation, ios::in);
	if (FichierPersonnage && FichierRelation) {
		if (!FichierPersonnage.fail() && !FichierRelation.fail()) {
			while (!ws(FichierPersonnage).eof()) {
				string nom, cheveux, yeux, dept;
				FichierPersonnage >> nom >> cheveux >> yeux >> dept;
				listePersonnage.push_back(Personnage(nom, cheveux, yeux, dept));
			}
			while (!ws(FichierRelation).eof()) {
				string nomGauche, nomDroit;
				Personnage* personnageDroit = new Personnage();
				int valeurRelation;
				FichierRelation >> nomGauche >> valeurRelation >> nomDroit;
				for (int j = 0; j < listePersonnage.size(); j++)
				{
					if (listePersonnage[j].getNom() == nomDroit) {
						*personnageDroit = listePersonnage[j];
					}
				}
				for (int i = 0; i < listePersonnage.size(); i++)
				{
					if (listePersonnage[i].getNom() == nomGauche) {
						pair<Personnage*, int> temp(personnageDroit, valeurRelation);
						if (personnageDroit->getRelation() != nullptr)
							listePersonnage[i].getRelation()->ajouterRelation(temp);
					}
				}
			}
			cout << "Les fichiers ont ete lu correctement.\n";
			FichierPersonnage.close();
			FichierRelation.close();
		}
		else creerReseauSocial(fichierPerso, fichierRelation);
	}
	else {
		string error = "On arrive pas a ouvrir le fichier \n";
		throw error;
	}
}

void afficherReseauSocial() {
	for (int i = 0; i < listePersonnage.size(); i++)
	{
		listePersonnage[i].afficherPersonnage();
	}
}

vector<Personnage> parcourirPersonnages(Personnage nom1, vector<Personnage> &grapheLocal) {
	grapheLocal.push_back(nom1);
	for (int i = 0; i < nom1.getRelation()->getListe().size(); i++) 
		grapheLocal = parcourirPersonnages(*nom1.getRelation()->getListe()[i].first, grapheLocal);
	return grapheLocal;
		
}


struct priorite {
	int operator()(const pair<int, Personnage> &pair1, const  pair<int, Personnage> &pair2) {
		return pair1.first < pair2.first;
	}
};

/////////Dijkstra
typedef pair<int, Personnage> pairLiee; //typedef pair<pair<Personnage, int>, pair<Personnage,int>> pairLiee;
void trouverChaineContacts(Personnage nom1, Personnage nom2) {
	

	vector<Personnage> grapheLocal;
	grapheLocal = parcourirPersonnages(nom1, grapheLocal);
	static const size_t vertices = grapheLocal.size() - 1;
	bool sontIlsLié = false;
	for (int i = 0; i < vertices; i++)
		if (grapheLocal[i].getNom() == nom2.getNom())
			sontIlsLié = true;


	if (sontIlsLié == false)
		cout << "Il n'y a pas de chaine possible entre les deux individus\n";
	else {


		vector<pair<Personnage, Personnage> > adjacents;  //adjacents[vertices?]
		adjacents.push_back(make_pair(nom1, nom2)); //adjacent[0]
		
		priority_queue<pairLiee, vector <pairLiee>, priorite> queue; //creer un queue de pair (poids, vertex)
		vector<int> longueur(vertices, 0); //Initialise tout vertex a 0

		queue.push(make_pair(1, nom1)); //Rentrer source, mettre ditance a 1;
		longueur[0] = 1;

		vector<pair<int, Personnage>> orderedList;

		while (!queue.empty()) {  //Tant que la queue est pas vide
			Personnage u = queue.top().second; //Sortir le plus court, rendre egal a u  //Personnage u
			int poids = queue.top().first;
			orderedList.push_back(queue.top());
			queue.pop();
			pair <int, Personnage> minimum;
			
			for (int i = 0; i < u.getRelation()->getListe().size(); i++) {
				Personnage v = *u.getRelation()->getListe()[i].first;
				int poidsV = u.getRelation()->getListe()[i].second;
				

				longueur[i] = poids + poidsV;

				//if (longueur[poidsV] == 0)
				;//longueur[poidsV] = longueur[poids] + poids;

				if (i == 0 || longueur[i] < longueur[i - 1]) {
					minimum = make_pair(longueur[i], v);
					queue.push(minimum);
					if (v.getNom() == nom2.getNom())
						break;
					//if (minimum.first != queue.top().first)						
				}
			}
		}
		
		
		int position;
		for (int i = 0; i < orderedList.size(); i++) {
			if (orderedList[i].second.getNom() == nom2.getNom()) 
				position = i;
			}

		for (int i = 0; i <= position; i++) {
			if (i != position)
				cout << "Individus  -  " << orderedList[i].second.getNom() << " ==> ";
			else
				cout << "Individus  -  " << orderedList[i].second.getNom() << endl;
			
		}
			

	}
}

void enleverArcIndesirable() {

	cout << "Entrez trois caracteristique indesirable:  ex. [yeux V cheveux N genie GE]\n\n";
	
	pair<string, string> caracteristique[16];

	caracteristique[0] = make_pair("cheveux", "N");
	caracteristique[1] = make_pair("cheveux", "R");
	caracteristique[2] = make_pair("cheveux", "B");
	caracteristique[3] = make_pair("cheveux", "M");

	caracteristique[4] = make_pair("yeux", "N");
	caracteristique[5] = make_pair("yeux", "V");
	caracteristique[6] = make_pair("yeux", "G");
	caracteristique[7] = make_pair("yeux", "M");

	caracteristique[8] = make_pair("genie", "GE");
	caracteristique[9] = make_pair("genie", "GP");
	caracteristique[10] = make_pair("genie", "GC");
	caracteristique[11] = make_pair("genie", "GA");
	caracteristique[12] = make_pair("genie", "GM");
	caracteristique[13] = make_pair("genie", "GB");
	caracteristique[14] = make_pair("genie", "GInd");
	caracteristique[15] = make_pair("genie", "ER");

	string typeDonnee[3];
	string caracteristiqueDonnee[3];
	bool carExiste[3];
	
	cin >> typeDonnee[0] >> caracteristiqueDonnee[0] >> typeDonnee[1] >> caracteristiqueDonnee[1] >> typeDonnee[2] >> caracteristiqueDonnee[2];
	for (int i = 0; i < 3; i++) {
		pair<string, string > pair = make_pair(typeDonnee[i], caracteristiqueDonnee[i]);
		for (int j = 0; j < sizeof(caracteristique); j++);
			if (pair.first.compare(caracteristique[i].first) && pair.second.compare(caracteristique[i].second))
				carExiste[i] = true;
	}

	if (carExiste[0] == true && carExiste[1] == true && carExiste[2] == true)
		cout << "Les caracteristiques rentrees sont valide\n\n";
	else
		cout << "Certaines ou toutes caracteristiques sont invalides\n";

	cout << "\nCaracteristique indesirable:  \n";
	for (int i = 0; i < 3; i++) 
		if (carExiste[i] == true)
			cout << typeDonnee[i] << " " << caracteristiqueDonnee[i] << " ";
	cout << endl << endl;
}

void afficherGrapheCaracteristique() {
	enleverArcIndesirable();
}

void afficherMeilleureChaine() {
	Personnage nom1;
	Personnage nom2;
	for (int i = 0; i < listePersonnage.size(); i++)
	{
		if (listePersonnage[i].getMystere() == true && nom1.getNom() == "") {
			nom1 = listePersonnage[i];
		}
		else if (listePersonnage[i].getMystere() == true) {
			nom2 = listePersonnage[i];
		}
	}
	
	cout << "La meilleur chaine est : ";
	trouverChaineContacts(nom1, nom2);
}

void afficherCarateristiqueIndesirable() {

}

void afficherResultat() {
	afficherGrapheCaracteristique();
	afficherMeilleureChaine();
	cout << "Nombres de questions posees par l'agent : " << nombreQuestion << endl;
	if (aTrouverLesMysteres == false) {
		for (int i = 0; i < listePersonnage.size(); i++)
		{
			if (listePersonnage[i].getMystere() == true) {
				cout << listePersonnage[i].getNom() << " n'as pas ete decouvert.\n";
			}
		}
	}
	else {
		for (int i = 0; i < listePersonnage.size(); i++)
		{
			if (listePersonnage[i].getMystere() == true) {
				cout << listePersonnage[i].getNom() << " a ete decouvert.\n";
			}
		}
	}
	afficherCarateristiqueIndesirable();
}

int main()
{
	string fichierRelation;
	string fichierPersonnage;
	string choixOption;
	bool a = false;
	bool c = false;
	while ((choixOption != "e") && (choixOption != "Quitter")) {
		menu();
		cin >> choixOption;
		cout << endl;
		if (choixOption == "a") {
			cout << "Saisir le nom du fichier (avec .txt) Personnage : \n";
			cin >> fichierPersonnage;
			//fichierPersonnage = "Individus.txt";
			cout << endl << "Saisir le nom du fichier (avec .txt) Relation : \n";
			cin >> fichierRelation;
			cout << endl;
			//fichierRelation = "Relations.txt";
			try { creerReseauSocial(fichierPersonnage, fichierRelation); }
			catch (string error) { cout << error; }
			a = true;
		}

		if (choixOption == "b" && a == true) {
			afficherReseauSocial();
		}
		else if (choixOption == "b" && a != true) { cout << "Il faut d'abord choisir l'option 'A' pour lire les fichiers\n"; }
		if(choixOption == "c" && a == true){
			identifierIndividus();
			c = true;
		}
		else if (choixOption == "c" && a != true) { cout << "Il faut d'abord choisir l'option 'A' pour lire les fichiers\n"; }
		if(choixOption == "d" && c ==true){
			afficherResultat();
		}
		else if (choixOption == "d" && c != true) { cout << "Il faut d'abord choisir l'option 'C' pour jouer au jeu et obtenir des resultats\n"; }
		else if(choixOption!="a" &&choixOption != "b" &&choixOption != "c" &&choixOption != "d") { cout << choixOption << " n'est pas une option valide\n"; }
	}
    return 0;
}
