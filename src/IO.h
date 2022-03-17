#pragma once
#include "image.h"
#include "test.h"
#include <string>

struct IO_READ_WRITE
{
	void read_file(std::string name, image& image_f)
	{
		image_f.read_file(name, image_f);
	}
	void write_file(std::string name, image& image_f)
	{
		image_f.write_with_name(name, image_f);
	}
	image create_file(header& h)
	{
		 return i.create_blank_file(h);
	}
private:
	image i;
};

struct IO_HEADER
{
	header create_header(char id_length, char color_map_type, 
		char image_type, short color_map_origin, 
		short color_map_length, char color_map_depth, 
		short x_origin, short y_origin, 
		short width, short height, 
		char pixel_depth, char image_descriptor)

	{
		return i.create_header(id_length, color_map_type, 
			image_type, color_map_origin, 
			color_map_length, color_map_depth,
			x_origin, y_origin,
			width, height, 
			pixel_depth, image_descriptor);
	}

private:
	image i;
};

struct IO_BLEND
{
	image multiply(image& top, image& bottom)
	{
		return i.multiply(top, bottom);
	}
	image subtract(image& top, image& bottom)
	{
		return i.subtract(top, bottom);
	}
	image screen(image& top, image& bottom)
	{
		return i.screen(top, bottom);
	}
	image overlay(image& top, image& bottom)
	{
		return i.overlay(top, bottom);
	}
	image combine(image& red, image& green, image& blue)
	{
		return i.combine(red, green, blue);
	}
	void flip(image& image_f)
	{
		image_f.flip();
	}
	void set_color(unsigned char red, unsigned char green, unsigned char blue, image& image_f)
	{
		image_f.set_color(red, green, blue);
	}
private:
	image i;
};

struct IO_TEST
{
	bool compare(const image& h0, const image& h1)
	{
		return t.test_compare_images(h0,h1);
		
	}
private:
	test t;
};