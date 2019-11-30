%{
#include "../scanner.hh"
#define YY_NO_UNISTD_H
%}
%option c++
%option yyclass="Scanner"
%option cnoyywrap

entier [0-9]+
decimal (,[0-9]+)?
nombre {entier}{decimal}

chaine (\"([^")|\\\")*\")

%%

{chaine} 	{
	std::cout<<"String detected : " <<YYText() <<" de longeur " << YYLeng()-2 << std::end;
}

begin|end	{
	std::count << "Keywords : " << YYText() << std::endl;
}

{nombre}	{
	std::cout<<"Nombre : " <<YYText() << std::endl;
}

[a-zA-Z][a-zA-Z0-9]*   {
    std::cout << "Identificateur : " << YYText() << std::endl;
}

[+\-/\*]|(\*\*)   {
    std::cout << "Operateur : " << YYText() << std::endl;
}

.           {
    /* 
     * The section between %% of the scanner.ll file defines the yylex fonction, thus we can acces the methods and members of the Scanner class
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
