#include <iostream>
#include <vector>
#include <string>

#include "parser/parser.h"

int main() {

	std::vector<Token> tokenStream = {
		Token(Token::TokenType::INTEGER, "2"),
		Token(Token::TokenType::PLUS, "+"),
		Token(Token::TokenType::INTEGER, "3"),
		Token(Token::TokenType::MULT, "*"),
		Token(Token::TokenType::INTEGER, "4"),
	};
	
	Parser parser(tokenStream);

} 

