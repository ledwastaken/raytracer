#pragma once

#include "texture.hh"

namespace texture
{
  class UniformTexture : public TextureMaterial
  {
  public:
    UniformTexture(struct TextureParams* textureParams);

    const struct TextureParams* render(const vector3::Vector3& point) const override;

  private:
    struct TextureParams* textureParams_;
  };
} // namespace texture
