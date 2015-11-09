#include "util.h"


namespace util
{
	float getAngle(sf::Vector2f v1, sf::Vector2f v2)
	{
		sf::Vector2f diff = v2 - v1;

        
	

		float angle = atan2(diff.y,diff.x) * 180 / PI;

		cout << "radians = " << atan2(diff.y,diff.x) << " desgrees = " << angle << endl;

		return angle;

	}
}