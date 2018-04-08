#include <limits>

#include "BoundingBoxCalculator.h"
#include "Objet3DPart.h"

BoundingBoxCalculator::BoundingBoxCalculator(void)
{
	// initialiser les bornes minimum aux plus grandes valeurs possibles
	// le float maximum est: std::numeric_limits<float>::max();

	// initialiser les bornes maximum aux plus petites valeurs possibles
	// le float minimum est: std::numeric_limits<float>::min();
}

void BoundingBoxCalculator::visit(Objet3DPart & obj)
{
	// Iterer sur tous les triangles contenus dans l'objet et faire:
	//    - Comparer les coordonnees des sommets des triangles aux bornes actuelle de la boite
	//    - Si une coordonnee est plus petite qu'une coordonnee min, faire:
	//         - stoker la nouvelle coordonnee min
	//    - Si une coordonnee est plus grande qu'une coordonnee max, faire:
	//         - stoker la nouvelle coordonnee max
}
