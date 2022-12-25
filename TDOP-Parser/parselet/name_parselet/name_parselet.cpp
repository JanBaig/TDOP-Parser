#include "name_parselet.h"
#include "../../expressions/name_expression/name_expression.h"

InterfaceExpression* NameParselet::parse(Parser parser, Token token)
{
	return new NameExpression(token.text);
}
