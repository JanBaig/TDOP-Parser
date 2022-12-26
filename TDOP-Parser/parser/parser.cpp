#include "parser.h"
#include <iostream>
#include "../parselet/interface_prefix_parselet.h" // what was the forward declaration for then?
#include "../parselet/interface_infix_parselet.h"

Token* Parser::consume() {
	// Returns the next token
	return ++Parser::currToken; 
}

void Parser::registerPrefix(Token::TokenType type, InterfacePrefixParselet* ptr) { 
	
	Parser::prefixMap[type] = ptr;
} 

void Parser::registerInfix(Token::TokenType type, InterfaceInfixParselet* ptr) {
	
	Parser::infixMap[type] = ptr;
}

void Parser::printMaps() {

	std::cout << "Prefix:\n";
	for (auto i = Parser::prefixMap.begin(); i != Parser::prefixMap.end(); i++) {
		std::cout << i->first << std::endl;
	} 

	std::cout << "Infix\n";
	for (auto i = Parser::infixMap.begin(); i != Parser::infixMap.end(); i++) {
		std::cout << i->first << std::endl;
	}
}

InterfaceExpression* Parser::parseExpression() {
	// Should consume the next token from here
	auto prefix = Parser::prefixMap.find(currToken->type); 
	if (prefix == Parser::prefixMap.end()) { std::cout << "ERROR: Prefix Not Found"; exit(0); }
	
	InterfacePrefixParselet* prefixParselet = Parser::prefixMap[currToken->type];
	InterfaceExpression* leftExpression = prefixParselet->parse(*this, *currToken);

	 Token* token = consume(); // should be lookahead without consuming
	 auto infix = Parser::infixMap.find(currToken->type);
	 if (infix == Parser::infixMap.end()) { return leftExpression; }

	 InterfaceInfixParselet* infixParselet = Parser::infixMap[currToken->type];
	 InterfaceExpression* binaryExpression = infixParselet->parse(*this, leftExpression, *currToken);

	return binaryExpression;
}

