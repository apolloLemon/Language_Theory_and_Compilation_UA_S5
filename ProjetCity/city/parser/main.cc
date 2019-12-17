#include "parser.hpp"
#include "scanner.hh"
#include "driver.hh"

#include <iostream>
#include <fstream>

#include <cstring>

#include <getopt.h>

void launchSTD (){
	Driver driver;
	Scanner scanner(std::cin, std::cout);
    yy::Parser parser(scanner, driver);
    parser.parse();	
}

void launchFile(const char* optarg){
	Driver driver;
	std::ifstream fichier(optarg);
	Scanner scanner(fichier, std::cout);
    yy::Parser parser(scanner, driver);
    parser.parse();
    //THE DRIVER HAS NOW RETURNED
	std::cout << "i="<<driver.getVariable("i")<<std::endl;
	//driver.getHouse(0);
	//driver.getGraph();
	//driver.getAST();
	for(auto i : driver.ast)
		if(i!=driver.ast->end())
		i->calculer(driver.getContexte());
	//driver.exec();
}

int main( int  argc, char* argv[]) {
    int opt;
    while((opt = getopt(argc,argv,"f:s")) !=-1){
		switch(opt){
			case 's': 
				launchSTD();
			break;
			case 'f': 
				launchFile(optarg);
			break;
			default:
				//std::cerr<<"Error"<<std::endl;
				exit(EXIT_FAILURE);
		}
	}
	//std::cout << "Hello2\n";
    return 0;
}
