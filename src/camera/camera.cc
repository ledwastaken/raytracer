#include "camera.hh"

#include <cmath>

namespace camera
{
  Camera::Camera(const vector3::Vector3& center,
                 const vector3::Vector3& target,
                 const vector3::Vector3& up_vector,
                 float field_of_view)
    : center_(center)
    , look_vector_((target - center).normalize())
    , right_vector_(look_vector_.cross(up_vector).normalize())
    , up_vector_(right_vector_.cross(look_vector_).normalize())
    , field_of_view_(field_of_view)
  {}

  vector3::Vector3 Camera::center_get(void) const { return center_; }

  vector3::Vector3
  Camera::compute_direction(int i, int j, int width, int height) const
  {
    constexpr float pi = 3.14159265358979f;
    float imageAspectRatio = float(width) / height;
    float x = (2 * ((i + 0.5f) / width) - 1) * imageAspectRatio
      * std::tan((field_of_view_ / 2.0f) * (pi / 180.0f));
    float y = (1 - 2 * ((j + 0.5f) / height))
      * std::tan((field_of_view_ / 2.0f) * (pi / 180.0f));

    return (look_vector_ + right_vector_ * x + up_vector_ * y).normalize();
  }
} // namespace camera
