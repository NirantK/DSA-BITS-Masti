#include <stdio.h>
#include "PhoneBook.h"
#include <stdlib.h>
#include <string.h>

int main(){
	PHBOOK *pb;
	pb = createAddressBook();

	if(isEmpty(pb) == -1) printf("\nPhone book is empty ");
	else printf("\nPhone book has %d elements",isEmpty(pb));

	printf("\nSize: %d",pb->size);	
	Contact c;
	strcpy(c.name,"Shikhar");
	c.mobile_number = 966058;
	pb = insertAddress(pb,c);

	strcpy(c.name,"Krishna");
        c.mobile_number = 86360;
        pb = insertAddress(pb,c);
	
	printf("\nSize: %d",pb->size);

	if(isEmpty(pb) == -1) printf("\nPhone book is empty ");
        else printf("\nPhone book has %d elements",isEmpty(pb));

	FILE *fp;
	fp = fopen("text.txt","w");
	printAddressBook(pb,fp);	

	Contact *con;
	con = searchByName(pb,"Krishna");
	printf("\nName :%s mobile number is %d",con->name,con->mobile_number);
	return 0;
}
