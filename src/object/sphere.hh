#pragma once

#include "object.hh"

namespace object
{
  class Sphere : public Object
  {
  public:
    Sphere(const texture::TextureMaterial* texture,
           const color3::Color3& color,
           const vector3::Vector3& center,
           float radius);

    const vector3::Vector3 intersect(const vector3::Vector3& origin,
                                     const vector3::Vector3& direction) const;
    const vector3::Vector3 normal(const vector3::Vector3& point) const;
    const struct texture::TextureParams* render(const vector3::Vector3& point) const;

  private:
    const vector3::Vector3& center_;
    float radius_;
  };
} // namespace object
