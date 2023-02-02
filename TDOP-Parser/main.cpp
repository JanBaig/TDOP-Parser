#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include "parser/parser.h"
#include "parselet/name_parselet/name_parselet.h"
#include "parselet/integer_parselet/integer_parselet.h"
#include "parselet/operator_parselet/operator_parselet.h"

int main() {

	// Will read from file later on
	std::vector<Token> tokenStream = { 

		/*Token(Token::TokenType::INTEGER, "2"),
		Token(Token::TokenType::MULT, "*"),
		Token(Token::TokenType::INTEGER, "10"),
		Token(Token::TokenType::DIVIDE, "/"),
		Token(Token::TokenType::INTEGER, "5"),
		Token(Token::TokenType::MINUS, "-"),
		Token(Token::TokenType::INTEGER, "1"),
		Token(Token::TokenType::PLUS, "+"),
		Token(Token::TokenType::INTEGER, "1"),
		Token(Token::TokenType::EOL, "EOL")*/ 

		Token(Token::TokenType::INTEGER, "2"),
		Token(Token::TokenType::MULT, "*"),
		Token(Token::TokenType::INTEGER, "3"),
		Token(Token::TokenType::PLUS, "+"),
		Token(Token::TokenType::INTEGER, "4"),
		Token(Token::TokenType::EOL, "EOL")

	};

	Parser parser(tokenStream);  

	parser.registerPrefix(Token::TokenType::NAME, new NameParselet());
	parser.registerPrefix(Token::TokenType::INTEGER, new IntegerParselet());
	parser.registerInfix(Token::TokenType::PLUS, new OperatorParselet());
	parser.registerInfix(Token::TokenType::MINUS, new OperatorParselet());
	parser.registerInfix(Token::TokenType::MULT, new OperatorParselet());
	parser.registerInfix(Token::TokenType::DIVIDE, new OperatorParselet());
	parser.registerInfix(Token::TokenType::EOL, new OperatorParselet()); // May change parselet

	InterfaceExpression* testingVar = parser.cTesting(0);  
	
	std::cout << "Precedence Parsing: \n\n" << testingVar->print() << std::endl; 
	std::cout << "\nStack-Based Interpreter: \n\n" << std::endl; 

} 

