/** 
* @file macro_profiler.h
* @brief macro                                                                  
*/
#ifndef MACRO_ROFILER_H_INCLUDED
#define MACRO_ROFILER_H_INCLUDED
/** Description of the macro _POSIX_C_SOURCE*/
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
* timespec                                                                 
*/
struct timespec tp;
/** Description of the macro times*/
double times;
/** Description of the macro file*/
FILE *file;

/** Description of the PROFILE */  
#define PROFILE file = fopen("./test/profile.log","a"); clock_gettime(CLOCK_REALTIME, &tp); times = tp.tv_sec + tp.tv_nsec / 1E9; fprintf(file, "%s -- time : %lfs\n", __FUNCTION__, times); fclose(file)
/** Description of the return */ 
#define return file = fopen("./test/profile.log","a"); clock_gettime(CLOCK_REALTIME, &tp); times = tp.tv_sec + tp.tv_nsec / 1E9; fprintf(file, "END -- time : %lfs\n", times); fclose(file); return



#endif 