#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
void usacoyearcowrun()
{
    int n, k; scanf("%d %d", &n, &k); int* year = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; scanf("%d", &year[i]), i++); std::sort(year, year + n);
    int max = (year[n - 1] + 12) % 12, counter = 0, jumps = 0, sum = 0;
    if (max == 0) max = year[n - 1]; else max = year[n - 1] + 12 - max;
    int* ox = (int*)malloc(max/12 * sizeof(int)), *gap = (int*)malloc((n - 1) * sizeof(int));
    for (int i = 0; i < n; ox[year[i] / 12] = 1, i++);
    for (int i = 0; i < max/12; jumps++, i++) if (ox[i] == 1 && (gap[counter++] = jumps) == jumps) jumps = -1;
    std::sort(gap, gap + counter); for (int i = 0; i < k - 1; sum += gap[counter - i - 1], i++);
    printf("%d\n", max - sum * 12);
}