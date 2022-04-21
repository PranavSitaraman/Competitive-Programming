#include "USACO COW.h"
void usacocowrun()
{
	int len;
	FILE* file = fopen("cow.in", "r");
	fscanf(file, "%d", &len);
	char* word = (char*)calloc(len, sizeof(char));
	fscanf(file, "%s", word);
	fclose(file);
	long long c = 0, o = 0, w = 0;
	for (int i = 0; i < len; i++)
	{
		switch (word[i])
		{
		case 'C': c++; break;
		case 'O': o += c; break;
		case 'W': w += o; break;
		}
	}
	file = fopen("cow.out", "w");
	fprintf(file, "%lld", w);
	fclose(file);
}