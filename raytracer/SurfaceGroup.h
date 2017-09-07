#ifndef RAYTRACER_SURFACEGROUP_H
#define RAYTRACER_SURFACEGROUP_H

#include <memory>
#include <vector>

#include "Surface.h"

namespace raytracer {

class SurfaceGroup : public Surface
{
public:
    static std::shared_ptr<SurfaceGroup> create(const std::vector<std::shared_ptr<Surface>>& surfaces)
    {
        return std::make_shared<SurfaceGroup>(surfaces);
    }

    explicit SurfaceGroup(const std::vector<std::shared_ptr<Surface>>& surfaces) : surfaces_(surfaces)
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
