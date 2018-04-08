#include "TransformStack.h"
#include "Objet3DTransform.h"

// Instancier le vecteur de stockage des transformations
std::vector<std::unique_ptr<Objet3DTransform>> TransformStack::m_transforms;

Objet3DTransform & TransformStack::getCurrent(void)
{
	// Si la pile de transformation est vide faire
	//    - Pousser une transformation vide sur la pile
	// Retourner la derniere transformation de la pile
	if (m_transforms.size() == 0) {
		m_transforms.push_back(std::unique_ptr<Objet3DTransform>(new Objet3DTransform()));
	}
	return *m_transforms.back();
}

void TransformStack::pushCurrent(void)
{
	// Si la pile de transformation n'est pas vide faire
	//    - Pousser la dernière transformation sur la pile
	// Sinon faire
	//    - Pousser une transformation vide sur la pile
	if (m_transforms.size() != 0) {
		TransformStack::push(*m_transforms.back());
	}
	else {
		TransformStack::push(Objet3DTransform());
	}
}

void TransformStack::push(const Objet3DTransform & t)
{
	// Pousser la transformation recue en parametre sur la pile
	m_transforms.push_back(std::unique_ptr<Objet3DTransform>(new Objet3DTransform(t)));
}

void TransformStack::pop(void)
{
	// Si la pile n'est pas vide faire
	//    - Retirer la derniere transformation de sur la pile
	if (m_transforms.size() != 0) {
		m_transforms.pop_back();
	}
}
