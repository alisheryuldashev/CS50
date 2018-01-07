This problem required implementation of a spell checker using either a hash table or a trie data structure. 
My solution worked, but had a few memory leaks and so I got 85% out of 100% for this problem.

Here is what was done: 

In speller.c file, CS50 staff has put together a program that’s designed to spell-check a file after loading a dictionary of words from disk into memory. However, they did not get around to implementing the loading and the checking parts, leaving them to be implemented by students.

Dictionary.h file only declares four functions (load, check, size, unload) which should be implemented in the dictionary.c file. My job was to re-implement those functions in dictionary.c file as cleverly as possible so that this spell checker works fast.

The output of this program will show all the misspelled words and the time it took to run the above 4 functions: 

$ ./speller texts/lalaland.txt<br />
MISSPELLED WORDS<br /><br />
<br />
[...]<br />
AH<br /><br />
[...]<br /><br />
Shangri<br />
[...]<br /><br />
fianc<br /><br />
[...]<br /><br />
Sebastian's<br /><br />
[...]<br /><br />
<br />
WORDS <br />MISSPELLED:<br />
WORDS IN DICvTIONARY:<br />
WORDS IN TE<br />:<br />
TIME IN load:<br />
TIME IN check:<br />
TIME IN size:<br />
TIME IN unload:<br />
TIME IN TOTAL:<br />
