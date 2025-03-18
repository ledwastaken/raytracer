#include "object.hh"

namespace object
{
  Object::Object(const texture::TextureMaterial* texture,
                const color3::Color3& color)
    : texture_(texture)
    , color_(color)
  {}

  const color3::Color3 Object::color_get(void) const { return color_; }
} // namespace object
