#!/bin/bash
gcc addnodetest/addnodetest.c ../../stackop.c addnodetest/0-print_dlistint.c
echo -e "\nadd_node():"
./a.out
echo -e "\nEXPECTED:\n1024\n402\n98\n4\n3\n2\n1\n0\n"
