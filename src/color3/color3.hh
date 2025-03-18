#pragma once

#include <iostream>

namespace color3
{
  class Color3
  {
  public:
    Color3(float r, float g, float b);
    Color3(void);

    static Color3 from_rgb(int r, int g, int b);

    float r_get(void) const;
    float g_get(void) const;
    float b_get(void) const;

    Color3 operator+(const Color3& color) const;
    Color3 operator-(const Color3& color) const;
    Color3 operator*(const Color3& color) const;
    Color3 operator*(float k) const;

  private:
    float r_;
    float g_;
    float b_;
  };

  std::ostream& operator<<(std::ostream& out, const Color3& color);

} // namespace color3
