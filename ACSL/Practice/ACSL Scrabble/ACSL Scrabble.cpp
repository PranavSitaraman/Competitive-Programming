#include "ACSL Scrabble.h"
void acslscrabblerun()
{
	char letter1, letter2, letter3, letter4;
	int score1, score2, score3, score4;
	int start;
	int bonus;
	int doublebonus;
	int triplebonus;
	FILE* input = fopen("scrabble.in", "r");
	fscanf(input, "%c, %c, %c, %c", &letter1, &letter2, &letter3, &letter4);
	FILE* output = fopen("scrabble.out", "w");
	int sum;
	switch (letter1)
	{
	case 'A': case 'E': score1 = 1; break;
	case 'D': case 'R': score1 = 2; break;
	case 'B': case 'M': score1 = 3; break;
	case 'V': case 'Y': score1 = 4; break;
	case 'J': case 'X': score1 = 8; break;
	}
	switch (letter2)
	{
	case 'A': case 'E': score2 = 1; break;
	case 'D': case 'R': score2 = 2; break;
	case 'B': case 'M': score2 = 3; break;
	case 'V': case 'Y': score2 = 4; break;
	case 'J': case 'X': score2 = 8; break;
	}
	switch (letter3)
	{
	case 'A': case 'E': score3 = 1; break;
	case 'D': case 'R': score3 = 2; break;
	case 'B': case 'M': score3 = 3; break;
	case 'V': case 'Y': score3 = 4; break;
	case 'J': case 'X': score3 = 8; break;
	}
	switch (letter4)
	{
	case 'A': case 'E': score4 = 1; break;
	case 'D': case 'R': score4 = 2; break;
	case 'B': case 'M': score4 = 3; break;
	case 'V': case 'Y': score4 = 4; break;
	case 'J': case 'X': score4 = 8; break;
	}
	for (int k = 0; k < 5; k++)
	{
		doublebonus = 0;
		triplebonus = 0;
		sum = 0;
		fscanf(input, "%d", &start);
		for (int j = 0; j < 4; j++)
		{
			bonus = 1;
			if ((start + j) % 3 == 0 && (start + j) % 2 != 0)
			{
				bonus = 2;
			}
			else if ((start + j) % 5 == 0)
			{
				bonus = 3;
			}
			else if ((start + j) % 7 == 0)
			{
				doublebonus++;
			}
			else if ((start + j) % 8 == 0)
			{
				triplebonus++;
			}
			if (j == 0)
			{
				sum += score1 * bonus;
			}
			else if (j == 1)
			{
				sum += score2 * bonus;
			}
			else if (j == 2)
			{
				sum += score3 * bonus;
			}
			else if (j == 3)
			{
				sum += score4 * bonus;
			}
		}
		sum = sum * int(pow(2, doublebonus)) * int(pow(3, triplebonus));
		fprintf(output, "%d\n", sum);
	}
	fclose(input);
	fclose(output);
}