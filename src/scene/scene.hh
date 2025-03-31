#pragma once

#include <memory>
#include <vector>
#include <set>

#include "camera.hh"
#include "image.hh"
#include "light.hh"
#include "object.hh"

typedef std::pair<object::Object*, vector3::Vector3> cast_ray_result;

namespace scene
{
  class Scene
  {
  public:
    Scene(std::vector<object::Object*> objects,
          std::vector<light::Light*> lights,
          camera::Camera& camera);

    void render(image::Image& image) const;
    color3::Color3 shade(cast_ray_result& surface, const vector3::Vector3& dir, int depth) const;
    cast_ray_result cast_ray(const vector3::Vector3& origin,
                             const vector3::Vector3& direction, std::set<object::Object*> blacklist) const;

  private:
    std::vector<object::Object*> objects_;
    std::vector<light::Light*> lights_;
    camera::Camera& camera_;
  };
} // namespace scene
