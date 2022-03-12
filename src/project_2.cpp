#include <iostream>
#include "image.h"
#include "test.h"
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

    read.read_file("examples/EXAMPLE_part1.tga", image_test);

    write.write_with_name("output/TEST1.tga", image_test);
    //image_test_2.write_with_name("output/TEST2.tga", image_test);
    read.read_file("examples/EXAMPLE_part1.tga", image_test_2);

    read.read_file("examples/EXAMPLE_part1.tga",image_test_3);

    //r, g, b
    image_test_3.set_color((unsigned char)0,(unsigned char)0,(unsigned char)0);

    write.write_with_name("output/TEST4.tga", image_test_3);


    read.read_file("examples/EXAMPLE_part1.tga", image_test_4);

    image_test_4.randomize_color();

    write.write_with_name("output/TEST5.tga", image_test_4);


    header_file = write.create_header("output/TEST6.tga",1,3,2,0,4,6,0,0,400,400,32,2);

    write.create_blank_file("output/FILE_1.tga", header_file);

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

