#include <stdio.h>
#include <stdlib.h>

#define MAX 2000000

typedef struct stack 
{
    int size;
    int eles[MAX];
} stack;

stack *stack_create()
{
    stack *p = (stack*)malloc(sizeof(stack));
    p->size = 0;
    return p;
}

void stack_push(stack *p, int e)
{
    p->eles[p->size++] = e;
}

int stack_pop(stack *p)
{
    int e = p->eles[--(p->size)];
    return e;
}

int stack_empty(stack *p)
{
    return p->size == 0;
}

void stack_print(stack *p)
{
    int size = p->size;
    while(size-- > 0)
    {
        printf("%d ", p->eles[size]);
    }
    printf("\n");
}

typedef struct max_stack
{
    int size;
    int eles[MAX];
    int max_precurssors[MAX];
} max_stack;

max_stack *max_stack_create()
{
    max_stack *p = (max_stack*)malloc(sizeof(max_stack));
    p->size = 0;
    return p;
}

void max_stack_push(max_stack *p, int e)
{
    p->eles[p->size] = e;
    if(p->size == 0) p->max_precurssors[p->size] = e;
    else
    {
        int top = p->max_precurssors[p->size-1];
        p->max_precurssors[p->size] = e > top ? e : top;
    }
    p->size++;
}

int max_stack_pop(max_stack *p)
{
    return p->eles[--p->size];
}

int max_stack_max(max_stack *p)
{
    return p->max_precurssors[p->size-1];
}

int max_stack_empty(max_stack *p)
{
    return p->size == 0;
}

void max_stack_print(max_stack *p)
{
    int size = p->size;
    int i;
    printf("elements in the max_stack:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d ", p->eles[i]);
    }
    printf("\n");

    printf("max_precurssors in the max_stack:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d ", p->max_precurssors[i]);
    }
    printf("\n");
}

typedef struct max_queue
{
    int size;           //only can you create valid max_stack by max_stack_create function
    max_stack *eles;
    max_stack *tmp;
} max_queue;

max_queue *max_queue_create()
{
    max_queue *p = (max_queue*)malloc(sizeof(max_queue));
    p->eles = (max_stack*)malloc(sizeof(max_stack));
    p->tmp = (max_stack*)malloc(sizeof(max_stack));
    p->size = 0;
    return p;
}

void max_queue_push(max_queue *p, int e)
{
    max_stack_push((p->tmp), e);
    p->size++;
}

int max_queue_pop(max_queue *p)
{
    int e;
    if(!max_stack_empty((p->eles))) 
    {
        e = max_stack_pop((p->eles));
    }
    else
    {
        int i;
        for(i = p->tmp->size-1; i >= 0; i--)
        {
            max_stack_push(p->eles, p->tmp->eles[i]);
        }
        p->tmp->size = 0;
        e = max_stack_pop((p->eles));
    }
    p->size--;
    return e;
}

int max_queue_max(max_queue *p)
{
    if(max_stack_empty((p->eles)))
    {
        return max_stack_max((p->tmp));
    }
    else if(max_stack_empty((p->tmp)))
    {
        return max_stack_max((p->eles));
    }
    else
    {
        int t1 = max_stack_max((p->tmp));
        int t2 = max_stack_max((p->eles));
        return t1 > t2 ? t1 : t2;
    }
}

int max_queue_empty(max_queue *p)
{
    return p->size == 0;
}

int test()
{
    // test stack data structure
    stack *s = stack_create();
    stack_push(s, 1);
    stack_push(s, 2);
    stack_print(s);
    stack_pop(s);
    stack_print(s);

    // test max_stack data structure
    max_stack *max_s = max_stack_create();
    max_stack_push(max_s, 1);
    max_stack_push(max_s, 3);
    max_stack_push(max_s, 2);
    max_stack_print(max_s);
    printf("current max elements in the max_stack is: %d\n", max_stack_max(max_s));

    max_stack_pop(max_s);
    max_stack_print(max_s);
    printf("current max elements in the max_stack is: %d\n", max_stack_max(max_s));

    // test max_queue data structure
    printf("test max_queue\n");

    max_queue *max_q = max_queue_create();
    max_queue_push(max_q, 1);
    max_queue_push(max_q, 3);
    max_queue_push(max_q, 2);

    int max, ele;
    max = max_queue_max(max_q);
    printf("current max element in the max_queue is: %d\n", max);

    ele = max_queue_pop(max_q);
    printf("element poped: %d\n", ele);
    max = max_queue_max(max_q);
    printf("current max element in the max_queue is: %d\n", max);

    ele = max_queue_pop(max_q);
    printf("element poped: %d\n", ele);
    max = max_queue_max(max_q);
    printf("current max element in the max_queue is: %d\n", max);
    
    return 0;
}

int main()
{
    max_queue *max_q = max_queue_create();
    int num_cases;
    scanf("%d", &num_cases);

    int i;
    char op;
    int ele, max, pop_ele;
    for(i = 0; i < num_cases; i++)
    {
        scanf(" %c", &op);
        if(op == 'E')
        {
            scanf("%d", &ele);
            max_queue_push(max_q, ele);
        }
        else if(op == 'M')
        {
            max = max_queue_max(max_q);
            printf("%d\n", max);
        }
        else
        {
            pop_ele = max_queue_pop(max_q);
            printf("%d\n", pop_ele);
        }
        
    }

    return 0;
}
