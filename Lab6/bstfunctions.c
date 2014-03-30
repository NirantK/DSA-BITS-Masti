#include"datastructure.h"
book_node* insert_node(book_node* bn,book b,int acc);
void inorder(book_node *temp);
int find_node(book_node* bn,book b );
bst* createEmptyBST()
{
	book_node *head=NULL;
	bst *bst1=(bst*)malloc(sizeof(bst));
	bst1->number=0;
	bst1->height=0;
	bst1->root=head;

	return bst1;
}

bst* insert_BST(bst* bk,book b)
{
	int acc=1;
	bk->root=insert_node(bk->root,b,acc);
	bk->number++;
	if(bk->height<acc)
		bk->height=acc;
	return bk;
} 



book_node* insert_node(book_node* bn,book b,int acc)
{
	
	if(bn==NULL)
	{
			// return newNode(b);

	bn = (book_node*)malloc(sizeof(book_node));
	bn->b.ano=b.ano;
	strcpy(bn->b.title,b.title);
	strcpy(bn->b.author,b.author);
	bn->b.price=b.price;
	bn->left  = NULL;
	bn->right = NULL;
	return(bn);
	}

	if(b.ano>bn->b.ano)
	{
		bn->right=insert_node(bn->right,b,++acc);
		
	}
	if(b.ano<=bn->b.ano)
	{
		printf("cc%d\n",bn->b.ano);
		//bn=bn->left;
		bn->left=insert_node(bn->left,b,++acc);
	}
	return(bn);
}

int find_BST(bst* bt,book b)
{
	int x= find_node(bt->root,b);
	printf("%d cc\n",x);
	return(x);
}
int find_node(book_node* bn,book b)
{
	if(bn==NULL)
	{
		return 0;
	}
	//printf("%d %d \n",b.ano,bn->b.ano);
	if(bn->b.ano==b.ano){
		return 1;}
	else if(bn->b.ano>b.ano)
	{
		find_node(bn->left,b);
	}
	else
	{
		find_node(bn->right,b);
	}
	

}

void inorderbst(bst* bt)
{
	inorder(bt->root);
}

void inorder(book_node *temp)
{
   if(temp!=NULL)
    {
    inorder(temp->left);
    printf("%s\n",temp->b.title);
    inorder(temp->right);
    }
}








