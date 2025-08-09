#ifndef PARSER_H
#define PARSER_H

void tokenizer(char* string, char** tokens, int size);

char** reader(char* input, size_t size);

void handler(void* stack, char** tokens);

#endif