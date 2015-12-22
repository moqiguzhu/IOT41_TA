#include<stdio.h>
#include<stdlib.h>

long ans = 0;
int cy[1000005];

/**
    write a standard quick sort
*/
void my_qsort(int* a, int* b, int l, int r)
{
    if(r <= l) return;
    int temp;
    int mi = l + ((r - l)>>1);
    temp = a[l]; a[l] = a[mi]; a[mi] = temp;
    temp = b[l]; b[l] = b[mi]; b[mi] = temp;
    int pivot = a[l];

    int i = l+1, j = l+1;
    int k;
    for(k = l+1; k <= r; k++)
    {
        if(a[k] > pivot) j++;
        else
        {
            temp = a[i]; a[i] = a[j]; a[j] = temp;
            temp = b[i]; b[i] = b[j]; b[j] = temp;
            i++; j++;
        }
    }
    temp = a[l]; a[l] = a[i-1]; a[i-1] = temp;
    temp = b[l]; b[l] = b[i-1]; b[i-1] = temp;

    my_qsort(a, b, l, i-2);
    my_qsort(a, b, i, r);
}

void merg(int* a, int l, int mi, int r)
{
    int i = l, j = mi+1;
    int index = l;
    while(i <= mi && j <= r)
    {
        if(a[i] < a[j])
        {
            cy[index++] = a[i++];
            ans += r - j + 1;
        }
        else cy[index++] = a[j++];
    }
    if(i > mi)
    {
        while(j <= r) cy[index++] = a[j++];
    }
    if(j > r)
    {
        while(i <= mi) cy[index++] = a[i++];
    }
    for(i = l; i <= r; i++)
    {
        a[i] = cy[i];
    }
}

void merge_sort(int* a, int l, int r)
{
    if(l == r) return;
    int mi = l + ((r - l)>>1);
    merge_sort(a, l, mi);
    merge_sort(a, mi+1, r);
    merg(a, l, mi, r);
}

int main()
{
    int num;
    scanf("%d\n", &num);
    int point_x[num];
    int point_y[num];

    int i;
    for(i = 0; i < num; i++)
    {
        scanf("%d %d",&point_x[i], &point_y[i]);
    }

    my_qsort(point_x, point_y, 0, num-1);

    merge_sort(point_y, 0, num-1);
    /**
        ld format
    */
    printf("%ld\n", ans);

    return 0;
}
