#include "parser.h"
#include <iostream>
#include "../parselet/interface_prefix_parselet.h" // what was the forward declaration for then?

// Returns the next token
Token* Parser::consume() {

	return ++Parser::currToken; 

}

void Parser::registerPrefix(Token::TokenType type, InterfacePrefixParselet* ptr) { 

	Parser::prefixMap[type] = ptr;
}

//InterfaceExpression* Parser::parseExpression() {
//
//	// prefixInterfaceParselet -> nameparselet -> nameexpression
//	// check if the current token belongs to the prefix category
//	// will need to register the token inside of the prefixHashmaps first
//	// How do integers get parsed? isn't there an Integer token?
//}

void Parser::parseExpression() {

	// Should include a getter .getCurrToken()
	// Check if currToken inside of the prefixMap
	// call the print() method on class InterfaceExpression. then consume next token

	auto prefix = Parser::prefixMap.find(currToken->type); 

	if (prefix == Parser::prefixMap.end()) { std::cout << "ERROR: Not Found"; return; }
	
	InterfacePrefixParselet* parselet = Parser::prefixMap[currToken->type];
	InterfaceExpression* leftExpression = parselet->parse(*this, *currToken);

	std::cout << leftExpression->print() << std::endl; 

}

