#pragma once

#include "object.hh"

namespace object
{
  class Plane : public Object
  {
  public:
    Plane(const texture::TextureMaterial* texture,
          const color3::Color3& color,
          const vector3::Vector3& position,
          const vector3::Vector3& normal);

    const vector3::Vector3 intersect(const vector3::Vector3& origin,
                                     const vector3::Vector3& direction) const;
    const vector3::Vector3 normal(const vector3::Vector3& point) const;
    const struct texture::TextureParams* render(const vector3::Vector3& point) const;

  private:
    vector3::Vector3 position_;
    vector3::Vector3 normal_;
  };
} // namespace object
