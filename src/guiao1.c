#include "stack.h"
#include <stdlib.h>
#include <math.h>


void sum(void* stack_p){
    Stack** stack = (Stack**)stack_p;
    Stack* elem1;
    Stack* elem2;
    pop(stack,&elem2);
    pop(stack,&elem1);
    Type type1 = get_type(elem1);
    Type type2 = get_type(elem2);


    if(type1 == FLOAT && type2 == FLOAT){
        double* sum_d = malloc(sizeof(double));
        *sum_d = return_float(elem1) + return_float(elem2);
        push(stack,sum_d,FLOAT);
    }
    else{
        int* sum = malloc(sizeof(int));
        *sum =  return_int(elem1) + return_int(elem2);
        push(stack,sum,INT);
    }

    free_node(elem1);
    free_node(elem2);
}

void sub(void* stack_p){
    Stack** stack = (Stack**)stack_p;
    Stack* elem1;
    Stack* elem2;
    pop(stack,&elem2);
    pop(stack,&elem1);
    Type type1 = get_type(elem1);
    Type type2 = get_type(elem2);

    if(type1 == FLOAT && type2 == FLOAT){
        double* sum_d = malloc(sizeof(double));
        *sum_d = return_float(elem1) - return_float(elem2);
        push(stack,sum_d,FLOAT);
    }
    else{
        int* sum = malloc(sizeof(int));
        *sum =  return_int(elem1) - return_int(elem2);
        push(stack,sum,INT);
    }

    free_node(elem1);
    free_node(elem2);
}

void times(void* stack_p){
    Stack** stack = (Stack**)stack_p;
    Stack* elem1;
    Stack* elem2;
    pop(stack,&elem2);
    pop(stack,&elem1);
    Type type1 = get_type(elem1);
    Type type2 = get_type(elem2);

    if(type1 == FLOAT || type2 == FLOAT){
        double* sum_d = malloc(sizeof(double));
        *sum_d = return_float(elem1) * return_float(elem2);
        push(stack,sum_d,FLOAT);
    }
    else{
        int* sum = malloc(sizeof(int));
        *sum =  return_int(elem1) * return_int(elem2);
        push(stack,sum,INT);
    }

    free_node(elem1);
    free_node(elem2);
}

void divd(void* stack_p){
    Stack** stack = (Stack**)stack_p;
    Stack* elem1;
    Stack* elem2;
    pop(stack,&elem2);
    pop(stack,&elem1);
    Type type1 = get_type(elem1);
    Type type2 = get_type(elem2);

    if(type1 == FLOAT || type2 == FLOAT){
        double* sum_d = malloc(sizeof(double));
        *sum_d = return_float(elem1) / return_float(elem2);
        push(stack,sum_d,FLOAT);
    }
    else{
        int* sum = malloc(sizeof(int));
        *sum = return_int(elem1) / return_int(elem2);;
        push(stack,sum,INT);
    }

    free_node(elem1);
    free_node(elem2);
}

void mod(void* stack_p){
    Stack** stack = (Stack**)stack_p;
    Stack* elem1;
    Stack* elem2;
    pop(stack,&elem2);
    pop(stack,&elem1);
    Type type1 = get_type(elem1);
    Type type2 = get_type(elem2);

    int* sum = malloc(sizeof(int));
    *sum =  return_int(elem1) % return_int(elem2);
    push(stack,sum,INT);

    free_node(elem1);
    free_node(elem2);
}

void expo(void* stack_p){
    Stack** stack = (Stack**)stack_p;
    Stack* elem1;
    Stack* elem2;
    pop(stack,&elem2);
    pop(stack,&elem1);
    Type type1 = get_type(elem1);
    Type type2 = get_type(elem2);
    
    double* sum_d = malloc(sizeof(double));
    if(type1 == FLOAT || type2 == FLOAT){
        *sum_d =  pow((return_float(elem1)),(return_float(elem2)));;
        push(stack,sum_d,FLOAT);
    }
    else{
        free(sum_d);
        int* sum = malloc(sizeof(int));
        *sum =  (int)pow((double)(return_int(elem1)),(double)(return_int(elem2)));
        push(stack,sum,INT);
    }

    free_node(elem1);
    free_node(elem2);
}

void bitwise_and(void* stack_p){
    Stack** stack = (Stack**)stack_p;
    Stack* elem1;
    Stack* elem2;
    pop(stack,&elem2);
    pop(stack,&elem1);

    int* sum = malloc(sizeof(int));
    *sum =  return_int(elem1) & return_int(elem2);
    push(stack,sum,INT);

    free_node(elem1);
    free_node(elem2);   
}

void bitwise_or(void* stack_p){
    Stack** stack = (Stack**)stack_p;
    Stack* elem1;
    Stack* elem2;
    pop(stack,&elem2);
    pop(stack,&elem1);

    int* sum = malloc(sizeof(int));
    *sum =  return_int(elem1) | return_int(elem2);
    push(stack,sum,INT);

    free_node(elem1);
    free_node(elem2);   
}

void bitwise_xor(void* stack_p){
    Stack** stack = (Stack**)stack_p;
    Stack* elem1;
    Stack* elem2;
    pop(stack,&elem2);
    pop(stack,&elem1);
    Type type1 = get_type(elem1);
    Type type2 = get_type(elem2);

    int* sum = malloc(sizeof(int));
    *sum =  return_int(elem1) ^ return_int(elem2);
    push(stack,sum,INT);

    free_node(elem1);
    free_node(elem2);   
}

void bitwise_not(void* stack_p){
    Stack** stack = (Stack**)stack_p;
    Stack* elem1;
    pop(stack,&elem1);
    Type type1 = get_type(elem1);

    int* sum = malloc(sizeof(int));
    *sum =  ~ return_int(elem1);
    push(stack,sum,INT);

    free_node(elem1);
}

void add_one(void* stack_p){
    Stack** stack = (Stack**)stack_p;
    Stack* elem1;
    pop(stack,&elem1);
    Type type = get_type(elem1);

    if(type == FLOAT){
        double* val = malloc(sizeof(double));
        *val = return_float(elem1) + 1;
        push(stack,val,FLOAT);
    }
    else{
        int* val = malloc(sizeof(int));
        *val = return_int(elem1) + 1;
        push(stack,val,INT);
    }
    free_node(elem1);
}

void sub_one(void* stack_p){
    Stack** stack = (Stack**)stack_p;
    Stack* elem1;
    pop(stack,&elem1);
    Type type = get_type(elem1);
    if(type == FLOAT){
        double* val = malloc(sizeof(double));
        *val = return_float(elem1) - 1;
        push(stack,val,FLOAT);
    }
    else{
        int* val = malloc(sizeof(int));
        *val = return_int(elem1) - 1;
        push(stack,val,INT);
    }
    free_node(elem1);
}