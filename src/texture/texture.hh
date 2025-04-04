#pragma once

#include "vector3.hh"

namespace texture
{
  struct TextureParams
  {
    float diffuse;
    float specular;
    float reflectance;
  };

  class TextureMaterial
  {
  public:
    TextureMaterial();

    virtual const struct TextureParams* render(const vector3::Vector3& point) const = 0;
  };
} // namespace texture
