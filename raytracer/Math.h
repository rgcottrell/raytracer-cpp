#ifndef RAYTRACER_MATH_H
#define RAYTRACER_MATH_H

#include <optional>

#include "Vector3.h"

namespace raytracer {

/// Returns a random float between 0.0f and 1.0f
extern float nextRandomNumber();

/// Returns a random point within a unit sphere.
extern Vector3 randomInUnitSphere();

/// Returns a random point within a unit disc on the XY plane.
extern Vector3 randomInUnitDisc();

/// Reflects an incoming vector v hitting a surface with the given normal and
/// returns the reflected vector.
extern Vector3 reflect(const Vector3& v, const Vector3& normal);

/// Refracts an incoming vector v hitting a surface with the given normal and
/// refraction index and returns the refracted vector if refraction was possible.
extern std::optional<Vector3> refract(const Vector3& v, const Vector3& normal, float ri);

/// Schlick approximation to varying reflectivity of dialectric by angle.
extern float schlick(float cosine, float ri);

} // namespace raytracer

#endif //RAYTRACER_MATH_H
