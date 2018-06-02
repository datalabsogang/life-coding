#include <stdio.h>


void supersum(int k, int n, int (*table)[16])
{
	//printf("%d %d %d\n", k, n, table[k][n]);

	if (k == 0) // case 1
	{
		//printf("case 1\n");

		table[k][n] = n; 
	} 
	
  else if (n == 1) // case 2
	{
		//printf("case 2\n");

	  if (table[k-1][n] == 0)
	  	supersum(k-1, n, table); 
	
		table[k][n] = table[k-1][n]; 
	}
	else // case 3
	{
//		//printf("case 3\n");

		if (table[k][n-1] == 0)
			supersum(k, n-1, table);
		if (table[k-1][n] == 0)
	  	supersum(k-1, n, table); 

		table[k][n] = table[k][n-1] + table[k-1][n]; 
	}
}


int main(void)
{
	int table[16][16]= {0};

	int k, n;
	while( scanf("%d %d", &k, &n) != EOF )
	{
		supersum(k,n,table);
    printf("%d\n", table[k][n]);
	}

	return 0;
}
