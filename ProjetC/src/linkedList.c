#include "../include/linkedList.h"

ptrNode createNode(const char* str,double t){
	ptrNode node=(ptrNode)malloc(sizeof(Node));
	node->name=(char*)malloc(strlen(str)+1);
	if (node == NULL)
	{
		fprintf(stderr, "create node error!\n");
		return NULL;
	}
	strcpy(node->name,str);
	node->funcTime=t;
	node->son=NULL;
	node->brother=NULL;
	return node;
}

ptrNode createList(FILE * fileLog){
	ptrNode ptr = NULL;
	char t[BUFFERSIZE];
	char fname[BUFFERSIZE];
	char* tmp;
	double ftime;
	if( fscanf(fileLog,"%s -- time : %s",fname,t) != EOF ){
      	ftime = strtod(t,&tmp);
      	if (strcmp(fname,"END") == 0)
      	{
      		count++;
      		return ptr;
      	}
      	ptr = createNode(fname,ftime);
      	ptr->son = createList(fileLog);
      	ptr->brother = createList(fileLog);
	}
	return ptr;
}

void createEndList(FILE* fileLog,double **endList){
	char t[BUFFERSIZE];
	char fname[BUFFERSIZE];
	char* tmp;
	double ftime;
	int i=0;

	*endList=(double *)malloc(sizeof(double)*count);
	while(fscanf(fileLog,"%s -- time : %s",fname,t) != EOF ){
		if (strcmp(fname,"END") == 0)
      	{
      		ftime = strtod(t,&tmp);
      		(*endList)[i++]=ftime;
      	}
	}
	return ;
}

void calculTreeTime(double *endList,ptrNode ptr){
	if (ptr== NULL)
		return;

	calculTreeTime(endList,ptr->son);
	ptr->funcTime= endList[count++] - ptr->funcTime;
	calculTreeTime(endList,ptr->brother);
	return;
}

ptrNode actualizeTree(char *path){
	count=0; 
	double *endList=NULL;
	FILE *fileLog =fopen(path,"r");
	if (fileLog==NULL)
		{
			fprintf(stderr, "no such file\n" );
		}	
	ptrNode ptr =  createList(fileLog);
	if (fseek(fileLog, 0L, SEEK_SET)==-1)
		fprintf(stderr, "error\n");
	createEndList(fileLog,&endList);	
	fclose(fileLog);
	count=0;
	calculTreeTime(endList, ptr);
	free(endList);
	return ptr;
 }