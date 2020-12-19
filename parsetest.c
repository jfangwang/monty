#include "monty.h"

#define MAXCHAR 1000
int main() {
	FILE *fp;
	/*Max num of chars */
	char str[MAXCHAR];
	/* This will be argv */
	char* filename = "/home/vagrant/monty/tests/01.m";
	int numcmd = 0;
	int a = 0;
	char* word = "push";
	int count = 0;
	int ind = 0;
	int worlen = 0;
	int toklen = 0;

	fp = fopen(filename, "r");
	if (fp == NULL){
		printf("Could not open file %s",filename);
		return 1;
	}
	while (fgets(str, MAXCHAR, fp) != NULL)
	{
		printf("Str is: %s", str);
		// Returns first token 
		char* token = strtok(str, " "); 

		// Keep printing tokens while one of the 
		// delimiters present in str[]. 
		while (token != NULL) {
			toklen = 0;
			worlen = 0;
			ind = 0;
			while (*(token + toklen) != '\0' && *(token + toklen) != '\n')
				toklen += 1;
			while (*(word + worlen) != '\0' && *(word + worlen) != '\n')
				worlen += 1;
			printf("%s, %d, %d\n", token, worlen, toklen);
			if (toklen == worlen)
			{
				while (word[ind] == token[ind] && token[ind] != '\0' && token[ind] != '\n')
				{
					printf("%c, %c\n", word[ind], token[ind]);
					ind++;
				}
			}
			if (ind == worlen)
				count += 1;
			token = strtok(NULL, " "); 
		}
	}
	printf("count: %d\n", count); 
	fclose(fp);
	return 0;
}
