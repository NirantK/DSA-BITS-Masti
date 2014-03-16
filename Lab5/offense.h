#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct driverNode* driver;
typedef struct ownerNode* owner;
typedef struct offenseNode* offense;

typedef struct driverNode
{
	int uid;
	int lic; 
	driver next;
} drvr;

typedef struct ownerNode
{
	int uid;
	int vno; 
	owner next;
} ownr;

// typedef struct offenseNode
// {
// 	int lic;
// 	int pen; 
// 	offense next;
// };

void populateVehicles(ownr *list, FILE *source);
void populateDrivers(drvr *list, FILE *source);