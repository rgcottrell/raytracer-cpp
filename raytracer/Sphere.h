#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include <memory>

#include "Material.h"
#include "Surface.h"
#include "Vector3.h"

namespace raytracer {

class Sphere : public Surface
{
public:
    static std::shared_ptr<Sphere> create(
            const Vector3& center, float radius, const std::shared_ptr<Material>& material)
    {
        return std::make_shared<Sphere>(center, radius, material);
    }

    Sphere(const Vector3& center, float radius, const std::shared_ptr<Material>& material)
            : center_(center), radius_(radius), material_(material)
    {
        // Do nothing.
    }

    std::optional<HitRecord> hit(const Ray& ray, float tMin, float tMax) const override
    {
        Vector3 oc = ray.origin() - center_;
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
                Vector3 normal = (point - center_).normalized();
                return std::make_optional<HitRecord>(t1, point, normal, material_);
            }
            float t2 = (-b + sqrtf(discriminant)) / a;
            if (t2 >= tMin && t2 < tMax)
            {
                Vector3 point = ray.pointAtParameter(t2);
                Vector3 normal = (point - center_).normalized();
                return std::make_optional<HitRecord>(t2, point, normal, material_);
            }
        }
        return std::nullopt;
    }

private:
    Vector3 center_;
    float radius_;
    std::shared_ptr<Material> material_;
};

} // namespace raytracer

#endif //RAYTRACER_SPHERE_H
