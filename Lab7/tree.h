#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct avlnode *node;
typedef struct pos *posNode;

struct avlnode{
    char word[100];
    struct avlnode *left;
    struct avlnode *right;
    int height;
    int count;
    posNode root;
};

struct pos{
	long pos;
	struct pos * next;
};


#define true 1;
#define false 0;
