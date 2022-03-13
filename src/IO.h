#pragma once
#include "image.h"
#include <string>
struct IO_READ
{
	void read_file(std::string name, image& image_f)
	{
		image_f.read_file(name, image_f);
	}
};

struct IO_WRITE
{
	void write_file(std::string name, image& image_f)
	{
		image_f.write_with_name(name, image_f);
	}
	void create_file(std::string name, header& h)
	{
		i.create_blank_file(name, h);
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
		h = i.create_header(id_length, color_map_type, 
			image_type, color_map_origin, 
			color_map_length, color_map_depth,
			x_origin, y_origin,
			width, height, 
			pixel_depth, image_descriptor);

		return h;
	}

private:
	image i;
	header h;
};