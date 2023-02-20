#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include "parser/parser.h"
#include "parselet/name_parselet/name_parselet.h"
#include "parselet/integer_parselet/integer_parselet.h"
#include "parselet/operator_parselet/operator_parselet.h"
#include "scanner/scanner.h"

static void registerGrammmar(Parser* parser) {

	parser->registerPrefix(Token::TokenType::NAME, new NameParselet());
	parser->registerPrefix(Token::TokenType::INTEGER, new IntegerParselet());
	parser->registerInfix(Token::TokenType::PLUS, new OperatorParselet());
	parser->registerInfix(Token::TokenType::MINUS, new OperatorParselet());
	parser->registerInfix(Token::TokenType::MULT, new OperatorParselet());
	parser->registerInfix(Token::TokenType::DIVIDE, new OperatorParselet());
	parser->registerInfix(Token::TokenType::EOL, new OperatorParselet()); // May change parselet

}

static void runRepl() {

	std::string userIn;
	
	// Iterate once for now 
	for (;;) {
		std::cout << "> ";
		std::getline(std::cin, userIn);

		Scanner scanner(userIn);
		std::vector<Token> tokenStream = scanner.scanTokens();

		Parser parser(tokenStream);
		registerGrammmar(&parser);

		InterfaceExpression* testingvar = parser.cTesting(0);

		// printing results
		std::cout << "\nprecedence parsing: \n\n" << testingvar->print() << std::endl;
		std::cout << "\nstack-based interpreter\n" << std::endl;
		std::cout << "result: " << parser.stackTest.top() << std::endl;
	}
}

int main(int argc, char* argv[]) {

	if (argc == 1) { runRepl(); } 

} 

