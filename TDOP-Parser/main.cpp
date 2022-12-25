#include <iostream>
#include <vector>
#include <string>

#include "parser/parser.h"
#include "parselet/name_parselet/name_parselet.h"

int main() {

	// Will read from file later on
	std::vector<Token> tokenStream = { 
		Token(Token::TokenType::NAME, "Jan"),
		Token(Token::TokenType::INTEGER, "2"),
		Token(Token::TokenType::PLUS, "+"),
		Token(Token::TokenType::INTEGER, "3"),
		Token(Token::TokenType::MULT, "*"),
		Token(Token::TokenType::INTEGER, "4"),
		Token(Token::TokenType::EOL, "EOL")
	};

	Parser parser(tokenStream);  

	parser.registerPrefix(Token::TokenType::NAME, new NameParselet());

	parser.parseExpression(); 

} 

