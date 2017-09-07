#ifndef RAYTRACER_METAL_H
#define RAYTRACER_METAL_H

#include <algorithm>
#include <memory>
#include <optional>

#include "Material.h"
#include "Math.h"
#include "Texture.h"
#include "Vector3.h"

namespace raytracer {

class Metal : public Material
{
public:
    static std::shared_ptr<Metal> create(const std::shared_ptr<Texture>& albedo, float fuzz)
    {
        return std::make_shared<Metal>(albedo, fuzz);
    }

    explicit Metal(const std::shared_ptr<Texture>& albedo, float fuzz)
            : albedo_(albedo), fuzz_(std::clamp(fuzz, 0.0f, 1.0f))
    {
        // Do nothing.
    }

    std::optional<ScatterRecord> scatter(const Ray& ray, const HitRecord& hit) const override
    {
        auto reflected = reflect(ray.direction().normalized(), hit.normal());
        if (dot(reflected, hit.normal()) > 0.0f)
        {
            Ray rayOut(hit.point(), reflected + fuzz_ * randomInUnitSphere(), ray.time());
            return std::make_optional<ScatterRecord>(rayOut, albedo_->value(0.0f, 0.0f, hit.point()));
        }
        return std::nullopt;
    }

private:
    std::shared_ptr<Texture> albedo_;
    float fuzz_;
};

} // namespace raytracer

#endif //RAYTRACER_METAL_H
