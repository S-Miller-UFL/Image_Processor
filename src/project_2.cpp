#include <iostream>
#include "image.h"
#include "test.h"

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

using namespace std;
int main()
{
    image image_test;
    image read;
    image write;
    image image_test_2;
    image image_test_3;
    image image_test_4;
    image image_test_5;
    image image_test_6;

    header header_file;
    test test_files;

    read.read_file("examples/EXAMPLE_extracredit.tga", image_test);

    write.write_with_name("output/TEST1.tga", image_test);

    image_test_2.write_with_name("output/TEST2.tga", image_test);

    read.read_file("examples/EXAMPLE_part1.tga", image_test_2);

    read.read_file("examples/EXAMPLE_part1.tga",image_test_3);

    //r, g, b
    image_test_3.set_color((unsigned char)0,(unsigned char)0,(unsigned char)0);

    write.write_with_name("output/TEST3.tga", image_test_3);


    read.read_file("examples/EXAMPLE_part1.tga", image_test_4);

    image_test_4.randomize_color();

   write.write_with_name("output/TEST4.tga", image_test_4);


   header_file = write.create_header(ID_LENGTH,COLOR_MAP_TYPE,DATA_TYPE_CODE,0,COLOR_MAP_LENGTH,0,0,0,1920,1080,BPP,0);

    write.create_blank_file("output/TEST5.tga", header_file);

    read.read_file("output/TEST5.tga", image_test_5);

    if (test_files.test_compare_images(image_test, image_test_2) == false)
    {
        cout << "failed!" << endl;
    }
    else
    {
        cout << "success!" << endl;
    }
    //image image_test_2;
    //image_test_2.read_file("output/TEST1.tga");
}

