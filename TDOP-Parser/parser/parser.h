#ifndef PARSER
#define PARSER

#include <vector>
#include <string>

#include "../token/token.h"

class Parser {

public: 

	std::vector<Token> tokenStream;

	Parser(std::vector<Token> tokenStream) : tokenStream(tokenStream) {};

};

#endif 
