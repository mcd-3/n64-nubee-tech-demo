#include <nusys.h>
#include "../../config.h"
#include "../../textdisplayer.h"
#include "../sprites/bee.h"
#include "../objects/base.h"
#include "definitions.h"

BASE gameObjects[MAXOBJECTS];

void clearBackground(u8 red, u8 green, u8 blue);

void drawHiBlocks();

void stage00_init(void) 
{
	int i = 0;
	char str[1] = {'a'};
	
	instance_create(gameObjects, TYPE_OBJ_BEE, 32, 32);
	drawHiBlocks();
	displayText(str, 100, 100);
}

void stage00_update(void) 
{
	instance_update_all(gameObjects);			
}

void stage00_draw(void) 
{
	glistp = glist;
	RCPInit(glistp);
	clearBackground(177, 209, 227);
	instance_draw_all(gameObjects);	
	gDPFullSync(glistp++);
	gSPEndDisplayList(glistp++);
	nuGfxTaskStart(glist, (s32)(glistp - glist) * sizeof(Gfx),
		NU_GFX_UCODE_F3DEX, NU_SC_SWAPBUFFER);
}

// Clears the background with a solid colour
void clearBackground(u8 red, u8 green, u8 blue) 
{
 	gDPSetCycleType(glistp++, G_CYC_FILL);
	gDPSetDepthImage(glistp++, nuGfxZBuffer);
	gDPSetColorImage(
		glistp++,
		G_IM_FMT_RGBA,
		G_IM_SIZ_16b,
		SCREEN_WIDTH,
		osVirtualToPhysical(nuGfxCfb_ptr));
		//nuGfxZBuffer);
	gDPSetFillColor(glistp++, (GPACK_RGBA5551(red, green, blue, 1) << 16
		| GPACK_RGBA5551(red, green, blue, 1)));
	gDPFillRectangle(glistp++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
	gDPPipeSync(glistp++);
}

// Draws a set of blocks on the screen that spell out "Hi"
void drawHiBlocks() 
{
	// H
	instance_create(gameObjects, TYPE_OBJ_BLOCK, 52, 202);
	instance_create(gameObjects, TYPE_OBJ_BLOCK, 52, 210);
	instance_create(gameObjects, TYPE_OBJ_BLOCK, 52, 218);
	instance_create(gameObjects, TYPE_OBJ_BLOCK, 52, 226);
	instance_create(gameObjects, TYPE_OBJ_BLOCK, 52, 232);
	instance_create(gameObjects, TYPE_OBJ_BLOCK, 60, 218);
	instance_create(gameObjects, TYPE_OBJ_BLOCK, 68, 202);
	instance_create(gameObjects, TYPE_OBJ_BLOCK, 68, 210);
	instance_create(gameObjects, TYPE_OBJ_BLOCK, 68, 218);
	instance_create(gameObjects, TYPE_OBJ_BLOCK, 68, 226);
	instance_create(gameObjects, TYPE_OBJ_BLOCK, 68, 232);
	
	// i
	instance_create(gameObjects, TYPE_OBJ_BLOCK, 84, 202);
	instance_create(gameObjects, TYPE_OBJ_BLOCK, 84, 218);
	instance_create(gameObjects, TYPE_OBJ_BLOCK, 84, 226);
	instance_create(gameObjects, TYPE_OBJ_BLOCK, 84, 232);
}