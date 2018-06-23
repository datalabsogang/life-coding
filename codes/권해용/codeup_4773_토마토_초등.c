#include <stdio.h>


int main(void)
{
  short tomatos[100][100][100]	= {0};
	tomatos[0][0][0] = 1;
	printf("%d\n",tomatos[0][0][0]);
	return 0;
}
