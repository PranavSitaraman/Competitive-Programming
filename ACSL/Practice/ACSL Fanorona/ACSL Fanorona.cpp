#include "ACSL Fanorona.h"
void acslfanoronarun()
{
	FILE* input = fopen("fanorona.in", "r");
	FILE* output = fopen("fanorona.out", "w");
	for (int l = 0; l < 5; l++)
	{
		int whitenum, blacknum;
		int white[13] = { 0 };
		int black[13] = { 0 };
		int capture[13] = { 0 };
		if (l == 0)
		{
			fscanf(input, "%d", &whitenum);
		}
		else
		{
			fscanf(input, "%*c%d", &whitenum);
		}
		for (int i = 0; i < whitenum; i++)
		{
			fscanf(input, "%*c%d", &white[i]);
		}
		fscanf(input, "%*c%d", &blacknum);
		for (int i = 0; i < blacknum; i++)
		{
			fscanf(input, "%*c%d", &black[i]);
		}
		int count = 0;
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				if (white[i] != 0 && black[j] != 0)
				{
					if ((white[i] - black[j] == 1 || white[i] - black[j] == -1 || white[i] - black[j] == 2 || white[i] - black[j] == -2) && int((white[i] - 1) / 5) == int((black[j] - 1) / 5))
					{
						//
						if (white[i] - black[j] == -2)
						{
							bool same = false;
							for (int r = 0; r < 13; r++)
							{
								if (black[r] == white[i] + 1)
								{
									same = true;
									break;
								}
								if (white[r] == white[i] + 1)
								{
									same = true;
									break;
								}
							}
							if (same == true)
							{
								goto label;
							}
						}
						if (white[i] - black[j] == 2)
						{
							bool same = false;
							for (int r = 0; r < 13; r++)
							{
								if (black[r] == white[i] - 1)
								{
									same = true;
									break;
								}
								if (white[r] == white[i] - 1)
								{
									same = true;
									break;
								}
							}
							if (same == true)
							{
								goto label;
							}
						}
						if (white[i] - black[j] == 1)
						{
							bool same = false;
							for (int r = 0; r < 13; r++)
							{
								if (black[r] == white[i] + 1)
								{
									same = true;
									break;
								}
								if (white[r] == white[i] + 1)
								{
									same = true;
									break;
								}
							}
							if (same == true)
							{
								goto label;
							}
						}
						if (white[i] - black[j] == -1)
						{
							bool same = false;
							for (int r = 0; r < 13; r++)
							{
								if (black[r] == white[i] - 1)
								{
									same = true;
									break;
								}
								if (white[r] == white[i] - 1)
								{
									same = true;
									break;
								}
							}
							if (same == true)
							{
								goto label;
							}
						}
						capture[count++] = black[j];
						if ((white[i] - black[j] == -1) || (white[i] - black[j] == -2))
						{
							for (int q = 1; q <= 3; q++)
							{
								bool equal = false;
								for (int r = 0; r < 13; r++)
								{
									if (black[r] == black[j] + q)
									{
										equal = true;
										break;
									}
								}
								if (equal == true)
								{
									capture[count++] = black[j] + q;
								}
								else
								{
									break;
								}
							}
						}
						if ((white[i] - black[j] == 1) || (white[i] - black[j] == 2))
						{
							for (int q = -1; q >= -3; q--)
							{
								bool equal = false;
								for (int r = 0; r < 13; r++)
								{
									if (black[r] == black[j] + q)
									{
										equal = true;
										break;
									}
								}
								if (equal == true)
								{
									capture[count++] = black[j] + q;
								}
							}
						}
					}
					else if ((white[i] - black[j] == 5 || white[i] - black[j] == -5 || white[i] - black[j] == 10 || white[i] - black[j] == -10))
					{
						if (white[i] - black[j] == -10)
						{
							bool same = false;
							for (int r = 0; r < 13; r++)
							{
								if (black[r] == white[i] + 5)
								{
									same = true;
									break;
								}
								if (white[r] == white[i] + 5)
								{
									same = true;
									break;
								}
							}
							if (same == true)
							{
								goto label;
							}
						}
						if (white[i] - black[j] == 10)
						{
							bool same = false;
							for (int r = 0; r < 13; r++)
							{
								if (black[r] == white[i] - 5)
								{
									same = true;
									break;
								}
								if (white[r] == white[i] - 5)
								{
									same = true;
									break;
								}
							}
							if (same == true)
							{
								goto label;
							}
						}
						if (white[i] - black[j] == 5)
						{
							bool same = false;
							for (int r = 0; r < 13; r++)
							{
								if (black[r] == white[i] + 5)
								{
									same = true;
									break;
								}
								if (white[r] == white[i] + 5)
								{
									same = true;
									break;
								}
							}
							if (same == true)
							{
								goto label;
							}
						}
						if (white[i] - black[j] == -5)
						{
							bool same = false;
							for (int r = 0; r < 13; r++)
							{
								if (black[r] == white[i] - 5)
								{
									same = true;
									break;
								}
								if (white[r] == white[i] - 5)
								{
									same = true;
									break;
								}
							}
							if (same == true)
							{
								goto label;
							}
						}
						capture[count++] = black[j];
						if ((white[i] - black[j] == -5) || (white[i] - black[j] == -10))
						{
							for (int q = 5; q <= 15; q += 5)
							{
								bool equal = false;
								for (int r = 0; r < 13; r++)
								{
									if (black[r] == black[j] + q)
									{
										equal = true;
										break;
									}
								}
								if (equal == true)
								{
									capture[count++] = black[j] + q;
								}
							}
						}
						if ((white[i] - black[j] == 55) || (white[i] - black[j] == 10))
						{
							for (int q = -5; q >= -15; q -= 5)
							{
								bool equal = false;
								for (int r = 0; r < 13; r++)
								{
									if (black[r] == black[j] + q)
									{
										equal = true;
										break;
									}
								}
								if (equal == true)
								{
									capture[count++] = black[j] + q;
								}
							}
						}
					}
				}
			label: printf("");
			}
		}
		if (l != 0)
		{
			fprintf(output, "\n");
		}
		bool empty = true;
		for (int s = 0; s < 13; s++)
		{
			for (int t = s + 1; t < 13; t++)
			{
				if (capture[s] == capture[t] && capture[s] != 0)
				{
					capture[t] = 0;
				}
			}
		}
		for (int k = 0; k < 13; k++)
		{
			if (capture[k] != 0)
			{
				if (k == 0)
				{
					fprintf(output, "%d", capture[k]);
				}
				else
				{
					fprintf(output, ", %d", capture[k]);
				}
				empty = false;
			}
		}
		if (empty == true)
		{
			fprintf(output, "NONE");
		}
	}
	fclose(input);
	fclose(output);
}