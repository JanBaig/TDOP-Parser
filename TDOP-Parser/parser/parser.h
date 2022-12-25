#ifndef PARSER
#define PARSER

#include <vector>
#include <string>
#include <map>

#include "../token/token.h"
#include "../expressions/interface_expression.h"

// Forward declaration
class InterfacePrefixParselet; 

class Parser {

public: 

	std::vector<Token> tokenStream;
	Token* currToken = &tokenStream[0];  
	std::map<Token::TokenType, InterfacePrefixParselet*> prefixMap;

	Parser(std::vector<Token> tokenStream) : tokenStream(tokenStream) {};

	Token* consume();
	void registerPrefix(Token::TokenType type, InterfacePrefixParselet* ptr);

	//InterfaceExpression* parseExpression();

};

#endif 
