#include "../include/macro_profiler.h"

int bino(int n,int p){
	PROFILE;
	int res;
	if (p==0 || n==p)
		res= 1;
	else
		res= bino(n-1,p)+bino(n-1,p-1);
	return res;
}

int main(int argc, char const *argv[])
{
	PROFILE;
	bino(6,3);
	return 0;
}