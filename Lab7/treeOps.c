# include "tree.h"

posNode createNode(long pos){   
    posNode newNode=(posNode)malloc(sizeof(struct pos));
    newNode->pos = pos;
    newNode->next = NULL;
}

posNode insertNode(posNode root, long pos){
    struct pos *temp = root;
    if(temp==NULL){
        temp = createNode(pos);
        return root;
    }
    if ( temp != NULL ) {
        while ( temp->next != NULL)
        {
            temp = temp->next;
        }
    }
    temp->next = createNode(pos);
    return root;
}

void print(struct pos * root){
    // root = root->next;
    while(root!=NULL){
        printf("%ld\t", root->pos);
        root = root->next;
    }
}

node newNode(char word[], long pos){
    node newNode = (node)malloc(sizeof(struct avlnode));
    strcpy(newNode->word,word);
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    newNode->count = 1;
    newNode->root = (struct pos*)malloc(sizeof(struct pos));
    newNode->root->next = NULL;
    newNode->root->pos = pos;
    return newNode;
}

int max(int a, int b){
    return (a > b)? a : b;
}

int height(node N){
    if (N == NULL)
        return 0;
    return N->height;
}

int findNode(node p, char word[]){
    if(p==NULL){
        return 0;
    }
    else if (strcmp(p->word, word)==0){
        return 1; //if found, return 1
    }
    else if(strcmp(p->word, word)<0){
        findNode(p->right, word);}
    else{
        findNode(p->left, word);
    }
    return 0;
}


node retNode(node p, char word[]){
    if(p==NULL){
        return NULL;
    }
    else if (strcmp(p->word, word)==0){
        return p;
    }
    else if(strcmp(p->word, word)<0){
        retNode(p->right, word);}
    else{
        retNode(p->left, word);
    }
}

node rightRotate(node y){
    node x = y->left;
    node T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}

node leftRotate(node x){
    node y = x->right;
    node T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}

int getBalance(node N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}



node insert(node node, char word[], long pos){
    if (node == NULL)
        return(newNode(word,pos));
    int x = strcmp(word, node->word);

    if (x<0)
        node->left  = insert(node->left, word, pos);
    else
        node->right = insert(node->right, word, pos);
 
    /* 2. Update height of this ancestor node */
    node->height = max(height(node->left), height(node->right)) + 1;
 
    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && (strcmp(word, node->left->word)<0))
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && (strcmp(word, node->right->word)>0))
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && (strcmp(word, node->left->word)>0))    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && (strcmp(word, node->right->word)<0))    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}

void inOrder(node root){
    if(root != NULL){
        inOrder(root->left);
        printf("Word: %s,\tNo of Instances: %d,\tPosition from beginning:", root->word, root->count);
        print(root->root);
        printf("\n");
        inOrder(root->right);
    }
}

/*under construction*/
void writeToFile(node root, FILE *fp){
	if(root!=NULL){
		writeToFile(root->left, fp);
	        fprintf(fp, "Word: %s,\tNo of Instances: %d,\n", root->word, root->count);
		writeToFile(root->right, fp);
		}
}

node asliInsert(node node, char word[], long pos){
    // int z = findNode(node, word);
    struct avlnode* up = retNode(node, word);
    if(up!=NULL){
        up->count = up->count+1;
        // printf("%s\n", up->word);
        up->root = insertNode(up->root, pos);
    }
    else
        node = insert(node, word, pos);
    return node;
}

int main(){
    char word[100];
    node root = NULL;
    FILE *input = fopen("input.txt", "r");//text file for reading into a hash table
FILE *out = fopen("new.txt","w+");
    if(input==NULL){
        exit(1);
    }        
    while(fscanf(input, "%s ", word)!=EOF){
        // root = newNode(word);
        long pos = ftell(input);
        root = asliInsert(root, word, pos);
        // printf("%ld\t",ftell(input));        
    }
    inOrder(root);
//	writeToFile(root, out);
}
