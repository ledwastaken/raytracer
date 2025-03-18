#include "vector3.hh"

#include <cmath>

namespace vector3
{
  Vector3::Vector3(float x, float y, float z)
    : x(x)
    , y(y)
    , z(z)
  {}

  const Vector3 Vector3::zero(void) { return Vector3(0, 0, 0); }
  const Vector3 Vector3::x_axis(void) { return Vector3(1, 0, 0); }
  const Vector3 Vector3::y_axis(void) { return Vector3(0, 1, 0); }
  const Vector3 Vector3::z_axis(void) { return Vector3(0, 0, 1); }
  const Vector3 Vector3::infinity(void)
  {
    return Vector3(std::numeric_limits<float>::infinity(),
                   std::numeric_limits<float>::infinity(),
                   std::numeric_limits<float>::infinity());
  }

  bool Vector3::is_infinity(void) const
  {
    return std::isinf(x) || std::isinf(y) || std::isinf(z);
  }

  float Vector3::magnitude(void) const
  {
    return std::sqrt(x * x + y * y + z * z);
  }

  float Vector3::dot(const Vector3& vect) const
  {
    return x * vect.x + y * vect.y + z * vect.z;
  }

  const Vector3 Vector3::cross(const Vector3& vect) const
  {
    return Vector3(y * vect.z - z * vect.y, z * vect.x - x * vect.z, x * vect.y - y * vect.x);
  }

  const Vector3 Vector3::normalize(void) const { return *this / magnitude(); }
  const Vector3 Vector3::operator+(const Vector3& vect) const
  {
    return Vector3(x + vect.x, y + vect.y, z + vect.z);
  }

  const Vector3 Vector3::operator-(const Vector3& vect) const
  {
    return Vector3(x - vect.x, y - vect.y, z - vect.z);
  }

  const Vector3 Vector3::operator-(void) const { return Vector3(-x, -y, -z); }

  const Vector3 Vector3::operator*(float value) const
  {
    return Vector3(x * value, y * value, z * value);
  }

  const Vector3 Vector3::operator/(float value) const
  {
    return Vector3(x / value, y / value, z / value);
  }

  std::ostream& operator<<(std::ostream& out, const Vector3& vect)
  {
    return out << "Vector3(" << vect.x << ", " << vect.y << ", " << vect.z
               << ")";
  }

} // namespace vector3
