#include "functions.h"
#include "stack.h"
#include "guiao1.h"
#include "guiao2.h"
#include "guiao3.h"
#include <stdio.h>
#include <string.h>

static char *operators[38] = {
    "",
    "+",
    "-",
    "*",
    "/",
    "%",
    "#",
    "^",
    "&",
    "|",
    "~",
    ")",
    "(",
    "i",
    "f",
    "c",
    "s",
    "_",
    ";",
    "\\",
    "@",
    "$",
    "l",
    "=",
    "<",
    ">",
    "!",
    "e&",
    "e|",
    "e<",
    "e>",
    "?",
    ",",
    "S/",
    "N/",
    "t",
    "w",
    "p",
};

Stack* var[26];

void null(void* stack){
    printf("Wrong function\n");
}

static void (*func_pointer[37])(void* stack) = {
    null,
    sum,
    //sum_a,
    sub,
    times,
    divd,
    mod,
    expo,
    bitwise_xor,
    bitwise_and,
    bitwise_or,
    bitwise_not,
    add_one,
    sub_one,
    trans_int,
    trans_float,
    trans_char,
    null,
    dup,
    poppy,
    swap,
    rotate,
    bring_forth,
    read_l,
    equals,
    smaller,
    larger,
    null,
    null,
    null,
    is_smaller,
    is_larger,
    null,
    null,
    null,
    null,
    null,
};

int getOperator(char* token){
    for(int i=0; operators[i]; i++){
        if(strcmp(operators[i],token)==0){
            return i;
        }
    }
    if(token[0] == ':'){
        return token[1];
    }
    for(int i = 0; i<26;i++){
        if((token[0])-65 == i){
            return 100 + token[0];
        }
    }
    return 0;
}

void fill_globals(){
    var[0] = init_global(10,INT);
    var[1] = init_global(11,INT);
    var[2] = init_global(12,INT);
    var[3] = init_global(13,INT);
    var[4] = init_global(14,INT);
    var[5] = init_global(15,INT);
    var[6] = NULL;
    var[7] = NULL;
    var[8] = NULL;
    var[9] = NULL;
    var[10] = NULL;
    var[11] = NULL;
    var[12] = NULL;
    var[18] = init_global(20,CHAR);
    var[13] = init_global(10,CHAR);
    var[14] = NULL;
    var[15] = NULL;
    var[16] = NULL;
    var[17] = NULL;
    var[19] = NULL;
    var[20] = NULL;
    var[21] = NULL;
    var[22] = NULL;
    var[23] = init_global(0,INT);
    var[24] = init_global(1,INT);
    var[25] = init_global(2,INT);
}

void update_global(void* stack_p, int index){
    Stack** stack = (Stack**) stack_p;
    var[index-65] = dup_node(*stack);
}

void get_global(void* stack_p, int index){
    Stack** stack = (Stack**) stack_p;
    push_node(stack, dup_node(var[index-65]));
}

int caller(void* stack, int index){
    if(index > 100){
        get_global(stack,index-100);
    }
    else if(index > 64){
        update_global(stack, index);
    }
    else{
        func_pointer[index](stack);
    }
}