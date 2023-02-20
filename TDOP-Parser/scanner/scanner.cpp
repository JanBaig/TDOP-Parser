
#include "scanner.h"
#include <iostream>

bool Scanner::isAtEnd() {

	return current >= source.length();
}

char Scanner::advance() {
	
	return source[current++];
}

char Scanner::peek() {

	if (isAtEnd()) { return ' '; }

	return source[current];
}

void Scanner::number() {
	
	while (isdigit(peek())) { advance(); }

	// Add functionality for decimals here later

	std::string subString = source.substr(start, current - start);
	tokenVec.push_back(Token(Token::TokenType::INTEGER, subString));
}

void Scanner::scanToken() {

	char c = advance();
	
	switch (c) {
		case '+': tokenVec.push_back(Token(Token::TokenType::PLUS, "+")); break;
		case '-': tokenVec.push_back(Token(Token::TokenType::MINUS, "-")); break;
		case '*' : tokenVec.push_back(Token(Token::TokenType::MULT, "*")); break;		
		case '/': tokenVec.push_back(Token(Token::TokenType::DIVIDE, "/")); break;
		case ' ': case '\r': case '\t': case '\n': break;
		default: if (isdigit(c)) { number(); }

	}

}

std::vector<Token> Scanner::scanTokens() {

	while (!isAtEnd()) {
	
		// Start of the next lexeme
		start = current;
		scanToken();
	}

	tokenVec.push_back(Token(Token::TokenType::EOL, "EOL"));
	return tokenVec;
}

void Scanner::printTokens() {

	for (Token i : tokenVec) {
		std::cout << i.text << " -> " << i.type << std::endl;
	}
}

