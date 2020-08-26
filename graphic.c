#include <nusys.h>
#include "config.h"

typedef struct {
	short	view_scale[4];
	short	view_transformation[4];
	long long int	force_structure_alignment;
}; 

static Vp viewport = {
	SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, G_MAXZ / 2, 0,
	SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, G_MAXZ / 2, 0,
};

Gfx rspinit_dl[] = {
	gsSPViewport(&viewport),
	gsSPClearGeometryMode(G_SHADE | G_SHADING_SMOOTH |
		G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
		G_TEXTURE_GEN_LINEAR | G_LOD),
	gsSPTexture(0,0,0,0,G_OFF),
	gsSPEndDisplayList()
};

Gfx rdpinit_dl[] = {
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT),
	gsDPSetCombineKey(G_CK_NONE),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
	gsDPSetColorDither(G_CD_DISABLE),
	gsDPPipeSync(),
	gsSPEndDisplayList()
};

void RCPInit(Gfx* glistp) 
{
	gSPSegment(glistp++, 0, 0);
	gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(rspinit_dl));
	gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(rdpinit_dl));
}