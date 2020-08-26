#include <nusys.h>
#include "assets/stages/definitions.h"

#define checkController(cont) (contPattern & (1<<(cont)))

NUContData contData[1]; // only 1 controller
u8 contPattern;
char mem_heap[1024*512];

static void vsyncCallBack(int pendingTaskCount);

// Entry point for NUSYS
int mainproc(void *dummy) 
{
	nuGfxInit();
	if (InitHeap(mem_heap, sizeof(mem_heap)) == -1) 
	{
		return -1;
	}
	
	contPattern = nuContInit();
	stage00_init();
	nuGfxFuncSet((NUGfxFunc)vsyncCallBack);
	nuGfxDisplayOn();
	while(1);
}

static void vsyncCallBack(int pendingTaskCount) 
{
	stage00_update();
	if (pendingTaskCount < 1) 
	{
		stage00_draw();
	}
}