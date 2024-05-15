#include "include/visitor.h"

static AST_T* builtinPrintFunc(visitor_T* visitor, AST_T** args, int args_size)
{
    for (int i = 0; i < args_size; i++) 
    {
        AST_T* visited = visitorVisit(visitor, args[i]);

        switch (visited->type) 
        {
            case AST_STRING:
                printf("%s\n", visited->stringValue);
                break;
            default:
                printf("%p\n", visited);
                break;
        }
    }
    return initAST(AST_NOOP);
}

visitor_T* initVisitor()
{
    visitor_T* visitor = calloc(1, sizeof(struct VISITOR_STRUCT));
    visitor->variable_definitions = (void*)0;
    visitor->variable_definitions_size = 0;

    return visitor;
}

AST_T* visitorVisit(visitor_T* visitor, AST_T* node)
{
    switch (node->type) 
    {
        case AST_VAR_DEFINE:
            return visitorVisitVarDef(visitor, node);
        case AST_VAR:
            return visitorVisitVar(visitor, node);
        case AST_FUNC_CALL:
            return visitorVisitFuncCall(visitor, node);
        case AST_STRING:
            return visitorVisitString(visitor, node);
        case AST_COMPOUND:
            return visitorVisitCompound(visitor, node);
        case AST_NOOP:
            return node;
    }
    printf("Error: uncaught statement of type: %d\n", node->type);
    exit(1);
}

AST_T* visitorVisitVarDef(visitor_T* visitor, AST_T* node)
{


    if (visitor->variable_definitions == (void*)0) 
    {
        visitor->variable_definitions = calloc(1, sizeof(struct AST_STRUCT*));
        visitor->variable_definitions[0] = node;
        visitor->variable_definitions_size += 1;
    }
    else 
    {
        visitor->variable_definitions_size += 1;
        visitor->variable_definitions = realloc(visitor->variable_definitions, 
                                        (visitor->variable_definitions_size + 1) * sizeof(struct AST_STRUCT*));
        visitor->variable_definitions[visitor->variable_definitions_size - 1] = node;
    }
    return node;
}

AST_T* visitorVisitVar(visitor_T* visitor, AST_T* node)
{
    for (int i = 0; i < visitor->variable_definitions_size; i++) 
    {
        AST_T* varDef = visitor->variable_definitions[i];
        if (strcmp(varDef->varDefVarName, node->variableName) == 0) 
        {
            return visitorVisit(visitor, varDef->varDefValue);
        }
    }
    printf("Error: variable %s not defined\n", node->variableName);
    return node;
}

AST_T* visitorVisitFuncCall(visitor_T* visitor, AST_T* node)
{
    if (strcmp(node->funcCallName, "say") == 0) 
    {
        return builtinPrintFunc(visitor, node->funcCallArguments, node->funcCallArgumentsSize);
    }
    else 
    {
        printf("Error: uncaught function call of name: %s\n", node->funcCallName);
        exit(1);
    }
}

AST_T* visitorVisitString(visitor_T* visitor, AST_T* node)
{
    return node;
}

AST_T* visitorVisitCompound(visitor_T* visitor, AST_T* node)
{
    for (int i = 0; i < node->compoundSize; i++) 
    {
        visitorVisit(visitor, node->compoundValue[i]);
    }

    return initAST(AST_NOOP); // No operation
}