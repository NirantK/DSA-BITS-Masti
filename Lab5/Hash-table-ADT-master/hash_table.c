#include <stdio.h>          //File and termininal input/output
#include <stdlib.h>         //General utilities
#include <string.h>         //String handling functions
#include <ctype.h>          //Character handling functions
#include <time.h>           //Time related functions
#define MAXLENGTH   100     //Maximum length of word processed

/* 
 *  Hash table characteristics.
 */

/*  Initial table size. If we know the number of elements we will have, by setting this number to 
 *  something reasonably big, it is possible to disable the automatic resizing. This could lead to 
 *  quicker table building.
 */
#define INIT_SIZE   2    
  
/*  Ratio of different items to hash table size. When table reaches this 
 *  level of fullness it is resized by GROWTH factor. We can sacrifice speed for memory efficiency, 
 *  or vice-versa, by tuning this number. It was chosen to be 1.2, because it makes a table with ~70% used cells, 
 *  longest chain 6-7 and average collided length of ~2.5. It makes the table quite memory efficient and in the same time
 *  the retrieval time is not high.
 */
#define RATIO       1.2    

/*  Resize constant - multiplier by which table size is increased. By setting the number 
 *  just a litle bit bigger than 1, we can get table with exactly the ratio we want, but there
 *  will be a lot of resizing. This will lead to longer table building times. For tables with small number of
 *  elements (<1000) we can set it to 1.01, but with big tables (>500 000) it is advised to make it about 2 
 *  For our problem size (~3500) it was chosen to be 1.3
 */
#define GROWTH      1.3        

/* Compile linked list functionality */
//#define MAKE_LIST 

/*  Custom data types. Part of hash table ADT.
 *
 *  "List" structure used to store a word and it's occurence (count) in a linked list. 
 *  Also used in every node in hash table, because hash collision is solved by using 
 *  linked list approach.
 */

typedef struct list 
{
    int count;
    char *word;
    struct list *next;
} list;

/*  "Table" structure is used for a hash table and consists of an array of lists (data)
 *  and two numbers, used for resizing the table automatically -
 *  number of elements (items) and table size (size).
 */

typedef struct table 
{
    int items;
    int size;
    list **data;
} table;

/* 
 *  Function prototypes
 */

/* Hash table ADT functions */
list *insert_word( list *word_list, char *word, int *used);
list *search_list( list *word_list, char *word, int *count);
unsigned int hash(char *word, int tbl_size);
list *search_table( table *hash_table, char *word, int *count);
table *grow_table(table *hash_table);
void destroy(list *word_list);
list *create_node( char *word);
void *gcalloc( int number, int size);

/* Various helper functions */
int ask_user(void);
table *build_table( FILE *input);
list *build_list( FILE *input);
void print_result(list *result, int count);
char *return_word(char *word, FILE *input);
void print_stats(table *hash_table);
double print_time( clock_t time);

int main(int argc, const char *argv[]) 
{
    FILE *input;                //File pointer
#ifdef MAKE_LIST
    list *word_list; //Linked list initialization
#endif
    list *result;   
    table *hash_table;          //Hash table initialization
    char word[MAXLENGTH];       //Variable for storing terminal input
    clock_t time;               //Variable for program running time calculations
    int count;                  //Number of comparisons made
    
    /* Checking for correct command-line arguments */
    if (argc != 2 ) 
    {
        printf("Program requires one text file as an argument!\n");
        exit(1);
    }
    if ( (input = fopen(argv[1], "r")) == NULL)
    {
        printf("Unable to open %s\n", argv[1]);
        exit(1);
    }
    
    time = clock();                     //initializing zero time value
#ifdef MAKE_LIST
    word_list = build_list(input);      //parsing input file into a linked list
    printf("Storing text in a list took %6.4f s\n", print_time(time));
    time = clock();                     //initializing zero time value
    fclose(input);                      //closing and reopening the
#endif
    input = fopen(argv[1], "r");        //text file for reading into a hash table
    hash_table = build_table(input);    //parsing input file into a hash table
    printf("Storing text in a hash table took %6.4f s\n", print_time(time));
    print_stats(hash_table);            //printing all the hash table statistics
    printf("\n");
    
    do {                //loop for searching in list and hash table
        printf("Enter a word to search:  ");
        scanf("%s", word);
#ifdef MAKE_LIST
        printf("list:\n");
        time = clock();
        result = search_list(word_list, word, &count);
        print_result(result, count);
        printf(", took %4.5f s\n", print_time(time));
#endif
        printf("hash table:\n");
        time = clock();
        result = search_table(hash_table, word, &count);
        print_result(result, count);
        printf(", took %4.5f s\n", print_time(time));
    } while( ask_user() );
    
    fclose(input);
    return 0;
}

