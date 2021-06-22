/** 
* @file draw.h
* @brief draw profilage                                                                  
*/
#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include <MLV/MLV_all.h>
#include "linkedList.h"
/** Description of the macro MLV_get_desktop_width*/
#define WIDTH MLV_get_desktop_width()
/** Description of the macro MLV_get_desktop_height*/
#define HEIGHT MLV_get_desktop_height()
/** Description of the macro GAP */
#define GAP WIDTH/50
/**
* @brief countDepth fonction
* @details exit unique
*
* @param  ptr  fonction's name
* @return int   
*     @retval num the level of tree's depth 
*    
*
*/
int countDepth(ptrNode ptr);
/**
* @brief countBrother fonction
* @details exit unique
*
* @param  ptr  the first node 
* @return int   
*     @retval num the number of the node's brother
*
*/
int countBrother(ptrNode ptr);
/**
* @brief countSon fonction
* @details exit unique
*
* @param  ptr  the first node 
* @return int   
*     @retval num the number of the node's son
*
*/
int countSon(ptrNode ptr);
/**
* @brief drawRect fonction
* @details exit unique
*
* @param  x  	The X coordinate of the north-west vertex of the rectangle.
* @param  y 	The Y coordinate of the north-west vertex of the rectangle.
* @param  rectWidth 	The width of the rectangle.
* @param  rectHeight 	The height of the rectangle.
* @param  intervalColor 	The unit of color in order to change from  red to green.
* @param  realDepth 	tree's depth 
* @param  name 			fonction's name

* @return void  
*     @retval void
*     
*/
void drawRect(int x,int y,int rectWidth,int rectHeight,int intervalColor,int realDepth,char *name);

/**
* @brief showTreeTime fonction
* @details  draw tree's information
*
* @param  ptr  tree
* @return void  
*     @retval void
*
*/
void showTreeTime(ptrNode ptr);
/**
* @brief Once the tree is built, we propose one or more graphic visualizations associated with the profiling log.
* @details exit unique
*
* @param  ptr  tree 
* @param  x  	The X coordinate of the north-west vertex of the rectangle.
* @param  y 	The Y coordinate of the north-west vertex of the rectangle.
* @param  width 	The width of the rectangle.
* @param  height 	The height of the rectangle.
* @param  intervalColor 	The unit of color in order to change from  red to green.
* @param  realDepth 	tree's depth 
* @param  fatherTime 		fonction's father's time
* @return void
*     @retval  void
*
*/
void drawProfiler(ptrNode ptr,int x,int y,int width,int height,int realDepth,int intervalColor,double fatherTime);
/**
* @brief show fonction
* @details show the profiler's graghic result graghic
*
* @param  ptr  tree
* @return void 
*     @retval void
*
*/
void show(ptrNode ptr);

#endif