/* textdisplayer.c
 *
 * Displays text on the screen.
 * Does not rteat text as sprites or objects.
 */
#include <nusys.h>
#include <ctype.h>
#include "config.h"
#include "textdisplayer.h"
#include "assets/sprites/fontRetro.h"

int * getCharCoordinates(char c);

void displayText(char *text, int x, int y) 
{
	gDPSetCycleType(glistp++, G_CYC_1CYCLE);
	gDPSetCombineMode(glistp++, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM);
	gDPSetRenderMode(glistp++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
	gDPSetDepthSource(glistp++, G_ZS_PRIM);
	gDPSetTexturePersp(glistp++, G_TP_NONE);
	gDPSetTextureLUT(glistp++, G_TT_RGBA16);
	gDPSetPrimDepth(glistp++, 10, 0);
	gDPSetPrimColor(glistp++, 0, 0, 0, 0, 0, 255);
	
	gDPLoadTLUT_pal16(glistp++, 0, fontRetro_tlut);
	
	gDPLoadTextureTile_4b( // Load the texture
		glistp++,
		fontRetro,
		G_IM_FMT_CI,
		48, 48,
		0, 0, // ulx, uly
		7, 7, // brx, bry
		0,
		G_TX_WRAP, G_TX_WRAP,
		G_TX_NOMASK, G_TX_NOMASK,
		G_TX_NOLOD, G_TX_NOLOD
		);
	// Draw the character
	gSPScisTextureRectangle( // Display texture
		glistp++,
		(((int)(x - 4)) << 2),
		(((int)(y - 4)) << 2),
		((int)(x + 4)) << 2,
		((int)(y + 4)) << 2,
		G_TX_RENDERTILE,
		0 << 5,
		0 << 5,
		1 << 10,
		1 << 10
	);
	gDPPipeSync(glistp++);
	gDPSetTextureLUT(glistp++, G_TT_NONE);
}

// WIP
int * getCharCoordinates(char c)
{
	int array[4]; // ulx, uly, brx, bry
	
	if (isalnum(c))
	{
		switch(c)
		{
			case 'a':
				array[0] = 0;
				array[1] = 0;
				array[2] = 7;
				array[3] = 7;
				break;
			case 'b':
				break;
			case 'c':
				break;
			case 'd':
				break;
			case 'e':
				break;
			case 'f':
				break;
			case 'g':
				break;
			case 'h':
				break;
			case 'i':
				break;
			case 'j':
				break;
			case 'k':
				break;
			case 'l':
				break;
			case 'm':
				break;
			case 'n':
				break;
			case 'o':
				break;
			case 'p':
				break;
			case 'q':
				break;
			case 'r':
				break;
			case 's':
				break;
			case 't':
				break;
			case 'u':
				break;
			case 'v':
				break;
			case 'w':
				break;
			case 'x':
				break;
			case 'y':
				break;
			case 'z':
				break;
			case '1':
				break;
			case '2':
				break;
			case '3':
				break;
			case '4':
				break;
			case '5':
				break;
			case '6':
				break;
			case '7':
				break;
			case '8':
				break;
			case '9':
				break;
			case '0':
			default:
				break;
		}
	}
	
	return *array;
}