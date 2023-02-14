# TDOP-Parser

Top Down Operator Precedence (TDOP) parsing is a parsing technique introduced by Vaughan Pratt in a 1973 paper. 
The technique combines the best properties of recursive descent and operator precedence.

This program can successfully parse a given expression in accordance to a predefined set of precedence rules.

## Example
```
2 * 10 / 5 - 1 + 4
```
In accordance to BEDMAS, the above expression can be parsed into:
```
( ( 2 * ( 10 / 5 ) ) - ( 1 + 4 ) )
```

## Future Goals
- [ ] Implement a lexer to spit out tokens
- [ x ] Implement stack-based interpreter


