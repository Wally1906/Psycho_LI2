#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void dup(void* stack_p){
    Stack** stack = (Stack**) stack_p;
    Stack* elem1;
    pop(stack,&elem1);

    Stack* elem2 = dup_node(elem1);
    push_node(stack,elem2);
    push_node(stack,elem1);
}

void poppy(void* stack_p){
    Stack** stack = (Stack**) stack_p;
    Stack* elem1;
    pop(stack,&elem1);
    free_node(elem1);
}

void swap(void* stack_p){
    Stack** stack = (Stack**) stack_p;
    Stack* elem1;
    Stack* elem2;
    pop(stack,&elem1);
    pop(stack,&elem2);
    push_node(stack,elem1);
    push_node(stack,elem2);
}

void rotate(void* stack_p){
    Stack** stack = (Stack**) stack_p;
    Stack* elem1;
    Stack* elem2;
    Stack* elem3;
    Type type1, type2,type3;

    pop(stack,&elem1);
    pop(stack,&elem2);
    pop(stack,&elem3);

    push_node(stack,elem2);
    push_node(stack,elem1);
    push_node(stack,elem3);
}

void bring_forth(void* stack_p){
    Stack** stack = (Stack**) stack_p;
    Stack* elem1;
    pop(stack,&elem1);

    Stack* elem2 = fetch(*stack,return_int(elem1));
    push_node(stack,elem2);

    free(elem1);
}

void trans_char(void* stack_p){
    Stack** stack = (Stack**) stack_p;
    Stack* elem;
    pop(stack,&elem);

    if(get_type(elem)==FLOAT){
        int* val = malloc(sizeof(int));
        *val = return_int(elem);
        push(stack,val,CHAR);
        free(elem);
    }
    else if(get_type(elem)==STRING){
        char* str = (char*) get_item(elem);
        int* val = malloc(sizeof(int));
        *val = atoi(str);
        push(stack,val,CHAR);
        free(elem);
    }
    else{
        update_type(elem,CHAR);
        push_node(stack,elem);
    }
}

void trans_int(void* stack_p){
    Stack** stack = (Stack**) stack_p;
    Stack* elem;
    pop(stack,&elem);

    if(get_type(elem)==FLOAT){
        int* val = malloc(sizeof(int));
        *val = (int)return_float(elem);
        push(stack,val,INT);
        free(elem);
    }
    else if(get_type(elem)==STRING){
        char* str = (char*) get_item(elem);
        int* val = malloc(sizeof(int));
        *val = atoi(str);
        push(stack,val,INT);
        free(elem);
    }
    else{
        update_type(elem,INT);
        push_node(stack,elem);
    }
}

void trans_float(void* stack_p){
    Stack** stack = (Stack**) stack_p;
    Stack* elem;
    pop(stack,&elem);

    if(get_type(elem)==STRING){
        char* str = (char*) get_item(elem);
        double* val = malloc(sizeof(double));
        *val = atof(str);
        push(stack,val,FLOAT);
        free(elem);
    }
    else{
        double* val = malloc(sizeof(double));
        *val = (double)return_int(elem);
        push(stack,val,FLOAT);
        free(elem);
    }
}

void read_l(void* stack_p){
    Stack** stack = (Stack**) stack_p;
    char* input = malloc(10);
    size_t size = 10;
    if(getline(&input,&size,stdin)){
        push(stack,input,STRING);
	}
}