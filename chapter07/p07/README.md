Without changing any variable names, modify bar5.c on page 719 so that foo5.c
prints the correct values of x and y

/* foo5.c */
#include <stdio.h>
void f(void);

int y = 15212l
int x = 15213;

int main()
{
    f();
    printf("x=0x%x y=0x%x\n", x, y);

    return 0;
}

/* bar5.c */
double x;

void f()
{
    x = -0.0;
}
