#ifndef SCOPE_H
#define SCOPE_H

#include "AST.h"
#include <string.h>

typedef struct SCOPE_STRUCT
{
    AST_T** funcDefintions;
    size_t funcDefintionsSize;
    AST_T** variable_definitions;
    size_t variable_definitions_size;
} scope_T;

scope_T* initScope();

AST_T* scopeAddFunctionDefinition(scope_T* scope, AST_T* fdef); 

AST_T* scopeGetFunctionDefinition(scope_T* scope, const char* name);

AST_T* scopeAddVariableDefinition(scope_T* scope, AST_T* varDef);

AST_T* scopeGetVariableDefinition(scope_T* scope, const char* name);

#endif