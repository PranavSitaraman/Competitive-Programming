#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>
typedef struct
{
	char d;
	long long x;
	long long y;
	bool stuck;
	long long ate;
} cow;
#define size 10000
void usacostuckrutrun(void);