#include <stdio.h>

char ito01(int i)
{
	if(i == 0)
		return '0';
	else if(i == 1)
		return '1';
	else // wrong input!
		return 'x';
}

int dec2bin(unsigned long n, char* answer, int nPow)
{
	if (n < 2)
	{
		answer[nPow] = ito01(n%2);
    return nPow;
  }
	else
	{
    answer[nPow] = ito01(n%2);
		return dec2bin(n/2, answer, nPow+1);
	}
}

void InverseString(char* src, char* dst, int len)
{
	if(len==0)
		return;

	dst[len-1] = src[0];
	//printf("index:%d, value:%c, src[0]:%c\n",len-1, dst[len-1], src[0]);
	InverseString(src+1, dst, len-1);
}

int main(void)
{
	
  unsigned long n;
	unsigned long nPow = 0;
  char answer[100] = {0};
  char printedAnswer[100] = {0};

	scanf("%ld",&n);
	nPow = dec2bin(n, answer, nPow);
	InverseString(answer, printedAnswer,nPow+1);
	printf("%s\n",printedAnswer);

	return 0;
}

