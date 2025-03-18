#include "light.hh"

namespace light
{
  Light::Light(const color3::Color3& color)
    : color_(color)
  {}

  const color3::Color3& Light::color_get(void) const { return color_; }
} // namespace light
