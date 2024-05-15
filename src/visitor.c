#include "include/visitor.h"

AST_T* visitorVisit(AST_T* node) 
{
    switch (node->type) 
    {
        case AST_VAR_DEFINE:
            return visitorVisitVarDef(node);
        case AST_VAR:
            return visitorVisitVar(node);
        case AST_FUNC_CALL:
            return visitorVisitFuncCall(node);
        case AST_STRING:
            return visitorVisitString(node);
        case AST_COMPOUND:
            return visitorVisitCompound(node);
        case AST_NOOP:
            return node;
    }
    printf("Error: uncaught statement of type: %d\n", node->type);
    exit(1);
}

AST_T* visitorVisitVarDef(AST_T* node) 
{

}

AST_T* visitorVisitVar(AST_T* node)
{
    
}

AST_T* visitorVisitFuncCall(AST_T* node)
{

}

AST_T* visitorVisitString(AST_T* node)
{

}

AST_T* visitorVisitCompound(AST_T* node)
{
    for (int i = 0; i < node->compoundSize; i++) 
    {
        visitorVisit(node->compoundValue[i]);
    }

    return initAST(AST_NOOP); // No operation
}