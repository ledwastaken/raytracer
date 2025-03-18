#pragma once

#include "color3.hh"
#include "vector3.hh"

namespace light
{
  class Light
  {
  public:
    Light(const color3::Color3& color);

    virtual const color3::Color3& color_get(void) const;
    virtual vector3::Vector3
    compute_light_direction(const vector3::Vector3& target) const = 0;

  protected:
    color3::Color3 color_;
  };
} // namespace light
