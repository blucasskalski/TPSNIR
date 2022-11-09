#include "cclub.h"

int main(int argc, char **argv) {
  CMembre *membres[NMAX];
  CMembre membre_test;
  membre_test.set("Anne", "Autation", CDate(2, JUL, 1971));
  // init();
  ajoute(membre_test);
  list();

  return 0;
}
