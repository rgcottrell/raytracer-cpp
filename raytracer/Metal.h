#ifndef RAYTRACER_METAL_H
#define RAYTRACER_METAL_H

#include <algorithm>
#include <optional>
#include <utility>

#include "Material.h"
#include "Math.h"
#include "Vector3.h"

namespace raytracer {

class Metal : public Material
{
public:
    explicit Metal(Vector3 albedo, float fuzz = 0.0f)
            : albedo_(std::move(albedo)), fuzz_(std::clamp(fuzz, 0.0f, 1.0f))
    {
        // Do nothing.
    }

    std::optional<ScatterRecord> scatter(const Ray& ray, const HitRecord& hit) const override
    {
        auto reflected = reflect(ray.direction().normalized(), hit.normal());
        if (dot(reflected, hit.normal()) > 0.0f)
        {
            Ray rayOut(hit.point(), reflected + fuzz_ * randomInUnitSphere());
            return std::make_optional<ScatterRecord>(rayOut, albedo_);
        }
        return std::nullopt;
    }

private:
    Vector3 albedo_;
    float fuzz_;
};

} // namespace raytracer

#endif //RAYTRACER_METAL_H
