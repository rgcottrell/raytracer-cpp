#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include <utility>

#include "Vector3.h"

namespace raytracer {

class Ray
{
public:
    Ray(Vector3 origin, Vector3 direction) : origin_(std::move(origin)), direction_(std::move(direction))
    {
        // Do nothing.
    }

    const Vector3& origin() const
    {
        return origin_;
    }

    const Vector3& direction() const
    {
        return direction_;
    }

    Vector3 pointAtParameter(float t) const
    {
        return origin_ + t * direction_;
    }

private:
    Vector3 origin_;
    Vector3 direction_;
};

} // namespace raytracer

#endif //RAYTRACER_RAY_H
