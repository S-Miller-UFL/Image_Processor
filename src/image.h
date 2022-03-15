#pragma once
#include <vector>
#include <string>
#include "pixel.h"
#include "header.h"
class image
{
public:
	//void setsize();
	//unsigned int getsize();
	void addpixel(pixel&);
	std::vector<pixel> get_pixel_array();
	pixel get_pixel(unsigned int);
	void read_file(std::string, image& );
	unsigned int getsize();
	void write_with_name(std::string, image&);
	void set_color(const unsigned char,const unsigned char,const unsigned char);
	void randomize_color();
	//image create_new_header(std::string ,char, char,char,short,short,char,short,short,short,short,char,char);
	void copy_to_file_create_new(std::string, image&, image&);
	void copy_to_file(const image&, image&);
	header create_header(char, char, char, short, short, char, short, short, short, short, char, char);

	image multiply(image&, image&);
	image subtract(image&, image&);
	image screen(image&, image&);
	image overlay(image&, image&);
	void edit_header();
	void add_color(unsigned char, unsigned char, unsigned char);
	void clear();
	void create_blank_file(std::string,header&);
	const std::vector<pixel> get_pixel_array() const;
	const pixel get_pixel(unsigned int) const;
	const unsigned int getsize() const;
	
private:
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
