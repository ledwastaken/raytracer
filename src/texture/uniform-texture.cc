#include "uniform-texture.hh"

namespace texture
{
  UniformTexture::UniformTexture(struct TextureParams* textureParams)
    : textureParams_(textureParams)
  {}

  const struct TextureParams*
  UniformTexture::render(const vector3::Vector3& point) const
  {
    return textureParams_;
  }
} // namespace texture
