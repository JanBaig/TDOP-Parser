#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include "parser/parser.h"
#include "scanner/scanner.h"

static void runRepl() {

	std::string userIn;
	
	// Iterate once for now  
	for (;;) {
		std::cout << "> ";
		std::getline(std::cin, userIn);

		Scanner scanner(userIn);
		std::vector<Token> tokenStream = scanner.scanTokens();

		Parser parser(tokenStream);

		InterfaceExpression* testingvar = parser.parseExpression(0);

		// printing results
		std::cout << "\nPrecedence parsing: \n" << testingvar->print() << std::endl;
		std::cout << "\nInterpreter Result:\n" << parser.stackTest.top() << "\n" << std::endl;
	}
}

int main(int argc, char* argv[]) {

	if (argc == 1) { runRepl(); } 

} 

