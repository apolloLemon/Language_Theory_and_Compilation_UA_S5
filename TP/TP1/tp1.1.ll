%{
#include "scanner.hh"
#define YY_NO_UNISTD_H
%}

%option c++
%option yyclass="Scanner"
%option noyywrap

%%
^[ ]+ ;

[ ]+   {
    std::cout << " ";
}


.           {
    /* 
     * The section between %% of the scanner.ll file defines the yylex fonction, thus we can acces the methods and members of the Scanner class
     */

     std::cout << YYText();
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
