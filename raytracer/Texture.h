#ifndef RAYTRACER_TEXTURE_H
#define RAYTRACER_TEXTURE_H

#include "Vector3.h"

namespace raytracer {

class Texture
{
public:
    virtual ~Texture() = default;

    virtual Vector3 value(float u, float v, const Vector3& point) = 0;
};

} // namespace raytracer

#endif //RAYTRACER_TEXTURE_H
