%{
#include "scanner.hh"
#define YY_NO_UNISTD_H

int words=0;
int numbers=0;
int punctuation=0;
%}

%option c++
%option yyclass="Scanner"
%option noyywrap

%%
[a-zA-z]+ {
	++words;
}
(-|\+)?[0-9]+((.|,)[0-9]+)? {
    ++numbers;
}
(-|\+)?([0-9]{1,3})([ ][0-9]{1,3})*((.|,)[0-9]+)? { //23 323,00000
	++numbers;
}
[.,;:?!"] {
    ++punctuation;	
}
.           {
     std::cout << YYText();
}

%%

int main( int argc, char* argv[] ) 
{
    Scanner* lexer = new Scanner(std::cin, std::cout);
    while(lexer->yylex() != 0);
    
    // placer son code ici pour effectuer des actions après le parsing du fichier
    std::cout << "Mots:" << words<<"\nNombres: "<<numbers<<"\nPonctuation: "<<punctuation<< std::endl;

    return 0;
}
