#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <tuple>


using namespace std;

#define _GLIBCXX_USE_CXX11_ABI 0



void afficherLeCheminParcouru() {

	ifstream file("Affichage.txt");

	if (file.is_open())
		cout << file.rdbuf();
	else
		cout << "Ya qqchose de bizarre qui sest passee";
}


void afficherLeDernierEvenement() {
	/*bool estGouffre;

	cout << "Evenement " << Evenement << endl;
	cout << "a. Porte" << numeroPorte << endl << cout << "b. ";
	int i = 0;
	for (i; i < nbrPorte - 1; i++)
		cout << "{" << motDePasse << ", Porte" << i << "," << validation << "}, " << endl;
	cout << "{" << motDePasse << ", Porte" << i + 1 << "," << validation << "}" << endl;
	cout << "c. ";	gouffre(estGouffre);
	out << endl;
	*/

	ifstream file("Affichage.txt");

	if (file.is_open())
	{
		int numberOfLines = 0;
		string temp;

		while (!ws(file).eof()) {
			//Sauvegarder porte possible a ouvrir et leur mot de passe
			//vector<pair<string, string>> portes;
			getline(file, temp);
			numberOfLines++;
		}

		for (int i = 0; i < numberOfLines; i++)
			getline(file, temp);
		for (int i = 0; i < 4; i++) {
			getline(file, temp);
			cout << temp;

		}
	}
}

void gouffre(bool estGouffre) {
	if (estGouffre)
		cout << "Cette porte est un gouffre, retour à Porte1." << endl;
	else
		cout << "Cette porte n'est pas un gouffre." << endl;
}

void ouvrirPorte(string fichier) {

	string numeroPorte = fichier;
	fichier += ".txt";
	ofstream file("Affichage.txt");

	if (!file.is_open())
		cout << "Ya qqchose de bizarre qui sest passee";
	else {

	bool estGouffre;
	vector<tuple<string, string, bool>> portes;
	int nbrPorte = 2;
	file << "Evenement ";
	if (fichier == "Boss.txt")
		file << "Boss" << endl;
	else
		file << "Porte" << endl;
	file << "a. " << numeroPorte << endl << "b. ";
	int i = 0;
	for (int i = 0; i < nbrPorte - 1; i++)
		file << "{" << get<0>(portes[i]) << ", " << get<1>(portes[i]) << "," << get<2>(portes[i]) << "}, " << endl;
	i++;
	file << "{" << get<0>(portes[i]) << ", " << get<1>(portes[i]) << "," << get<2>(portes[i]) << "} " << endl;
	file << "c. ";	gouffre(estGouffre);
	file << endl;
}
}

void genererAutomate() {


}


void concatenerLangage() {

	

}


void affronterBoss() {
	ifstream FichierBoss("Boss.txt", ios::in);

	if (FichierBoss) {
		if (!FichierBoss.fail()) {
			string porteBoss;
			while (FichierBoss >> porteBoss);
			//				lirePorte(porteBoss);
		}
	}
	else {
		string error = "On arrive pas a ouvrir le fichier \n";
		throw error;
	}
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
	ifstream FichierPorte(fichierPorte, ios::in);
	string temp;
	if (FichierPorte) {
		if (!FichierPorte.fail()) {
			int i = 0;
			getline(FichierPorte, temp);
			
			getline(FichierPorte, temp);
			while (!ws(FichierPorte).eof()) {
				//Sauvegarder porte possible a ouvrir et leur mot de passe
				//vector<pair<string, string>> portes;
				getline(FichierPorte, temp,',');
				cout << temp;
				//FichierPorte >> portes[i].first >> portes[i].second;
				i++;
			}

			cout << "Les fichiers ont ete lu correctement.\n";
			FichierPorte.close();
		}
	}
	else {
		string error = "On arrive pas a ouvrir le fichier \n";
		throw error;
	}
}


int main()
{
	string porteChoisie;
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
			//afficherLeDernierEvenement();
			cout << "Quelle porte voulez vous ouvrir?	(ex. Porte1)" << endl;
			cin >> porteChoisie;
			ouvrirPorte(porteChoisie);

			vector<tuple<string, string, bool>> portes;
			bool estGouffre = true;
			for (int i = 0; i < portes.size(); i++)
			{
				if (get<2>(portes[i]) == true) //portes.second = estValide
					estGouffre = false;
			}
			afficherLeDernierEvenement();

			if (estGouffre = true)
				choixOption = a;
			

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
	return 0;
}

