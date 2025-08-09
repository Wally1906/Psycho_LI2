typedef struct stack Stack;

typedef enum type{
    INT,
    CHAR,
    FLOAT,
    STRING,
    ARRAY_INT,
    ARRAY_CHAR,
    ARRAY_FLOAT,
    ARRAY_SRING,
    ARRAY_END,
} Type;

Stack* create_stack();

void push(Stack** stack, void* element,Type type);

void push_node(Stack** stack, Stack* element);

void pop(Stack** stack,Stack** elem);

double return_float(Stack* elem);

int return_int(Stack* elem);

void print_stack(Stack* stack);

Stack* fetch(Stack* stack, int num);

void free_node(Stack* elem);

Stack* dup_node(Stack* element);

Type get_type(Stack* elem);

void* get_item(Stack* elem);

void update_type(Stack* elem, Type type);

Stack* init_global(int val, Type type);