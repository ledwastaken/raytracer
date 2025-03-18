#include "image.hh"

#include <cmath>
#include <fstream>

namespace image
{
  Image::Image(int width, int height)
    : width_(width)
    , height_(height)
    , pixels_(width * height)
  {}

  void Image::color_pixel(const color3::Color3& color, int i, int j)
  {
    pixels_[j * width_ + i] = color;
  }

  int Image::width_get(void) const { return width_; }
  int Image::height_get(void) const { return height_; }

  void Image::display(const std::string& filename) const
  {
    std::ofstream output;

    output.open(filename);
    output << "P3 " << width_ << " " << height_ << " 255\n";

    for (int i = 0; i < height_; i++)
      {
        for (int j = 0; j < width_; j++)
          {
            color3::Color3 color = pixels_[i * width_ + j];

            output << " " << std::round(color.r_get() * 255.0f) << " "
                   << std::round(color.g_get() * 255.0f) << " "
                   << std::round(color.b_get() * 255.0f);
          }
        output << "\n";
      }

    output.close();
  }
} // namespace image