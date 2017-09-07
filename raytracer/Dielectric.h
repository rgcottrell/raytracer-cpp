#ifndef RAYTRACER_DIELECTRIC_H
#define RAYTRACER_DIELECTRIC_H

#include <algorithm>
#include <optional>
#include <utility>

#include "Material.h"
#include "Math.h"
#include "Vector3.h"

namespace raytracer {

class Dielectric : public Material
{
public:
    static std::shared_ptr<Dielectric> create(float ri)
    {
        return std::make_shared<Dielectric>(ri);
    }

    explicit Dielectric(float ri) : ri_(ri)
    {
        // Do nothing.
    }

    std::optional<ScatterRecord> scatter(const Ray& ray, const HitRecord& hit) const override
    {
        Vector3 normalOut;
        float cosine;
        float ri;
        if (dot(ray.direction(), hit.normal()) > 0.0f)
        {
            normalOut = -hit.normal();
            cosine = ri_ * dot(ray.direction(), hit.normal()) / ray.direction().length();
            ri = ri_;
        }
        else
        {
            normalOut = hit.normal();
            cosine = -dot(ray.direction(), hit.normal()) / ray.direction().length();
            ri = 1.0f / ri_;
        }

        auto refracted = refract(ray.direction(), normalOut, ri);
        float reflectProbability = (refracted) ? schlick(cosine, ri) : 1.0f;
        if (nextRandomNumber() < reflectProbability)
        {
            Vector3 reflected = reflect(ray.direction(), hit.normal());
            return std::make_optional<ScatterRecord>(
                    Ray(hit.point(), reflected, ray.time()), Vector3(1.0f, 1.0f, 1.0f));
        }
        return std::make_optional<ScatterRecord>(Ray(hit.point(), *refracted, ray.time()), Vector3(1.0f, 1.0f, 1.0f));
    }

private:
    float ri_;
};

} // namespace raytracer

#endif //RAYTRACER_DIELECTRIC_H
