%{

#include "scanner.hh"

#define YY_NO_UNISTD_H

%}

%option c++
%option yyclass="Scanner"
%option noyywrap


%%

[a-zA-Z]+   {
    std::cout << "un mot : " << YYText() << std::endl;
}


.           {
    /* 
     * La section entre %% du fichier scanner.ll correspond à la définition de la fonction yylex, on peut donc accéder au méthodes et aux membres de la classe Scanner 
     */
}

%%

int main( int argc, char* argv[] ) 
{
    Scanner* lexer = new Scanner(std::cin, std::cout);
    while(lexer->yylex() != 0);
    
    // placer son code ici pour effectuer des actions après le parsing du fichier
    std::cout << "Affiche quelque chose après le parsing" << std::endl;

    return 0;
}
