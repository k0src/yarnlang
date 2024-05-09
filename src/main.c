#include <stdio.h>
#include "include/lexer.h"

int main(int argc, char* argv[]) 
{
    lexer_T* lexer = initLexer(
    "yarn name : \"Lonnie Liston Smith\"|\n"
    "say<name>|\n"
    "yarn x : 10\n"
    "yarn y : 20\n"
    "yarn z : x + y\n" 
    ); 

    token_T* token = (void*)0;

    while ((token = getNextToken(lexer)) != (void*)0)
    {
        printf("TOKEN(%d, %s)\n", token->type, token->value);
    }
    return 0;
}