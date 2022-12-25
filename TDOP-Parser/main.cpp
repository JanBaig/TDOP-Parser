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

	for (Token* i = parser.currToken; i->type != Token::TokenType::EOL; i = parser.consume()) {

		std::cout << i->text << std::endl;

	} 

	parser.registerPrefix(Token::TokenType::NAME, new NameParselet());

	for (auto i = parser.prefixMap.begin(); i != parser.prefixMap.end(); i++) {
		
		std::cout << i->first << " : " << i->second << std::endl;

	}

} 

