# Speller :pencil2:
A program in C that spell-checks a file. It uses a hash table data structure to load and manage a dictionary with more than 140,000 words.

# Goal :dart:
The goal of this project is to create a program that will read a given text file and it'll look for words that are not found in a dictionary with 143,091 words. 

The goal is achieved by using a hash table data structure to store the dictionary and creating an algorithm that checks if every word is found in the dictionary and counts and shows how many are not. There are many ways to approach this but the idea is to find the most time-efficient algorithm.

# Example :mag:

Let's spell check "The Complete PG Works of Oliver Wendell Holmes, Sr.", a complete ebook!

After running:
```c
make speller
```
```c
./speller dictionaries/large text/holmes.txt
```
The results are a long list of words and this:
```c
WORDS MISSPELLED:     17845
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        1150970
TIME IN load:         0.03
TIME IN check:        114.97
TIME IN size:         0.00
TIME IN unload:       0.01
TIME IN TOTAL:        115.01
```

As seen, the program found 17,845 probably mispelled words in a total of 1,150,970 words in just 1 minute and 54 seconds!
Loaded the dictionary and freed it in less than a second. No memory leaks!

This can definitely be improved even more but is a relatively decent performance as it is. Thanks for checking it out!
For more info visit: https://cs50.harvard.edu/x/2021/psets/5/speller/
