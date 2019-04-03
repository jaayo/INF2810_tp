#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <tuple>

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




void reinitialiseDonnees() {


}

void menu() {
	cout << "\n(a) Entrer dans le labyrinthe" << endl <<
		"(b) Ouvrir une porte" << endl <<
		"(c) Afficher le chemin parcouru" << endl <<
		"(d) Quitter" << endl << endl;
}



void affronterBoss() {
	//genererAutomate();

}

typedef struct node
{
	char data;
	vector<struct node *> pointeurs;
}	Node;

struct node A;
struct node A1;
struct node A2;
struct node A3;

struct node B;
struct node B1;
struct node B2;
struct node B3;

struct node C;
struct node C1;
struct node C2;

struct node D;
struct node D1;
struct node D2;

struct node E;
struct node E1;
struct node E2;

struct node F;
struct node F1;
struct node F2;

struct node S;
struct node S1;
struct node S2;
struct node S3;
struct node S4;
struct node S5;

int compteurA = 0;
int compteurB = 0;
int compteurC = 0;
int compteurD = 0;
int compteurE = 0;
int compteurF = 0;
int compteurS = 0;
int compteurMots = 0; 
vector<string> listeMots;
int compteurCaracteres = 0;
void nodeInit() {
	
	struct node* structTemp;

	*structTemp = A1;
	A.pointeurs.push_back(structTemp);
	*structTemp = A2;
	A.pointeurs.push_back(structTemp);
	*structTemp = A3;
	A.pointeurs.push_back(structTemp);

	*structTemp = B1;
	B.pointeurs.push_back(structTemp);
	*structTemp = B2;
	B.pointeurs.push_back(structTemp);
	*structTemp = B3;
	B.pointeurs.push_back(structTemp);

	*structTemp = C1;
	C.pointeurs.push_back(structTemp);
	*structTemp = C2;
	C.pointeurs.push_back(structTemp);


	*structTemp = D1;
	D.pointeurs.push_back(structTemp);
	*structTemp = D2;
	D.pointeurs.push_back(structTemp);


	*structTemp = E1;
	E.pointeurs.push_back(structTemp);
	*structTemp = E2;
	E.pointeurs.push_back(structTemp);

	*structTemp = F1;
	F.pointeurs.push_back(structTemp);
	*structTemp = F2;
	F.pointeurs.push_back(structTemp);

	*structTemp = S1;
	S.pointeurs.push_back(structTemp);
	*structTemp = S2;
	S.pointeurs.push_back(structTemp);
	*structTemp = S3;	
	S.pointeurs.push_back(structTemp);
	*structTemp = S4;
	S.pointeurs.push_back(structTemp);
	*structTemp = S5;
	S.pointeurs.push_back(structTemp);

}
vector<tuple<string, string, bool>> portes;

struct node genererAutomate(char source, char terminal) {

	if (compteurA == 1 && source == 'A')
	{
		A1.data = terminal;
		compteurA++;
		return A1;
	}

	if (compteurA == 2 && source == 'A')
	{
		A2.data = terminal;
		compteurA++;
		return A2;
	}

	if (compteurA == 3 && source == 'A')
	{
		A3.data = terminal;
		compteurA++;
		return A3;
	}


	if (compteurB == 1 && source == 'B')
	{
		B1.data = terminal;
		compteurB++;
		return B1;
	}

	if (compteurB == 2 && source == 'B')
	{
		B2.data = terminal;
		compteurB++;
		return B2;
	}

	if (compteurB == 3 && source == 'B')
	{
		B3.data = terminal;
		compteurB++;
		return B3;
	}

	if (compteurC == 1 && source == 'C')
	{
		C1.data = terminal;
		compteurC++;
		return C1;
	}

	if (compteurC == 2 && source == 'C')
	{
		C2.data = terminal;
		compteurC++;
		return C2;
	}

	if (compteurD == 1 && source == 'D')
	{
		D1.data = terminal;
		compteurD++;
		return D1;
	}

	if (compteurD == 2 && source == 'D')
	{
		D2.data = terminal;
		compteurD++;
		return D2;
	}

	if (compteurE == 1 && source == 'E')
	{
		E1.data = terminal;
		compteurE++;
		return E1;
	}

	if (compteurE == 2 && source == 'E')
	{
		E2.data = terminal;
		compteurE++;
		return E2;
	}

