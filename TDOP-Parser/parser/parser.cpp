#include "parser.h"

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
//
//}
