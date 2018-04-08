///////////////////////////////////////////////////////////
//  Objet3DPart.h
//  Implementation of the Class Objet3DPart
//  Created on:      12-mars-2018 10:42:05
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_9DB65DC2_FBFC_4180_8428_6F8FA7ACA1CE__INCLUDED_)
#define EA_9DB65DC2_FBFC_4180_8428_6F8FA7ACA1CE__INCLUDED_

#include "AbsObjet3D.h"

class Objet3DPart : public AbsObjet3D
{

public:
	Objet3DPart();
	explicit Objet3DPart(const Triangle& t);
	Objet3DPart(const Objet3DPart& mdd);
	virtual ~Objet3DPart();
	virtual Objet3DPart* cloner(void) const;

	// Interface de gestion des enfants dans le patron composite
	virtual Objet3DIterator begin();
	virtual Objet3DIterator end();
	virtual Objet3DIterator_const cbegin() const;
	virtual Objet3DIterator_const cend() const;
	virtual void addChild(const AbsObjet3D&);
	virtual Objet3DIterator_const removeChild(Objet3DIterator_const);

	// Interface de gestion des triangles definissant l'objet
	virtual TriangleIterator triangle_begin();
	virtual TriangleIterator triangle_end();
	virtual TriangleIterator_const triangle_cbegin() const;
	virtual TriangleIterator_const triangle_cend() const;
	virtual void addTriangle(const Triangle&);
	virtual TriangleIterator_const removeTriangle(TriangleIterator_const);

private:
	TriangleContainer m_triangles;
};
#endif // !defined(EA_9DB65DC2_FBFC_4180_8428_6F8FA7ACA1CE__INCLUDED_)
