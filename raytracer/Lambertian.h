#ifndef RAYTRACER_LAMBERTIAN_H
#define RAYTRACER_LAMBERTIAN_H

#include <utility>

#include "Material.h"
#include "Math.h"
#include "Vector3.h"

namespace raytracer {

class Lambertian : public Material
{
public:
    explicit Lambertian(Vector3 albedo) : albedo_(std::move(albedo))
    {
        // Do nothing.
    }

    std::optional<ScatterRecord> scatter(const Ray& ray, const HitRecord& hit) const override
    {
        Ray rayOut(hit.point(), hit.normal() + randomInUnitSphere());
        return std::make_optional(ScatterRecord(rayOut, albedo_));
    }

private:
    Vector3 albedo_;
};

} // namespace raytracer

#endif //RAYTRACER_LAMBERTIAN_H
