Data Structures and Algorithms Lab7: Indexing using AVL Trees, Hashing, Tries
==============
The code structure uses AVL tree to build an index of words. 
The words were read from a sanitized text file (to eliminate all special characters). The accompanying python script (authored by me) was used to sanitize the file.

ftell was used to keep track of the file pointer since beginnning. (No new lines are allowed in the sanitized text file.)

basicLL.c and basicAVL.c were used as references for the final code.
While basicLL.c is written by me, basicAVL.c was used from http://www.geeksforgeeks.com
Note that each node of the AVL tree node uses a linked list to keep track of the positions where a particular word has occurred.

CamelCase has been used consistently throughout all codes authored by me. 
Codes used from web sources have been attributed wherever possible.

***ONLY AVL Tree based Index has been implemented so far.***