///////////////////////////////////////////////////////////
//  Objet3DTransform.h
//  Implementation of the Class Objet3DTransform
//  Created on:      12-mars-2018 10:42:29
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_2B1DE59F_2DAD_4838_A385_A7B4A90F464B__INCLUDED_)
#define EA_2B1DE59F_2DAD_4838_A385_A7B4A90F464B__INCLUDED_

#include "AbsObjet3D.h"

class Objet3DTransform : public AbsObjet3D
{

public:
	Objet3DTransform(Objet3DIterator& cible, float dx = 0.0, float dy = 0.0, float dz = 0.0);
	Objet3DTransform(const Objet3DTransform& mdd);
	virtual Objet3DTransform* cloner(void) const;
	virtual ~Objet3DTransform();

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

	// Methode appliquant la transformation
	virtual void transform(const Triangle& orig, Triangle& dest) const;

protected:
	Objet3DIterator m_objet_cible;
	float m_delta[3];
};

#endif // !defined(EA_2B1DE59F_2DAD_4838_A385_A7B4A90F464B__INCLUDED_)
