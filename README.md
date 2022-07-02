# image-decoder
Simple binary image decoder. This is a program that will read commands from a file and compute results that look like pictures.

Here is an example input file:

~~~
01010100011000
01011011101000
01001011100110
11001011100111
10101011111111
10101011100111
00101011111110
10101101100111
10110000111111
01000110001010
01010001010010
01010101111110
~~~

Output after decoding:

~~~
 XX        XX 
 X X      X X 
 X  X    X  X 
 X  XXXXXX  X 
 XXXXXXXXXXXX 
XXXX  XX  XXXX
XXXXXXXXXXXXXX
XXXXXX  XXXXXX
 XXXXXXXXXXXX 
  XXXXXXXXXX  
    XXXXXX 
~~~
