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

%token <double> 		num
%token <std::string> 	id_maison id_var
%token <std::string> 	hex_RGB

%token                  Construire
%token					Detruire
%token                  Maison maison
%token                  Route arrow
%token                  Tourner horaire
%token                  Orienter Orientation
%token                  Deplacer Position
%token                  Voisinage Voisin
%token                  Coloriser Couleur

%token                  Si Sinon
%token                  Tant que
%token                  Repeter fois
%token					Pour

%token					eq ne
%token					inf sup

%token 					degree

%token                  f_void


%type <int>             NODE
%type <ExpressionPtr>   expression 
%type <ExpressionPtr>   STATEMENT

%type <std::vector<ExpressionPtr>> STATEMENTS
%type <int>				COORD 
%left '-' '+' eq ne
%left '*' '/' inf sup
%precedence  NEG

%%
programme:
    function programme {
    	$$=$2
    	$$.push_back($1);
    }| 
    %empty {
    	driver.setAST($$);
        YYACCEPT;
    }

function:
    Construire RAYON '{' STATEMENTS '}' {
        $$ = std::make_shared<Construire>($2,$4);    	
    } |
    VAR NL {
    	$$ = std::make_shared<Affect>($1);
    }

RAYON:
	'(' expression ')' {
		$$ = std::make_shared<RAYON>($2);
	}|
	%empty {
		$$ = std::make_shared<RAYON>();
	}

STATEMENTS:
	STATEMENT NL STATEMENTS {
    $$=$3;
    $$.push_back($1);
    } |
    NL STATEMENTS {$$=$2;}|
	%empty {$$=std::vector<ExpressionPtr>();}

STATEMENT:
	BASE {$$=$1}|
	MANAGE {$$=$1}|
	VAR {$$=$1}|
	KEVIN {$$=$1}|
	CONDLOOP {$$=$1}|


COORD:
	'(' expression ',' expression ',' expression ')' {
		$$ = std::make_shared<COORD>($2,$4,$6);
	}


NODE:
	id_maison {
		$$ = std::make_shared<NODE>($1);
	} |
	maison '[' expression ']' {
		$$ = std::make_shared<NODE>($3);
	}|
	COORD {
		$$ = std::make_shared<NODE>($1);
	}

BASE:
	HOUSE {
		$$=$1;
	} |
	HOUSE COORD {
		$1.setCOORD($2);
		$$=$1;
	} |
	Route NODE arrow NODE {
		$$ = std::make_shared<Route>($2,$4);
	}

HOUSE:
	Maison {
		$$ = std::make_shared<Maison>();
	} |
	Maison id_maison {
		$$ = std::make_shared<Maison>($2);
	}

MANAGE:
	Tourner NODE HORAIRE {
		$$ = std::make_shared<Tourner>($2,$3);
	} |
	Orienter NODE expression degree {
		$$ = std::make_shared<Orienter>($2,$3);
	}  |
	Deplacer NODE arrow COORD {
		$$ = std::make_shared<Deplacer>($2,$4);
	} |
	Detruire NODE {
		$$ = std::make_shared<Detruire>($2);
	} |
	Detruire NODE arrow NODE{
		$$ = std::make_shared<Detruire>($2,$4);
	} |
	Position NODE {
		$$ = std::make_shared<Position>($2);
	} |
	Orientation NODE {
		$$ = std::make_shared<Orientation>($2);
	} |
	Voisinage NODE {
		$$ = std::make_shared<Voisinage>($2);
	}
	
HORAIRE:
	horaire {
		$$ = 1;
	} |
	'!' horaire {
		$$ = -1;
	} 


VAR: 
	id_var '=' expression {
		$$ = std::make_shared<Affect>($1,$3);
	} 

KEVIN:
	Coloriser NODE COLOR {
		$$ = std::make_shared<Coloriser>($2,$3);
	} |
	Couleur NODE {
		$$ = std::make_shared<Couleur>($2);
	} |
	Voisin NODE expression {
		$$ = std::make_shared<Voisin>($2,$3);
	}
COLOR:
	hex_RGB {
		$$ = std::make_shared<hexRGB>($1);
	} |
	COORD {
		$$ = $1;
	}

CONDLOOP:
	Si expression '{' STATEMENTS '}' SINON {
		$$ = std::make_shared<Si>($2,$4,$6); 
	} |
	Tant que expression '{' STATEMENTS '}' {
		$$ = std::make_shared<TantQue>($3,$5);
	} |
	Repeter expression fois '{' STATEMENTS '}' {
		$$ = std::make_shared<Repeter>($2,$5);
	}
SINON:
	Sinon '{' STATEMENTS '}' {
		$$ = $3;
	} |
	%empty {
		$$ = std::vector<ExpressionPtr>();
	}

expression:
    num {
        $$ = std::make_shared<Constante>($1);
    } 
    | id_maison {
        $$ = std::make_shared<IDMaison>($1);
    }
    | id_var {
        $$ = std::make_shared<Variable>($1);
    }
    | '(' expression ')' {
        $$ = $2;
    }
    | expression '+' expression {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::plus);
    }
    | expression '-' expression {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::moins);
    }
    | expression '*' expression {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::multiplie);
    }
    | expression '/' expression {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::divise);
    }
    | '-' expression %prec NEG {
        $$ = std::make_shared<ExpressionUnaire>($2, OperateurUnaire::neg);
    } |


    expression eq expression {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::egal);
    } |
    expression ne expression {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::negal);
    } |
    expression inf expression {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::inf);
    } |
    expression sup expression {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::sup);
    } |
    '!' expression %prec NEG {
        $$ = std::make_shared<ExpressionUnaire>($2, OperateurUnaire::lneg);
    }
%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
