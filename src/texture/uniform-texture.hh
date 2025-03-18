#pragma once

#include "texture.hh"

namespace texture
{
  class UniformTexture : public TextureMaterial
  {
  public:
    UniformTexture(float diffuse, float specular);

    std::tuple<float, float> render(const vector3::Vector3& point) const override;

  private:
    float diffuse_;
    float specular_;
  };
} // namespace texture
