#include <stdio.h>

#define MAXN 1600000

typedef int bool;
#define true 1
#define false 0

int stk[MAXN];         // true means push false means pop
int sTop = 0;
bool ops[MAXN*2];

void push(int i)
{
    stk[sTop++] = i;
}

void pop()
{
    sTop--;
}

int top()
{
    return sTop == 0 ? 0 : stk[sTop-1];
}

int main()
{
    int num_compartments, station_size;
    scanf("%d %d", &num_compartments, &station_size);

    int orders[num_compartments];
    int i;
    for(i = 0; i < num_compartments; i++)
    {
        scanf("%d", &orders[i]);
    }

    int cur = 0;
    int index = 0;

    for(i = 0; i < num_compartments; i++)
    {
        if(orders[i] < top())
        {
            printf("%s\n", "No");
            return 0;
        }
        if(orders[i] > cur)
        {
            while(cur < orders[i])
            {
                push(++cur);
                ops[index++] = true;
            }

        }
        if(sTop > station_size)
        {
            printf("%s\n", "No");
            return 0;
        }
        if(orders[i] == top())
        {
            pop();
            ops[index++] = false;
        }
    }

    for(i = 0; i < index; i++)
    {
        if(ops[i])
        {
            printf("%s\n", "push");
        }
        else
        {
            printf("%s\n", "pop");
        }
    }
    return 0;
}
