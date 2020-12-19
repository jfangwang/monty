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
	char* word = "push\0";
	int count = 0;

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
			a = 0;
			printf("%s, %zu, %zu\n", token, strlen(word), strlen(token));
			if (strlen(word) == strlen(token))
			{
				while (word[a] == token[a] && token[a] != '\0')
				{
					printf("%c, %c\n", word[a], token[a]);
					a++;
				}
			}
			if (a == strlen(token))
				count += 1;
			token = strtok(NULL, " "); 
		}
	}
	printf("count: %d\n", count); 
	fclose(fp);
	return 0;
}
