///////////////////////////////////////////////////////////
//  TP4_Tests.h
//  Implementation of the Class TP4_Tests
//  Created on:      12-mars-2018 10:42:32
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_8F5DA6E7_D3AF_4553_9518_33D2FA7BE423__INCLUDED_)
#define EA_8F5DA6E7_D3AF_4553_9518_33D2FA7BE423__INCLUDED_

#include "Objet3DComposite.h"
#include "Objet3DTransform.h"

class TP4_Tests
{

public:
	TP4_Tests();
	virtual ~TP4_Tests();

	void testComposite();
	void testDecorator();

	// Methode permettant d'imprimer un Objet3D sur un stream
	virtual void outToStream(const AbsObjet3D& obj, std::string indent, std::ostream& o) const;

private:
	Objet3DComposite m_objet;
	// Objet3DTransform m_objet_proxy;

};
#endif // !defined(EA_8F5DA6E7_D3AF_4553_9518_33D2FA7BE423__INCLUDED_)
