#include <chrono>
#include <random>

#include "Math.h"

namespace raytracer {

float nextRandomNumber() {
    static std::mt19937  generator(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count()));
    static std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
    return distribution(generator);
}

Vector3 randomInUnitSphere() {
    float radius = nextRandomNumber();
    float theta = 2.0f * static_cast<float>(M_PI) * nextRandomNumber();
    float phi = static_cast<float>(M_PI) * nextRandomNumber() - static_cast<float>(M_PI_2);
    return Vector3(radius * cosf(theta), radius * sinf(theta), radius * sin(phi));
}

Vector3 randomInUnitDisc()
{
    float radius = nextRandomNumber();
    float theta = 2.0f * static_cast<float>(M_PI) * nextRandomNumber();
    return Vector3(radius * cosf(theta), radius * sinf(theta), 0.0f);
}

Vector3 reflect(const Vector3& v, const Vector3& normal)
{
    return v - 2.0f * dot(v, normal) * normal;
}

std::optional<Vector3> refract(const Vector3& v, const Vector3& normal, float ri)
{
    auto uv = v.normalized();
    float dt = dot(uv, normal);
    float discriminant = 1.0f - ri * ri * (1.0f - dt * dt);
    if (discriminant > 0)
    {
        return std::make_optional(ri * (uv - dt * normal) - sqrtf(discriminant) * normal);
    }
    return std::nullopt;
}

float schlick(float cosine, float ri)
{
    float r0 = (1.0f - ri) / (1.0f + ri);
    r0 = r0 * r0;
    return r0 + (1.0f - r0) * powf((1.0f - cosine), 5.0f);
}

} // namespace raytracer