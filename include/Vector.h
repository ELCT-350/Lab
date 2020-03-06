#pragma once

namespace ELCT350
{
  class Vector final
  {
  public:
    Vector(size_t vectorSize = 0);
    Vector(const Vector& original);
    Vector(Vector&& old) noexcept;
    ~Vector();

    size_t getSize() const;
    double& operator[](size_t index);
    double operator[](size_t index) const;
    Vector operator+(const Vector& rhs) const;
    double operator*(const Vector& rhs) const;
    Vector& operator=(const Vector& rhs);

  private:
    size_t _size;
    double* _values;
  };
}