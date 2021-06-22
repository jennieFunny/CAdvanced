#include "../include/macro_profiler.h"

int fact(int n) {
	PROFILE;
	int result = 1;
	if (n <= 1) {
		return 1;
	}
	result = n * fact(n - 1);
	return result;
}

int fact2(int n) {
	PROFILE;
	int result = 1;
	if (n <= 1) {
		return 1;
	}
	result = n * fact2(n - 1);
	return result;
}

int cal(int n){
	PROFILE;
	fact(n);
	fact2(n);
	return n;
}


int main(int argc, char *argv[]) {
	PROFILE;
	fact(5);
	cal(10);
	cal(5);
	return 1;
}