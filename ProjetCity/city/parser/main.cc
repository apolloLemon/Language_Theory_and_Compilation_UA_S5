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
	//std::cout << "launchFile\n";
	//std::cout << "optarg"<<optarg<<std::endl;
	Driver driver;
	std::ifstream fichier(optarg);
	Scanner scanner(fichier, std::cout);
    yy::Parser parser(scanner, driver);
    parser.parse();
}

int main( int  argc, char* argv[]) {
    //Driver driver;
	
	int opt;
    while((opt = getopt(argc,argv,"f:s")) !=-1){
		switch(opt){
			case 's': 
				launchSTD();
			break;
			case 'f': 
			//std::cout << "case f\n";
				launchFile(optarg);
			break;
			default:
				std::cerr<<"Error"<<std::endl;
				exit(EXIT_FAILURE);
		}
	}
	/*
    Scanner scanner(std::istream, std::cout);
    yy::Parser parser(scanner, driver);

    parser.parse();
	*/
    return 0;
}
