#pragma once

#include <iostream>

namespace vector3
{
  class Vector3
  {
  public:
    Vector3(float x, float y, float z);

    static const Vector3 zero(void);
    static const Vector3 x_axis(void);
    static const Vector3 y_axis(void);
    static const Vector3 z_axis(void);
    static const Vector3 infinity(void);

    bool is_infinity(void) const;
    float magnitude(void) const;
    float dot(const Vector3& vect) const;
    const Vector3 cross(const Vector3& vect) const;
    const Vector3 normalize(void) const;
    const Vector3 operator+(const Vector3& vect) const;
    const Vector3 operator-(const Vector3& vect) const;
    const Vector3 operator-(void) const;
    const Vector3 operator*(float value) const;
    const Vector3 operator/(float value) const;

    float x;
    float y;
    float z;
  };

  std::ostream& operator<<(std::ostream& out, const Vector3& vect);

} // namespace vector3
