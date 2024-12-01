#pragma once
#include "Header.h"

template <class C>
class PileV
{
private:
	vector<C> stack_elements;
public:
	PileV(int size);
	PileV(PileV<C> const& a_copier);

	void merge(PileV<C> const& a_fusionner);
	void print() const;
	void push(C val);
	C pop();
	size_t size()const;
	PileV<C> reverse()const;

	PileV<C> operator=(PileV<C> const& a_copier);
};

template<class C>
inline PileV<C>::PileV(int size)
{
	//c'est mieux de r�server de l'espace avant pour les �l�ments � stocker
	// pour qu'on �vite la r�allocation de m�moire � chaque 'push'
	//�a am�liore la performance du programme
	try
	{
		if (size < 0)
			throw runtime_error("PileV(int size) : size pass� est n�gatif");
		stack_elements.reserve(static_cast<size_t>(size));
	}
	catch (const exception& e)
	{
		Rl; wcerr << E_YELLOW << "Attention! " << e.what() << E_RESET; Rl; Rl;
	}
	
}

template<class C>
inline PileV<C>::PileV(PileV<C> const& a_copier)
{
	//assigne � la PileV courante le contenu de la PileV 'a_copier'
	//le contenu pr�c�dent de la PileV courante sera �cras�
	stack_elements.assign(a_copier.stack_elements.begin(), a_copier.stack_elements.end());
}

template<class C>
inline void PileV<C>::merge(PileV<C> const& a_fusionner)
{
	//copier les �l�ments de 'a_fusionner' vers la fin de la PileV courante 'this'
	copy(a_fusionner.stack_elements.begin(), a_fusionner.stack_elements.end(), back_inserter(stack_elements));
}

template<class C>
void PileV<C>::print() const
{
	for (auto it = stack_elements.rbegin(); it != stack_elements.rend(); ++it) {
		cout << "| " << BEIGE << setw(10) << *it << RESET << setw(10) << " |" << endl; 
	}

	cout << "----------------------\n\n"; 
}


template<class C>
inline void PileV<C>::push(C val)
{
	stack_elements.push_back(val);
}

template<class C>
inline C PileV<C>::pop()
{
	//stocker le sommet de la PileV (le dernier �l�ment du vecteur) � part
	C element_to_pop = stack_elements.back();
	//d�piler
	stack_elements.pop_back();
	//retourner l'�l�ment d�pil�
	return element_to_pop;
}

template<class C>
inline size_t PileV<C>::size() const
{
	return stack_elements.size();
}

template<class C>
PileV<C> PileV<C>::reverse() const
{
	//inverse la PileV dans une nouvelle PileV. On retourne cette derni�re.
 	PileV<C> stack_reversed(stack_elements.size());
	reverse_copy(stack_elements.begin(), stack_elements.end(), back_inserter(stack_reversed.stack_elements));
	return stack_reversed;
}

template<class C>
inline PileV<C> PileV<C>::operator=(PileV<C> const& a_copier)
{
	stack_elements = a_copier.stack_elements;	
	return *this;
}
