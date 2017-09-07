#ifndef RAYTRACER_HITRECORD_H
#define RAYTRACER_HITRECORD_H

#include <memory>

#include "Vector3.h"

namespace raytracer {

class Material;

class HitRecord
{
public:
    HitRecord(float t, const Vector3& point, const Vector3& normal, const std::shared_ptr<Material>& material)
            : t_(t), point_(point), normal_(normal), material_(material)
    {
        // Do nothing.
    }

    const Vector3& point() const
    {
        return point_;
    }

    const Vector3& normal() const
    {
        return normal_;
    }

    const std::shared_ptr<Material>& material() const
    {
        return material_;
    }

    float t() const
    {
        return t_;
    }

private:
    float t_;
    Vector3 point_;
    Vector3 normal_;
    std::shared_ptr<Material> material_;
};

} // namespace raytracer

#endif //RAYTRACER_HITRECORD_H
