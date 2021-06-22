#include "../include/draw.h"
/** 
* @file         main.c 
* @brief        This is a main fonction. 
* @details  This is the detail description. 
* @author       Wang Qi and Zhang Yue 
* @date     2019.01 
* @version  1.0 
* @par Copyright (c):  
*      UPEM 
* @par History:          
*   version: Wang Qi and Zhang Yue , 2019.01 , 1.0
*/  
/**
* @brief main fonction
* @details exit unique
*
* @param argc 命令参数个数 number of parameters
* @param argv 命令参数指针数组 array of parameters
* @return if the main run correctly  
*     @retval 0 success
*     @retval 1 failed
* @note a simple example
*/
int main(int argc, char *argv[]){
	if (argc<1){
		fprintf(stderr, "no log fichier\n");
		return 0;
	}
	ptrNode ptr = actualizeTree(argv[1]);
	show(ptr);
	
	return 0;
}

