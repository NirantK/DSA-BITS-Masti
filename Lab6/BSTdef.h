// typedef struct __book{
// 	int acc; //unique accession number
// 	char *title;
// 	char *name;
// 	int price;
// }book;

// typedef struct __bookNode
// {
// 	book b;
// 	struct bookNode *left, *right;
// }bookNode;

// typedef struct __bst{
// 	int totalBooks;
// 	int height;
// 	bookNode* root;
// }bst;
struct __book{
	int acc; //unique accession number
	char *title;
	char *name;
	int price;
};
typedef struct __book book;

struct __bookNode
{
	book *b;
	struct __bookNode *left, *right;
};

typedef struct __bookNode bNode; 
typedef struct __bookNode* node;

struct __bst{
	int totalBooks;
	int height;
	node root;
};

typedef struct __bst* BST;
typedef struct __bst BinTree;

#define TRUE 1
#define FALSE 0