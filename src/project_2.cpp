#include <iostream>
#include "image.h"
#include "test.h"
#include "IO.h"
#include <vector>

//////////////////////////////////
//DO NOT REASSIGN IMAGE OBJECTS WITHOUT CALLING "CLEAR()" FIRST
//////////////////////////////////


//////////////////////////////////
//constant macros
//MUST REMAIN DEFINED AS THEY CURRENTLY ARE
#define ID_LENGTH 0
#define COLOR_MAP_TYPE 0
#define DATA_TYPE_CODE 2
#define COLOR_MAP_LENGTH 0
#define BPP 24
//////////////////////////////////


//COLOR MACROS
#define RED 255,0,0
#define GREEN 0,255,0
#define BLUE 0,0,255
#define BLACK 0,0,0
#define WHITE 255,255,255
#define MAX 255
#define NONE 0

void read_write_test();
void set_color_test();
void randomize_color_test();
void create_file_test();
void multiply_test();
void subtract_test();
void screen_test();

int main()
{

    //simple read and write test
    read_write_test();
    //set color test
    set_color_test();
    //randomize color test
    randomize_color_test();
    //create header and file test
    create_file_test();
    //multiply test
    multiply_test();
    //subtract test
    subtract_test();
    //screen test
    screen_test();


}

void read_write_test()
{
    IO_READ read;
    IO_WRITE write;
    image image_;
    image image_2;
    IO_TEST test;
    std::cout << "starting read and write test:" << std::endl;

    read.read_file("examples/EXAMPLE_part1.tga", image_);

    write.write_file("output/TEST1.tga", image_);

    read.read_file("examples/EXAMPLE_part1.tga", image_2);

    test.compare(image_, image_2);
    std::cout << std::endl;
}

void set_color_test()
{
    IO_READ read;
    IO_WRITE write;
    image image_;
    image image_2;
    IO_TEST test;
    std::cout << "starting set color test:" << std::endl;
    read.read_file("examples/EXAMPLE_part1.tga", image_);

    //r, g, b
    image_.set_color(RED);

    write.write_file("output/set_color.tga", image_);

    read.read_file("output/TEST3.tga", image_2);

    test.compare(image_, image_2);
    std::cout << std::endl;
}

void randomize_color_test()
{
    IO_READ read;
    IO_WRITE write;
    image image_;
    image image_2;
    IO_TEST test;
    std::cout << "starting randomize color test:" << std::endl;
    read.read_file("examples/EXAMPLE_part1.tga", image_);

    image_.randomize_color();

    write.write_file("output/random_colors.tga", image_);

    read.read_file("output/TEST4.tga", image_2);

    test.compare(image_, image_2);
    std::cout << std::endl;

}

void create_file_test()
{

    IO_READ read;
    IO_WRITE write;
    image image_;
    image image_2;
    IO_HEADER header_io;
    IO_TEST test;
    header header_file;

    std::cout << "starting create header test:" << std::endl;

    header_file = header_io.create_header(ID_LENGTH, COLOR_MAP_TYPE, DATA_TYPE_CODE, 0, COLOR_MAP_LENGTH, 0, 0, 0, 1920, 1080, BPP, 0);

    std::cout << "starting create file test:" << std::endl;
    write.create_file("output/TEST5.tga", header_file);

    read.read_file("output/TEST5.tga", image_);

    write.write_file("output/create_file.tga", image_);

    read.read_file("output/create_file.tga", image_2);

    test.compare(image_, image_2);
    //std::cout << "create file test passed" << std::endl;
    std::cout << std::endl;
}

void multiply_test()
{
    image image_;
    image image_2;
    image operations;
    IO_READ read;
    IO_WRITE write;
    IO_TEST test;

     std::cout << "starting multiply test:" << std::endl;

    read.read_file("input/layer1.tga", image_);

    read.read_file("input/pattern1.tga", image_2);

    //top, bottom
    image_2 = operations.multiply(image_, image_2);

    write.write_file("output/multiply_test.tga", image_2);

    image_.clear();
    image_2.clear();

    read.read_file("examples/EXAMPLE_part1.tga", image_);
    read.read_file("output/multiply_test.tga", image_2);

    //image 1, image 2
    test.compare(image_, image_2);
    //std::cout << "multiply test passed" << std::endl;
    std::cout << std::endl;

}

void subtract_test()
{
    image image_;
    image image_2;
    image operations;
    IO_READ read;
    IO_WRITE write;
    IO_TEST test;

    image_.clear();
    image_2.clear();

     std::cout << "starting subtract test:" <<  std::endl;

   // image_6.clear();
    //top
    read.read_file("input/layer2.tga", image_);
    //bottom
    read.read_file("input/car.tga", image_2);

    image_2 = operations.subtract(image_, image_2);

    write.write_file("output/subtract_test.tga", image_2);

    image_.clear();

    read.read_file("examples/EXAMPLE_part2.tga", image_);

    test.compare(image_, image_2);
    std::cout << std::endl;
}

void screen_test()
{
    image image_;
    image image_2;
    image image_3;
    image image_4;
    image image_5;
    image operations;
    IO_READ read;
    IO_WRITE write;
    IO_TEST test;

     std::cout << "starting screen test:" <<  std::endl;

    //top
    read.read_file("input/layer1.tga", image_);
    //bottom
    read.read_file("input/pattern2.tga", image_2);

    image_3 = operations.multiply(image_2, image_);

    read.read_file("input/text.tga", image_4);

    image_5 = operations.screen(image_4, image_3);

    write.write_file("output/screen_test.tga", image_5);

    image_.clear();
    read.read_file("examples/EXAMPLE_part3.tga", image_);

    test.compare(image_, image_5);
}
