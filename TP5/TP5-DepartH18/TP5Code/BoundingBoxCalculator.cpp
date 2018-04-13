#include <limits>

#include "BoundingBoxCalculator.h"
#include "Objet3DPart.h"

BoundingBoxCalculator::BoundingBoxCalculator(void)
{
	// initialiser les bornes minimum aux plus grandes valeurs possibles
	// le float maximum est: std::numeric_limits<float>::max();
	m_boite[4] = std::numeric_limits<float>::max();
	m_boite[2] = std::numeric_limits<float>::max();
	m_boite[0] = std::numeric_limits<float>::max();
	// initialiser les bornes maximum aux plus petites valeurs possibles
	// le float minimum est: std::numeric_limits<float>::min();
	m_boite[5] = std::numeric_limits<float>::min();
	m_boite[3] = std::numeric_limits<float>::min();
	m_boite[1] = std::numeric_limits<float>::min();
}

void BoundingBoxCalculator::visit(Objet3DPart & obj)
{
	// Iterer sur tous les triangles contenus dans l'objet et faire:
	//    - Comparer les coordonnees des sommets des triangles aux bornes actuelle de la boite
	//    - Si une coordonnee est plus petite qu'une coordonnee min, faire:
	//         - stoker la nouvelle coordonnee min
	//    - Si une coordonnee est plus grande qu'une coordonnee max, faire:
	//         - stoker la nouvelle coordonnee max
	for (TriangleIterator iter = obj.triangle_begin(); iter != obj.triangle_end(); iter++) {
		const Sommet* sommets = iter->sommets();
		for (unsigned int i = 0; i < 3; i++) {
			const float* coordonnees = sommets[i].coords();

			//X
			if (coordonnees[0] < m_boite[0]) {
				m_boite[0] = coordonnees[0];
			}
			else if (coordonnees[0] > m_boite[1]) {
				m_boite[1] = coordonnees[0];
			}

			//Y
			if (coordonnees[1] < m_boite[2]) {
				m_boite[2] = coordonnees[1];
			}
			else if (coordonnees[1] > m_boite[3]) {
				m_boite[3] = coordonnees[1];
			}

			//Z
			if (coordonnees[2] < m_boite[4]) {
				m_boite[4] = coordonnees[2];
			}
			else if (coordonnees[2] > m_boite[5]) {
				m_boite[5] = coordonnees[2];
			}
		}
	}
}
