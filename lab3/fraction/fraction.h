#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class fraction {
private:
  int numerator;
  int denominator;
  void reduce();
  int gcd(int a, int b);
  void normalize();

public:
  fraction();
  fraction(int num, int den = 1);
  fraction(const char *str);
  fraction(double value);
  fraction(const fraction &other);

  fraction &operator+=(const fraction &other);
  fraction &operator+=(int value);
  fraction &operator+=(double value);

  friend fraction operator+(const fraction &left, const fraction &right);
  friend fraction operator+(const fraction &left, int right);
  friend fraction operator+(int left, const fraction &right);
  friend fraction operator+(const fraction &left, double right);
  friend fraction operator+(double left, const fraction &right);

  friend std::ostream &operator<<(std::ostream &out, const fraction &f);
  friend std::istream &operator>>(std::istream &in, fraction &f);
};

#endif
