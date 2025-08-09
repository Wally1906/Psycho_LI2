#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include "parser.h"
#include "stack.h"
#include "functions.h" 

int isFloat(char* token){
    for(int i = 0; token[i]; i++){
        if(token[i] =='.'){
            return 1;
        }
    }
    return 0;
}

void handle_array(void* stack_2p, char** tokens, int* token_p){
    Stack** stack = (Stack**) stack_2p;
    *token_p += 1;
    int chosen = 0;
    Stack* init_array = *stack;
    while(tokens[*token_p]){
        int op_index = 0;
        if(op_index = getOperator(tokens[*token_p])){
            caller(stack,op_index);
        }
        else{
            if(isFloat(tokens[*token_p])){
                    double* elem =malloc(sizeof(double));
                    *elem = atof(tokens[*token_p]); 
                    push(stack, elem, FLOAT);
            }
            else if(strcmp(tokens[*token_p],"[") == 0){
                handle_array(stack,tokens,token_p);
            }
            else if(strcmp(tokens[*token_p],"]") == 0){
                push(stack,init_array,ARRAY_END);   
                token_p++;
                //printf("%p\n",init_array);
                break;
            }
            else{
                int* elem =malloc(sizeof(int));
                *elem = atoi(tokens[*token_p]); 
                push(stack, elem, INT);
            }
            //printf("%p\n",*stack);
        }
        *token_p += 1;
    }
    printf("\n");
}

void handler(void* stack_2p, char** tokens){
    Stack* stack = (Stack*)stack_2p;
    for(int i = 0;tokens[i];i++){
        int op_index = 0;
        if(op_index = getOperator(tokens[i])){
            caller(&stack,op_index);
        }
        else{
            if(isFloat(tokens[i])){
                double* elem =malloc(sizeof(double));
                *elem = atof(tokens[i]); 
                push(&stack, elem, FLOAT);
            }
            else if(strcmp(tokens[i],"[") == 0){
                handle_array(&stack,tokens,&i);
            }
            else{
                int* elem =malloc(sizeof(int));
                *elem = atoi(tokens[i]); 
                push(&stack, elem, INT);
            }
        }
    }
}

void tokenizer(char* string, char** tokens, int size){
    char* token;
    char* svptr;
    int counter = 1;
    
    while((token = strtok_r(string, " \n", &svptr)) != NULL){
        string = NULL;
        if(counter == size){
            tokens = realloc(tokens,size*2*sizeof(char*));
            size *= 2;
        }
        tokens[counter-1] = token;
        tokens[counter] = NULL;
        counter++;
    }
}

char** reader(char* input, size_t size){
	if(getline(&input,&size,stdin)){
        char** tokens = malloc(10*sizeof(char*));
		if (size >= 0){
			tokenizer(input, tokens, 10);
		}
        
        return tokens;
	}
}