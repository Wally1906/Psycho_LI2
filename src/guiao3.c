#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void equals(void* stack_p){
    Stack** stack = (Stack**)stack_p;

    Stack* elem1;
    Stack* elem2;
    pop(stack,&elem2);
    pop(stack,&elem1);

    int* truth = malloc(sizeof(int));
    *truth == -1;
    if(get_type(elem1)== STRING && get_type(elem2)== STRING){
        *truth = !strcmp((char*)get_item(elem1),(char*)get_item(elem2));
    }
    else{
        *truth = return_float(elem2) == return_float(elem1);
    }
    push(stack,truth,INT);

    free(elem2);
    free(elem1);

}

void larger(void* stack_p){
    Stack** stack = (Stack**)stack_p;

    Stack* elem1;
    Stack* elem2;
    pop(stack,&elem2);
    pop(stack,&elem1);

    int* truth = malloc(sizeof(int));
    *truth == -1;
    if(get_type(elem1)== STRING && get_type(elem2)== STRING){
        *truth = strcmp((char*)get_item(elem2),(char*)get_item(elem1)) > 0;
    }
    else{
        *truth = return_float(elem2) > return_float(elem1);
    }
    push(stack,truth,INT);

    free(elem2);
    free(elem1);

}

void smaller(void* stack_p){
    Stack** stack = (Stack**)stack_p;

    Stack* elem1;
    Stack* elem2;
    pop(stack,&elem2);
    pop(stack,&elem1);

    int* truth = malloc(sizeof(int));
    *truth == -1;
    if(get_type(elem1)== STRING && get_type(elem2)== STRING){
        *truth = strcmp((char*)get_item(elem2),(char*)get_item(elem1)) < 0;
    }
    else{
        *truth = return_float(elem2) < return_float(elem1);
    }
    push(stack,truth,INT);

    free(elem2);
    free(elem1);

}

void is_smaller(void* stack_p){
    Stack** stack = (Stack**)stack_p;

    Stack* elem1;
    Stack* elem2;
    pop(stack,&elem2);
    pop(stack,&elem1);

    if(get_type(elem1)== STRING && get_type(elem2)== STRING){
        if(strcmp((char*)get_item(elem2),(char*)get_item(elem1)) < 0){
            push_node(stack,elem2);
            free(elem1);
        }
        else{
            push_node(stack,elem1);
            free(elem2);
        }
    }
    else{
        if(return_float(elem2) < return_float(elem1)){
            push_node(stack,elem2);
            free(elem1);
        }
        else{
            push_node(stack,elem1);
            free(elem2);
        }
    }
}

void is_larger(void* stack_p){
    Stack** stack = (Stack**)stack_p;

    Stack* elem1;
    Stack* elem2;
    pop(stack,&elem2);
    pop(stack,&elem1);

    if(get_type(elem1)== STRING && get_type(elem2)== STRING){
        if(strcmp((char*)get_item(elem2),(char*)get_item(elem1)) > 0){
            push_node(stack,elem2);
            free(elem1);
        }
        else{
            push_node(stack,elem1);
            free(elem2);
        }
    }
    else{
        if(return_float(elem2) > return_float(elem1)){
            push_node(stack,elem2);
            free(elem1);
        }
        else{
            push_node(stack,elem1);
            free(elem2);
        }
    }
}