#include <stdio.h>          //File and termininal input/output
#include <stdlib.h>         //General utilities
#include <string.h>         //String handling functions
#include <ctype.h>          //Character handling functions
#include <time.h>           //Time related functions

typedef struct driverNode* driver;
typedef struct ownerNode* owner;
typedef struct offenseNode* offense;

typedef struct driverNode
{
	int uid;
	int lic;
	int penalty; 
	driver next;
} drvr;

typedef struct ownerNode
{
	int uid;
	int vno; 
	owner next;
} ownr;

typedef struct offenseNode
{
	int lic;
	int pen; 
	offense next;
} ofnc;

/* Hash table characteristics.  */

/*  Initial table size. If we know the number of elements we will have, by setting this number to 
 *  something reasonably big, it is possible to disable the automatic resizing. This could lead to 
 *  quicker table building.
 */
#define INIT_SIZE   5000
  
/*  Ratio of different items to hash table size. When table reaches this 
 *  level of fullness it is resized by GROWTH factor. We can sacrifice speed for memory efficiency, 
 *  or vice-versa, by tuning this number. It was chosen to be 1.2, because it makes a table with ~70% used cells, 
 *  longest chain 6-7 and average collided length of ~2.5. It makes the table quite memory efficient and in the same time
 *  the retrieval time is not high.
 */
#define RATIO       1.5    

/*  Resize constant - multiplier by which table size is increased. By setting the number 
 *  just a litle bit bigger than 1, we can get table with exactly the ratio we want, but there
 *  will be a lot of resizing. This will lead to longer table building times. For tables with small number of
 *  elements (<1000) we can set it to 1.01, but with big tables (>500 000) it is advised to make it about 2 
 *  For our problem size (~3500) it was chosen to be 1.3
 */
#define GROWTH      1.3

/*
 "List" structure used to store a UID and it's owner (license) in a linked list. 
   Also used in every node in hash table, because hash collision is solved by using 
   linked list approach.
*/

typedef struct list 
{
    int uid;
    int license;
    struct list *next;
} list;

/*  "Table" structure is used for a hash table and consists of an array of lists (data)
 *  and two numbers, used for resizing the table automatically -
 *  number of elements (items) and table size (size).
 */

typedef struct table 
{
    int items; //no of elements (n)
    int size; // table size  (m)
    driver *data;
} table;

owner populateVehicles(FILE *source);
driver populateDrivers(FILE *source);
void printVehicleList(owner node);
void printDriversList(driver node);
void printOffensesList(offense node);

/* Hash table ADT functions */
driver insert_word(driver word_list, int uid, int license, int penalty, int *used);
driver search_list(driver word_list, int license, int *count) ;
unsigned int hash(int data, int tbl_size);
driver search_table(table *hash_table, int license, int *count);
table *grow_table(table *hash_table);
void destroy(driver word_list);
driver create_node(int uid, int license, int penalty);
void *gcalloc( int number, int size);
// driver makeRevokeList(FILE *source, table *hash_table, int* count);

/* Various helper functions */
int ask_user(void);
table *build_table( FILE *input);
list *build_list( FILE *input);
void print_result(driver result, int count);
char *return_word(char *word, FILE *input);
void print_stats(table *hash_table);
double print_time( clock_t time);