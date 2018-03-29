In this final challenge of this problem set we had to implement a program that recovers JPEGs from a forensic image, per the below: 

$ ./recover card.raw

The file card.raw had around 50 jpeg files so we had to open, read from that file and save all 50 images into a directory. 

In recover.c source code I looked for JPEGs' signatures. Each time I found a signature, I opened a new file for writing and started
filling that file with bytes from card.raw, closing that file only once I encountered another signature. 
Moreover, rather than read my memory card’s bytes one at a time, I read 512 of them at a time into a buffer for efficiency’s sake. 
With JPEGs' signatures you only need to look in a block’s first four bytes.

Once the code worked, it created a directory with 0..49 readable jpeg files. 

Here is one of them: 

![pset4e](https://user-images.githubusercontent.com/14170402/38070446-2e98abd8-32d9-11e8-8ebe-131a36d66c3b.PNG)

