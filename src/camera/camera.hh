#pragma once

#include "vector3.hh"

namespace camera
{
  class Camera
  {
  public:
    Camera(const vector3::Vector3& center, const vector3::Vector3& target, const vector3::Vector3& up_vector, float field_of_view);

    vector3::Vector3 center_get(void) const;

    vector3::Vector3 compute_direction(int i, int j, int width, int height) const;

  private:
    vector3::Vector3 center_;
    vector3::Vector3 look_vector_;
    vector3::Vector3 right_vector_;
    vector3::Vector3 up_vector_;
    float field_of_view_;
  };
}