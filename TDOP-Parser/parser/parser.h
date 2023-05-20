#ifndef PARSER
#define PARSER

#include <vector>
#include <string>
#include <map>
#include <stack>

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
	
	std::stack<double> stackTest;
	
	std::map<Token::TokenType, int> precedenceMap = {
		{Token::TokenType::EOL, -1},
		{Token::TokenType::PLUS, 3},
		{Token::TokenType::MINUS, 2},
		{Token::TokenType::MULT, 4},
		{Token::TokenType::DIVIDE, 5},
	};
	int prevPrecedence = 0;
 
	Token* curr = &tokenStream[0];
	Token* prev = 0;
	 
	Parser(std::vector<Token> tokenStream) : tokenStream(tokenStream) {};

	void printMaps();
	int getPrecedence(); 
	Token* advance();
	void stackEval(Token* token);
	InterfaceExpression* parseExpression(int precedence);
};	

#endif 
