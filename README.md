# Bucket Sort Program
1. This program sorts words from user input into different buckets based on command line arguments. Each bucket represents a range of words, starting from the command line argument for that bucket up to (but not including) the command line argument for the next bucket.

How to Compile and Run
Compile the program using GCC:
```bash
gcc -o bucketsort bucketsort.c 
# or with make file as 
make 
```
1. Run the program with command line arguments representing the minimum word for each bucket:
```bash
./bucketsort apple carrot kiwi
```
- In this example, words that are lexicographically less than "apple" will go into the first bucket, words that are lexicographically equal to or greater than "apple" but less than "carrot" will go into the second bucket, and so on.

- Enter words to be sorted. The program will sort the words into the appropriate buckets as they are entered.
Program Structure
- The program uses two structs: `node` and `bucket`. The `node` struct represents a node in a linked list of words, and the bucket struct represents a bucket containing a linked list of words.

- The `createNode `function creates a new node with a given word. The `insertNode` function inserts a word into a sorted linked list. The printBucket function prints the words in each bucket.

- The `removePunctuation` function removes punctuation from the end of a word, allowing words with punctuation to be sorted correctly.

- The main function initializes the buckets based on the command line arguments, reads words from the user input, inserts each word into the appropriate bucket, and then prints the words in each bucket.

# Error Handling
The program checks if there is at least one command line argument and outputs an error message if not.

# Limitations
The program currently does not handle memory allocation errors. It also does not free allocated memory when it's no longer needed.