int ask_user(void)
{
    /*  Query handling function
     *  Returns 1 if user wants to continue, 0 for other cases.
     */
    
    char c;
    
    while(getchar() != '\n');    //discard all newline characters from previous user input
    
    printf("Do you wish to perform another query? [y/n]:  ");
    scanf("%c", &c);
    if( c == 'y')
        return 1;
    else 
        return 0;
}

void print_result(list *result, int count) 
{
    /*  Prints search result and number of comparisons made.
     */
    
    if(result == NULL)
        printf("Not found, compared %d times", count );
    else
        printf("\'%s\' was counted %d times, compared %d times", result->word, result->count, count);
}

void print_stats(table *hash_table)
{
    /*  Prints various hash table statistics.
     *  Accepts pointer to table structure
     *
     *  The function prints table size, number of items stored,
     *  used and free cells in a hash table, number of cells with hash collisions,
     *  percentage of cells used and how much of them are collided,
     *  longest chain in a table, average length of all cells and 
     *  average length of collided cells
     */
    
    int j, i = 0;
    int free, used, collision;
    int chain_max = 1;
    int chain_sum = 0;
    list *tmp;
    
    free = used = collision = 0;
    
    for( ; i < hash_table->size ; i++)   //loops through the hash table
    {
        j = 0;
        if (hash_table->data[i] == NULL)
            free++;
        else if (hash_table->data[i]->next == NULL)
        {
            chain_sum++;
            used++;
        }
        else 
        {
            tmp = hash_table->data[i];
            for( ; tmp != NULL ; tmp = tmp->next)   //descends the list in a cell and counts for words stored
            {    
                j++;
                chain_sum++;
                if(j > chain_max)                   //remembers the maximum list length
                    chain_max = j;
            }
            collision++;
        }
    }
    
    printf("------STATS-----\n");
    printf("Table size: %d\n# of Items: %d\n", hash_table->size, chain_sum);
    printf("Cells used: %d\nCells free: %d\n", used + collision, free);
    printf("Collisions: %d\n%% used: %5.3f\n", collision, ((double)(used + collision) / hash_table->size) * 100);
    printf("%% of them collided: %5.3f\nLongest chain: %d\n", ((double)(collision) / (double)(used + collision) * 100), chain_max);
    printf("Average chain lenght: %5.2f\n", (double)chain_sum / (hash_table->size - free));
    printf("Average collided lenght: %5.2f\n", (double)(chain_sum - used) / (collision));     
}

list *search_table(table *hash_table, char *word, int *count)
{
    /*  Searches hash table for a string.
     *  Accepts pointer to hash table, character array and pointer to variable 
     *  storing comparisons executed
     *  Returns pointer to result list structure
     */
    
    unsigned int h = hash(word, hash_table->size);            //hash value calculation
    return search_list(hash_table->data[h], word, count);    //list search function call with an array cell as an argument
}

table *grow_table(table *hash_table) 
{
    /*  Resizes hash table.
     *  Requires hash table as an argument and returns pointer to bigger hash table
     *
     *  It first allocates memory to a table two times bigger and then rehashes all 
     *  the previous values into a new one. Memory allocated for old table is freed
     */
    
    int h, i = 0;
    list *bucket;       //for storing a list to be rehashed
    list *node;        
    table *new_table = gcalloc(1, sizeof(table));    //memory allocated for table structure
    
    new_table->size =  (int) (hash_table->size * GROWTH) + 1;   //Size is increased and 1 is added for the number to be odd
    new_table->items = hash_table->items;                       //Number of elements is copied to the new table
    new_table->data = gcalloc(new_table->size, sizeof(list));   //Memory allocated for data array

    for( ; i <= hash_table->size ; i++)         //Loops through all hash table 
    {            
        if( hash_table->data[i] != NULL) 
        {
            bucket = hash_table->data[i];       //Stores cell pointer for manipulation 
            while( bucket != NULL) 
            {
                h = hash(bucket->word, new_table->size);    //Rehashing values for new table size
                node = create_node(bucket->word);           //Creating a list node from a string
                node->count = bucket->count;
                node->next = new_table->data[h];            //Connecting node with the list
                new_table->data[h] = node;                  //Replacing pointer to the list head
                bucket = bucket->next;                      //Advancing through the list 
            }
            destroy(hash_table->data[i]);       //Freeing the memory allocated for the list in a cell
        }
    }
    
    free(hash_table);   //Freeing the memory allocated for old hash table
    return new_table;
}

