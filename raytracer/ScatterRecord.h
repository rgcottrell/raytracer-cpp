#ifndef RAYTRACER_SCATTERRECORD_H
#define RAYTRACER_SCATTERRECORD_H

#include "Ray.h"
#include "Vector3.h"

namespace raytracer {

class ScatterRecord {
public:
    ScatterRecord(const Ray& ray, const Vector3& attenuation) : ray_(ray), attenuation_(attenuation)
    {
        // Do nothing.
    }

    const Ray &ray() const {
        return ray_;
    }

    const Vector3& attenuation() const
    {
        return attenuation_;
    }

private:
    Ray ray_;
    Vector3 attenuation_;
};

} // namespace raytracer

#endif //RAYTRACER_SCATTERRECORD_H
