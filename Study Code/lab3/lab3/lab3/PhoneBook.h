#define MAX_CAPACITY 100

#include<stdio.h>

typedef struct Contact{
	char name[30];
	int mobile_number;
	struct Contact* next;
}Contact;

typedef struct PHBOOK{
	int size;
	int capacity;
	Contact* next;
}PHBOOK;

extern PHBOOK* createAddressBook(void);
extern int isNotFull(PHBOOK* head);
extern int isEmpty(PHBOOK* head);
extern void printAddressBook(PHBOOK *head,FILE *output);
extern Contact* searchByName(PHBOOK *head,char name[]);
extern Contact* insertAddress(Contact *fnode,Contact con);
extern Contact* deleteAddress(Contact *fnode,Contact con);
extern PHBOOK* deleteAllAddresses(Contact *fnode);
extern PHBOOK* uploadAddressese(PHBOOK *ph,char fname[]);
