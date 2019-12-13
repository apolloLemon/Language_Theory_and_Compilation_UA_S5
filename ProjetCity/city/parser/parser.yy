%skeleton "lalr1.cc"
%require "3.0"

%defines
%define parser_class_name { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
    #include "contexte.hh"
    #include "expressionUnaire.hh"
    #include "expressionBinaire.hh"
    #include "expression.hh"
    #include "constante.hh"
    #include "variable.hh"

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

%token <double> 		num
%token <std::string> 	id_maison
%token <std::string> 	id_var
%token <std::string> 	hex_RGB

%token                  Construire
%token					Detruire
%token                  Maison
%token                  maison
%token                  Route
%token					arrow
%token                  Tourner horaire
%token                  Orienter Orientation
%token                  Deplacer Position
%token                  Voisinage
%token                  Voisin
%token                  Coloriser
%token                  Couleur

%token                  Si
%token                  Sinon
%token                  Tant
%token                  que
%token                  Repeter
%token                  fois
%token					Pour

%token					eq
%token					ne
%token					inf
%token					sup

%token 					degree

%token                  f_void


%type <int>             expression NODE
%type <ExpressionPtr>   operation
%type <int>				COORD
%left '-' '+'
%left '*' '/'
%precedence  NEG

%%
programme:
    function NL programme
    | END NL {
        YYACCEPT;
    }

function:
    expression  {
        std::cout << "#-> " << $1 << std::endl;
    }|
    Construire RAYON '{' STATEMENTS '}' {
		//Last rule    	
    }
RAYON:
	'(' expression ')' {
		//Rayon=$2
	}|
	%empty {
		//Rayon=5
	}

STATEMENTS:
	STATEMENT NL STATEMENTS |
	%empty

STATEMENT:
	BASE |
	MANAGE |
	VAR |
	KEVIN |
	CONDLOOP


COORD:
	'(' expression ',' expression ',' expression ')' {
		//return coord
	}


NODE:
	id_maison {} |
	maison '[' expression ']' {}|
	COORD {
		//These Return a graph node
	}

BASE:
	HOUSE {
		//Makes House at random xyz
	} |
	HOUSE COORD {
		//Makes House at xyz
	} |
	Route NODE arrow NODE {}

HOUSE:
	Maison {
		//Unamed House
	} |
	Maison id_maison {
		//House name = id_maison
	}

MANAGE:
	Tourner NODE HORAIRE {} |
	Orienter NODE DEGREE {}  |
	Deplacer NODE arrow COORD {} |
	Detruire NODE {} |
	Detruire NODE {} arrow NODE |
	Position NODE {} |
	Orientation NODE {} |
	Voisinage NODE {}

DEGREE:
	num degree {}
	
HORAIRE:
	horaire {} |
	'!' horaire {} 


VAR: 
	id_var '=' operation {
		try {
            double val = $3->calculer(driver.getContexte());
            driver.setVariable($1, val);
            std::cout << "#-> " << $1 << " = " << val << std::endl;
        } catch(const std::exception& err) {
            std::cerr << "#-> " << err.what() << std::endl;
        }
	}

KEVIN:
	Coloriser NODE COLOR {} |
	Couleur NODE {} |
	Voisin NODE expression
COLOR:
	hex_RGB {} |
	COORD {}

CONDLOOP:
	Si expression '{' STATEMENTS '}' SINON {} |
	Tant que expression '{' STATEMENTS '}' {} |
	Repeter expression fois '{' STATEMENTS '}' {}
SINON:
	Sinon '{' STATEMENTS '}' {} |
	%empty

expression:
    operation {
        $$ = $1->calculer(driver.getContexte());
    }

operation:
    num {
        $$ = std::make_shared<Constante>($1);
    }
    | id_var {
        $$ = std::make_shared<Variable>($1);
    }
    | '(' operation ')' {
        $$ = $2;
    }
    | operation '+' operation {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::plus);
    }
    | operation '-' operation {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::moins);
    }
    | operation '*' operation {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::multiplie);
    }
    | operation '/' operation {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::divise);
    }
    | '-' operation %prec NEG {
        $$ = std::make_shared<ExpressionUnaire>($2, OperateurUnaire::neg);
    }

%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
