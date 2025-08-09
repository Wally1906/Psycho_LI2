#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "stack.h"
#include "functions.h"


int main(){
	Stack* stack = create_stack();
	char* input = NULL;
	char** tokens = reader(input,0);
	fill_globals();

	handler(stack,tokens);
	//printf("%p\n",stack);
	print_stack(stack);
	free(tokens);
	free(input);
	return 0;
}


