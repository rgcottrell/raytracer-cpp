#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include <cmath>

#include "Math.h"
#include "Ray.h"
#include "Vector3.h"

namespace raytracer {

class Camera
{
public:
    Camera(Vector3 lookFrom, Vector3 lookAt, Vector3 vup, float vfov, float aspect, float aperture, float focusDistance)
    {
        lensRadius_ = aperture / 2.0f;
        float theta = vfov * static_cast<float>(M_PI) / 180.f;
        float halfHeight = tanf(theta / 2.0f);
        float halfWidth = aspect * halfHeight;
        origin_ = lookFrom;
        w_ = (lookFrom - lookAt).normalized();
        u_ = cross(vup, w_).normalized();
        v_ = cross(w_, u_);
        lowerLeft_ = origin_ - halfWidth * focusDistance * u_ - halfHeight * focusDistance * v_ - focusDistance * w_;
        horizontal_ = 2.0f * halfWidth * focusDistance * u_;
        vertical_ = 2.0f * halfHeight * focusDistance * v_;
    }

    Ray getRay(float s, float t)
    {
        auto rd = lensRadius_ * randomInUnitDisc();
        auto offset = u_ * rd.x() + v_ * rd.y();
        return Ray(origin_ + offset, lowerLeft_ + s * horizontal_ + t * vertical_ - origin_ - offset);
    }

private:
    Vector3 origin_;
    Vector3 lowerLeft_;
    Vector3 horizontal_;
    Vector3 vertical_;
    Vector3 u_;
    Vector3 v_;
    Vector3 w_;
    float lensRadius_;
};

} // namespace raytracer

#endif //RAYTRACER_CAMERA_H
