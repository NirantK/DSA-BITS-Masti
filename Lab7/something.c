#include <stdio.h>
#include <stdlib.h>

struct node {
  int x;
  struct node *next;
};
void print(struct node * root){
    while(root!=NULL){
        printf("%d\t", root->x);
        root = root->next;
    }
 }
int main()
{
    /* This won't change, or we would lose the list in memory */
    struct node *root;       
    /* This will point to each node as it traverses the list */
    struct node *conductor;  

    root = (node*)malloc( sizeof(struct node) );  
    root->next = NULL;   
    root->x = 12;
    conductor = root; 
    if ( conductor != NULL ) {
        while ( conductor->next != NULL)
        {
            conductor = conductor->next;
        }
    }
    /* Creates a node at the end of the list */
    conductor->next = (node*)malloc( sizeof(struct node) );  

    conductor = conductor->next; 

    if ( conductor == NULL )
    {
        printf( "Out of memory" );
        return 0;
    }
    /* initialize the new memory */
    conductor->next = NULL;         
    conductor->x = 42;

    print(root);
    return 0;
}