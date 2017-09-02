#ifndef RAYTRACER_VEC3_H
#define RAYTRACER_VEC3_H

namespace raytracer {

class Vector3
{
public:
    constexpr Vector3(float x, float y, float z) noexcept : x_(x), y_(y), z_(z)
    {
        // Do nothing.
    }

    Vector3() : x_(0), y_(0), z_(0)
    {
        // Do nothing.
    }

    Vector3(const Vector3& other) : x_(other.x_), y_(other.y_), z_(other.z_)
    {
        // Do nothing.
    }

    float x() const
    {
        return x_;
    }

    float y() const
    {
        return y_;
    }

    float z() const
    {
        return z_;
    }

    float length() const
    {
        return sqrtf(x_ * x_ + y_ * y_ + z_ * z_);
    }

    float squaredNorm() const {
        return x_ * x_ + y_ * y_ + z_ * z_;
    }

    Vector3 normalized() const {
        float k = 1.0f / sqrtf(x_ * x_ + y_ * y_ + z_ * z_);
        return Vector3(k * x_, k * y_, k * z_);
    }

    Vector3 sqrt() const {
        return Vector3(sqrtf(x_), sqrtf(y_), sqrtf(z_));
    }

    Vector3 operator-() const
    {
        return Vector3(-x_, -y_, -z_);
    }

private:
    float x_;
    float y_;
    float z_;
};

inline Vector3 operator+(const Vector3 &lhs, const Vector3 &rhs)
{
    return Vector3(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
}

inline Vector3 operator-(const Vector3 &lhs, const Vector3 &rhs)
{
    return Vector3(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
}

inline Vector3 operator*(float t, const Vector3 &v)
{
    return Vector3(t * v.x(), t * v.y(), t * v.z());
}

inline Vector3 operator*(const Vector3 &v, float t)
{
    return Vector3(t * v.x(), t * v.y(), t * v.z());
}

inline Vector3 operator*(const Vector3 &lhs, const Vector3 &rhs)
{
    return Vector3(lhs.x() * rhs.x(), lhs.y() * rhs.y(), lhs.z() * rhs.z());
}

inline Vector3 operator/(const Vector3 &v, float t)
{
    float k = 1.0f / t;
    return Vector3(k * v.x(), k * v.y(), k * v.z());
}

inline float squaredDistance(const Vector3& lhs, const Vector3& rhs)
{
    return (lhs.x() - rhs.x()) * (lhs.x() - rhs.x())
           + (lhs.y() - rhs.y()) * (lhs.y() - rhs.y())
           + (lhs.z() - rhs.z()) * (lhs.z() - rhs.z());
}

inline float distance(const Vector3& lhs, const Vector3& rhs)
{
    return sqrtf((lhs.x() - rhs.x()) * (lhs.x() - rhs.x())
           + (lhs.y() - rhs.y()) * (lhs.y() - rhs.y())
           + (lhs.z() - rhs.z()) * (lhs.z() - rhs.z()));
}

inline float dot(const Vector3 &lhs, const Vector3 &rhs)
{
    return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z();
}

inline Vector3 cross(const Vector3& lhs, const Vector3& rhs)
{
    float x = lhs.y() * rhs.z() - lhs.z() * rhs.y();
    float y = -(lhs.x() * rhs.z() - lhs.z() * rhs.x());
    float z = lhs.x() * rhs.y() - lhs.y() * rhs.x();
    return Vector3(x, y, z);
}

} // namespace raytracer

#endif //RAYTRACER_VEC3_H
