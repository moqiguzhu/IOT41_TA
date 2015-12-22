#include <stdio.h>

// 1
// 2 3
// e
// for more information about read single char from stdin, please refer to 
// http://stackoverflow.com/questions/13542055/how-to-do-scanf-for-single-char-in-c
int main()
{
    int x, y, z;
    scanf("%d", &x);
    
    scanf("%d %d", &y, &z);
    printf("x = %d, y = %d, z = %d\n", x, y, z);

    char c;
    scanf(" %c", &c);   // this space is necessary
    printf("c = %c\n", c);
    return 0;
}
