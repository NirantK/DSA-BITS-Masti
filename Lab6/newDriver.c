#include "BSTdef.h"
#include "BSTOps.h"
int main(){
	BST bt = createEmptyBST();
	book b = {10, "Introduction to Algorithms", "Cormen", 720};
    book b1 = {5, "Analysis of Algorithms", "Sedgewick", 1000};    
    book b2 = {3, "Arthashastra", "Chanakya", 3600};
    book b3 = {50, "Losing My Virginity", "Richard Branson", 6000};
    book b4 = {10, "Because Shit Happened", "Harsh Snehanshu", 200};
    book b5 = {2, "Business Technology and Knowledge Sharing", "APJ Abdul Kalam", 400};
    book b6 = {10, "SM", "RK", 500};
	
	bt = insertBST(bt, b);
	bt = insertBST(bt, b1);
	bt = insertBST(bt, b2);
	bt = insertBST(bt, b3);
	bt = insertBST(bt, b4);
	bt = insertBST(bt, b5);
	bt = insertBST(bt, b6);
	// bt = insertBST(bt, b6);
	// bstPrint(bt);
	// printf("\n");
	printf("Height of tree is %d\n",getHeight(bt));

	printf("\nDid I find Cormen? \t %d \n", findBST(bt,b));
	printf("Deleting b...\n");
	delBST(bt,b);
	// bstPrint(bt);
	// printf("\n");
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

	BST pricebt = reOrderBST(bt);
	bstPrint(pricebt);
	return 0;
}