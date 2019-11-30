%skeleton "lalr1.cc"
%require "3.0"

%defines
%define parser_class_name { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
    class Scanner;
    class Driver;
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code{
    #include <iostream>
    #include <string>
    
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex
}

%token                  NL
%token                  END
%token                  PLUS
%token                  NEG
%token                  MULT
%token <int>            NUMBER
%type <int>             negate
%type <int>             addition
%type <int>             produit
%type <int>             operation

%%

programme:
    operation NL {
        std::cout << "Resultat : " << $1 << std::endl;
    } programme
    | END NL {
        YYACCEPT;
    }

operation:
    NUMBER {
        $$=$1;
    }
    | produit {
        $$=$1;
    }
    | addition {
        $$=$1;
    }
    | negate {
        $$=$1;
    }

negate:
    NEG operation {
        $$ = 0-$2;
    }

addition:
    operation PLUS operation {
        $$ = $1 + $3;
    }

produit:
    operation MULT operation {
        $$ = $1 * $3;
    }
    
%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
