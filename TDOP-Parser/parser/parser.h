#ifndef PARSER
#define PARSER

#include <vector>
#include <string>
#include <map>

#include "../token/token.h"
#include "../expressions/interface_expression.h"

// Forward declaration
class InterfacePrefixParselet; 
class InterfaceInfixParselet;

class Parser {

public: 

	std::vector<Token> tokenStream;
	Token* currToken = &tokenStream[0];
	Token* nextToken = currToken;
	std::map<Token::TokenType, InterfacePrefixParselet*> prefixMap;
	std::map<Token::TokenType, InterfaceInfixParselet*> infixMap;
	std::map<Token::TokenType, int> precedenceMap = {
		{Token::TokenType::PLUS, 3},
		{Token::TokenType::MINUS, 3},
		{Token::TokenType::MULT, 4},
	};

	Parser(std::vector<Token> tokenStream) : tokenStream(tokenStream) {};

	Token* consume();
	Token* lookAhead();
	void registerPrefix(Token::TokenType type, InterfacePrefixParselet* ptr);
	void registerInfix(Token::TokenType type, InterfaceInfixParselet* ptr);
	void printMaps();
	int getPrecedenceNext();
	int getPrecedence();

	InterfaceExpression* parseExpression(int precedence);
	std::string testing(int precedence);
};	

#endif 
