#include "AVLTree.h"
/*Insert and Delete operations and their dependencies used from 
http://www.geeksforgeeks.org/avl-tree-set-1-insertion/  and
http://www.geeksforgeeks.org/avl-tree-set-2-deletion/ */

//AVL Trees are balanced binary search trees
//BSTs are ordered binary trees. 
// Thus, AVL Trees are a balanced and ordered binary trees.

int max(int a, int b){
    return (a > b)? a : b;
}

purchaseInfo newNode(int custId, int itemId){
    purchaseInfo newNode = (purchaseInfo)malloc(sizeof(struct node));
    newNode->custId = custId;
    newNode->itemId = itemId;
    newNode->left = newNode->right = NULL;
    newNode->height = 0;
    return newNode;
}

int height(purchaseInfo N){
    if (N == NULL)
        return 0;
    return N->height;
}

purchaseInfo rightRotate(purchaseInfo y){
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}

purchaseInfo leftRotate(purchaseInfo x){
    struct node *y = x->right;
    struct node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(purchaseInfo N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

purchaseInfo insert(purchaseInfo node, int custId, int itemId){
	if (node == NULL)
        return(newNode(custId, itemId));
    if (custId < node->custId)
        node->left  = insert(node->left, custId, itemId);
    else
        node->right = insert(node->right, custId, itemId);
 
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
    if (balance > 1 && custId > node->left->custId)    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && custId < node->right->custId)    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}

PurchaseData avlInsert(PurchaseData pd, int custId, int itemId){
	pd->root = insert(pd->root, custId, itemId);
	return pd;
}

void preOrder(purchaseInfo root){
    if(root != NULL){
        printf("custId:%d\titemId:%d\n", root->custId, root->itemId);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(purchaseInfo root){
    if(root != NULL){
        inOrder(root->left);
        printf("custId:%d\titemId:%d\n", root->custId, root->itemId);
        inOrder(root->right);
    }
}


purchaseInfo findNode(purchaseInfo p, int custId){
	if(p==NULL){
        return NULL;
    }
    else if (p->custId == custId){
        return p;
    }
    else if(p->custId < custId){
        findNode(p->right, custId);}
    else{
        findNode(p->left, custId);
    }
}

purchaseInfo find(PurchaseData pd, int custId){
	return findNode(pd->root, custId);
}

void findAll(purchaseInfo root, int custId){
	if(root != NULL){
        // printf("custId:%d\titemId:%d\n", root->custId, root->itemId);
        findAll(root->left, custId);
        if(root->custId == custId){
            printf("Found(findAll):%d and %d\n", root->itemId, root->custId);
    	        // printf("custId:%d\titemId:%d\n", root->custId, root->itemId);        	
        }
        findAll(root->right, custId);
    }
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
purchaseInfo deleteNode(purchaseInfo root, int custId, int itemId){
    // STEP 1: PERFORM STANDARD BST DELETE
 
    if (root == NULL)
        return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( custId < root->custId )
        root->left = deleteNode(root->left, custId, itemId);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( custId > root->custId )
        root->right = deleteNode(root->right, custId, itemId);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    { // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            purchaseInfo temp = root->left ? root->left : root->right;
 
            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of the non-empty child
 
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            purchaseInfo temp = minValueNode(root->right);
 
            // Copy the inorder successor's data to this node
            root->custId = temp->custId;
            root->itemId = temp->itemId;
 
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->custId, temp->itemId);
        }
    }
    if (root == NULL)
       return root;
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = max(height(root->left), height(root->right)) + 1;
 
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    // this node became unbalanced)
    int balance = getBalance(root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}


int main(){
	printf("\n");
	struct node *root = NULL;
    
    /*Constructing a treee*/ 
    root = insert(root, 10, 50);
	root = insert(root, 10, 33);
	root = insert(root, 10, 50);
	root = insert(root, 10, 50);
  	root = insert(root, 20, 90);
  	root = insert(root, 30, 110);
  	root = insert(root, 40, 50);
  	root = insert(root, 50, 60);
  	root = insert(root, 25, 50);
    printf("Initial AVL Tree:\n");   
	inOrder(root);
	
	purchaseInfo naya = findNode(root, 20);
	if(naya!=NULL)
		printf("Found:%d and %d\n", naya->itemId, naya->custId);
	else
		printf("Not Found.\n");

	findAll(root, 10);
    root = deleteNode(root, 10, 50);
    printf("After deletion:\n");
    preOrder(root);
    return 0;
}