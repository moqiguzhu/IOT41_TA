#include <stdlib.h>
#include <stdio.h>


int binsearch(int *p, int lo, int hi, int e)
{
    while(lo < hi)
    {
        int mi = ((hi - lo)>>1) + lo;
        (e < p[mi]) ? hi = mi : (lo = mi+1);
    }
    return --lo;
}

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int m, n;
    scanf("%d %d\n", &m, &n);
    int arr[m];

    int i;
    for(i = 0; i < m; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, m, sizeof(int), cmp);

    int low, high;

    for(i = 0; i < n; i++)
    {
        scanf("%d %d\n", &low, &high);
        int low_index = binsearch(arr, 0, m, low);
        int high_index = binsearch(arr, 0, m, high);
        if(arr[low_index] == low && low_index >= 0) low_index--;

        int cnt = high_index - low_index;
        printf("%d\n", cnt);
    }

    return 0;
}
