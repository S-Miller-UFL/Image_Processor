#include <iostream>
#include "image.h"
#include "test.h"
#include "IO.h"

//////////////////////////////////
//constant macros
//MUST REMAIN DEFINED AS THEY CURRENTLY ARE
#define ID_LENGTH 0
#define COLOR_MAP_TYPE 0
#define DATA_TYPE_CODE 2
#define COLOR_MAP_LENGTH 0
#define BPP 24
//////////////////////////////////


/*
//////////////////////////////////
//changeable macros
//ARE ABLE TO BE CHANGED BUT ARE DEFINED FOR YOUR CONVENIENCE
#define COLOR_MAP_ORIGIN 0
#define COLOR_MAP_DEPTH 0
#define X_ORIGIN 0
#define Y_ORIGIN 0
#define WIDTH 0
#define HEIGHT 0
#define DESCRIPTOR 0
//////////////////////////////////
*/

//COLOR MACROS
#define RED 255,0,0
#define GREEN 0,255,0
#define BLUE 0,0,255
#define BLACK 0,0,0
#define WHITE 255,255,255
#define MAX 255
#define NONE 0
using namespace std;
int main()
{
    //image
    image image_;
    image image_2;
    image image_3;
    image image_4;
    image image_5;
    image image_6;

    header header_file;
    test test_files;

    //IO header
    IO_WRITE write;
    IO_READ read;
    IO_HEADER header_io;

    //test
    test test;

    read.read_file("examples/EXAMPLE_part1.tga", image_);

    write.write_file("output/TEST1.tga", image_);

    image_2.write_with_name("output/TEST2.tga", image_);

    read.read_file("examples/EXAMPLE_part1.tga", image_2);

    read.read_file("examples/EXAMPLE_part1.tga",image_3);

    //r, g, b
    image_3.set_color(RED);

    write.write_file("output/TEST3.tga", image_3);


    read.read_file("examples/EXAMPLE_part1.tga", image_4);

    image_4.randomize_color();

   write.write_file("output/TEST4.tga", image_4);


   header_file = header_io.create_header(ID_LENGTH,COLOR_MAP_TYPE,DATA_TYPE_CODE,0,COLOR_MAP_LENGTH,0,0,0,1920,1080,BPP,0);

    write.create_file("output/TEST5.tga", header_file);

    read.read_file("output/TEST5.tga", image_5);

}

