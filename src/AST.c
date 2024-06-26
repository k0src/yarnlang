#include "include/AST.h"

AST_T* initAST(int type) 
{
    AST_T* ast = calloc(1, sizeof(struct AST_STRUCT));
    ast->type = type;

    ast->scope = (void*)0;

    ast->varDefVarName = (void*)0;
    ast->varDefValue = (void*)0;

    ast->funcDefBody = (void*)0;
    ast->funcDefName = (void*)0;
    ast->funcDefArgs = (void*)0;
    ast->funcDefArgsSize = 0;

    ast->variableName = (void*)0;

    ast->funcCallName = (void*)0;
    ast->funcCallArguments = (void*)0;
    ast->funcCallArgumentsSize = 0;

    ast->stringValue = (void*)0;

    ast->compoundValue = (void*)0;
    ast->compoundSize = 0;

    return ast;
}