	if (compteurF == 1 && source == 'F')
	{
		F1.data = terminal;
		compteurF++;
		return F1;
	}

	if (compteurF == 2 && source == 'F')
	{
		F2.data = terminal;
		compteurF++;
		return F2;
	}

	if (compteurS == 1 && source == 'S')
	{
		S1.data = terminal;
		compteurS++;
		return S1;
	}
	if (compteurS == 2 && source == 'S')
	{
		S2.data = terminal;
		compteurS++;
		return S2;
	}
	if (compteurS == 3 && source == 'S')
	{
		S3.data = terminal;
		compteurS++;
		return S3;
	}
	if (compteurS == 4 && source == 'S')
	{
		S4.data = terminal;
		compteurS++;
		return S4;
	}
	if (compteurS == 5 && source == 'S')
	{
		S5.data = terminal;
		compteurS++;
		return S5;
	}
}

void linkAutomate(struct node source, char destination) {

	switch (destination) {
		case 'A':
			struct node* structTemp;
			*structTemp = A;
			source.pointeurs.push_back(structTemp);
			break;

		case 'B':
			struct node* structTemp;
			*structTemp = B;
			source.pointeurs.push_back(structTemp);
			break;

		case 'C':
			struct node* structTemp;
			*structTemp = C;
			source.pointeurs.push_back(structTemp);
			break;

		case 'D':
			struct node* structTemp;
			*structTemp = D;
			source.pointeurs.push_back(structTemp);
			break;

		case 'E':
			struct node* structTemp;
			*structTemp = E;
			source.pointeurs.push_back(structTemp);
			break;

		case 'F':
			struct node* structTemp;
			*structTemp = F;
			source.pointeurs.push_back(structTemp);
			break;

		case 'S':
			struct node* structTemp;
			*structTemp = S;
			source.pointeurs.push_back(structTemp);
			break;
	}
		

	
	return;
}

void genererMots() {

	for (int i = 0; i < S.pointeurs.size(); i++)
	{
		if (S.pointeurs[i] != nullptr && compteurCaracteres < 10 && S.data != ' ') {
			listeMots[compteurMots] += S.data;
			compteurCaracteres++;

			genererMots(*(S.pointeurs[i]));
		}
		else break;
		compteurMots++;
	}


}

void genererMots(struct node source) {

	for (int i = 0; i < source.pointeurs.size(); i++)
	{
		if (source.pointeurs[i] != nullptr && compteurCaracteres < 10 && source.data != ' ') {
			listeMots[compteurMots][compteurCaracteres] = source.data;
			compteurCaracteres++;

			genererMots(*(source.pointeurs[i]));
		}
		else if (source.data == ' ') {
			compteurMots++;
			compteurCaracteres--;
			break;
		}
	}

}

void lirePorte(string fichierPorte) {
	ifstream FichierPorte(fichierPorte, ios::in);
	nodeInit();


	if (FichierPorte) {
		if (!FichierPorte.fail()) {
			int i = 0;
			//getline(FichierPorte, temp);
			while (!ws(FichierPorte).eof()) {
				//Multimap? , multilinkedList
				char temp = FichierPorte.get();
				char character = ' ';
				char source;
				struct node nodeSource;
				while(character != '\n'){
					if (character == ' ');
					else {
						character = FichierPorte.get();
						source = character;
						temp = FichierPorte.get();
						temp = FichierPorte.get();
						character = FichierPorte.get();
						if (character == ',') {
							//Link source and ""
							genererAutomate(source, ' ');
						}
						//if (character == 'a' || character == 'b' || character == 'c' || character == 'd' || character == 'e' || character == 'f'){													
						else {	
							char terminal = character;
							character = FichierPorte.get();
							if (character == ',')
								//link source and terminal
								genererAutomate(source, terminal);
							else {
								//link source and terminal + character
								nodeSource = genererAutomate(source, terminal);
								linkAutomate(nodeSource, character);
							}
						}
					}
					temp = FichierPorte.get();
				}
				if(temp != '}') temp = FichierPorte.get(); //lire }
				
				FichierPorte >> get<0>(portes[i]) >> get<1>(portes[i]); 
				get<2>(portes[i]) = false;

				i++;

			}

			verifierMDP(portes);
			
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

