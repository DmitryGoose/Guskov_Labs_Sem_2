#include "fraction.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

const int N_DEC = 4;

void fraction::reduce() {
  if (denominator < 0) {
    numerator = -numerator;
    denominator = -denominator;
  }
  int div = gcd(abs(numerator), abs(denominator));
  numerator /= div;
  denominator /= div;
}

int fraction::gcd(int a, int b) {
  while (b) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

void fraction::normalize() {
  if (denominator < 0) {
    numerator = -numerator;
    denominator = -denominator;
  }
  reduce();
}

fraction::fraction() : numerator(0), denominator(1) {}

fraction::fraction(int num, int den) : numerator(num), denominator(den) {
  if (denominator == 0) {
    throw std::invalid_argument("Denominator cannot be zero");
  }
  normalize();
}

fraction::fraction(const char *str) {
  char *temp = new char[strlen(str) + 1];
  strcpy(temp, str);

  int whole = 0;
  numerator = 0;
  denominator = 1;
  bool isNegative = false;

  if (temp[0] == '-') {
    isNegative = true;
    memmove(temp, temp + 1, strlen(temp));
  }

  char *context = nullptr;
  char *part = strtok_r(temp, " ", &context);

  if (part == nullptr) {
    delete[] temp;
    throw std::invalid_argument("Invalid fraction format");
  }

  if (strchr(part, '/') != nullptr) {
    char *num = strtok(part, "/");
    char *den = strtok(nullptr, "/");
    if (num && den) {
      numerator = atoi(num);
      denominator = atoi(den);
    }
  } else {
    whole = atoi(part);
    part = strtok_r(nullptr, " ", &context);
    if (part != nullptr) {
      char *num = strtok(part, "/");
      char *den = strtok(nullptr, "/");
      if (num && den) {
        numerator = atoi(num);
        denominator = atoi(den);
      }
    }
  }

  if (whole != 0) {
    numerator = abs(whole) * denominator + numerator;
  }

  if (isNegative) {
    numerator = -numerator;
  }

  if (denominator == 0) {
    delete[] temp;
    throw std::invalid_argument("Denominator cannot be zero");
  }

  delete[] temp;
  normalize();
}

fraction::fraction(double value) {
  int power = pow(10, N_DEC);
  numerator = round(value * power);
  denominator = power;
  normalize();
}

fraction::fraction(const fraction &other)
    : numerator(other.numerator), denominator(other.denominator) {}

fraction &fraction::operator+=(const fraction &other) {
  numerator = numerator * other.denominator + other.numerator * denominator;
  denominator = denominator * other.denominator;
  normalize();
  return *this;
}

fraction &fraction::operator+=(int value) { return *this += fraction(value); }

fraction &fraction::operator+=(double value) {
  return *this += fraction(value);
}

fraction operator+(const fraction &left, const fraction &right) {
  fraction result = left;
  return result += right;
}

fraction operator+(const fraction &left, int right) {
  return left + fraction(right);
}

fraction operator+(int left, const fraction &right) {
  return fraction(left) + right;
}

fraction operator+(const fraction &left, double right) {
  return left + fraction(right);
}

fraction operator+(double left, const fraction &right) {
  return fraction(left) + right;
}

std::ostream &operator<<(std::ostream &out, const fraction &f) {
  if (f.denominator == 1) {
    out << f.numerator;
  } else {
    int whole = f.numerator / f.denominator;
    int num = abs(f.numerator % f.denominator);
    if (whole != 0) {
      out << whole;
      if (num != 0) {
        out << " " << num << "/" << f.denominator;
      }
    } else {
      out << f.numerator << "/" << f.denominator;
    }
  }
  return out;
}

std::istream &operator>>(std::istream &in, fraction &f) {
  char input[100];
  in.getline(input, 100);
  fraction temp(input);
  f = temp;
  return in;
}
