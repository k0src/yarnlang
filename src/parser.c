#include "include/parser.h"


parser_T* initParser(lexer_T* lexer)
{
    parser_T* parser = calloc(1, sizeof(struct PARSER_STRUCT));
    parser->lexer = lexer;
    parser->currentToken = getNextToken(lexer);

    return parser;
}

parser_T* parserEat(parser_T* parser, int tokenType)
{
    if (parser->currentToken->type == tokenType)
        parser->currentToken = getNextToken(parser->lexer);
    else 
    {
        printf("Unexpected token :( -> %s, Type -> %d", parser->currentToken->value, parser->currentToken->type);
        exit(1);
    }
}

AST_T* parserParse(parser_T* parser)
{
    return parseStatements(parser);
}

AST_T* parseStatement(parser_T* parser)
{
    switch (parser->currentToken->type)
    {
        case TOKEN_ID: return parseID(parser);
    }
}

AST_T* parseStatements(parser_T* parser)
{
    AST_T* compound = initAST(AST_COMPOUND);
    compound->compoundValue = calloc(1, sizeof(struct AST_STRUCT*));
    
    AST_T* astStatement = parseStatement(parser);
    compound->compoundValue[0] = astStatement;

    while (parser->currentToken->type == TOKEN_TERMIN)
    {
        parserEat(parser, TOKEN_TERMIN);

        AST_T* astStatement = parseStatement(parser);
        compound->compoundSize += 1;
        compound->compoundValue = realloc(compound->compoundValue, compound->compoundSize * sizeof(struct AST_STRUCT*));
        compound->compoundValue[compound->compoundSize - 1] = astStatement;
    }
    
    return compound;
}

AST_T* parseExpr(parser_T* parser)
{
    switch (parser->currentToken->type)
    {
        case TOKEN_STRING: return parseString(parser);
    }
}

AST_T* parseFactor(parser_T* parser)
{

}

AST_T* parseTerm(parser_T* parser)
{

}

AST_T* parseFuncCall(parser_T* parser)
{

}

AST_T* parseVarDefinition(parser_T* parser) 
{
    parserEat(parser, TOKEN_ID); //var 
    char* varDefVarName = parser->currentToken->value;
    parserEat(parser, TOKEN_ID); // var name
    parserEat(parser, TOKEN_EQUALS);
    AST_T* varDefValue = parseExpr(parser);

    AST_T* varDefintion = initAST(AST_VAR_DEFINE);
    varDefintion->varDefVarName = varDefVarName;
    varDefintion->varDefValue = varDefValue;

    return varDefintion;
}

AST_T* parseVar(parser_T* parser)
{
    char* tokenValue = parser->currentToken->value;
    parserEat(parser, TOKEN_ID); // var or func call

    if (parser->currentToken->type == TOKEN_LBRAK)
        return parseFuncCall(parser);

    AST_T* astVar = initAST(AST_VAR);
    astVar->variableName = tokenValue;

    return astVar;
}

AST_T* parseString(parser_T* parser)
{
    AST_T* astString = initAST(AST_STRING);
    astString->stringValue = parser->currentToken->value;

    parserEat(parser, TOKEN_STRING);

    return astString;
}

AST_T* parseID(parser_T* parser)
{
    if (strcmp(parser->currentToken->value, "yarn") == 0)
    {
        return parseVarDefinition(parser);
    }
    else
    {
        return parseVar(parser);
    }
}