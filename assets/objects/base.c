#include <nusys.h>
#include "../../config.h"
#include "base.h"

#include "../sprites/bee.h"
#include "../sprites/ice.h"

//Creates an instance of a game object and puts it in memory
int instance_create(BASE *base, char type, int x, int y) 
{
	int i = 0;
	
	// Find an empty index in the engine and fill with a value
	for (i = 0; i < MAXOBJECTS; i++) 
	{
		if (base[i].type == TYPE_OBJ_NULL) 
		{
			break;
		}
	}
	
	base[i].type = type;
	base[i].x = x;
	base[i].y = y;
	
	return i;
}

// Updates the state of all game objects
void instance_update_all(BASE *base) 
{
	int i = 0;
	float speedX = 0;
	float speedY = 0;
	
	for (i = 0; i < MAXOBJECTS; i++) 
	{
		if (base[i].type == TYPE_OBJ_BEE) 
		{
			nuContDataGetExAll(contData);
	
			// set the speed depending on how much the stick was pushed
			if (contData[0].stick_x > 16) 
			{
				speedX = MIN(64, contData[0].stick_x);
			} 
			else if (contData[0].stick_x < -16) 
			{
				speedX = MAX(-64, contData[0].stick_x);
			}
			if (contData[0].stick_y > 16) 
			{
				speedY = MIN(64, contData[0].stick_y);
			} 
			else if (contData[0].stick_y < -16) 
			{
				speedY = MAX(-64, contData[0].stick_y);
			}
	
			// move bee and check for bounds
			base[i].x += speedX / 8;
			if (base[i].x - 8 < 0) 
			{
				base[i].x = 8;
			}
			if (base[i].x + 24 > SCREEN_WIDTH) 
			{
				base[i].x = SCREEN_WIDTH - 24;
			}
	
			base[i].y -= speedY / 8;
			if (base[i].y - 8 < 0) 
			{
				base[i].y = 0;
			}
			if (base[i].y + 24 > SCREEN_HEIGHT) 
			{
				base[i].y = SCREEN_HEIGHT - 24;
			}
		}
	}
}

// Draws all game objects in memory
void instance_draw_all(BASE *base) 
{
	int i = 0;
	for (i = 0; i < MAXOBJECTS; i++) 
	{
		if (base[i].type == TYPE_OBJ_BEE) 
		{
			gDPSetCycleType(glistp++, G_CYC_1CYCLE);
			gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
			gDPSetRenderMode(glistp++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE);
			gDPSetDepthSource(glistp++, G_ZS_PRIM);
			gDPSetPrimDepth(glistp++, 0, 0);
			gDPSetTexturePersp(glistp++, G_TP_NONE);
			gDPLoadTextureBlock( // Load the texture
				glistp++,
				bee,
				G_IM_FMT_RGBA,
				G_IM_SIZ_16b,
				32, 32,
				0,
				G_TX_WRAP, G_TX_WRAP,
				G_TX_NOMASK, G_TX_NOMASK,
				G_TX_NOLOD, G_TX_NOLOD
			);
			// Draw the bee
			gSPTextureRectangle( // Display texture
				glistp++,
				(((int)(base[i].x - 8)) << 2),
				(((int)(base[i].y - 8)) << 2),
				((int)(base[i].x + 24)) << 2,
				((int)(base[i].y + 24)) << 2,
				G_TX_RENDERTILE,
				0 << 5,
				0 << 5,
				1 << 10,
				1 << 10
			);
			gDPPipeSync(glistp++);
			gDPSetTextureLUT(glistp++, G_TT_NONE);
		} 
		else if (base[i].type == TYPE_OBJ_BLOCK) 
		{
			gDPSetCycleType(glistp++, G_CYC_1CYCLE);
			gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
			gDPSetRenderMode(glistp++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE);
			gDPSetDepthSource(glistp++, G_ZS_PRIM);
			gDPSetPrimDepth(glistp++, 0, 0);
			gDPSetTexturePersp(glistp++, G_TP_NONE);
			gDPLoadTextureBlock( // Load the texture
				glistp++,
				ice,
				G_IM_FMT_RGBA,
				G_IM_SIZ_16b,
				8, 8,
				0,
				G_TX_WRAP, G_TX_WRAP,
				G_TX_NOMASK, G_TX_NOMASK,
				G_TX_NOLOD, G_TX_NOLOD
			);
			// Draw the block
			gSPTextureRectangle( // Display texture
				glistp++,
				(((int)(base[i].x - 4)) << 2),
				(((int)(base[i].y - 4)) << 2),
				((int)(base[i].x + 4)) << 2,
				((int)(base[i].y + 4)) << 2,
				G_TX_RENDERTILE,
				0 << 5,
				0 << 5,
				1 << 10,
				1 << 10
			);
			gDPPipeSync(glistp++);
			gDPSetTextureLUT(glistp++, G_TT_NONE);
		}
	}
}