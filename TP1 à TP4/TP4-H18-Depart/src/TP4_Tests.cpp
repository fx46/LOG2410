///////////////////////////////////////////////////////////
//  TP4_Tests.cpp
//  Implementation of the Class TP4_Tests
//  Created on:      12-mars-2018 10:42:32
//  Original author: p482457
///////////////////////////////////////////////////////////

#include<iostream>

#include "TP4_Tests.h"

#include "Sommet.h"
#include "Triangle.h"
#include "Objet3DPart.h"

TP4_Tests::TP4_Tests(){
}

TP4_Tests::~TP4_Tests(){
}

void TP4_Tests::testComposite(){
	// Definir quelques sommets
	Sommet s1;
	Sommet s2(1.0);
	Sommet s3(1.0, 1.0);
	Sommet s4(0.0, 1.0);
	Sommet s5(0.0, 1.0, 1.0);
	Sommet s6(1.0, 1.0, 1.0);

	// Definir quelques triangles
	Triangle t1(s1, s2, s3);
	Triangle t2(s2, s3, s4);
	Triangle t3(s3, s4, s5);
	Triangle t4(s4, s5, s6);

    // Definir des morceaux d'objets
	std::cout << "Tests du patron COMPOSITE" << std::endl;
	std::cout << "=========================" << std::endl << std::endl;
	Objet3DPart part1(t1);
	outToStream(part1, "part1   ", std::cout);
	Objet3DPart part2(t2);
	part2.addTriangle(t3);
	part2.addTriangle(t1);
	part2.addTriangle(t4);
	outToStream(part2, "part2   ", std::cout);
	Objet3DPart part3(t4);
	outToStream(part3, "part3   ", std::cout);
	Objet3DPart part4(t2);
	part4.addTriangle(t4);
	outToStream(part4, "part4   ", std::cout);

	// Definir un objet composite
	std::cout << std::endl << "=========================" << std::endl;
	Objet3DComposite composit1;
	composit1.addChild(part2);
	composit1.addChild(part3);
	outToStream(composit1, "composit1   ", std::cout);

    // Cloner un objet composite
	std::cout << std::endl << "=========================" << std::endl << std::endl;
	Objet3DComposite* composit1Clone = composit1.cloner();
	outToStream(*composit1Clone, "composit1Clone   ", std::cout);

    // Definir un composite a plusieur niveaux
	std::cout << std::endl << "=========================" << std::endl << std::endl;
	Objet3DComposite composit2(composit1);
	composit2.addChild(composit1);
	m_objet.addChild(part2);
	m_objet.addChild(part1);
	m_objet.addChild(composit1);
	m_objet.addChild(composit2);
	m_objet.addChild(part4);
	outToStream(m_objet, "m_objet   ", std::cout);
}

void TP4_Tests::testDecorator()
{
	// Recuperer un iterateur sur la Part2
	Objet3DIterator m_objetIter(m_objet.begin());
	Objet3DIterator part1Iter(m_objetIter);

	// Construire un Decorateur de transformation sur la Part1
	std::cout << std::endl << std::endl;
	std::cout << "Tests du patron DECORATOR" << std::endl;
	std::cout << "=========================" << std::endl << std::endl;

	Objet3DTransform transformPart1(part1Iter, 0.5, -0.5, 1.0);
	outToStream(transformPart1, "transformPart1   ", std::cout);
}

void TP4_Tests::outToStream(const AbsObjet3D& obj, std::string indent, std::ostream & o) const
{
	// Imprimer tous les triangles contenus dans l'objet 
	int itri = 0;
	for( auto itert = obj.triangle_cbegin(); itert != obj.triangle_cend(); ++itert, ++itri )
		o << indent << "T" << itri << ": "
		  << itert->s1() << " | "
		  << itert->s2() << " | "
		  << itert->s3() << std::endl;
	
	// Imprimer tous les enfants de l'objet
	auto itero = obj.cbegin();
	if (itero != obj.cend())
	{
		std::string extraIndent = indent + "   ";
		o << indent << "COMPOSITE:" << std::endl;
		for (; itero != obj.cend(); ++itero)
			outToStream(*itero, extraIndent, o);
	}
}


