#ifndef VISITOR_H
#define VISITOR_H

#include "AST.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scope.h"

typedef struct VISITOR_STRUCT
{
    AST_T** variable_definitions;
    size_t variable_definitions_size;
} visitor_T;

visitor_T* initVisitor();

AST_T* visitorVisit(visitor_T* visitor, AST_T* node);

AST_T* visitorVisitVarDef(visitor_T* visitor, AST_T* node);

AST_T* visitorVisitFuncDef(visitor_T* visitor, AST_T* node);

AST_T* visitorVisitVar(visitor_T* visitor, AST_T* node);

AST_T* visitorVisitFuncCall(visitor_T* visitor, AST_T* node);

AST_T* visitorVisitString(visitor_T* visitor, AST_T* node);

AST_T* visitorVisitCompound(visitor_T* visitor, AST_T* node);

#endif