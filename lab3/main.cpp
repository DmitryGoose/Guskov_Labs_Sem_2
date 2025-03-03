#include "fraction/fraction.h"
#include <cstring>
#include <iostream>

void demo() {
  fraction f1("3/4");
  fraction f2(1, 2);
  fraction f3 = f1 + f2;
  std::cout << f1 << " + " << f2 << " = " << f3 << std::endl;
}

void interactive() {
  try {
    std::cout << "Введите дробь: \n";
    fraction z;
    std::cin >> z;
    std::cout << "z=" << z << std::endl;

    fraction fr1(10, 14), fr2;
    std::cout << "fr2=" << fr2 << std::endl;
    std::cout << "fr1=" << fr1 << std::endl;

    fraction fr = "-1 4/8";
    std::cout << "fr=" << fr << std::endl;

    fraction x(z), y;
    std::cout << "x=" << x << std::endl;

    double dbl = -1.25;
    fraction f = dbl;
    std::cout << "f=" << f << std::endl;

    y = x + z;
    std::cout << "y=" << y << std::endl;

    y += x;
    f += dbl / 2;
    std::cout << "f=" << f << std::endl;

    y = x + dbl;
    std::cout << "y=" << y << std::endl;

    y = dbl + y;
    std::cout << "y=" << y << std::endl;

    y += dbl;
    std::cout << "y=" << y << std::endl;

    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;

    y = i + x;
    std::cout << "y=" << y << std::endl;

    y = x + i;
    std::cout << "y=" << y << std::endl;

    y += dbl + i + x;
    std::cout << "y=" << y << std::endl;

  } catch (const std::invalid_argument &e) {
    std::cerr << "Ошибка: " << e.what() << std::endl;
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char *argv[]) {
  bool isInteractive = false;

  if ((argc == 2) && strcmp(argv[1], "i") == 0) {
    isInteractive = true;
  }

  if (isInteractive) {
    interactive();
  } else {
    demo();
  }

  return 0;
}
