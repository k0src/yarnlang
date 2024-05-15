#include <stdio.h>
#include "include/lexer.h"
#include "include/parser.h"
#include "include/visitor.h"

int main(int argc, char* argv[]) 
{
    lexer_T* lexer = initLexer(
    "yarn name : \"Lonnie Liston Smith\"|\n"
    "yarn otherName : \"LTJ Bukem\"|\n"
    "say<name, otherName>|\n"
    ); 

    parser_T* parser = initParser(lexer);
    AST_T* root = parserParse(parser);
    visitor_T* visitor = initVisitor();
    visitorVisit(visitor, root);

    return 0;
}