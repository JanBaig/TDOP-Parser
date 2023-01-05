#include "parser.h"
#include <iostream>
#include "../parselet/interface_prefix_parselet.h" // what was the forward declaration for then?
#include "../parselet/interface_infix_parselet.h"

// CLOX Methods

Token* Parser::advance() {

	prev = curr;
	++curr;	 
	return prev;
}

// -------------------------

Token* Parser::consume() {

	return currToken++; 
}  

Token* Parser::lookAhead() {
	
	nextToken = currToken;
	return nextToken++;
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

// Delete this later
int Parser::getPrecedenceNext() {
	// Gets precedence for the next token
	Token* old = Parser::currToken;
	old++;
	int precedence = Parser::precedenceMap[old->type];
	return precedence;
}  

int Parser::getPrecedence() {
	
	// This throws an error after we return from the last stack frame. 
	// It already reads the '3' when it calls testing() for the right but it ends up reading '3' again
	// even after the token is already consumed! Should we have global state?

	//Token* token = lookAhead();
	
	Token* token = curr;
	
	if (infixMap.find(token->type) == infixMap.end()) { std::cout << "ERROR: Infix " << token->text << " Not Valid"; exit(0); }	
	
	return precedenceMap[token->type];
}

InterfaceExpression* Parser::parseExpression(int precedence) {

	auto prefix = prefixMap.find(currToken->type); 
	if (prefix == prefixMap.end()) { std::cout << "ERROR: Prefix Not Found"; exit(0); }
	
	InterfacePrefixParselet* prefixParselet = prefixMap[currToken->type];
	InterfaceExpression* leftExpression = prefixParselet->parse(*this, *currToken);
;
 	while (precedence < getPrecedenceNext()) { // next token have a higher precedence?
		consume(); 

		auto infix = infixMap.find(currToken->type);
		if (infix == infixMap.end()) { return leftExpression; }

		InterfaceInfixParselet* infixParselet = infixMap[currToken->type];
		leftExpression = infixParselet->parse(*this, leftExpression, *currToken);
	}

	return leftExpression;
}

InterfaceExpression* Parser::testing(int precedence) {
	
	Token* token = consume();

	if (prefixMap.find(token->type) == prefixMap.end()) { std::cout << "ERROR: Prefix Not Found"; exit(0); }

	InterfacePrefixParselet* prefixParselet = prefixMap[token->type];
	InterfaceExpression* left = prefixParselet->parse(*this, *token); 
	
	while (precedence < getPrecedence()) {
		
		prevPrecedence = getPrecedence(); // for passing into the next call for this function
		
		token = consume(); 

		InterfaceInfixParselet* infixParselet = infixMap[token->type];
		left = infixParselet->parse(*this, left, *token);
		std::cout << left->print() << std::endl;

	}   

	std::cout << left->print() << std::endl;
	return left; // return left here
} 

InterfaceExpression* Parser::cTesting(int precedence) {

	Token* token = advance();
	
	if (prefixMap.find(token->type) == prefixMap.end()) { std::cout << "ERROR: Prefix Not Found"; exit(0); }

	InterfacePrefixParselet* prefixParselet = prefixMap[token->type];
	InterfaceExpression* left = prefixParselet->parse(*this, *token);

	while (precedence <= getPrecedence()) {
		
		token = advance(); // gets the infix
		InterfaceInfixParselet* infixParselet = infixMap[token->type];
		left = infixParselet->parse(*this, left, *token);

	}

	return left;
}
