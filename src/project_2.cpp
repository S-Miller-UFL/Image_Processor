#include <iostream>
#include "image.h"
#include "test.h"
#include "IO.h"
#include <vector>
#include "macros.h"

//////////////////////////////////
//DO NOT READ IN NEW FILES TO IMAGE OBJECTS WITHOUT CALLING "CLEAR()" FIRST
//////////////////////////////////

/*
MACROS:
//////////////////////////////////
 RED: 255,0,0
 GREEN: 0,255,0
 BLUE: 0,0,255
 ID_LENGTH: 0
 COLOR_MAP_TYPE: 0
 DATA_TYPE_CODE: 2
 COLOR_MAP_LENGTH: 0
 BPP: 24
 WIDTH: 512
 HEIGHT: 512
 HEADER: ID_LENGTH, COLOR_MAP_TYPE, DATA_TYPE_CODE, 0, COLOR_MAP_LENGTH, 0, 0, 0, WIDTH, HEIGHT, BPP, 0
//////////////////////////////////
*/

/*
bool read_write_test();
bool set_color_test();
bool randomize_color_test();
bool create_file_test();
*/
bool multiply_test();
bool subtract_test();
bool screen_test();
bool subtract_test_2();
bool overlay_test();
bool add_color_test();
bool scale_test();
bool split_image_color_test();
bool unsplit_image_test();
bool flip_image_test();

int main()
{
    bool test = true;
    while (test == true)
    {
        /*
        //simple read and write test
        
        if (read_write_test())
        {
            std::cout << "read and write test passed" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "read and write test failed" << std::endl;
            std::cout << std::endl;
        }
        
        //set color test
        set_color_test();
        if (set_color_test())
        {
            std::cout << "set color test passed" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "set color test failed" << std::endl;
            std::cout << std::endl;
        }
        //randomize color test
        randomize_color_test();
        if (randomize_color_test())
        {
            std::cout << "randomize color test passed" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "randomize color test failed" << std::endl;
            std::cout << std::endl;
        }
        //create header and file test
        create_file_test();
        if (create_file_test())
        {
            std::cout << "create_file test passed" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "create file test failed" << std::endl;
            std::cout << std::endl;
        }
        */

        //multiply test
        if (multiply_test())
        {
            std::cout << "multiply test passed" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "multiply test failed" << std::endl;
            std::cout << std::endl;
        }
        //subtract test
        if (subtract_test())
        {
            std::cout << "first subtract test passed" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "first subtract test failed" << std::endl;
            std::cout << std::endl;
        }
        //screen test
        if (screen_test())
        {
            std::cout << "screen test passed" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "screen test failed" << std::endl;
            std::cout << std::endl;
        }
        //subtract test 2
        if (subtract_test_2())
        {
            std::cout << "second subtract test passed" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "second subtract test failed" << std::endl;
            std::cout << std::endl;
        }
        //overlay test
        if (overlay_test())
        {
            std::cout << "overlay test passed" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "overlay test failed" << std::endl;
            std::cout << std::endl;
        }
        //add color test
        if (add_color_test())
        {
            std::cout << "add color test passed" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "add color test failed" << std::endl;
            std::cout << std::endl;
        }
        //mutliply test 2
        if (scale_test())
        {
            std::cout << "scale test passed" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "scale test failed" << std::endl;
            std::cout << std::endl;
        }
        //split image into seperate colors
        if (split_image_color_test())
        {
            std::cout << "split image color test passed" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "split image color test failed" << std::endl;
            std::cout << std::endl;
        }
        //unsplit images test
        if (unsplit_image_test())
        {
            std::cout << "combine image test passed" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "combine image test failed" << std::endl;
            std::cout << std::endl;
        }
        //flip test
        if (flip_image_test())
        {
            std::cout << "flip image test passed" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "flip image test failed" << std::endl;
            std::cout << std::endl;
        }

        test = false;
    }
}

/*
bool read_write_test()
{
    IO_READ_WRITE io;

    image image_;
    image image_2;
    IO_TEST test;

    io.read_file("examples/EXAMPLE_part1.tga", image_);

    io.write_file("output/TEST1.tga", image_);

    io.read_file("examples/EXAMPLE_part1.tga", image_2);

    return test.compare(image_2, image_);
    //std::cout << std::endl;
}

bool set_color_test()
{
    IO_READ_WRITE io;
    image image_;
    image image_2;
    IO_TEST test;
    IO_BLEND f;

    io.read_file("examples/EXAMPLE_part1.tga", image_);

    //r, g, b
    f.set_color(RED, image_);

    io.write_file("output/RED.tga", image_);

    io.read_file("output/RED.tga", image_2);

    return test.compare(image_2, image_);
    //std::cout << std::endl;
}

bool randomize_color_test()
{
    IO_READ_WRITE io;
    image image_;
    image image_2;
    IO_TEST test;

    io.read_file("examples/EXAMPLE_part1.tga", image_);

    image_.randomize_color();

    io.write_file("output/randomize_colors.tga", image_);

    io.read_file("output/randomize_colors.tga", image_2);

    return test.compare(image_, image_2);
    //std::cout << std::endl;

}

bool create_file_test()
{
    IO_READ_WRITE io;
    image image_;
    image image_2;
    IO_HEADER header_io;
    IO_TEST test;
    header header_file;


    header_file = header_io.create_header(HEADER);

    image_ = io.create_file(header_file);

    //read.read_file("output/TEST5.tga", image_);

    io.write_file("output/created_file.tga", image_);

    io.read_file("output/created_file.tga", image_2);

    return test.compare(image_, image_2);
    //std::cout << "create file test passed" << std::endl;
    //std::cout << std::endl;
}
*/
bool multiply_test()
{
    image top;
    image bottom;
    image result;
    image control;
    image operations;
    IO_READ_WRITE io;
    IO_TEST test;

    io.read_file("input/layer1.tga", top);
    io.read_file("input/pattern1.tga", bottom);

    result = operations.multiply(top, bottom);

    io.read_file("examples/EXAMPLE_part1.tga", control);

    io.write_file("output/part1.tga", result);

    return test.compare(control, result);

}

