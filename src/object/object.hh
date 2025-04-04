#pragma once

#include "color3.hh"
#include "texture.hh"
#include "vector3.hh"

namespace object
{
  class Object
  {
  public:
    Object(const texture::TextureMaterial* texture,
           const color3::Color3& color);

    const color3::Color3 color_get(void) const;

    virtual const vector3::Vector3
    intersect(const vector3::Vector3& origin,
              const vector3::Vector3& direction) const = 0;
    virtual const vector3::Vector3
    normal(const vector3::Vector3& point) const = 0;
    virtual const struct texture::TextureParams*
    render(const vector3::Vector3& point) const = 0;

  protected:
    const texture::TextureMaterial* texture_;
    color3::Color3 color_;
  };
} // namespace object
