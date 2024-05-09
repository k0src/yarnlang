#ifndef TOKEN_H
#define TOKEN_H

// Tokens are the basic unit of data that the lexer will process.
// We need tokens for strings, variables, numbers, etc...

typedef struct TOKEN_STRUCT
{
    enum
    {
        TOKEN_ID,
        TOKEN_EQUALS,
        TOKEN_STRING,
        TOKEN_TERMIN,
        TOKEN_LBRAK,
        TOKEN_RBRAK
    } type;

    char* value;
} token_T;

// Create the token
token_T* initToken(int type, char* value);

#endif