#ifndef RAYTRACER_SURFACEGROUP_H
#define RAYTRACER_SURFACEGROUP_H

#include <memory>
#include <utility>
#include <vector>

#include "Surface.h"

namespace raytracer {

class SurfaceGroup : public Surface
{
public:
    explicit SurfaceGroup(std::vector<std::shared_ptr<Surface>> surfaces) : surfaces_(std::move(surfaces))
    {
        // Do nothing.
    }

    std::optional<HitRecord> hit(const Ray& ray, float tMin, float tMax) const override
    {
        float tClosest = tMax;
        std::optional<HitRecord> result = std::nullopt;
        for (const auto& surface : surfaces_)
        {
            auto hit = surface->hit(ray, tMin, tClosest);
            if (hit)
            {
                tClosest = hit->t();
                result.swap(hit);
            }
        }
        return result;
    }

private:
    std::vector<std::shared_ptr<Surface>> surfaces_;
};

} // namespace raytracer

#endif //RAYTRACER_SURFACEGROUP_H
