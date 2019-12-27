#include "parser.hpp"
#include "scanner.hh"
#include "driver.hh"

#include <iostream>
#include <fstream>

#include <cstring>
#include <getopt.h>

#include <random>
#include <time.h>

int main( int  argc, char* argv[]) {
	srand(time(NULL));
 	Driver driver;
	Scanner scanner(std::cin, std::cout);
    yy::Parser parser(scanner, driver);
    parser.parse();   
    std::cout<<"Parsing done, now AST.exec\n"
    		<<driver.ast.size()<<" functions\n";
    for(auto exp : driver.ast)
    	exp->calculer(driver.getContexte());
    return 0;
}
