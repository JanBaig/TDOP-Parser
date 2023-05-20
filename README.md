# TDOP-Parser

Top Down Operator Precedence (TDOP) parsing is a parsing technique introduced by Vaughan Pratt in a 1973 paper. 
The technique combines the best properties of recursive descent and operator precedence.

This program can successfully parse and evaluate a given expression in accordance to a predefined set of precedence rules.

## Example
In accordance to BEDMAS, the input expression `2 * 10 / 5 - 1 + 4` can be parsed and evaluated to:
```
> 2 * 10 / 5 - 1 + 4

Precedence Parsing:
( ( 2 * ( 10 / 5 ) ) - ( 1 + 4 ) )

Interpreter results:
-1 
```

## Precedence Table (BEDMAS) 
| Operator      | Precedence |
| ----------- | ----------- |
| `-`   | 0       |
| `+`   | 1        |
| `*`   | 2        |
| `/`   | 3        |

## Future Goals
- [x] Implement a Custom Lexer
- [x] Implement a Stack-based Interpreter
- [ ] Support for Unary & Ternary Operators
- [ ] Allow decimal values as input 
- [ ] Create User Interface

