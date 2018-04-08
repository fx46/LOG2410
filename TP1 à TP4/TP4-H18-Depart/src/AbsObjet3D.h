///////////////////////////////////////////////////////////
//  AbsObjet3D.h
//  Implementation of the Class AbsObjet3D
//  Created on:      12-mars-2018 10:43:12
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_E5457525_34F5_4f8d_9391_101D9DE26E42__INCLUDED_)
#define EA_E5457525_34F5_4f8d_9391_101D9DE26E42__INCLUDED_

#include <vector>
#include <memory>
#include <string>
#include <iostream>

#include "Objet3DIterator.h"
#include "TriangleProxyIterator.h"

class AbsObjet3D
{

public:
	AbsObjet3D() = default;
	virtual ~AbsObjet3D() {};
	virtual AbsObjet3D* cloner(void) const = 0;

	// Interface de gestion des enfants dans le patron composite
	virtual Objet3DIterator begin() = 0;
	virtual Objet3DIterator end() = 0;
	virtual Objet3DIterator_const cbegin() const = 0;
	virtual Objet3DIterator_const cend() const = 0;
	virtual void addChild( const AbsObjet3D& ) = 0;
	virtual Objet3DIterator_const removeChild(Objet3DIterator_const) = 0;

	// Interface de gestion des triangles definissant l'objet
	virtual TriangleIterator triangle_begin() = 0;
	virtual TriangleIterator triangle_end() = 0;
	virtual TriangleIterator_const triangle_cbegin() const = 0;
	virtual TriangleIterator_const triangle_cend() const = 0;
	virtual void addTriangle(const Triangle&) = 0;
	virtual TriangleIterator_const removeTriangle(TriangleIterator_const) = 0;
};

#endif // !defined(EA_E5457525_34F5_4f8d_9391_101D9DE26E42__INCLUDED_)
