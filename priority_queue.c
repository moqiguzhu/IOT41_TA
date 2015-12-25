#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long long MAX_PRIORITY;

int flag = 0;

typedef struct node
{
   	long long key;
    char val[9];
} node;

int compare(node s1,node s2)
{
	if(s1.key != s2.key)
    {
        if(s1.key < s2.key) return 1;
        else return -1;
    }
    return -strcmp(s1.val, s2.val);
}

typedef struct priority_queue
{
    int size;
    node *eles;
} priority_queue;

void bubble_down(priority_queue *p, int index)
{
    if(index < 1) return;

    int left = index * 2;
    int right = index * 2 + 1;
    int min = index;
    if(left <= p->size && compare(p->eles[min], p->eles[left]) == -1)
        min = left;
    if(right <= p->size && compare(p->eles[min], p->eles[right]) == -1)
        min = right;
    if(min != index)
    {
        node tmp = p->eles[index];
        p->eles[index] = p->eles[min];
        p->eles[min] = tmp;
        bubble_down(p, min);
    }
}

void bubble_up(priority_queue *p, int index)
{
    int p_index = index / 2;
    node cur = p->eles[index];
    node pa = p->eles[p_index];
    while(p_index >= 1)
    {
        if(compare(cur, pa) == 1) 
        {
            node tmp = cur;
            cur = pa;
            pa = tmp;
            bubble_up(p, p_index);
        } 
    }
}

priority_queue *create_priority_queue(node *nodes, int len)
{
    priority_queue *p = malloc(sizeof(priority_queue));
    p->eles = malloc(sizeof(node) * (len+1));
    int i;
    for(i = 1; i <= len; i++)
    {
        p->eles[i] = nodes[i-1];
    }
    p->size = len;

    for(i = len / 2; i > 0; i--)
        bubble_down(p, i);
    return p;
}

node *parent(priority_queue *p, int i)
{
    if(i / 2 >= 1) return &(p->eles[i/2]);
    else return NULL;
}

node *left(priority_queue *p, int i)
{
    if(2*i <= p->size) return &(p->eles[2*i]);
    else return NULL;
}

node *right(priority_queue *p, int i)
{
    if(2*i+1 <= p->size) return &(p->eles[2*i+1]);
    else return NULL;
}

void set_key(priority_queue *p, int index, long long new_key)
{
    long long old_key = p->eles[index].key;
    p->eles[index].key = new_key;
    if(new_key > old_key) bubble_down(p, index);
    else bubble_up(p, index);
}

void *get_min(priority_queue *p, char *min_val)
{
    if(flag) 
    {
        flag++;
        if(flag > p->size) return NULL;
        else strcpy(min_val, p->eles[flag].val);

        return min_val;
    }

    //node res = p->eles[1];
    long long new_key = p->eles[1].key * 2;
    strcpy(min_val, p->eles[1].val);
    
    if(new_key >= MAX_PRIORITY) flag = 1;
    else 
    {
        set_key(p, 1, new_key);
    }

    return min_val;
}

int main()
{
    #ifndef _OJ_
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    MAX_PRIORITY = pow(2, 32);
    int num_task;
    int num_run;
    scanf("%d", &num_task);
    scanf("%d", &num_run);
    
    int i;
    char val[9];
    long long key;
    node *nodes = malloc(sizeof(node) * num_task);

    for(i=0; i<num_task; i++)
    {
	    scanf("%lld",&key);
	    scanf("%s", val);

//        node tmp;
//        printf("address of tmp : %p\n", &tmp);
//        tmp.key = key;
//        tmp.val = val;
//
//        nodes[i] = tmp;
        nodes[i].key = key;
        strcpy(nodes[i].val, val);
    }

    priority_queue *p = create_priority_queue(nodes, num_task);
    
    char *min_val = malloc(sizeof(char) * 9);
    void *res;
    for(i = 0; i < num_run; i++)
    {
        res = get_min(p, min_val);
        if(!res) break;
        else printf("%s\n", min_val);
//        else printf("%s flag = %d size = %d min_val = %p\n", min_val, flag, p->size, min_val);
    }  

    return 0;
}

