#ifndef RAYTRACER_CHECKERTEXTURE_H
#define RAYTRACER_CHECKERTEXTURE_H

#include <memory>

#include "Texture.h"

namespace raytracer {

class CheckerTexture : public Texture
{
public:
    static std::shared_ptr<CheckerTexture> create(
            const std::shared_ptr<Texture>& texture0, const std::shared_ptr<Texture>& texture1)
    {
        return std::make_shared<CheckerTexture>(texture0, texture1);
    }

    CheckerTexture(const std::shared_ptr<Texture>& texture0, const std::shared_ptr<Texture>& texture1)
            : texture0_(texture0), texture1_(texture1)
    {
        // Do nothing.
    }

    Vector3 value(float u, float v, const Vector3& point) override
    {
        float sines = sinf(10.0f * point.x()) * sinf(10.0f * point.y()) * sinf(10.0f * point.z());
        if (sines < 0.0f)
        {
            return texture0_->value(u, v, point);
        }
        else
        {
            return texture1_->value(u, v, point);
        }
    }

private:
    std::shared_ptr<Texture> texture0_;
    std::shared_ptr<Texture> texture1_;
};

}// namespace raytracer

#endif //RAYTRACER_CHECKERTEXTURE_H
