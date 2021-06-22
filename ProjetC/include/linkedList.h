/** 
* @file linkedList.h
* @brief tree's definition                                                                   
*/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/** Description of the macro BUFFERSIZE*/
#define BUFFERSIZE 256
/** Description of the macro count*/
int count;
/** 
 * Each node will correspond to a function call . 
 *  
 */

typedef struct node{
	char* name;/*!<fonction's name */
	double funcTime;/*!<fonction's time */
	struct node *son;/*!<node's son */
	struct node *brother;/*!<node's brother */
}Node, *ptrNode;/*!<node's pointeur */

/**
* @brief createNode fonction
* @details exit unique
*
* @param  str  fonction's name
* @param  t  fonction's initial time
* @return a node  
*     @retval ptrNode success
*     @retval NULL node empty
*
*/
ptrNode createNode(const char* str,double t);
/**
* @brief createList fonction
* @details recursive
*
* @param  fileLog  file(.log) which we use
* @return a node  
*     @retval ptrNode success
*     @retval NULL if the fonction's name is END
*
*/
ptrNode createList(FILE * fileLog);
/**
* @brief createEndList fonction
* @details create a list to stock the time real of fonction's execution. 
*
* @param  fileLog  file(.log) which we use
* @param  endList  list to be used
* @return void 
*     @retval void
*     
*/
void createEndList(FILE* fileLog,double **endList);
/**
* @brief calculTreeTime fonction
* @details exit unique
* @param   endList  list to be used
* @param   ptr node which we want to know its time real
* @return 
*		@return void 
*
*/
void calculTreeTime(double *endList,ptrNode ptr);
/**
* @brief actualizeTree fonction
* @details run the opreations total
*
* @param  path  file's path
* @return a node  
*     @retval ptrNode success
*     @retval NULL failed
*
*/
ptrNode actualizeTree(char *path);

#endif