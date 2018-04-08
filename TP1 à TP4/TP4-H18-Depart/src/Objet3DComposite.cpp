///////////////////////////////////////////////////////////
//  Objet3DComposite.cpp
//  Implementation of the Class Objet3DComposite
//  Created on:      12-mars-2018 10:42:22
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Objet3DComposite.h"

Objet3DComposite::Objet3DComposite(){

}

Objet3DComposite::Objet3DComposite(const Objet3DComposite & mdd)
{
	for (auto iter = mdd.cbegin(); iter != mdd.cend(); ++iter)
		addChild(*iter);
}

Objet3DComposite::~Objet3DComposite(){

}

Objet3DComposite * Objet3DComposite::cloner(void) const
{
	// Construire et retourner un nouvel objet identique a this
	// A COMPLETER
	return (new Objet3DComposite(*this));
}

Objet3DIterator Objet3DComposite::begin()
{
	// Constuire et retourner un iterateur au debut des objets enfants
	// A COMPLETER
	return Objet3DIterator(m_objets.begin());
}

Objet3DIterator Objet3DComposite::end()
{
	// Constuire et retourner un iterateur apres la fin des objets enfants
	// A COMPLETER
	return Objet3DIterator(m_objets.end());
}

Objet3DIterator_const Objet3DComposite::cbegin() const
{
	// Constuire et retourner un iterateur constant au debut des objets enfants
	// A COMPLETER
	return Objet3DIterator_const(m_objets.cbegin());
}

Objet3DIterator_const Objet3DComposite::cend() const
{
	// Constuire et retourner un iterateur constant apres la fin des objets enfants
	// A COMPLETER
	return Objet3DIterator_const(m_objets.cend());
}

void Objet3DComposite::addChild(const AbsObjet3D & obj)
{
	// Constuire un nouvel objet identique a celui passe en argument par clonage
	// Inserer un pointeur unique sur l'objet construit dans le vecteur des enfants
	// A COMPLETER
	std::unique_ptr<AbsObjet3D> objet (obj.cloner());
	m_objets.push_back(std::move(objet));
}

Objet3DIterator_const Objet3DComposite::removeChild(Objet3DIterator_const iter)
{
	// Effacer l'objet pointe par l'iterateur du vecteur des enfants
	// retourner l'iterateur resultant de l'operation d'effacement
	// A COMPLETER
	m_objets.erase((Objet3DContainer::const_iterator)iter);
	return iter;
}

// Conteneur vide de triangles pour simplifier l'écriture des methodes
// qui retournent des iterateurs.
static TriangleContainer empty_container;

// Les objets composites ne gerent pas de triangles
TriangleIterator Objet3DComposite::triangle_begin()
{
	// Constuire et retourner un iterateur au debut du contenant vide de triangle
	// L'iterateur de fin doit egalement etre fourni pour construire l'iterateur sur les triangles
	// A COMPLETER
	return TriangleProxyIterator_impl<TriangleContainer::iterator>(empty_container.begin(), empty_container.end());
}

TriangleIterator Objet3DComposite::triangle_end()
{
	// Constuire et retourner un iterateur apres la fin du contenant vide de triangle
	// L'iterateur de fin doit etre fourni 2 fois pour construire l'iterateur sur les triangles
	// A COMPLETER
	return TriangleProxyIterator_impl<TriangleContainer::iterator>(empty_container.end(), empty_container.end());
}

TriangleIterator_const Objet3DComposite::triangle_cbegin() const
{
	// Constuire et retourner un iterateur constant au debut du contenant vide de triangle
	// L'iterateur de fin doit egalement etre fourni pour construire l'iterateur sur les triangles
	// A COMPLETER
	return TriangleProxyIterator_impl<TriangleContainer::const_iterator>(empty_container.cbegin(), empty_container.cend());
}

TriangleIterator_const Objet3DComposite::triangle_cend() const
{
	// Constuire et retourner un iterateur constant apres la fin du contenant vide de triangle
	// L'iterateur de fin doit etre fourni 2 fois pour construire l'iterateur sur les triangles
	// A COMPLETER
	return TriangleProxyIterator_impl<TriangleContainer::const_iterator>(empty_container.cend(), empty_container.cend());
}

void Objet3DComposite::addTriangle(const Triangle &)
{
	// Echoue silencieusement
}

TriangleIterator_const Objet3DComposite::removeTriangle(TriangleIterator_const)
{
	// Echoue silencieusement
	// Constuire et retourner un iterateur constant apres la fin du contenant vide de triangle
	// L'iterateur de fin doit etre fourni 2 fois pour construire l'iterateur sur les triangles
	// A COMPLETER
	return TriangleProxyIterator_impl<TriangleContainer::const_iterator>(empty_container.cend(), empty_container.cend());
}

