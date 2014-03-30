#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BST bst;
typedef struct BOOK book;
typedef struct BOOK_NODE book_node;

struct BST{
	int number;
	int height;
	book_node* root;
};

struct BOOK{
	int ano;
	char title[10];
	char author[10];
	int price;
};

struct BOOK_NODE{
	book b;
	book_node* left;
	book_node* right;
};





