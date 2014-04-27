

typedef struct node* Elem; 	//Elem is the pointer to node

struct node
{
	int data;
	Elem next;
};

typedef struct stack* Stack; 	//Stack is pointer to stack

struct stack
{
	Elem top;
	int size; 
};

typedef enum {FALSE=0, TRUE=1} Boolean; 