void destroy(list *word_list)
{
    /*  Frees memory allocated to a linked list
     *  Accepts pointer to a list
     *  Steps through whole list freeing every node separately
     */
    
    list *tmp;
    
    for( ; tmp != NULL; word_list = tmp) 
    {
        tmp = word_list->next;
        free(word_list);
    }
}

table *build_table( FILE *input)
{
    /*  Function builds a hash table from file
     *  Accepts file pointer and returns pointer to hash table structure
     *  Function automatically resizes the table when it reaches certain ammount of items.
     *  This is controlled by typedef'ed constant "RATIO"
     */
    
    table *hash_table = gcalloc(1, sizeof(table));      //allocating memory to the hash table
    char *word = gcalloc(MAXLENGTH, sizeof(char));      //temporary storage of a word being processed
    int max_size;   //maximum ammount of items in a table to trigger the resizing
    int h;          //hash variable
    
    hash_table->size = INIT_SIZE;                                   //initial size
    hash_table->items = 0;                                          //number of items
    hash_table->data = gcalloc(hash_table->size, sizeof(list));     //allocating memory for data storage
    max_size = hash_table->size * RATIO;                            //update maximum allowed size

    while( (word = return_word(word, input)) != NULL)   //loop through the input file one word at a time
    {        
        if( max_size < hash_table->items)               //trigering the resize
        {             
            hash_table = grow_table(hash_table);        
            max_size = hash_table->size * RATIO;        //storing new size to trigger the resize
        }
        h = hash(word, hash_table->size);               //string hashing
        hash_table->data[h] = insert_word(hash_table->data[h], word, &hash_table->items);   //inserting word in a right place
    }
    
    free(word);     //freeing memory allocate for temporary word storage
    return hash_table;
}

unsigned int hash(char *word, int tbl_size)
{
    /*  Hashing function
     *  Accepts a string and table size, returns int hash value    
     *  
     *  Statistics:
     *  Table size: 6143
     *  # of Items: 4231
     *  Cells used: 3079
     *  Cells free: 3064
     *  Collisions: 926
     *  % used: 50.122
     *  % of them collided: 30.075
     *  Longest chain: 5
     *  Average chain lenght:  1.37
     *  Average collided lenght:  2.24
     *  
     *  It was chosen because, comparing to the next one, it yielded slightly more different hashes - 3079 vs 3065.
     *  Under more extreeme circumstances (RATIO set to 4), however, it behaved worse than the other - 1433 vs 1438
     *  But since the hash table will have a ratio of ~1 it is not important. 
     *  The speed of both functions is almost the same - less than 0.1s difference when looped 10^9 times.
     */
    
    unsigned long h = 5381;
    unsigned char *p;
    
    for( p = (unsigned char *) word; *p != '\0'; p++)
        h = ((h << 5) + h) + *p; /* hash * 33 + c */
    
    return h % tbl_size;
}

/*
unsigned int hash(char *word, int tbl_size)
{
     *  Statistics
     *  
     *  Table size: 6143
     *  # of Items: 4231
     *  Cells used: 3065
     *  Cells free: 3078
     *  Collisions: 935
     *  % used: 49.894
     *  % of them collided: 30.506
     *  Longest chain: 6
     *  Average chain lenght:  1.38
     *  Average collided lenght:  2.25
     *
     *
    
    unsigned int h;
    unsigned char *p;
    unsigned int multiplier = 31
    
    h = 1;

    for( p = (unsigned char *) word; *p != '\0'; p++)
        h = multiplier * h + *p;
    return h % tbl_size;
}
*/

