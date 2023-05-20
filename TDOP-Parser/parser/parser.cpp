#include "parser.h"
#include <iostream>
#include "../parselet/interface_prefix_parselet.h"
#include "../parselet/interface_infix_parselet.h"
#include "../parselet/integer_parselet/integer_parselet.h"
#include "../parselet//name_parselet//name_parselet.h"
#include "../parselet/operator_parselet/operator_parselet.h"

std::map<Token::TokenType, InterfacePrefixParselet*> prefixMap = {
		{Token::TokenType::NAME, new NameParselet()},
		{Token::TokenType::INTEGER, new IntegerParselet()},
};

std::map<Token::TokenType, InterfaceInfixParselet*> infixMap = {
		{Token::TokenType::PLUS, new OperatorParselet()},
		{Token::TokenType::MINUS, new OperatorParselet()},
		{Token::TokenType::MULT, new OperatorParselet()},
		{Token::TokenType::DIVIDE, new OperatorParselet()},
		{Token::TokenType::EOL, new OperatorParselet()},
};

Token* Parser::advance() {

	prev = curr;
	++curr;	 
	return prev;
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

void Parser::stackEval(Token * token) {

	// Pop the values from stack
	double b = stackTest.top();
	stackTest.pop();

	double a = stackTest.top();
	stackTest.pop();

	double result = 0;

	if (token->type == Token::TokenType::MULT) { result = a * b; }
	if (token->type == Token::TokenType::DIVIDE) { result = a / b; }
	if (token->type == Token::TokenType::PLUS) { result = a + b; }
	if (token->type == Token::TokenType::MINUS) { result = a - b; }
	
	stackTest.push(result);
}

InterfaceExpression* Parser::parseExpression(int precedence) {

	Token* token = advance();
	
	if (prefixMap.find(token->type) == prefixMap.end()) { std::cout << "ERROR: Prefix Not Found"; exit(0); }

	InterfacePrefixParselet* prefixParselet = prefixMap[token->type];
	InterfaceExpression* left = prefixParselet->parse(this, *token);
	
	stackTest.push(stoi(left->print()));

	while (precedence <= getPrecedence()) {
		
		token = advance();

		InterfaceInfixParselet* infixParselet = infixMap[token->type]; 
		left = infixParselet->parse(this, left, *token);  

		stackEval(token);
	}

	return left;
}
