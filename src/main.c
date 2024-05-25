#include <stdio.h>
#include "include/lexer.h"
#include "include/parser.h"
#include "include/visitor.h"
#include "include/io.h"

void printHelp()
{
    printf("Usage:\nyarn.out <filename>\n");
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printHelp();
        return 1;
    }

    char* file_contents = getFileContents(argv[1]);
    if (file_contents == NULL) {
        printf("Error: Failed to open file '%s'\n", argv[1]);
        return 1;
    }

    lexer_T* lexer = initLexer(file_contents);

    parser_T* parser = initParser(lexer);
    AST_T* root = parserParse(parser);

    visitor_T* visitor = initVisitor();
    visitorVisit(visitor, root);

    free(file_contents); 

    return 0;
}