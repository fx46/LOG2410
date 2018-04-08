///////////////////////////////////////////////////////////
//  Objet3DTransform.cpp
//  Implementation of the Class Objet3DTransform
//  Created on:      12-mars-2018 10:42:30
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Objet3DTransform.h"

void TriangleProxyIterator_impl<TriangleContainer::const_iterator>::loadCacheTransform(void)
{
	if (m_iter != m_iterEnd)
	{
		if (m_transform != nullptr)
			m_transform->transform(*m_iter, m_triangleCache);
		else
			m_triangleCache = *m_iter;
	}
}

void TriangleProxyIterator_impl<TriangleContainer::iterator>::loadCacheTransform(void)
{
	if (m_iter != m_iterEnd)
	{
		if (m_transform != nullptr)
			m_transform->transform(*m_iter, m_triangleCache);
		else
			m_triangleCache = *m_iter;
	}
}


Objet3DTransform::Objet3DTransform(Objet3DIterator& cibleIter, float dx, float dy, float dz)
    : m_objet_cible(cibleIter)
{
	m_delta[0] = dx;
	m_delta[1] = dy;
	m_delta[2] = dz;
}

Objet3DTransform::Objet3DTransform(const Objet3DTransform & mdd)
	: m_objet_cible(mdd.m_objet_cible)
{
	m_delta[0] = mdd.m_delta[0];
	m_delta[1] = mdd.m_delta[1];
	m_delta[2] = mdd.m_delta[2];
}

Objet3DTransform * Objet3DTransform::cloner(void) const
{
	// Construire et retourner un nouvel objet identique a this
	// A COMPLETER
	return (new Objet3DTransform(*this));
}

Objet3DTransform::~Objet3DTransform(){

}

Objet3DIterator Objet3DTransform::begin()
{
	// Delegue a l'objet cible la construction d'un iterateur au debut du vecteur des enfants
	// et retourne le resultat
	// A COMPLETER
	return  m_objet_cible->begin();
}

Objet3DIterator Objet3DTransform::end()
{
	// Delegue a l'objet cible la construction d'un iterateur apres la fin du vecteur des enfants
	// et retourne le resultat
	// A COMPLETER
	return  m_objet_cible->end();
}

Objet3DIterator_const Objet3DTransform::cbegin() const
{
	// Delegue a l'objet cible la construction d'un iterateur constant au debut du vecteur des enfants
	// et retourne le resultat
	// A COMPLETER
	return  m_objet_cible->cbegin();
}

Objet3DIterator_const Objet3DTransform::cend() const
{
	// Delegue a l'objet cible la construction d'un iterateur constant apres la fin du vecteur des enfants
	// et retourne le resultat
	// A COMPLETER
	return  m_objet_cible->cend();
}

void Objet3DTransform::addChild(const AbsObjet3D & obj)
{
	// Delegue a l'objet cible l'ajout de l'objet dans le vecteur des enfants
	// A COMPLETER
	m_objet_cible->addChild(obj);
}

Objet3DIterator_const Objet3DTransform::removeChild(Objet3DIterator_const iter)
{
	// Delegue a l'objet cible l'effacement de l'objet pointe par l'iterateur du vecteur des enfants
	// Retourne l'iterateur resultant de l'operation
	// A COMPLETER
	return m_objet_cible->removeChild(iter);
}

TriangleIterator Objet3DTransform::triangle_begin()
{
	// Construit un iterateur local sur le debut des triangles en utilisant la methode de l'objet cible
	// Injecte l'objet this comme transformation dans l'iterateur
	// Retourne le resultat
	// A COMPLETER
	return TriangleProxyIterator_impl<TriangleContainer::iterator>(
		(TriangleContainer::iterator)m_objet_cible->triangle_begin(),
		(TriangleContainer::iterator)m_objet_cible->triangle_end(),
		this
	);
}

TriangleIterator Objet3DTransform::triangle_end()
{
	// Construit un iterateur local apres la fin des triangles en utilisant la methode de l'objet cible
	// Injecte l'objet this comme transformation dans l'iterateur
	// Retourne le resultat
	// A COMPLETER
	return TriangleProxyIterator_impl<TriangleContainer::iterator>(
		(TriangleContainer::iterator)m_objet_cible->triangle_end(),
		(TriangleContainer::iterator)m_objet_cible->triangle_end(),
		this
	);
}

TriangleIterator_const Objet3DTransform::triangle_cbegin() const
{
	// Construit un iterateur local constant sur le debut des triangles en utilisant la methode de l'objet cible
	// Injecte l'objet this comme transformation dans l'iterateur
	// Retourne le resultat
	// A COMPLETER
	return TriangleProxyIterator_impl<TriangleContainer::const_iterator>(
		(TriangleContainer::const_iterator)m_objet_cible->triangle_cbegin(),
		(TriangleContainer::const_iterator)m_objet_cible->triangle_cend(),
		this
	);
}

TriangleIterator_const Objet3DTransform::triangle_cend() const
{
	// Construit un iterateur local constant apres la fin des triangles en utilisant la methode de l'objet cible
	// Injecte l'objet this comme transformation dans l'iterateur
	// Retourne le resultat
	// A COMPLETER
	return TriangleProxyIterator_impl<TriangleContainer::const_iterator>(
		(TriangleContainer::const_iterator)m_objet_cible->triangle_cend(),
		(TriangleContainer::const_iterator)m_objet_cible->triangle_cend(),
		this
	);
}

void Objet3DTransform::addTriangle(const Triangle & tri)
{
	// Delegue a l'objet cible la tache d'inserer le triangle dans le vecteur de triangles
	// A COMPLETER
	m_objet_cible->addTriangle(tri);
}

TriangleIterator_const Objet3DTransform::removeTriangle(TriangleIterator_const iterTri)
{
	// Effacer le triangle pointe par l'iterateur dans le vecteur des triangles
	// retourner l'iterateur resultant de l'operation d'effacement
	// A COMPLETER
	return m_objet_cible->removeTriangle(iterTri);
}

void Objet3DTransform::transform(const Triangle & orig, Triangle & dest) const
{
	// Applique la transformation a chaque coordonnees des sommets d'un triangle
	Sommet* sommets_dest = dest.sommets();
	const Sommet* sommets_orig = orig.sommets();
	for (int i = 0; i < 3; ++i)
	{
		sommets_dest[i].x() = sommets_orig[i].x() + m_delta[0];
		sommets_dest[i].y() = sommets_orig[i].y() + m_delta[1];
		sommets_dest[i].z() = sommets_orig[i].z() + m_delta[2];
	}
}
