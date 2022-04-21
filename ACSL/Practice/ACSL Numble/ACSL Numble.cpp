#include "ACSL Numble.h"
void acslnumblerun()
{
	FILE* input = fopen("numble.in", "r");
	FILE* output = fopen("numble.out", "w");
	int num, digit;
	int counter;
	int d[7] = { 0 };
	int m, a;
	int sum;
	int last, secondlast, thirdlast;
	for (int l = 0; l < 5; l++)
	{
		last = 0;
		thirdlast = 0;
		secondlast = 0;
		sum = 0;
		counter = 0;
		fscanf(input, "%d, %d", &num, &digit);
		m = num;
		while (num > 0)
		{
			num = num / 10;
			counter++;
		}
		while (m > 0)
		{
			d[counter - 1] = m % 10;
			m = m / 10;
			counter--;
		}
		for (int i = 0; i < 7; ++i)
		{
			for (int j = i + 1; j < 7; ++j)
			{
				if (d[i] < d[j])
				{
					a = d[i];
					d[i] = d[j];
					d[j] = a;
				}
			}
		}	
		for (int q = 0; q < digit - 3; q++)
		{
			sum += d[q];
		}
		for (int q = digit - 3; q < 5; q++)
		{
			for (int r = q + 1; r < 6; r++)
			{
				for (int s = r + 1; s < 7; s++)
				{
					if ((sum + d[q] + d[r] + d[s]) % 5 == 0)
					{
						thirdlast = d[q];
						secondlast = d[r];
						last = d[s];
						break;
					}
				}
				if (last != 0 && secondlast != 0 && thirdlast != 0)
				{
					break;
				}
			}
			if (last != 0 && secondlast != 0 && thirdlast != 0)
			{
				break;
			}
		}
		if (last == 0 || secondlast == 0 || thirdlast == 0)
		{
			fprintf(output, "NONE");
		}
		else
		{
			for (int i = 0; i < digit - 3; i++)
			{
				fprintf(output, "%d", d[i]);
			}
			fprintf(output, "%d", thirdlast);
			fprintf(output, "%d", secondlast);
			fprintf(output, "%d", last);
		}
		fprintf(output, "\n");
	}
	fclose(input);
	fclose(output);
}