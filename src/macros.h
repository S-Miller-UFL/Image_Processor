#pragma once
//////////////////////////////////
//constant macros
//MUST REMAIN DEFINED AS THEY CURRENTLY ARE
#define ID_LENGTH 0
#define COLOR_MAP_TYPE 0
#define DATA_TYPE_CODE 2
#define COLOR_MAP_LENGTH 0
#define BPP 24
//////////////////////////////////

//////////////////////////////////
//COLOR MACROS
#define RED 255,0,0
#define GREEN 0,255,0
#define BLUE 0,0,255
#define BLACK 0,0,0
#define WHITE 255,255,255
#define MAX_INT	 255
#define NONE 0.0f
#define MAX_FLOAT 255.0f
//////////////////////////////////

//////////////////////////////////
//FILE MACROS
#define CHAR 1
#define SHORT 2
#define WIDTH 512
#define HEIGHT 512
#define HEADER ID_LENGTH, COLOR_MAP_TYPE, DATA_TYPE_CODE, 0, COLOR_MAP_LENGTH, 0, 0, 0, WIDTH, HEIGHT, BPP, 0
//////////////////////////////////