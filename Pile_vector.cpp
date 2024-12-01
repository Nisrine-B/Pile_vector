// Pile_vector.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "Header.h"
#include "PileV.h"

int main()
{
	locale::global(locale("fr_FR.UTF-8"));

	//création de la 1ère pile d'entiers
	PileV<int> pile_entiers1(11);

	cout << "\nAlimentation de la pile\n";
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < 4; ++i) {
		int randomValue = rand() % 100;
		pile_entiers1.push(randomValue);
		cout << "Ajouté : " << randomValue;
		Rl;
	}
	Rl;

	//size
	cout << "La pile 1 contient : " << pile_entiers1.size() << " éléments.\n";
	//affichage
	cout << "Affichage Pile 1\n";
	pile_entiers1.print();


	cout << "On va essayer de créer une pile avec un size négatif pour voir ce qui se passe.\n";
	//création de la 2ème pile d'entiers
	PileV<int> pile_entiers2(-6);
	//inverser la 1ère pile et la mettre dans la 2ème pile
	pile_entiers2 = pile_entiers1.reverse();


	//affichage
	cout << "Affichage Pile 2\n"; 
	pile_entiers2.print();


	cout << "\nOn dépile la pile 2 . Elément depilé : " << pile_entiers2.pop();
	cout << "\nAffichage après dépilement\n";
	pile_entiers2.print();

	cout << "\n\n\n****************************************Fin Programme ************************************************\n\n";
	return 0;
}
