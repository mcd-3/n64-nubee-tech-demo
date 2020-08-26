#ifndef N64_CONFIG_H
#define N64_CONFIG_H

	#define NTSC	0
	#define PAL		1
	#define MPAL	2

	#define SCREEN_WIDTH  320
	#define SCREEN_HEIGHT 240
	#define GLIST_LENGTH 2048
	#define MAXOBJECTS 256
	
	Gfx glist[GLIST_LENGTH];
	Gfx* glistp;
	void RCPInit(Gfx *glistp);
	
	extern NUContData contData[1];
	extern u8 contPattern;
	
#endif