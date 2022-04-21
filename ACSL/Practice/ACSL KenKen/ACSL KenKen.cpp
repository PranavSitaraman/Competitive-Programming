#include "ACSL KenKen.h"
void acslkenkenrun()
{
	FILE* input = fopen("kenken.in", "r");
	FILE* output = fopen("kenken.out", "w");
	int set[10] = { 0 };
	int sum[10] = { 0 };
	int numsect = 0;
	int tile = 0;
	int match[10] = { 0 };
	int entry[10] = { 0 };
	int count = 1;
	int total = 0;
	fscanf(input, "%d", &numsect);
	for (int i = 0; i < 20; i++)
	{
		fscanf(input, "%d", &tile);
		if ((fgetc(input)) != ',')
		{
			sum[count++] = tile;
		}
		else
		{
			set[tile] = count;
		}
		if ((fgetc(input)) == '\n')
		{	
			break;
		}
	}
	for (int a = 1; a <= 3; a++)
	{
		for (int b = 1; b <= 3; b++)
		{
			for (int c = 1; c <= 3; c++)
			{
				for (int d = 1; d <= 3; d++)
				{
					for (int e = 1; e <= 3; e++)
					{
						for (int f = 1; f <= 3; f++)
						{
							for (int g = 1; g <= 3; g++)
							{
								for (int h = 1; h <= 3; h++)
								{
									for (int i = 1; i <= 3; i++)
									{
										entry[1] = a;
										entry[2] = b;
										entry[3] = c;
										entry[4] = d;
										entry[5] = e;
										entry[6] = f;
										entry[7] = g;
										entry[8] = h;
										entry[9] = i;
										bool right = true;
										for (int q = 1; q <= numsect; q++)
										{
											total = 0;
											for (int k = 1; k < 10; k++)
											{
												if (set[k] == q)
												{
													total += entry[k];
												}
											}
											if (total != sum[q])
											{
												right = false;
												break;
											}
										}
										if (right == true && a != b && b != c && c != a
											&&
											d != e && e != f && d != f
											&&
											g != h && h != i && g != i
											&&
											a != d && a != g && d != g
											&&
											b != e && b != h && e != h
											&&
											c != f && c != i && f != i)
										{
											goto label;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	label:
	fprintf(output, "");
	int num;
	for (int i = 1; i <= 5; i++)
	{
		if (i == 1)
		{
			fscanf(input, "%d", &num);
		}
		else
		{
			fscanf(input, "%*c%d", &num);
		}
		fprintf(output, "%d\n", entry[num]);
		if ((fgetc(input)) == '\n')
		{
			break;
		}
	}
	fclose(input);
	fclose(output);
}