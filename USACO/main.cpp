#include "Practice/USACO Censoring/USACO Censoring.h"
#include "Practice/USACO COW/USACO COW.h"
#include "Practice/USACO Cow Hopscotch/USACO Cow Hopscotch.h"
#include "Practice/USACO Superbull/USACO Superbull.h"
#include "Practice/USACO Fencing the Herd/USACO Fencing the Herd.h"
#include "Contest/December 2020 Bronze/USACO ABCs/USACO ABCs.h"
#include "Contest/December 2020 Bronze/USACO Daisy Chains/USACO Daisy Chains.h"
#include "Contest/December 2020 Bronze/USACO Stuck Rut/USACO Stuck Rut.h"
#include "Contest/December 2020 Silver/USACO Cowntagion/USACO Cowntagion.h"
#include "Contest/December 2020 Silver/USACO Rectangular Pasture/USACO Rectangular Pasture.h"
#include "Contest/December 2020 Silver/USACO Stuck in a Rut/USACO Stuck in a Rut.h"
#include "Contest/January 2021 Silver/USACO Dance Mooves/USACO Dance Mooves.h"
#include "Contest/January 2021 Silver/USACO Time to Paint/USACO Time to Paint.h"
#include "Contest/January 2021 Silver/USACO Spaced Out/USACO Spaced Out.h"
#include "Contest/February 2021 Silver/USACO Comfortable Cows/USACO Comfortable Cows.h"
#include "Contest/February 2021 Silver/USACO Green Enough/USACO Green Enough.h"
#include "Contest/February 2021 Silver/USACO Year Cow/USACO Year Cow.h"
#include "Contest/US Open 2021 Silver/USACO Acowdemia/USACO Acowdemia.h"
#include "Contest/US Open 2021 Silver/USACO Know Your ABCs/USACO Know Your ABCs.h"
#include "Contest/US Open 2021 Silver/USACO Maze Tac Toe/USACO Maze Tac Toe.h"
#include "Training/Chapter 1/1.2/1.2.h"
#include "Contest/December 2021 Silver/December 2021 Silver.h"
#include "Training/Chapter 1/1.3/1.3.h"
#include "Training/Chapter 1/1.4/1.4.h"
#include "Training/Chapter 1/1.5/1.5.h"
#include "Training/Chapter 1/1.6/1.6.h"
#include "Training/Chapter 2/2.1/2.1.h"
#include "Training/Chapter 2/2.2/2.2.h"
#include "Training/Chapter 2/2.3/2.3.h"
#include "Training/Chapter 2/2.4/2.4.h"
#include "Contest/January 2022 Silver/January 2022 Silver.h"
#include "Contest/February 2022 Silver/February 2022 Silver.h"
#include "Contest/US Open 2022 Silver/US Open 2022 Silver.h"
#include "Training/Chapter 3/3.1/3.1.h"
int main()
{
	char funcNames[][100] =
	{
		"Practice - USACO Censoring",
		"Practice - USACO COW",
		"Practice - USACO Cow Hopscotch",
		"Practice - USACO Superbull",
		"Practice - USACO Fencing the Herd",
		"Contest - December 2020 Bronze - USACO ABCs",
		"Contest - December 2020 Bronze - USACO Daisy Chains",
		"Contest - December 2020 Bronze - USACO Stuck Rut",
		"Contest - December 2020 Silver - USACO Cowntagion",
		"Contest - December 2020 Silver - USACO Rectangular Pasture",
		"Contest - December 2020 Silver - USACO Stuck in a Rut",
		"Contest - January 2021 Silver - USACO Dance Mooves",
		"Contest - January 2021 Silver - USACO Time to Paint",
		"Contest - January 2021 Silver - USACO Spaced Out",
		"Contest - February 2021 Silver - USACO Year Cow",
		"Contest - February 2021 Silver - USACO Green Enough",
		"Contest - February 2021 Silver - USACO Comfortable Cows",
		"Contest - US Open 2021 Silver - USACO Acowdemia",
		"Contest - US Open 2021 Silver - USACO Know Your ABCs",
		"Contest - US Open 2021 Silver - USACO Maze Tac Toe",
		"Training - Chapter 1 - 1.2",
		"Contest - December 2021 Silver - USACO Closest Cow",
		"Contest - December 2021 Silver - USACO Connecting Barns",
		"Contest - December 2021 Silver - USACO Convoluted Intervals",
		"Training - Chapter 1 - 1.3",
		"Training - CHapter 1 - 1.4",
		"Training - Chapter 1 - 1.5",
		"Training - Chapter 1 - 1.6",
		"Training - Chapter 2 - 2.1",
		"Training - Chapter 2 - 2.2",
		"Training - Chapter 2 - 2.3",
		"Training - Chapter 2 - 2.4",
		"Contest - January 2022 Silver - USACO Searching for Soulmates",
		"Contest - January 2022 Silver - USACO Cow Frisbee",
		"Contest - January 2022 Silver - USACO Cereal 2",
		"Contest - February 2022 Silver - USACO Redistributing Gifts",
		"Contest - February 2022 Silver - USACO Robot Instructions",
		"Contest - February 2022 Silver - USACO Email Filing",
		"Contest - US Open 2022 Silver - USACO Visits",
		"Contest - US Open 2022 Silver - USACO Subset Equality",
		"Contest - US Open 2022 Silver - USACO Cow Operations",
		"Training - Chapter 3 - 3.1"
	};
	void (*funcs[])() =
	{
		usacocensoringrun,
		usacocowrun,
		usacohopscotchrun,
		usacosuperbullrun,
		usacofencingrun,
		usacoabcrun,
		usacodaisychainsrun,
		usacostuckrutrun,
		usacocowntagionrun,
		usacorectpasturerun,
		usacostuckinarutrun,
		usacodancemoovesrun,
		usacotimetopaintrun,
		usacospacedoutrun,
		usacoyearcowrun,
		usacogreenenoughrun,
		usacocomfortablecowsrun,
		usacoacowdemiarun,
		usacoknowyourabcsrun,
		usacomazetactoerun,
		onepointtwo,
		closestcow,
		connectingbarns,
		convolutedintervals,
		onepointthree,
		onepointfour,
		onepointfive,
		onepointsix,
		twopointone,
		twopointtwo,
		twopointthree,
		twopointfour,
		searchingforsoulmates,
		cowfrisbee,
		cereal2,
		redistributinggifts,
		robotinstructions,
		emailfiling,
		usacovisits,
		usacosubsetequality,
		usacocowoperations,
		threepointone
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