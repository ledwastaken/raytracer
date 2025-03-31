#include "sphere.hh"

#include <cmath>

namespace object
{
  Sphere::Sphere(const texture::TextureMaterial* texture,
                 const color3::Color3& color,
                 const vector3::Vector3& center,
                 float radius)
    : Object(texture, color)
    , center_(center)
    , radius_(radius)
  {}

  const vector3::Vector3
  Sphere::intersect(const vector3::Vector3& origin,
                    const vector3::Vector3& direction) const
  {
    const vector3::Vector3& oc = origin - center_;
    float a = direction.dot(direction);
    float b = 2 * direction.dot(oc);
    float c = oc.dot(oc) - radius_ * radius_;
    float delta = b * b - 4 * a * c;

    if (delta < 0)
      return vector3::Vector3::infinity();
    else
      {
        float t1 = (-b + std::sqrt(delta)) / (2 * a);
        float t2 = (-b - std::sqrt(delta)) / (2 * a);

        if (t1 > 0 && t1 < t2)
          return origin + direction * t1;
        else if (t2 > 0)
          return origin + direction * t2;
        else
          return vector3::Vector3::infinity();
      }
  }

  const vector3::Vector3 Sphere::normal(const vector3::Vector3& point) const
  {
    return (point - center_).normalize();
  }

  std::tuple<float, float> Sphere::render(const vector3::Vector3& point) const
  {
    return texture_->render(point);
  }
} // namespace object
