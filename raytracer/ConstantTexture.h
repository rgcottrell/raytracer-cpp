#ifndef RAYTRACER_CONSTANTTEXTURE_H
#define RAYTRACER_CONSTANTTEXTURE_H

#include <memory>

#include "Texture.h"
#include "Vector3.h"

namespace raytracer {

class ConstantTexture : public Texture
{
public:
    static std::shared_ptr<ConstantTexture> create(const Vector3& color)
    {
        return std::make_shared<ConstantTexture>(color);
    }

    static std::shared_ptr<ConstantTexture> create(float red, float green, float blue)
    {
        return std::make_shared<ConstantTexture>(Vector3(red, green, blue));
    }

    explicit ConstantTexture(const Vector3& color) : color_(color)
    {
        // Do nothing.
    }

    Vector3 value(float u, float v, const Vector3& point) override
    {
        return color_;
    }

private:
    Vector3 color_;
};

} // namespace raytracer

#endif //RAYTRACER_CONSTANTTEXTURE_H
