#ifndef STRUCT_H
#define STRUCT_H
struct map{
    uint8_t object[10];
    uint16_t obj_x[10];
    uint16_t obj_y[10];
	uint8_t npcsprite;

	char* sound[5];
	int hz[5];

    char* background;

	uint8_t cinematic;
};
struct cinematic{
	uint16_t time[8];

	char* sound[8];
	int hz[8];

	char* bg[8];
};
struct spritelist{
	char* link[11];
};
#endif