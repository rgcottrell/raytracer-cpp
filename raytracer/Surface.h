#ifndef RAYTRACER_SURFACE_H
#define RAYTRACER_SURFACE_H

#include <optional>

#include "HitRecord.h"
#include "Ray.h"

namespace raytracer {

class Surface
{
public:
    virtual ~Surface() = default;

    virtual std::optional<HitRecord> hit(const Ray& ray, float tMin, float tMax) const = 0;
};

} // namespace raytracer

#endif //RAYTRACER_SURFACE_H
