#include <iostream>
#include <vector>
#include <string>

#include "parser/parser.h"
#include "parselet/name_parselet/name_parselet.h"

int main() {

	std::vector<Token> tokenStream = {
		Token(Token::TokenType::INTEGER, "2"),
		Token(Token::TokenType::PLUS, "+"),
		Token(Token::TokenType::INTEGER, "3"),
		Token(Token::TokenType::MULT, "*"),
		Token(Token::TokenType::INTEGER, "4"),
	};

	Parser parser(tokenStream);  

	NameParselet testing; 
	std::cout << testing.parse(parser, tokenStream[0])->print() << std::endl;

} 

