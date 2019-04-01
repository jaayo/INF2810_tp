#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "MotDePasse.h"

using namespace std;

#define _GLIBCXX_USE_CXX11_ABI 0

vector<char> lowerCase;
vector<char> upperCase;

void afficherLeCheminParcouru() {


}

/*void afficherLeDernierEvenement() {
bool siGrouffre; // "Cette porte n'est pas un gouffre", "Cette porte est un gouffre, retour � Porte1";
cout << "Evenement " << Evenement << endl;
cout << "a. Porte" << numeroPorte << endl << cout << "b. ";
int i = 0;
for (i; i < nbrPorte - 1; i++)
cout << "{" << motDePasse << ", Porte" << i << "," << validation << "}, " << endl;
cout << "{" << motDePasse << ", Porte" << i + 1 << "," << validation << "}" << endl;
cout << "c. " << siGouffre << endl;


}*/

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
	ifstream FichierPorte(fichierPorte, ios::in);
	string temp;

	lowerCase.push_back('a');
	lowerCase.push_back('b');
	lowerCase.push_back('c');
	lowerCase.push_back('d');
	lowerCase.push_back('e');
	lowerCase.push_back('f');

	upperCase.push_back('A');
	upperCase.push_back('B');
	upperCase.push_back('C');
	upperCase.push_back('D');
	upperCase.push_back('E');
	upperCase.push_back('F');

	vector<MotDePasse*> mdpListe;

typedef struct node
{
    int data;
    vector<struct node *> Max;
}	Node;


	if (FichierPorte) {
		if (!FichierPorte.fail()) {
			int i = 0;
			//getline(FichierPorte, temp);
			while (!ws(FichierPorte).eof()) {
				FichierPorte >> temp;
				MotDePasse* mdpTemp = new MotDePasse();
				//Multimap? , multilinkedList
				char temp = FichierPorte.get();
				char character = "";
				char lastCharacter;
				while(character != "\n"){
					if (character == " ");
					else {
						character = FichierPorte.get();
						lastCharacter = character;
						temp = FichierPorte.get();
						temp = FichierPorte.get();
						character = FichierPorte.get();
						if (character == ",")
							//Link lastcharacter and "";
						if (character == "a" || character == "b" || character == "c" || character == "d" || character == "e" || character == "f"){													
							char terminal = character;
							character = FichierPorte.get();
							if (character == ",");
								//link lastCharater and terminal
							else {
								//link lastCharacter and terminal + character
							}
						}
					}

				}
				temp = getchar();
				/*
				if (temp[0] != '{' && temp[0] != '}') {
					mdpTemp->setSource(temp[0]);
					for (int j = 0; j < temp.length(); j++)
					{
						if (temp[3] != ',' && temp[3] != upperCase[j]) {
							mdpTemp->setTerminal(temp[3]);
						}
						else if (temp[3] != ',') {
							mdpTemp->setDestination(new MotDePasse(temp[3], nullptr, ' '));
							break;
						}
						else if (temp[3] == ',') {
							mdpTemp->setStatus(true);
							break;
						}
						if (temp[4] == ',') {
							mdpTemp->setStatus(true);
							break;
						}
						else if(temp[3] != ','){
							mdpTemp->setDestination(new MotDePasse(temp[4], nullptr, ' '));
							break;
						}
					}
				}
				*/

				/*getline(FichierPorte, temp,'}');
				size_t found = temp.find_first_of("->{}");
				while (found != string::npos) {
					temp[found] = ' ';
					found = temp.find_first_of("->{}", found + 1);
				}*/
				/*for (int j = 0; j < temp.length; j++)
				{
					if (temp[j] == '{' || temp[j] == '}' || temp[j] == '-' || temp[j] == '>') j++;
					else {
						for (int k = 0; k < upperCase.size(); k++)
						{
							if (temp[j] == upperCase[k] && mdp->getSource() == ' ') {
								mdp->setSource(temp[j]);
							}
							else if (temp[j] == lowerCase[k]) {
								mdp->setDestination(temp[j]);
							}
							else {
								mdp->setTerminal(temp[j]);
								if (mdp->getTerminal() == mdp->getSource())
									mdp->setLoop(true);
							}
						}
					}
				}*/


				//Sauvegarder porte possible a ouvrir et leur mot de passe
				//vector<pair<string, string>> portes;
				//getline(FichierPorte, temp, '{');
				cout << temp << endl;
				mdpListe.push_back(mdpTemp);
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
			//afficherLeDernierEvenement();
			cout << "Quelle porte voulez vous ouvrir?	(ex. Porte1)" << endl;
			cin >> porteChoisi;
			porteChoisi += ".txt";
			lirePorte(porteChoisi);

			//	ouvrirPorte(porteChoisi);
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
	return 0;
}

