rm a.out monty.h
STACK=$(find ../../../ -name stackop.c) 
cp $(find ../../../ -name monty.h) .
gcc monty.h $STACK *.c
./a.out
