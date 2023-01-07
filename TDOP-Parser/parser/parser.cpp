#include "parser.h"
#include <iostream>
#include "../parselet/interface_prefix_parselet.h" // what was the forward declaration for then?
#include "../parselet/interface_infix_parselet.h"

Token* Parser::advance() {

	prev = curr;
	++curr;	 
	return prev;
}

void Parser::registerPrefix(Token::TokenType type, InterfacePrefixParselet* ptr) { 
	
	prefixMap[type] = ptr;
} 

void Parser::registerInfix(Token::TokenType type, InterfaceInfixParselet* ptr) {
	
	infixMap[type] = ptr;
}

void Parser::printMaps() {

	std::cout << "Prefix:\n";
	for (auto i = prefixMap.begin(); i != prefixMap.end(); i++) {
		std::cout << i->first << std::endl;
	} 

	std::cout << "Infix\n";
	for (auto i = infixMap.begin(); i != infixMap.end(); i++) {
		std::cout << i->first << std::endl;
	}
}

int Parser::getPrecedence() {
	
	Token* token = curr;
	
	if (infixMap.find(token->type) == infixMap.end()) { std::cout << "ERROR: Infix " << token->text << " Not Valid"; exit(0); }	
	
	return precedenceMap[token->type];
}

InterfaceExpression* Parser::cTesting(int precedence) {

	Token* token = advance();
	
	if (prefixMap.find(token->type) == prefixMap.end()) { std::cout << "ERROR: Prefix Not Found"; exit(0); }

	InterfacePrefixParselet* prefixParselet = prefixMap[token->type];
	InterfaceExpression* left = prefixParselet->parse(*this, *token);

	while (precedence <= getPrecedence()) {
		
		token = advance(); // gets the infix
		InterfaceInfixParselet* infixParselet = infixMap[token->type]; 
		left = infixParselet->parse(this, left, *token); 
	}

	return left;
}
