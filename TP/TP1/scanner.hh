#ifndef SCANNER_H
#define SCANNER_H

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif


class Scanner : public yyFlexLexer {
public:
    Scanner(std::istream & in, std::ostream & out) : yyFlexLexer(in, out) {
    }

    ~Scanner() {
    }

    virtual
    int yylex();


    // ajouter des variables/méthodes si besoin (exercice avec compteur de mots)

};


#endif
