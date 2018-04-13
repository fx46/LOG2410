#include "OutputTransformVisitor.h"
#include "Objet3DPart.h"
#include "Objet3DComposite.h"

void OutputTransformVisitor::visit(Objet3DPart & obj)
{
	// Imprimer tous les triangles contenus dans l'objet
	// Meme methode que OutputVisitor::visit(Objet3DPart& obj)
	auto it = obj.triangle_cbegin();
	for (int index = 0; it != obj.triangle_cend(); it++, index++){
		m_stream << m_indent 
				 << "T" 
				 << index 
				 << ":" 
				 << it->s1()
				 << " | " 
				 << it->s2() 
				 << " | " 
				 << it->s3() 
				 << std::endl;
	}
}

void OutputTransformVisitor::visit(Objet3DComposite & obj)
{
	// Si l'objet composite a des enfants, faire:
	//     - Incrementer l'indentation de 3 espaces
	//     - Imprimer "COMPOSITE:" selon la bonne indentation sur une ligne seule
	//     - Invoquer la methode TransformVisitor::visit(Objet3DComposite &) de 
	//       la classe de base  pour visiter les enfants
	//     - Restaurer l'indentation
	m_indent += "   ";
	m_stream << m_indent
			 << "COMPOSITE:"
			 << std::endl;

	TransformVisitor::visit(obj);

	m_indent = m_indent.substr(0, m_indent.length() - 3);
}