/*
unsigned int hash(char *word, int tbl_size)        
{
     *  This function was not chosen because of very bad hash spread. It yealds 5 times 
     *  less different hashes than other two tested functions.
     *
     *  Statistics:
     *  Table size: 6143
     *  # of Items: 4231
     *  Cells used: 760
     *  Cells free: 5383
     *  Collisions: 551
     *  % used: 12.372
     *  % of them collided: 72.500
     *  Longest chain: 27
     *  Average chain lenght:  5.57
     *  Average collided lenght:  7.30
     *

    unsigned long h = 0;
    unsigned char *p;
    
    for( p = (unsigned char *) word; *p != '\0'; p++)
        h += *p;
    
    return h % tbl_size;
}
*/


char *return_word(char *word, FILE *input) 
{
    /*  File parsing function
     *  Accepts string and file pointer, returns string
     *  Function reads one word per call. All strings returned are lowercase.
     *  It treats text like "we'll" as two words, but "who's" is counted as one.
     */
    
    int c, i = 1;        //loop variable and character storage    
    
    while ( (c = fgetc(input)) != EOF)  //loops through input until it encounters first letter
    {        
        if (isalpha(c))
        {                    
            word[0] = tolower(c);       //adds the character to array
            break;                      //then breaks out of the loop
        }
    }
    
    while( (c = fgetc(input)) != EOF)   //loops through the rest of the input until non-letter character is encountered
    {        
        if (!isalpha(c)) 
        {
            if( c == '\'' && c != EOF)  //checks if there is no "'s" at the end of the word
            {     
                if((c = fgetc(input)) != 's')
                    ungetc(c, input);                            
            }
            word[i] = '\0';
            return word;
        }
        word[i] = tolower(c);
        i++;
    }
    
    return NULL;
}

list *build_list( FILE *input) 
{
    /*  List building function
     *  Accepts file pointer as an argument, returns a list
     *  Function loops through strings returned by return_word() and calls insert_word() for each word
     */
    char *word = gcalloc(MAXLENGTH, sizeof(char));          //temporary word storage
    int used = 0;               //number of different words read
    int i = 0;                  //loop counter
    list *word_list = NULL;     //linked list head

    while( (word = return_word(word, input)) != NULL )      //reading words from input
    {        
        word_list = insert_word(word_list, word, &used);    //appending list
        i++;
    }
    
    free(word);
    printf("%d words read\n", i);
    return word_list;
}

list *search_list( list *word_list, char *word, int *count) 
{
    /*  List searching function
     *  Accepts pointer to a list, string to search and a pointer to int for storing 
     *  number of comparisons made
     *  Funtion returns NULL if word is not found and pointer to list structure if it's found.
     */
     
    *count = 0;
    
    while(word_list != NULL)        //looping through a list
    {        
        *count+=1;                  //increase number of comparisons made
        if( strcmp(word_list->word, word) == 0 )    
            return word_list;
        word_list = word_list->next;
    };
    
    return NULL;
}

list *insert_word( list *word_list, char *word, int *used) 
{
    /*  Function for inserting word to a list
     *  Accepts pointer to a list, string and pointer to int for storing number of different words
     *  Returns head of a list
     *  Function increments the count if string is already in a list or creates a new node.
     */
     
    int count;              //dummy variable required by search_list()
    list *node, *result;    
    
    if( (result = search_list(word_list, word, &count)) == NULL ) 
    {
        node = create_node(word);        
        node->next = word_list;
        *used+=1;           //increments number of different words in a list
        return node;
    }
    else 
    {
        result->count += 1;
        return word_list;
    }
}

double print_time( clock_t time)
{
    /*  Function calculates time elapsed after the "time" variable was set
     *  Accepts clock_t variable and returns time in seconds
     */
    
    return ((double)(clock() - time)/CLOCKS_PER_SEC);
}

list *create_node(char *word)
{
    /*  Function creates new instance of list variable
     *  Accepts a string and returns pointer to list variable storing that string
     */
     
    list *node = gcalloc(1, sizeof(list));
    
    node->word = gcalloc(strlen(word) + 1, sizeof(char));
    node->count = 1;
    strcpy(node->word, word);
    node->next = NULL;
    return node;
}

void *gcalloc( int number, int size) 
{
    /*  Gracefull calloc function
     *  Checks if memory allocation using calloc() was successful
     */
    void *p = calloc(number, size);
    
    if(p == NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }
    else return p;
}
