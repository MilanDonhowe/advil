# Advil :: Another BrainF__k Interpreter
Advil is an interpreter for the esoteric language known as "brainf__k" originally devised by Urban Müller in 1993.

This implementation isn't anything special, it was mostly created as a programming exercise in C.  Nonetheless this implementation strives to be somewhat faithful to the original implementation, mostly by virtue of being written in C.

* The "tape" or base array size is 30,000 blocks each holding an integer value and the pointer starts at the left end of the array.  

* The cell width is 8 bits, managed like a unsigned 8 bit integer (0-255)

* EOF treated as -1 due to C stdio functions for input and output.

* There is cell-wrapping, if you shift below the zeroth cell it will wrap to the right most cell and vice-versa.  



## More about brainf**k:

* EsoLang Wiki Entry: https://esolangs.org/wiki/Brainfuck
* 






