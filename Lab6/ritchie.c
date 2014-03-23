// Look into getWord for debugging; 
// that's function with mofo errors

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct tnode
{
	/* data */
	char* word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

#define MAXWORD 100

struct tnode *addTree(struct tnode*, char*);
void treePrint(struct tnode*);
int getWord(char *, int);

int main(int argc, char const *argv[])
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while(getWord(word, MAXWORD)!=EOF){
		if(isalpha(word[0]))
			root = addTree(root, word);
	}
	treePrint(root);
	return 0;
}

int getWord(char* word, int lim){
	int c, 
	// int getch(void);
	// void ungetch(int);
	char *w = word;

	while(isspace(c=getch())){
		if(c!=EOF)
			*w++ = c;
		if(!isalpha(c)){
			*w = '\0';
			return c;
		}
	}

	for(;--lim>0; w++)
		if(!isalnum(*w = getch())){
			ungetch(*w);
			break;
		}

	*w = '\0';
	return word[0];
}

char *strdup (char *s){
	char *p;

	p = (char*) malloc(strlen(s)+1);
	if (p != NULL)
		strcpy(p,s);

	return p;
}

struct tnode *addTree( struct tnode *p, char *w){
	int cond;

	if(p==NULL){
		p = (struct tnode*) malloc(sizeof(struct tnode));
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word))==0)
		p->count++;
	else if (cond<0)
		p->left = addTree(p->left, w);
	else
		p->right = addTree(p->right, w);

	return p;
}

void treePrint(struct tnode *p){
	if(p!=NULL){
		treePrint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treePrint(p->right);
	}
}