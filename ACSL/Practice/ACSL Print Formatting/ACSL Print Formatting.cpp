#include "ACSL Print Formatting.h"
void printfcomma(int n, FILE* output)
{
	if (n < 1000) {
		fprintf(output, "%d", n);
		return;
	}
	printfcomma(n / 1000, output);
	fprintf(output, ",%03d", n % 1000);
}
void acslprintrun()
{
	FILE* input = fopen("print.in", "r");
	FILE* output = fopen("print.out", "w");
	char format[30];
	int value;
	bool comma, dollar, star, minus;
	int amperandcount;
	for (int l = 0; l < 5; l++)
	{
		amperandcount = 0;
		comma = false;
		dollar = false;
		star = false;
		minus = false;
		fscanf(input, "%s%d", &format, &value);
		format[strlen(format) - 1] = '\0';
		for (int i = 0; i < 30; i++)
		{
			if (format[i] == ',')
			{
				comma = true;
			}
			else if (format[i] == '$')
			{
				dollar = true;
			}
			else if (format[i] == '*')
			{
				star = true;
			}
			else if (format[i] == '-')
			{
				minus = true;
			}
			else if (format[i] == '&')
			{
				amperandcount++;
			}
		}
		int count = 0;
		int n = value;
		while (n != 0)
		{
			n = n / 10;
			++count;
		}
		if (dollar == true && star == false)
		{
			fprintf(output, "$");
		}
		else if (dollar == true && star == true)
		{
			for (int q = 0; q < amperandcount - count; q++)
			{
				fprintf(output, "*");
			}
			fprintf(output, "$");
		}
		else
		{
			for (int q = 0; q < amperandcount - count; q++)
			{
				fprintf(output, "*");
			}
		}
		if (comma == true)
		{
			printfcomma(int(fabs(value)), output);
		}
		else
		{
			fprintf(output, "%d", int(fabs(value)));
		}
		if (minus == true)
		{
			fprintf(output, "-");
		}
		fprintf(output, "\n");
	}
	fclose(input);
	fclose(output);
}