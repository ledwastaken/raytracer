#include "color3.hh"

#include <algorithm>

namespace color3
{
  Color3::Color3(float r, float g, float b)
    : r_(std::clamp(r, 0.0f, 1.0f))
    , g_(std::clamp(g, 0.0f, 1.0f))
    , b_(std::clamp(b, 0.0f, 1.0f))
  {}

  Color3::Color3(void)
    : r_(0)
    , g_(0)
    , b_(0)
  {}

  Color3 Color3::from_rgb(int r, int g, int b)
  {
    return Color3(r / 255.0f, g / 255.0f, b / 255.0f);
  }

  float Color3::r_get(void) const { return r_; }
  float Color3::g_get(void) const { return g_; }
  float Color3::b_get(void) const { return b_; }

  Color3 Color3::operator+(const Color3& color) const
  {
    return Color3(r_ + color.r_, g_ + color.g_, b_ + color.b_);
  }

  Color3 Color3::operator-(const Color3& color) const
  {
    return Color3(r_ - color.r_, g_ - color.g_, b_ - color.b_);
  }

  Color3 Color3::operator*(const Color3& color) const
  {
    return Color3(r_ * color.r_, g_ * color.g_, b_ * color.b_);
  }

  Color3 Color3::operator*(float k) const
  {
    return Color3(r_ * k, g_ * k, b_ * k);
  }

  std::ostream& operator<<(std::ostream& out, const Color3& color)
  {
    return out << "Color3(" << color.r_get() << ", " << color.g_get() << ", "
               << color.b_get() << ")";
  }

} // namespace color3