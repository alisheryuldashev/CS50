This problem required implementation of a spell checker using either a hash table or a trie data structure. 

In speller.c file, CS50 staff has put together a program that’s designed to spell-check a file after loading a dictionary of words from disk into memory. However, they did not get around to implementing the loading and the checking parts, leaving them to be implemented by students.

Dictionary.h file only declares four functions (load, check, size, unload) which should be implemented in the dictionary.c file. My job was to re-implement those functions in dictionary.c file as cleverly as possible so that this spell checker works fast.

The output of this program will show all the misspelled words and the time it took to run the above 4 functions: 

$ ./speller texts/lalaland.txt
MISSPELLED WORDS

[...]
AH
[...]
Shangri
[...]
fianc
[...]
Sebastian's
[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:
