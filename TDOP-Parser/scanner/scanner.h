#ifndef SCANNER
#define SCANNER

#include <string>
#include <vector>
#include "../token/token.h"

class Scanner {

public: 

	std::string source;
	std::vector<Token> tokenVec;
	int start = 0;
	int current = 0;

	Scanner(std::string source) : source(source) {};

	std::vector<Token> scanTokens();
	bool isAtEnd();
	void scanToken();
	char advance();
	void number();
	char peek();
	void printTokens();

};

#endif
