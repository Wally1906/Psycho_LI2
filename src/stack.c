#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

struct stack{
	void* item;
    Type type;
    int index;
    Stack* prev;
    Stack* next;
};

// corrected(nt)
Stack* create_stack(){
	Stack* stack = malloc(sizeof(Stack));
    stack->index = 0;
    stack->item = NULL;
    stack->prev = NULL;
    stack->next = NULL;
    return stack;
}

// corrected(nt)
void push(Stack** stack, void* element, Type type){
    Stack* node = malloc(sizeof(Stack));
    if(type == ARRAY_END){
        node->item = ((Stack*)element)->next;    
    }
    else{
        node->item = element;
    }
    node->index = (*stack)->index+1;
    node->type = type;
    (*stack)->next = node;
    node->prev = (*stack);
    *stack = node;
}

void push_array(Stack** stack, Stack* element, Stack* end){
    element->index = (*stack)->index+1;
    (*stack)->next = element;
    element->prev = *stack;
    *stack = element;

    while(*stack != end){
        Stack* aux = (*stack)->next;
        aux->index = (*stack)->index+1;
        (*stack)->next = aux;
        aux->prev = *stack;
        *stack = aux;
    }
}

void push_node(Stack** stack, Stack* element){
    if(element->type == ARRAY_END){
        push_array(stack,element->item,element);
        return;
    }
    else{
        element->index = (*stack)->index+1;
        (*stack)->next = element;
        element->prev = *stack;
        element->next = NULL;
        *stack = element;
    }
}

// corrected(nt)
void pop(Stack** stack,Stack** elem){
    *elem = (*stack);
    printf("%p\n",*stack);
    if((*stack)->type == ARRAY_END){
        *stack = ((Stack*)((*elem)->item))->prev;
        //printf("%p\n",*stack);
    }
    else{
        *stack = (*stack)->prev;
    }
    (*stack)->next=NULL;
}

// corrected(nt)
void print_stack(Stack* stack){
    printf("\n\n\n");
    stack = stack->next;
    while(stack){
        // printf(" %p -> %p\n",stack,stack->next);
        if(stack->type == FLOAT){
            printf("%g",*((double*)stack->item));
        }
        else if(stack->type == CHAR){
            printf("%c",(char)*((int*)stack->item));
        }
        else if(stack->type == STRING){
            printf("%s",((char*)stack->item));
        }
        else if(stack->type == ARRAY_END){
            Stack* prev = stack;
            stack = stack->next;
            free(prev);
            continue;
        }
        else{
            printf("%d",*((int*)stack->item));
        }
        free(stack->item);
        Stack* prev = stack;
        stack = stack->next;
        free(prev);
    }
    printf("\n");
}

Stack* dup_node(Stack* element){
    Stack* dup = malloc(sizeof(Stack));
    dup->index = -1;
    dup->type = element->type;
    if(element->type == FLOAT){
        double* val = malloc(sizeof(double));
        *val = *((double*)element->item);
        dup->item = val;
    }
    else{
        int* val = malloc(sizeof(int));
        *val = *((int*)element->item);
        dup->item = val;
    }
    return dup;
}

Stack* fetch(Stack* stack, int num){
    while(num > 0){
        stack=stack->prev;
        num--;
    }
    return dup_node(stack);
}

int return_int(Stack* elem){
    if(elem->type == FLOAT){
        return (int)*((double*)elem->item);
    }
    return *((int*)elem->item);
}

double return_float(Stack* elem){
    if(elem->type != FLOAT){
        return (double)*((int*)elem->item);
    }
    return *((double*)elem->item);
}


void free_node(Stack* elem){
    free(elem->item);
    free(elem);
}

Type get_type(Stack* elem){
    return elem->type;
}

void* get_item(Stack* elem){
    return elem->item;
}

// Only use when types can be seamlessly converted, aka char-int, array_type-type
void update_type(Stack* elem, Type type){
    elem->type = type;
}

Stack* init_global(int val, Type type){
    Stack* node = malloc(sizeof(Stack));
    int* val_p = malloc(sizeof(int));
    *val_p = val;
    node->index = -1;
    node->type = type;
    node->item = val_p;
    return node;
}

