#ifndef SCOPE_H
#define SCOPE_H

#include "AST.h"
#include <string.h>

typedef struct SCOPE_STRUCT
{
    AST_T** funcDefintions;
    size_t funcDefintionsSize;
} scope_T;

scope_T* initScope();

AST_T* scopeAddFunctionDefinition(scope_T* scope, AST_T* fdef); 

AST_T* scopeGetFunctionDefinition(scope_T* scope, const char* name);

#endif