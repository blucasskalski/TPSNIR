#ifndef CDEF_H
#define CDEF_H

#include <ostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
class CDef
{
    static string cl[];
    string def, lang;

public:
    CDef() : def(""), lang("") {}
    CDef(const string &definition, int langue = 0)
    {
        setDef(definition);
        setLang(CodLang(langue));
    }
    CDef(const CDef &cdef)
    {
        setDef(cdef.getDef());
        setLang(cdef.getLang());
    }
    ~CDef() {}
    static string CodLang(int langue)
    {
        int i = 0;
        while (!cl[i].empty())
        {
            if (i == langue)
                return cl[i];
            i++;
        }
        return cl[i];
    }
    string getDef() const { return def; }
    string getLang() const { return lang; }
    void setDef(string def) { CDef::def = def; }
    void setLang(string lang) { CDef::lang = lang; }
    void setLang(int lang) { setLang(CodLang(lang)); }
    string print()
    {
        std::ostringstream oss;
        oss << std::setfill('0');
        oss << "définition : " << def << " ";
        oss << "- langue : " << lang << endl;
        return oss.str();
    }
};
string CDef::cl[] = {"EN", "FR", "DE", "SP", "IT", "JP", "RU", ""};
#endif