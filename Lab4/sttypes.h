typedef struct node* Elem; 

struct node
{
	int data;
	Elem next;
};

typedef struct stack *Stack; 

struct stack
{
	Elem top;
	int size; 
};

typedef enum {FALSE=0, TRUE=1} Boolean; 


