#include "cmatch.h"

int main(int argc, char *argv[]) {
  CDate date(12, JUI, 2022);
  CMembre membre1("John", "Doe");
  CMembre membre2("Jane", "Smith");
  CMatch match(date, &membre1, &membre2);
  std::cout << match.print() << std::endl;
  return 0;
}
