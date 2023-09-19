#include "cdico.h"
#define DEFAULTDTA "acronym4.dta"

int main(int argc, char** argv)
{
    string nf = DEFAULTDTA;
    if(argc >1) nf = string(argv[1]);
    CDico dico(nf);
    if(!dico.load()) return -1;
    dico.sort();
    cout << dico.size() << " acronymes" << endl;
    for(int i = 0; i < dico.size(); i ++)
    {
        CAcro a = dico.acro(i);
        cout << a.acro() << endl;
        for(int j = 0; j < a.size(); j++)
        {
            cout << "- " << a.def(j).def();
            cout << " [";
            cout << CDef::CodLang(a.def(j).lang());
            cout << "]" << endl;
        }
    }
    return 0;
}