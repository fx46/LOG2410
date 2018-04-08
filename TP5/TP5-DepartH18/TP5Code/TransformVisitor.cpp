#include "TransformVisitor.h"
#include "TransformStack.h"
#include "Objet3DTransform.h"
#include "Objet3DComposite.h"

void TransformVisitor::visit(Objet3DComposite & obj)
{
	// Si le composite a des enfants faire
	//    - Pousser la transformation sur la pile des transformations
	//    - Iterer sur les enfants et visiter chaque enfant
	//    - Eliminer la transformation poussee sur la pile
	TransformStack::pushCurrent();
	for (auto it = obj.begin(); it != obj.end(); it++) {
		it->accueillir(*this);
	}
	TransformStack::pop();
}

void TransformVisitor::visit(Objet3DTransform & obj)
{
	// Combiner la transformation contenue dans l'objet à la transformation courante
	TransformStack::getCurrent() += obj;
}
