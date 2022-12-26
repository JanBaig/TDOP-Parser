#include <string>
#include "operator_expression.h"

std::string OperatorExpression::print() {
	
	std::string binaryExpr = "Binary:\n" + OperatorExpression::left->print() + "\n" + OperatorExpression::operType + "\n" + OperatorExpression::right->print();
	return binaryExpr;
}