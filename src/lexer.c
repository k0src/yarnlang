#include "include/lexer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

lexer_T* initLexer(char* contents)
{
    // Alloctae memory for Lexer, initalize content and first character
    lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->contents = contents;
    lexer->i = 0;
    lexer->c = contents[lexer->i];

    return lexer;
}

void advanceLexer(lexer_T* lexer)
{
    // Move to next character
    if (lexer->c != '\0' && lexer->i < strlen(lexer->contents)) 
    {
        lexer->i++;
        lexer->c = lexer->contents[lexer->i];
    }
}

void skipWhitespace(lexer_T* lexer) 
{
    // Advance lexer if current char is whitespace or new line
    while (lexer->c == ' ' || lexer->c == 10)
    {
        advanceLexer(lexer);
    }
}    

token_T* getNextToken(lexer_T* lexer)
{
    // While there is still text to parse, keep getting next token
    while (lexer->c != '\0' && lexer->i < strlen(lexer->contents)) 
    {
        if (lexer->c == ' ' || lexer->c == 10)
            advanceLexer(lexer);

        if (lexer->c == '"')
            return getString(lexer);

        if (isalnum(lexer->c))
            return getID(lexer);

        switch (lexer->c)
        {
            case ':': return advanceLexerWithToken(lexer, 
                            initToken(TOKEN_EQUALS,
                            getCurrentCharAsString(lexer)));
                            break;
            case '|': return advanceLexerWithToken(lexer,
                            initToken(TOKEN_TERMIN,
                            getCurrentCharAsString(lexer)));
                            break;
            case '<': return advanceLexerWithToken(lexer,
                            initToken(TOKEN_LBRAK,
                            getCurrentCharAsString(lexer)));
                            break;
            case '>': return advanceLexerWithToken(lexer,
                            initToken(TOKEN_RBRAK,
                            getCurrentCharAsString(lexer)));
                            break;
            case '+': return advanceLexerWithToken(lexer,
                            initToken(TOKEN_ADD,
                            getCurrentCharAsString(lexer)));
                            break;
            case '-': return advanceLexerWithToken(lexer,
                            initToken(TOKEN_SUB,
                            getCurrentCharAsString(lexer)));
                            break;
            case '*': return advanceLexerWithToken(lexer,
                            initToken(TOKEN_MUL,
                            getCurrentCharAsString(lexer)));
                            break;
            case '/': return advanceLexerWithToken(lexer,
                            initToken(TOKEN_DIV,
                            getCurrentCharAsString(lexer)));
                            break;
            case ',': return advanceLexerWithToken(lexer,
                            initToken(TOKEN_COMMA,
                            getCurrentCharAsString(lexer)));
                            break;
 
        }
    }

    return initToken(TOKEN_EOF, "\0");
}

token_T* getString(lexer_T* lexer)
{
    // Skip " and find next "
    advanceLexer(lexer);

    char* value = calloc(1, sizeof(char));
    value[0] = '\0';

    // Add to new string
    while (lexer->c != '"') 
    {
        char* s = getCurrentCharAsString(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value, s);

        advanceLexer(lexer);
    }

    advanceLexer(lexer);

    return initToken(TOKEN_STRING, value);
}

token_T* getID(lexer_T* lexer) 
{
    char* value = calloc(1, sizeof(char));
    value[0] = '\0';
    
    while (isalnum(lexer->c)) 
    {
        char* s = getCurrentCharAsString(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value, s);

        advanceLexer(lexer);
    }

    return initToken(TOKEN_ID, value);
}

token_T* advanceLexerWithToken(lexer_T* lexer, token_T* token)
{
    advanceLexer(lexer);
    return token;
}

char* getCurrentCharAsString(lexer_T* lexer)
{
    char* str = calloc(2, sizeof(char));
    str[0] = lexer->c;
    str[1] = '\0';

    return str;
}