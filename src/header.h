#pragma once
struct header
{
	char id_length;
	char color_map_type;
	char image_type;
	//color map
	short color_map_origin;
	short color_map_length;
	char color_map_depth;
	//image specification
	short x_origin;
	short y_origin;
	short width;
	short height;
	char pixel_depth;
	char image_descriptor;
	std::vector<pixel> v_image;
	unsigned int size;
};