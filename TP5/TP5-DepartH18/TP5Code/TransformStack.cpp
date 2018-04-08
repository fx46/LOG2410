#include "TransformStack.h"
#include "Objet3DTransform.h"

// Instancier le vecteur de stockage des transformations

Objet3DTransform & TransformStack::getCurrent(void)
{
	// Si la pile de transformation est vide faire
	//    - Pousser une transformation vide sur la pile
	// Retourner la derniere transformation de la pile

	return Objet3DTransform();
}

void TransformStack::pushCurrent(void)
{
	// Si la pile de transformation n'est pas vide faire
	//    - Pousser la dernière transformation sur la pile
	// Sinon faire
	//    - Pousser une transformation vide sur la pile
}

void TransformStack::push(const Objet3DTransform & t)
{
	// Pousser la transformation recue en parametre sur la pile
}

void TransformStack::pop(void)
{
	// Si la pile n'est pas vide faire
	//    - Retirer la derniere transformation de sur la pile
}
