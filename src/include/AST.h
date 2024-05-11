#ifndef AST_H
#define AST_H

#include <stdlib.h>

typedef struct AST_STRUCT
{
   enum {
        AST_VAR_DEFINE,
        AST_VAR,
        AST_FUNC_CALL,
        AST_STRING,
        AST_COMPOUND
   } type;

    // AST VAR DEFINITION 
    char* varDefVarName;
    struct AST_STRUCT* varDefValue;

    // AST VARIABLE 
    char* variableName;

    // AST FUNCTION CALL
    char* funcCallName;
    struct AST_STRUCT** funcCallArguments;
    size_t funcCallArgumentsSize;

    char* stringValue;

    // AST COMPOUND
    struct AST_STRUCT** compoundValue;
    size_t compoundSize;

} AST_T;

AST_T* initAST(int type);

#endif