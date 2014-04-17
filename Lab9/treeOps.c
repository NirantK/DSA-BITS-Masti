# include "tree.h"
PurchaseData create(int custId, int itemId){
	PurchaseData newNode = (PurchaseData)malloc(sizeof(struct avlnode));
    newNode->custId = custId;
    newNode->itemId = itemId;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
};

int max(int a, int b){
    return (a > b)? a : b;
}

int height(PurchaseData p){
    if (p == NULL)
        return 0;
    return p->height;
}
// Get Balance factor of PurchaseData N
int getBalance(PurchaseData N){
    if (N == NULL)
        return 0;
    // return (height(N->left) - height(N->right));
}

PurchaseData insert(PurchaseData pd, int custId, int itemId)
{
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return(newNode(custId));
 
    if (custId < node->custId)
        node->left  = insert(node->left, custId);
    else
        node->right = insert(node->right, custId);
 
    /* 2. Update height of this ancestor node */
    node->height = max(height(node->left), height(node->right)) + 1;
 
    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && custId < node->left->custId)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && custId > node->right->custId)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && custId > node->left->custId){
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && custId < node->right->custId)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}

int main(){
    printf("\n");
}