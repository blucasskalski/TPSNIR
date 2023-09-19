#include "cnotes.h"

void affiche(const string &m, const CNotes &c)
{
    cout << m << " : " << c.nbNotes() << " note";
    if (c.nbNotes() > 1)
        cout << 's';
    cout << ", moy. = " << c.Moyenne() << endl;
}

int main(void)
{
    CNotes math;
    math.Ajoute(12);
    math.Ajoute(10);
    affiche("math    ", math);

    CNotes physique(7);
    physique += 13;
    physique += 10;
    affiche("physique", physique);

    CNotes anglais;
    anglais[0] = 11;
    anglais[1] = 15;
    anglais = anglais + 13;
    cout << anglais.print();
    affiche("anglais ", anglais);

    CNotes francais(12);
    francais[2] = 14;
    cout << francais.print();
    affiche("francais", francais);

    // CNotes test2;
    // CNotes test(math);
    //test += math;
    // cout << test.print();
    // affiche("test", test);

    CNotes langues;
    langues += francais;
    langues += anglais;
    cout << langues.print();
    affiche("langues ", langues);

    CNotes bilan;
    bilan += math + physique;
    bilan += anglais;
    bilan += francais;
    affiche("bilan   ", bilan);
   // cout << bilan.print();
}