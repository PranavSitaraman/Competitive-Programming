#include "USACO Censoring.h"
#define LENWORD 1000
#define LENKEY 100
void usacocensoringrun()
{
	int lenword, lenkey, resize, top = 0;
	char word[LENWORD] = { 0 }, key[LENKEY] = { 0 };
	int keyresult[LENWORD] = { 0 };
	int wordresult[LENWORD] = { 0 };
	int stack[LENWORD] = { 0 };
	FILE* file = fopen("censor.in", "r");
	fscanf(file, "%s", word + 1);
	fscanf(file, "%s", key + 1);
	fclose(file);
	lenword = strlen(word + 1);
	lenkey = strlen(key + 1);
	for (int i = 2, j = 0; i <= lenkey; i++)
	{
		while (j && key[i] != key[j + 1])
		{
			j = keyresult[j];
		}
		if (key[i] == key[j + 1])
		{
			j++;
		}
		keyresult[i] = j;
	}
	for (int i = 1, j = 0; i <= lenword; i++)
	{
		while (j && word[i] != key[j + 1])
		{
			j = keyresult[j];
		}
		if (word[i] == key[j + 1])
		{
			j++;
		}
		wordresult[i] = j;
		stack[++top] = i;
		if (j == lenkey)
		{
			top -= lenkey;
			resize = 0;
			if (top > 0)
			{
				j = wordresult[stack[top]];
			}
		}
	}
	file = fopen("censor.out", "w");
	for (int i = 1; i <= top; i++)
	{
		fprintf(file, "%c", word[stack[i]]);
	}
	fclose(file);
}