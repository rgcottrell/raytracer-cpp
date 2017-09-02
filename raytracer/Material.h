#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include <optional>

#include "HitRecord.h"
#include "Ray.h"
#include "ScatterRecord.h"

namespace raytracer {

class Material
{
public:
    virtual ~Material() = default;

    virtual std::optional<ScatterRecord> scatter(const Ray& ray, const HitRecord& hit) const = 0;
};

} // namespace raytracer

#endif //RAYTRACER_MATERIAL_H
