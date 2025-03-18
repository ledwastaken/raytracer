#pragma once

#include "light.hh"
#include "vector3.hh"

namespace light
{
  class PointLight : public Light
  {
  public:
    PointLight(const color3::Color3& color, const vector3::Vector3& origin);

    const vector3::Vector3& origin_get(void) const;
    vector3::Vector3
    compute_light_direction(const vector3::Vector3& target) const override;

  private:
    vector3::Vector3 origin_;
  };
} // namespace light