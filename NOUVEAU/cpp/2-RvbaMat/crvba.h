#ifndef CRVBA
#define CRVBA
#include <string>
#include <iostream>

using namespace std;

class CRvba
{
private:
    int rvba[4];

public:
    CRvba()
    {
        for (int i = 0; i < 3; i++)
            rvba[i] = 0;
        rvba[3] = 255;
    }
    CRvba(int R, int V, int B, int A = 255)
    {
        setRvba(R, V, B, A);
    }
    void setRvba(int R, int V, int B, int A = 255);
    std::string printRvba() const;
    void setR(int R);
    void setV(int V);
    void setB(int B);
    void setA(int A);
    int getR() const { return rvba[0]; }
    int getV() const { return rvba[1]; }
    int getB() const { return rvba[2]; }
    int getA() const { return rvba[3]; }
};
#endif
