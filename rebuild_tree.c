#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 4000000

// global variables
int pre_order[MAX];
int post_order[MAX];
int in_order[MAX];
int post_indexes[MAX + 1];
int pre_indexes[MAX + 1];

void build_indexes()
{
	int i = 0;
    int *post_tmp = post_order;
	while(*post_tmp)
	{
		post_indexes[*post_tmp] = i++;
		post_tmp++;
	}
	
	i = 0;
    int *pre_tmp = pre_order;
	while(*pre_tmp)
	{
		pre_indexes[*pre_tmp] = i++;
		pre_tmp++;
	}
}

// flag = false means left
//      = true means right
void rebuild_tree(int pre_start, int pre_end, int post_start, int post_end, int flag)
{	
	if(pre_start == pre_end)
	{
        assert(post_start == post_end);

		int root = pre_order[pre_start];
		int new_root_index;
		
		if(!flag)
			new_root_index = post_indexes[root];
		else
			new_root_index = post_indexes[root] + 1;

		in_order[new_root_index] = root;
	}
	else if(pre_start < pre_end)
	{
        assert(post_start < post_end);

		int root, pre_left_start, pre_left_end, pre_right_start, pre_right_end;
        int post_left_start, post_left_end, post_right_start, post_right_end;

		root = pre_order[pre_start];

		int R = post_order[post_end - 1];
        int P = pre_order[pre_start];
        int L = pre_order[pre_start + 1];

        pre_left_start = pre_start + 1;
		pre_right_start = pre_indexes[R];
		pre_left_end = pre_right_start - 1;
		pre_right_end = pre_end;

        post_left_start = post_start;
        post_left_end = post_indexes[L];
        post_right_start = post_left_end + 1;
        post_right_end = post_end - 1;

		int new_root_index = post_right_start;
		in_order[new_root_index] = root;

		// recursive call
		rebuild_tree(pre_left_start, pre_left_end, post_left_start, post_left_end, 0);
		rebuild_tree(pre_right_start, pre_right_end, post_right_start, post_right_end, 1);
	}
    else
    {
        return;
    }
}


int main()
{
    #ifndef _OJ_
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	int num_eles;
	scanf("%d", &num_eles);

	int i;
	for(i = 0; i < num_eles; i++)
		scanf("%d ", &pre_order[i]);

	for(i = 0; i < num_eles; i++)
		scanf("%d", &post_order[i]);

	build_indexes();
	
    // begin with left or right will be okay
	rebuild_tree(0, num_eles-1, 0, num_eles-1, 0);

    // print result
	for(i = 0; i < num_eles; i++)
		printf("%d ", in_order[i]);
	printf("\n");
	
	return 0;
}
