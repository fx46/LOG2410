///////////////////////////////////////////////////////////
//  TriangleProxyIterator.h
//  Implementation of the Class TriangleProxyIterator
//  Created on:      12-mars-2018 22:00:28
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_F0C16EB1_B2AA_4071_9F1C_4CC9F4A39647__INCLUDED_)
#define EA_F0C16EB1_B2AA_4071_9F1C_4CC9F4A39647__INCLUDED_

#include <iterator>
#include <memory>

#include "Triangle.h"

// Definition d'une classe generique d'iterateur sur un vecteur de triangles.
// L'iterateur conserve de facon interne un iterateur sur un triangle original
// et une copie locale du triangle.
// Si une transformation est definie, la copie locale contient une version transformee
// du triangle original.
template <typename IterTy> class
TriangleProxyIterator_impl : public std::iterator<std::random_access_iterator_tag, size_t>
{

public:
	TriangleProxyIterator_impl<IterTy>(IterTy& it, IterTy& ite, const class Objet3DTransform* transform = nullptr) 
		: m_iter(it), m_iterEnd(ite), m_transform(transform) { loadCacheTransform(); };
	TriangleProxyIterator_impl<IterTy>(const TriangleProxyIterator_impl<IterTy>& mdd) 
		: m_iter(mdd.m_iter), m_iterEnd(mdd.m_iterEnd), m_transform(mdd.m_transform),m_triangleCache(mdd.m_triangleCache) {};

	operator IterTy() const { return m_iter; };
	const TriangleProxyIterator_impl<IterTy>& operator++() { ++m_iter; loadCacheTransform(); return *this; }
	TriangleProxyIterator_impl<IterTy> operator++(int) { TriangleProxyIterator_impl<IterTy> itertmp(*this); ++m_iter; loadCacheTransform(); return itertmp; }
	const TriangleProxyIterator_impl<IterTy>& operator--() { --m_iter; loadCacheTransform(); return *this; }
	TriangleProxyIterator_impl<IterTy> operator--(int) { TriangleProxyIterator_impl<IterTy> itertmp(*this); --m_iter; loadCacheTransform(); return itertmp; }
	bool operator==(const TriangleProxyIterator_impl<IterTy>& rhs) const { return m_iter == rhs.m_iter; }
	bool operator!=(const TriangleProxyIterator_impl<IterTy>& rhs) const { return !(m_iter == rhs.m_iter); }
	const Triangle& operator*() const { return m_triangleCache; }
	const Triangle* operator->() const { return &m_triangleCache; }
	const TriangleProxyIterator_impl<IterTy>& operator+=(size_t s) { m_iter += s; loadCacheTransform(); return *this; }
	const TriangleProxyIterator_impl<IterTy>& operator-=(size_t s) { m_iter -= s; loadCacheTransform(); return *this; }

	const class Objet3DTransform* getTransform(void) const { return m_transform; }
	void setTransform(const class Objet3DTransform* transform) { m_transform = transform; loadCacheTransform(); }

private:
	void loadCacheTransform(void);

	Triangle m_triangleCache;
	IterTy m_iter;
	IterTy m_iterEnd;

	// L'objet associé à ce pointeur n'est pas gere par la classe.
	// La transformation est injecte dans l'iterateur.
	const class Objet3DTransform* m_transform;
};

typedef std::vector<Triangle> TriangleContainer;

typedef TriangleProxyIterator_impl<TriangleContainer::const_iterator> TriangleIterator_const;
typedef TriangleProxyIterator_impl<TriangleContainer::iterator> TriangleIterator;

#endif