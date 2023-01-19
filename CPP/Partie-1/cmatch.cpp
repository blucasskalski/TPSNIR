#include "cmatch.h"

string CMatch::print() {
  return "Date: " + date.printLong() +
         ", Adversaires: " + adversaire1->getPrenom() + ' ' +
         adversaire1->getNom() + " vs " + adversaire2->getPrenom() + ' ' +
         adversaire2->getNom();
}

CMatch::CMatch(CDate date, CMembre *adversaire1, CMembre *adversaire2)
    : date(date), adversaire1(adversaire1), adversaire2(adversaire2){};
