#include "point-light.hh"

namespace light
{
  PointLight::PointLight(const color3::Color3& color,
                         const vector3::Vector3& origin)
    : Light(color)
    , origin_(origin)
  {}

  const vector3::Vector3& PointLight::origin_get(void) const { return origin_; }

  vector3::Vector3
  PointLight::compute_light_direction(const vector3::Vector3& target) const
  {
    return (origin_ - target).normalize();
  }
} // namespace light