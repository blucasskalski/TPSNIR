#include "crvba.h"
#include <sstream>
#include <iomanip>
#include <iostream>

void CRvba::setRvba(int R, int V, int B, int A)
{
    rvba[0] = R;
    rvba[1] = V;
    rvba[2] = B;
    rvba[3] = A;
}

std::string CRvba::printRvba() const
{
    std::ostringstream oss;
    oss << std::setfill('0');
    oss << "R:" << rvba[0];
    oss << " V:" << rvba[1];
    oss << " B:" << rvba[2];
    oss << " A:" << rvba[3];
    return oss.str();
}

void CRvba::setR(int R)
{
    this->rvba[0] = R;
}
void CRvba::setV(int V)
{
    this->rvba[1] = V;
}
void CRvba::setB(int B)
{
    this->rvba[2] = B;
}
void CRvba::setA(int A)
{
    this->rvba[3] = A;
}