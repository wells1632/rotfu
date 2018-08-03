Introduction:

rotfu takes the old ROT13 function and plays with it. Instead of simply rotating the alphabet 13 characters,
it will instead progressively rotate the alphabet, such that the first character of the alphabet it
encounters will be incremented by one letter (i.e. "C" becomes "D"), then the next will increment two ("C"
becomes "E"), etc. The same will happen for numerals under a different counter. Punctuation characters will
remain the same.

Caveats:

If a binary file is fed into rotfu, it will error out declaring that the file cannot be converted.
