#ifndef N64_OBJECTS_BASE
#define N64_OBJECTS_BASE

	#define TYPE_OBJ_NULL 0
	#define TYPE_OBJ_BEE 1
	#define TYPE_OBJ_BLOCK 2

	typedef struct _base BASE;
	struct _base {
		u8 type;
		int x;
		int y;
	};
	
	int instance_create(BASE *base, char type, int x, int y);
	
	void instance_update_all(BASE *base);
	
	void instance_draw_all(BASE *base);

#endif