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
		{Token::TokenType::EOL, 0},
		{Token::TokenType::PLUS, 3},
		{Token::TokenType::MINUS, 3},
		{Token::TokenType::MULT, 4},
	};
	int prevPrecedence = 0;

	// CLOX Variables 
	Token* curr = &tokenStream[0];
	Token* prev = 0; // mimics the first advance() in CLOX

	Parser(std::vector<Token> tokenStream) : tokenStream(tokenStream) {};

	Token* consume();
	Token* lookAhead();
	void registerPrefix(Token::TokenType type, InterfacePrefixParselet* ptr);
	void registerInfix(Token::TokenType type, InterfaceInfixParselet* ptr);
	void printMaps();
	int getPrecedenceNext();
	int getPrecedence(); 

	// CLOX Methods
	Token* advance(); // should return the prev token...

	InterfaceExpression* parseExpression(int precedence);
	InterfaceExpression* testing(int precedence);
	std::string cTesting(int precedence);
};	

#endif 
