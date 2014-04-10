struct node create(int key){
	node newNode = (node)malloc(sizeof(struct avlnode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
};

int max(int a, int b){
    return (a > b)? a : b;
}

int height(node p){
    if (p == NULL)
        return 0;
    return p->height;
}

// Get Balance factor of node N
int getBalance(node N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}