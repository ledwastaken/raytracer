#include "uniform-texture.hh"

namespace texture
{
  UniformTexture::UniformTexture(float diffuse, float specular)
    : diffuse_(diffuse)
    , specular_(specular)
  {}

  std::tuple<float, float>
  UniformTexture::render(const vector3::Vector3& point) const
  {
    return std::make_tuple(diffuse_, specular_);
  }
} // namespace texture
