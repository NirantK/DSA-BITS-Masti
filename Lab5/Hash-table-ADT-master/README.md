The assignment was to implement a word occurance counter that stores the data in both linked list and a hash table. We had to measure the number of collisions for few hash functions and compare their performance. Unsurprisingly hash table is much faster than linked list for this kind of application.

First non-trivial C program written. Few things to mention:

 * Linked list approach suppressed by undefining MAKE_LIST
 * Grows hash table automatically
 * Stores colliding entries in a linked list
 * Compares few hash functions, results in comments


