#pragma once

#include <string>
#include <vector>

#include "color3.hh"

namespace image
{
  class Image
  {
  public:
    Image(int width, int height);

    int width_get(void) const;
    int height_get(void) const;

    void display(const std::string& filename) const;
    void color_pixel(const color3::Color3& color, int i, int j);

  private:
    int width_;
    int height_;
    std::vector<color3::Color3> pixels_;
  };
} // namespace image
