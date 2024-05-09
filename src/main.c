#include <stdio.h>
#include "include/lexer.h"

int main(int argc, char* argv[]) 
{
    lexer_T* lexer = initLexer(
    "yarn : \"Lonnie Liston Smith\"|\n"
    "say<name>|\n" 
    ); 

    token_T* token = (void*)0;

    while ((token = getNextToken(lexer)) != (void*)0)
    {
        printf("TOKEN(%d, %s)\n", token->type, token->value);
    }
    return 0;
}