#ifndef TOKEN
#define TOKEN

#include <string>

class Token {

public:
	
	enum TokenType {
		PLUS, 
		MINUS, 
		NAME, 
		MULT, 
		INTEGER
	};

	TokenType type;
	std::string text;

	Token(TokenType type, std::string text) : type(type), text(text) {};

}; 

#endif