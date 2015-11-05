#include "Light.h"

Light::Light()
{
        color = Color(255,255,255);
        position = Vector2f(0,0);
        radius = 0;
        angleSpeed = 0;
        angle = 0;
        dynamic = true;
}