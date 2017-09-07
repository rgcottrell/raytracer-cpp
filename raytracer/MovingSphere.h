#ifndef RAYTRACER_MOVINGSPHERE_H
#define RAYTRACER_MOVINGSPHERE_H

#include <memory>
#include <optional>

#include "Material.h"
#include "Surface.h"
#include "Vector3.h"

namespace raytracer {

class MovingSphere : public Surface
{
public:
    static std::shared_ptr<MovingSphere> create(
            const Vector3& center0, const Vector3& center1, float time0, float time1, float radius,
            const std::shared_ptr<Material>& material)
    {
        return std::make_shared<MovingSphere>(center0, center1, time0, time1, radius, material);
    }

    MovingSphere(
            const Vector3& center0, const Vector3& center1, float time0, float time1, float radius,
            const std::shared_ptr<Material>& material)
            : center0_(center0), center1_(center1), time0_(time0), time1_(time1), radius_(radius), material_(material)
    {
        // Do nothing.
    }

    std::optional<HitRecord> hit(const Ray& ray, float tMin, float tMax) const override
    {
        Vector3 centerNow = center(ray.time());
        Vector3 oc = ray.origin() - centerNow;
        float a = ray.direction().squaredNorm();
        float b = dot(oc, ray.direction());
        float c = oc.squaredNorm() - radius_ * radius_;
        float discriminant = b * b - a * c;
        if (discriminant > 0)
        {
            float t1 = (-b - sqrtf(discriminant)) / a;
            if (t1 >= tMin && t1 < tMax)
            {
                Vector3 point = ray.pointAtParameter(t1);
                Vector3 normal = (point - centerNow).normalized();
                return std::make_optional<HitRecord>(t1, point, normal, material_);
            }
            float t2 = (-b + sqrtf(discriminant)) / a;
            if (t2 >= tMin && t2 < tMax)
            {
                Vector3 point = ray.pointAtParameter(t2);
                Vector3 normal = (point - centerNow).normalized();
                return std::make_optional<HitRecord>(t2, point, normal, material_);
            }
        }
        return std::nullopt;
    }

private:
    Vector3 center(float time) const
    {
        return center0_ + ((time - time0_) / (time1_ - time0_)) * (center1_ - center0_);
    }

    Vector3 center0_;
    Vector3 center1_;
    float time0_;
    float time1_;
    float radius_;
    std::shared_ptr<Material> material_;
};

} // namespace raytracer

#endif //RAYTRACER_MOVINGSPHERE_H
