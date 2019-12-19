#include "parser.hpp"
#include "scanner.hh"
#include "driver.hh"

#include <iostream>
#include <fstream>

#include <cstring>
#include <getopt.h>

int main( int  argc, char* argv[]) {
 	Driver driver;
	Scanner scanner(std::cin, std::cout);
    yy::Parser parser(scanner, driver);
    parser.parse();   
    for(auto exp : driver.ast)
    	exp->calculer();
    return 0;
}
