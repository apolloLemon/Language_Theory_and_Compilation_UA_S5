%{

#include "scanner.hh"
#include <cstdlib>

#define YY_NO_UNISTD_H

using token = yy::Parser::token;

#undef  YY_DECL
#define YY_DECL int Scanner::yylex( yy::Parser::semantic_type * const lval, yy::Parser::location_type *loc )

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option c++
%option yyclass="Scanner"
%option noyywrap

%%
%{
    yylval = lval;
%}
fin return token::END;

"+" return '+';
"*" return '*';
"-" return '-';
"/" return '/';

"(" return '(';
")" return ')';
"{" return '{';
"}" return '}';
"[" return '[';
"]" return ']';
"," return ',';
"}" return '}';

"=" return '=';
"==" return token::eq;
"!=" return token::ne;
"<" return token::inf;
">" return token::sup;

"not" return '!';
"!" return '!';

"->" return token::arrow;
"°" return token::degree;

"Construire" return token::Construire;
"Maison" return token::Maison;
"maison" return token::maison;
"Route" return token::Route;
"Tourner" return token::Tourner;
"horaire" return token::horaire;
"Orienter" return token::Orienter;
"Deplacer" return token::Deplacer;
"Orientation" return token::Orientation;
"Position" return token::Position;
"Voisinage" return token::Voisinage;
"Voisin" return token::Voisin;
"Coloriser" return token::Coloriser;
"Couleur" return token::Couleur;
"Detruire" return token::Detruire;

"Si" return token::Si;
"Sinon" return token::Sinon;
"Tant" return token::Tant;
"que" return token::que;
"Repeter" return token::Repeter;
"fois" return token::fois;
"Pour" return token::Pour;

"void" return token::f_void;
"$" return '$';



"\n"          {
    loc->lines();
    return token::NL;
}

(%%.*$) {}
(%\/.*\/%) {}

[0-9]+      {
    yylval->build<double>(std::atoi(YYText()));
    return token::num;
}

([A-Z][A-Za-z0-9_]*) {
	yylval->build<std::string>(YYText());
	return token::id_maison;
}
([a-z][A-Za-z0-9_]*) {
	yylval->build<std::string>(YYText());
	return token::id_var;
}
(#[A-Fa-f0-9]{6}) {
	yylval->build<std::string>(YYText());
	return token::hex_RGB;
}
%%
