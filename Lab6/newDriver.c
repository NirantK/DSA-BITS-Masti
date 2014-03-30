#include "BSTdef.h"
BST createEmptyBST();
node insertInBST(node tree, book newb);
BST insertBST(BST bt, book b); 
node createNode(book b);
void bstPrint(BST bt);
void treePrint(node p);
book findMax(node p, book b);
book findMaxPrice(BST bt);
book findMinPrice(BST bt);
int getHeight(BST bt);
book findLatestBook(BST bt);
book findOldestBook(BST bt);
int main(){
	BST bt = createEmptyBST();
	book b = {10, "Introduction to Algorithms", "Cormen", 720};
    book b1 = {5, "Analysis of Algorithms", "Sedgewick", 1000};    
    book b2 = {3, "Arthashastra", "Chanakya", 3600};
    book b3 = {50, "Losing My Virginity", "Richard Branson", 200};
    book b4 = {100, "Because Shit Happened", "Harsh Snehanshu", 210};
    book b5 = {9, "SM", "RK", 210};
    book b6 = {90, "SM", "RK", 210};
	
	bt = insertBST(bt, b);
	bt = insertBST(bt, b1);
	bt = insertBST(bt, b2);
	bt = insertBST(bt, b3);
	bt = insertBST(bt, b4);
	bt = insertBST(bt, b5);
	bt = insertBST(bt, b6);
	bt = insertBST(bt, b6);
	bstPrint(bt);
	printf("\n");

	// printf("\nDid I find Cormen? \t %d \n", findBST(bt,b));
	// printf("Deleting b3	..\n");
	// delBST(bt, b3);
	// bstPrint(bt);
	book max,min, latest, oldest;
	max = findMaxPrice(bt);
	printf("Maximum priced book is %s\n", max.title);
	min = findMinPrice(bt);
	printf("Minimum priced book is %s\n", min.title);
	printf("Height of tree is %d\n",getHeight(bt));
	latest = findLatestBook(bt);
	printf("The latest book is '%s'\n",latest.title);
	oldest = findOldestBook(bt);
	printf("The oldest book is %s\n",oldest.title );


	return 0;
}