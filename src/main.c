#include <stdio.h>
#include "include/lexer.h"
#include "include/parser.h"

int main(int argc, char* argv[]) 
{
    lexer_T* lexer = initLexer(
    "yarn name : \"Lonnie Liston Smith\"|\n"
    "say<name>|\n"
    ); 

    parser_T* parser = initParser(lexer);
    AST_T* root = parserParse(parser);

    return 0;
}