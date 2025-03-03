#include "hohma.h"
#include <iostream>

int main() {
  setlocale(LC_ALL, "Russian");
  std::cout << "Я умею делать хохму!!!" << '\n';

  hohma::anekdot();

  return 0;
}
