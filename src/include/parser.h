#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "AST.h"

typedef struct PARSER_STRUCT
{
    lexer_T* lexer;
    token_T* currentToken;    
} parser_T;

parser_T* initParser(lexer_T* lexer);

parser_T* parserEat(parser_T* parser, int tokenType);

AST_T* parserParse(parser_T* parser);

#endif