bool subtract_test()
{
    image top;
    image bottom;
    image result;
    IO_BLEND operations;
    image control;
    IO_READ_WRITE io;
    IO_TEST test;

    io.read_file("input/layer2.tga", top);
    io.read_file("input/car.tga", bottom);

    result = operations.subtract(top, bottom);

    io.read_file("examples/EXAMPLE_part2.tga", control);

    io.write_file("output/part2.tga", result);

    return test.compare(control, result);

}

bool screen_test()
{
    image top;
    image bottom;
    image control;
    image result;
    IO_BLEND operations;
    IO_HEADER header_io;
    header header_f;
    IO_READ_WRITE io;

    IO_TEST test;

    io.read_file("input/layer1.tga", top);
    io.read_file("input/pattern2.tga", bottom);
    bottom = operations.multiply(top, bottom);
    top.clear();
    io.read_file("input/text.tga", top);

    result = operations.screen(top, bottom);
    io.write_file("output/part3.tga", result);
    io.read_file("examples/EXAMPLE_part3.tga", control);

    return test.compare(control, result);

}

bool subtract_test_2()
{
    image top;
    image bottom;
    image result;
    image control;
    IO_BLEND operations;
    IO_READ_WRITE io;
    IO_TEST test;

    io.read_file("input/layer2.tga", top);
    io.read_file("input/circles.tga", bottom);

    bottom = operations.multiply(top, bottom);

    top.clear();

    io.read_file("input/pattern2.tga", top);

    result = operations.subtract(top, bottom);

    io.read_file("examples/EXAMPLE_part4.tga", control);
    io.write_file("output/part4.tga", result);

    return test.compare(result, control);
 
}

bool overlay_test()
{
    image top;
    image bottom;
    image result;
    image control;
    IO_BLEND operations;
    IO_READ_WRITE io;
    IO_TEST test;


    io.read_file("input/layer1.tga", top);
    io.read_file("input/pattern1.tga", bottom);

    result = operations.overlay(top, bottom);

    io.write_file("output/part5.tga", result);

    io.read_file("examples/EXAMPLE_part5.tga", control);

    return test.compare(control, result);

}

bool add_color_test()
{
    image image_;
    image image_2;
    IO_READ_WRITE io;
    IO_TEST test;


    io.read_file("input/car.tga", image_);

    image_.add(0, 200, 0);

    io.write_file("output/part6.tga", image_);

    io.read_file("examples/EXAMPLE_part6.tga", image_2);

    return test.compare(image_2, image_);
}

bool scale_test()
{
    image image_;
    image image_2;
    IO_READ_WRITE io;
    IO_TEST test;


    io.read_file("input/car.tga", image_);

    image_.scale(4,1,0);

    io.read_file("examples/EXAMPLE_part7.tga", image_2);

    io.write_file("output/part7.tga", image_);


    return test.compare(image_2, image_);
}

bool split_image_color_test()
{
    image image_;
    image blue;
    image green;
    image red;
    image result_blue;
    image result_green;
    image result_red;
    IO_BLEND operations;
    IO_READ_WRITE io;
    IO_TEST test;


    io.read_file("input/car.tga", image_);

    image_.split_image("output/part8.tga");

    image_.clear();
    
    io.read_file("output/part8_b.tga", blue);
    io.read_file("output/part8_g.tga", green);
    io.read_file("output/part8_r.tga", red);

    io.read_file("examples/EXAMPLE_part8_b.tga", result_blue);
    io.read_file("examples/EXAMPLE_part8_g.tga", result_green);
    io.read_file("examples/EXAMPLE_part8_r.tga", result_red);

    if (test.compare(result_blue, blue) && test.compare(result_green, green) && test.compare(result_red, red))
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool unsplit_image_test()
{
    image blue;
    image green;
    image red;
    image result;
    image control;
    IO_BLEND operations;
    IO_READ_WRITE io;
    IO_TEST test;


    io.read_file("input/layer_red.tga", blue);
    io.read_file("input/layer_green.tga", green);
    io.read_file("input/layer_blue.tga", red);

    result = operations.combine(blue, green, red);

    io.write_file("output/part9.tga", result);

    io.read_file("examples/EXAMPLE_part9.tga", control);

    return test.compare(control, result);
}

bool flip_image_test()
{
    image image_;
    image image_2;
    IO_READ_WRITE io;
    IO_BLEND f;
    IO_TEST test;

    io.read_file("input/text2.tga", image_);

    f.flip(image_);

    io.write_file("output/part10.tga", image_);

    io.read_file("examples/EXAMPLE_part10.tga", image_2);

    return test.compare(image_2, image_);
}