#include "scene.hh"

#include <cmath>

#include "point-light.hh"

namespace scene
{
  Scene::Scene(std::vector<object::Object*> objects,
               std::vector<light::Light*> lights,
               camera::Camera& camera)
    : objects_(objects)
    , lights_(lights)
    , camera_(camera)
  {}

  void Scene::render(image::Image& image) const
  {
    int width = image.width_get();
    int height = image.height_get();

    for (int j = 0; j < height; j++)
      {
        for (int i = 0; i < width; i++)
          {
            auto direction = camera_.compute_direction(i, j, width, height);
            auto result = cast_ray(camera_.center_get(), direction);

            if (result.first)
              image.color_pixel(shade(result, direction, 0), i, j);
          }
      }
  }

  color3::Color3 Scene::shade(cast_ray_result& surface, const vector3::Vector3& dir, int depth) const
  {
    const float ambient_intensity = 0.15f;
    auto [object, point] = surface;
    auto pixel_color = object->color_get() * ambient_intensity;
    auto [diffuse, specular] = object->render(point);

    for (light::Light* light_source : lights_)
      {
        auto light_dir = light_source->compute_light_direction(point);
        auto normal = object->normal(point);
        auto reflected_dir = dir - normal * 2 * dir.dot(normal);
        float diffuse_factor = std::max(0.0f, normal.dot(light_dir)) * diffuse;
        float ns = 50;

        if (depth < 1) {
          auto result = cast_ray(point + normal * 0.5f, reflected_dir);

          if (result.first && result.first != object)
            pixel_color = pixel_color + shade(result, reflected_dir, depth + 1);
        }

        color3::Color3 Id = object->color_get() * light_source->color_get() * diffuse_factor;
        color3::Color3 Is = light_source->color_get() * std::pow(reflected_dir.dot(-light_dir), ns) * specular;

        pixel_color = pixel_color + Id + Is;
      }

    return pixel_color;
  }

  cast_ray_result Scene::cast_ray(const vector3::Vector3& origin,
                                  const vector3::Vector3& direction) const
  {
    object::Object* object = nullptr;
    vector3::Vector3 point = vector3::Vector3::infinity();

    for (auto obj : objects_)
      {
        const vector3::Vector3& intersection =
          obj->intersect(origin, direction);

        if (!intersection.is_infinity()
            && (!object
                || (point - origin).magnitude()
                  > (intersection - origin).magnitude()))
          {
            object = obj;
            point = intersection;
          }
      }

    return std::make_pair(object, point);
  }

} // namespace scene
