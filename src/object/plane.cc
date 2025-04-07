#include "plane.hh"

namespace object
{
  Plane::Plane(const texture::TextureMaterial* texture,
               const color3::Color3& color,
               const vector3::Vector3& position,
               const vector3::Vector3& normal)
    : Object(texture, color)
    , position_(position)
    , normal_(normal)
  {}

  const vector3::Vector3 Plane::intersect(const vector3::Vector3& origin,
    const vector3::Vector3& direction) const
  {
    float dot = normal_.dot(direction);

    if (dot >= 0)
      return vector3::Vector3::infinity();
    else {
      float t = (position_ - origin).dot(normal_) / dot;

      return origin + direction * t;
    }
  }

  const vector3::Vector3 Plane::normal(const vector3::Vector3& point) const
  {
    return normal_;
  }

  const texture::TextureParams* Plane::render(const vector3::Vector3& point) const
  {
    return texture_->render(point);
  }
} // namespace object