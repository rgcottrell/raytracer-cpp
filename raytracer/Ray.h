#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Vector3.h"

namespace raytracer {

class Ray
{
public:
    Ray(const Vector3& origin, const Vector3& direction, float time)
            : origin_(origin), direction_(direction), time_(time)
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

    float time() const
    {
        return time_;
    }

    Vector3 pointAtParameter(float t) const
    {
        return origin_ + t * direction_;
    }

private:
    Vector3 origin_;
    Vector3 direction_;
    float time_;
};

} // namespace raytracer

#endif //RAYTRACER_RAY_H
