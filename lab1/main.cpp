#include "hohma/hohma.h"
#include "mymath/mymath.h"
#include <iostream>

int main() {
  setlocale(LC_ALL, "Russian");
  std::cout << "Я умею суммировать! Зацени 1+1=";
  std::cout << mymath::sum(1, 1) << std::endl;
  std::cout << "А еще я умею делать хохму!!!" << '\n';

  hohma::anekdot();

  return 0;
}
