#ifndef LEXER_H
#define LEXER_H

#include "token.h"

// Store current state of Lexer

typedef struct LEXER_STRUCT 
{
    // Current character
    char c;
    // Index
    unsigned int i;
    // Source code to be lexed
    char* contents;
} lexer_T;

// Lexer methods
lexer_T* initLexer(char* contents);

// Move pointer to next character in the content
void advanceLexer(lexer_T* lexer);

// Skip whitespace
void skipWhitespace(lexer_T* lexer);

// Get to the next token in the contents
token_T* getNextToken(lexer_T* lexer);

// Parse strings
token_T* getString(lexer_T* lexer);

// Parse ID
token_T* getID(lexer_T* lexer);

// Helper method
token_T* advanceLexerWithToken(lexer_T* lexer, token_T* token);

// Get current character, and return it as a string
char* getCurrentCharAsString(lexer_T* lexer);

#endif