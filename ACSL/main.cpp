#include "Practice/ACSL Scrabble/ACSL Scrabble.h"
#include "Practice/ACSL Fanorona/ACSL Fanorona.h"
#include "Practice/ACSL Numble/ACSL Numble.h"
#include "Practice/ACSL Print Formatting/ACSL Print Formatting.h"
#include "Practice/ACSL KenKen/ACSL KenKen.h"
#include "Contest/2020-2021/ACSL Numeral Triangles/ACSL Numeral Triangles.h"
#include "Contest/2020-2021/ACSL Lex Strings/ACSL Lex Strings.h"
#include "Contest/2020-2021/ACSL Multiple Arrays/ACSL Multiple Arrays.h"
#include "Contest/2020-2021/ACSL Graphs/ACSL Graphs.h"
#include "Contest/2020-2021/ACSL Finals/ACSL Finals.h"
#include "Contest/2021-2022/ACSL Fibonacci Clock/ACSL Fibonacci Clock.h"
#include "Practice/ACSL Quine-McClusky/ACSL Quine-McClusky.h"
#include "Contest/2021-2022/ACSL Fibonacci Cypher/ACSL Fibonacci Cypher.h"
#include "Contest/2021-2022/ACSL Fibonacci and Pascal/ACSL Fibonacci and Pascal.h"
int main()
{
	char funcNames[][100] =
	{
		"Practice - ACSL Scrabble",
		"Practice - ACSL Fanorona",
		"Practice - ACSL Numble",
		"Practice - ACSL Print Formatting",
		"Practice - ACSL KenKen",
		"Contest - 2020 to 2021 - ACSL Numeral Triangles",
		"Contest - 2020 to 2021 - ACSL Lex Strings",
		"Contest - 2020 to 2021 - ACSL Multiple Arrays",
		"Contest - 2020 to 2021 - ACSL Graphs",
		"Contest - 2020 to 2021 - ACSL Finals Problem 1",
		"Contest - 2020 to 2021 - ACSL Finals Problem 2",
		"Contest - 2021 to 2022 - ACSL Fibonacci Clock",
		"Practice - ACSL Quine-McClusky",
		"Contest - 2021 to 2022 - ACSL Fibonacci Cypher",
		"Contest - 2021 to 2022 - ACSL Fibonacci and Pascal",
	};
	void (*funcs[])() =
	{
		acslscrabblerun,
		acslfanoronarun,
		acslnumblerun,
		acslprintrun,
		acslkenkenrun,
		acslnumeraltrianglesrun,
		acsllexstringsrun,
		acslmultiplearraysrun,
		acslgraphsrun,
		acslfinalsonerun,
		acslfinalstworun,
		acslfibclock,
		acslquinemcclusky,
		acslfibcypher,
		acslfibandpascal
	};
	int choice;
	int maxFuncs = sizeof(funcs) / sizeof(funcs)[0];
	for (int i = 0; i < maxFuncs; i++)
	{
		printf("%d: %s:\n", i + 1, funcNames[i]);
	}
	while (true)
	{
		printf("Enter selection: ");
		scanf("%d", &choice);
		getchar();
		if (choice > maxFuncs || choice <= 0)
		{
			break;
		}
		printf("%s : Output below\n", funcNames[choice - 1]);
		funcs[choice - 1]();
		printf("\n");
	}
	return 0;
}