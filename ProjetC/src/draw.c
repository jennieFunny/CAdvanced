#include "../include/draw.h"

int countDepth(ptrNode ptr){
	int sonDepth=1,broDepth=0;
	if (ptr == NULL)
		return 0;

	sonDepth+=countDepth(ptr->son);
	broDepth+=countDepth(ptr->brother);
	return (sonDepth>broDepth?sonDepth:broDepth);
}

int countBrother(ptrNode ptr){
	return ptr->brother==NULL? 0 : 1+countBrother(ptr->brother);
}

int countSon(ptrNode ptr){
	return ptr->son==NULL? 0 : 1+countSon(ptr->son);
}

void drawRect(int x,int y,int rectWidth,int rectHeight,int intervalColor,int realDepth,char *name){
	MLV_Color color = MLV_rgba(realDepth*intervalColor,255-(realDepth*intervalColor),0,255);
	MLV_draw_filled_rectangle (x, y, rectWidth, rectHeight, color);
	MLV_draw_text(x+GAP/4, y+GAP/4, name, MLV_COLOR_BLACK);
	MLV_draw_rectangle( x, y, rectWidth, rectHeight, MLV_COLOR_BLACK);
	MLV_actualise_window();
	MLV_wait_milliseconds(250);
}

void showTreeTime(ptrNode ptr) {
	if (ptr != NULL) {
		printf("name : %s, time : %fs\n", ptr ->name, ptr ->funcTime);
		showTreeTime(ptr -> son);
		showTreeTime(ptr -> brother);
	}
}

void drawProfiler(ptrNode ptr,int x,int y,int width,int height,int realDepth,int intervalColor,double fatherTime){
	int rectWidth = width-GAP;
	int rectHeight = height-GAP;
	int nbBro = countBrother(ptr);
	int nbSon = countSon(ptr);

	if (nbBro > 0){
		if (ptr->funcTime<0.01)
		{
			if (width >= height){
				rectWidth = rectWidth/(nbBro+1);
				rectWidth = rectWidth+GAP*nbSon>width-GAP? width-GAP: rectWidth+GAP*nbSon;
			}
			else{
				rectHeight = rectHeight/(nbBro+1);
				rectHeight = rectHeight+GAP*nbSon>height-GAP? height-GAP: rectHeight+GAP*nbSon;
			}
		}else{
			if (width >= height)
				rectWidth = rectWidth*(ptr->funcTime/fatherTime);
			else
				rectHeight = rectHeight*(ptr->funcTime/fatherTime);
		}
	}

	if (rectWidth < WIDTH/20 || rectHeight < HEIGHT/20){
		MLV_draw_text(x+GAP/4, y+GAP/4, "...", MLV_COLOR_BLACK);
		return ;
	}
	else
		drawRect(x, y, rectWidth, rectHeight, intervalColor, realDepth,ptr->name);
	
	if (ptr->son != NULL )
		drawProfiler(ptr->son, x+GAP, y+GAP, rectWidth-GAP, rectHeight-GAP, realDepth-1, intervalColor,ptr->funcTime);

	if (ptr->brother != NULL ){
		if (width >= height)
			drawProfiler(ptr->brother, x+rectWidth+GAP, y,width-rectWidth-GAP, height, realDepth, intervalColor,fatherTime);
		else
			drawProfiler(ptr->brother, x,y+rectHeight+GAP,width, height-rectHeight-GAP , realDepth, intervalColor,fatherTime);
	}
	return ;
}

void show(ptrNode ptr){
	int depth = countDepth(ptr);
	int x,y;
	printf("depth : %d \n", depth);
	showTreeTime(ptr);
 	MLV_create_full_screen_window("profiler","profiler",WIDTH,HEIGHT);
	drawProfiler( ptr,0,0,WIDTH,HEIGHT,depth,255/depth,0);
	MLV_wait_mouse(&x, &y);
	MLV_free_window();
}