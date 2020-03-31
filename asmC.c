#include<stdio.h>
// a mov to b
#define MOVTO(a,b) asm("movl %1,%%eax; \
	movl %%eax,%0;" \
	:"=r"(b) \
	:"r"(a) \
	:"%eax"\
	);
int a=10,b;
int
main()
{
	MOVTO(a,b);
	printf("%d\n",b);
	return 0;
}
