#pragma once

#include "vector3.hh"

namespace texture
{
  class TextureMaterial
  {
  public:
    TextureMaterial();

    virtual std::tuple<float, float> render(const vector3::Vector3& point) const = 0;
  };
} // namespace texture
