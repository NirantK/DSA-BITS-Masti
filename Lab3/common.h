#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct cl{
	//Phone Number
	char num[10];
	//Person Name; Max characters = 40
	char name[40];
	struct cl *next;
}contact;

//typedef contact *phbook;
