# Monty
#### Description: Will provide a description later

# Usage
```
$ gcc *.c
$ ./a.out someMontyFile.m
```
# File Structure

    monty
    ├── ...
    └── unit_tests      
        ├── monty # Monty Files
        |   └── ...             
        └── linkedlists # C Files
            ├── addnodetest
            |   └── ...
            ├── deletenodetest
            |   └── ...
            └── unit_test_readme.me
### Root Directory
| Monty  |
| ------------- |
| functionpointers.c - Has a lists of commands| 
| monty.h - Header file| 
| parse.c - Takes in a file.m and tokenizes strings|
| stackop.c - Helper functions to help create commands|
| README.md | 
### unit_tests Directory
| Monty  | Linkedlists |
| ------------- |:-------------:|
| 01.m          | addnodetest    |
| validCommand.m|   deletenodetest    |
|      |   a.out    |
### linkedlist Directory
| addnodetest | deletenode |
| ------------- |-----------|
| 0-print_dlistint.c | 0-print_dlistint.c |
| addnodetest.c | deletenodetest.c
| printlisttest.c | printlisttest.c |
| monty.h | monty.h |
| testaddnode.sh | testdeletenode.sh |

#### To run test files in Linked List Directory, cd into a directory and run the .sh files for output

#### Example of running _addnodetest.sh_ script in addnodetest dir. 
```
$ cd monty/unit_tests/linkedlists
$ ./addnodetest.sh
$ cd monty/unit_tests/linkedlists
$ ./addnodetest.sh

add_node():
1024
402
98
4
3
2
1
0

EXPECTED:
1024
402
98
4
3
2
1
0

$
```
# Authors
#### This project was created by Jonathan Wang and Stephen Schwartz
