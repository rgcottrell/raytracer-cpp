#ifndef RAYTRACER_LAMBERTIAN_H
#define RAYTRACER_LAMBERTIAN_H

#include <memory>

#include "Material.h"
#include "Math.h"
#include "Texture.h"
#include "Vector3.h"

namespace raytracer {

class Lambertian : public Material
{
public:
    static std::shared_ptr<Lambertian> create(const std::shared_ptr<Texture>& albedo)
    {
        return std::make_shared<Lambertian>(albedo);
    }

    explicit Lambertian(const std::shared_ptr<Texture>& albedo) : albedo_(albedo)
    {
        // Do nothing.
    }

    std::optional<ScatterRecord> scatter(const Ray& ray, const HitRecord& hit) const override
    {
        Ray rayOut(hit.point(), hit.normal() + randomInUnitSphere(), ray.time());
        return std::make_optional(ScatterRecord(rayOut, albedo_->value(0.0f, 0.0f, hit.point())));
    }

private:
    std::shared_ptr<Texture> albedo_;
};

} // namespace raytracer

#endif //RAYTRACER_LAMBERTIAN_H
