#ifndef RAYTRACER_HITRECORD_H
#define RAYTRACER_HITRECORD_H

#include <memory>
#include <utility>

#include "Vector3.h"

namespace raytracer {

class Material;

class HitRecord
{
public:
    HitRecord(float t, Vector3 point, Vector3 normal, std::shared_ptr<Material> material)
            : t_(t), point_(std::move(point)), normal_(std::move(normal)), material_(std::move(material))
    {
        // Do nothing.
    }

    float t() const
    {
        return t_;
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

private:
    float t_;
    Vector3 point_;
    Vector3 normal_;
    std::shared_ptr<Material> material_;
};

} // namespace raytracer

#endif //RAYTRACER_HITRECORD_H
