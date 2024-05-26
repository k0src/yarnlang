#include "include/scope.h"

scope_T* initScope()
{
    scope_T* scope = calloc(1, sizeof(struct SCOPE_STRUCT));
    scope->funcDefintions = (void*)0;
    scope->funcDefintionsSize = 0;

    return scope;
}

AST_T* scopeAddFunctionDefinition(scope_T* scope, AST_T* fdef)
{
    scope->funcDefintionsSize += 1;

    if (scope->funcDefintions == (void*)0)
    {
        scope->funcDefintions = calloc(1, sizeof(struct AST_STRUCT*));
    }
    else
    {
        scope->funcDefintions = realloc(scope->funcDefintions, scope->funcDefintionsSize * sizeof(struct AST_STRUCT**));
    }

    scope->funcDefintions[scope->funcDefintionsSize - 1] = fdef;

    return fdef;
}

AST_T* scopeGetFunctionDefinition(scope_T* scope, const char* name)
{
    for (int i = 0; i < scope->funcDefintionsSize; i++)
    {
        AST_T* fdef = scope->funcDefintions[i];
        if (strcmp(fdef->funcDefName, name) == 0)
        {
            return fdef;
        }
    }

    return (void*)0;
}