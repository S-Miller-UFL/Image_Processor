#include "image.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "color.h"
//got help from alex duffaut on 3/14/2022 at around 2:30 pm
//got help from james horn on 3/14/2022 at around 3:30 pm
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
#define MAX 255
#define NONE 0
//////////////////////////////////

//////////////////////////////////
//FILE MACROS
#define CHAR 1
#define SHORT 2
//////////////////////////////////
using namespace std;
void image::addpixel(pixel& pix)
{
	this->v_image.push_back(pix);
}
std::vector<pixel> image::get_pixel_array()
{
	return v_image;
}
pixel image::get_pixel(unsigned int i)
{
	return v_image.at(i);
}
unsigned int image::getsize()
{
	return this->v_image.size();
}
const unsigned int image::getsize() const
{
	return v_image.size();
}
const std::vector<pixel> image::get_pixel_array() const
{
	return v_image;
}

const pixel image::get_pixel(unsigned int i) const
{
	return v_image.at(i);
}

void image::read_file(std::string file_name, image& file)
{
	pixel pixel_Data;

	std::ifstream image(file_name, std::ios_base::binary); //declare ifstream object

	image.read(&file.id_length, CHAR);//read id length

	image.read(&file.color_map_type, CHAR); //read color map type

	image.read(&file.image_type, CHAR); //read image type

	image.read((char*)&file.color_map_origin, SHORT); //read color map origin

	image.read((char*)&file.color_map_length, SHORT); //read color map length

	image.read(&file.color_map_depth, CHAR); //read color map depth

	image.read((char*)&file.x_origin, SHORT); //read x origin

	image.read((char*)&file.y_origin, SHORT); //read y origin

	image.read((char*)&file.width, SHORT); //read width

	image.read((char*)&file.height, SHORT); //read height

	image.read(&file.pixel_depth, CHAR); //read pixel depth

	image.read(&file.image_descriptor, CHAR); //read image descriptor

	//display image details

	cout << "ID Length: " << (int)file.id_length << endl;
	cout << "Color Map Type: " << (int)file.color_map_type << endl;
	cout << "Data Type Code: " << (int)file.image_type << endl;
	cout << "Color Map Origin: " << (short)file.color_map_origin << endl;
	cout << "Color Map Length: " << (short)file.color_map_length << endl;
	cout << "Color Map Depth: " << (int)file.color_map_depth << endl;
	cout << "X Origin: " << (short)file.x_origin << endl;
	cout << "Y Origin: " << (short)file.y_origin << endl;
	cout << "Width: " << (short)file.width << endl;
	cout << "Height: " << (short)file.height << endl;
	cout << "Bits Per Pixel: " << (int)file.pixel_depth << endl;
	cout << "Image Descriptor: " << (int)file.image_descriptor << endl;
	cout << endl;
	
	//read image data 
	unsigned char blue = 0;
	unsigned char green = 0;
	unsigned char red = 0;
	
	for (unsigned int i = 0; i < file.height * file.width; i++)
	{
		image.read((char*)&blue, CHAR);
		image.read((char*)&green, CHAR);
		image.read((char*)&red, CHAR);
		pixel_Data.set_blue(blue);
		pixel_Data.set_green(green);
		pixel_Data.set_red(red);
		file.addpixel(pixel_Data);
	}
	image.close();
	
	//display each pixels color info
	/*
	for (unsigned int i = 0; i < file.getsize(); i++)
	{
		std::cout << "pixel number: " << i << std::endl;
		std::cout << "Blue value: " <<(int) file.get_pixel(i).get_blue() << std::endl;
		std::cout << "Green value: " <<(int) file.get_pixel(i).get_green() << std::endl;
		std::cout << "Red value: " << (int) file.get_pixel(i).get_red() << std::endl;
	}
	*/
}

void image::write_with_name(std::string name, image& image_f)
{
	std::ofstream file_write(name, std::ios_base::binary);

	//write header file
	/*
	* read id length: 1 byte
	* read color map type: 1 byte
	* read image type: 1 byte
	* read color map origin: 2 bytes
	* color map length: 2 bytes
	* color map depth: 1 byte
	* x origin: 2 byte
	* y origin: 2 bytes
	* read width: 2 bytes
	* read height: 2 bytes
	* read pixel depth: 1 bytes
	* read image descriptor: 1 byte
	*/
	
	file_write.write(&image_f.id_length, CHAR);

	file_write.write(&image_f.color_map_type, CHAR);

	file_write.write(&image_f.image_type, CHAR);

	file_write.write((char*)&image_f.color_map_origin, SHORT);

	file_write.write((char*)&image_f.color_map_length, SHORT);

	file_write.write(&image_f.color_map_depth, CHAR);

	file_write.write((char*)&image_f.x_origin, SHORT);

	file_write.write((char*)&image_f.y_origin, SHORT);

	file_write.write((char*)&image_f.width, SHORT);

	file_write.write((char*)&image_f.height, SHORT);

	file_write.write(&image_f.pixel_depth, CHAR);

	file_write.write(&image_f.image_descriptor, CHAR);

	//write file data
	
	for (unsigned int i = 0; i < image_f.getsize(); i++)
	{
		file_write.write((char*)&image_f.v_image.at(i).get_blue(), CHAR);

		file_write.write((char*)&image_f.v_image.at(i).get_green(), CHAR);

		file_write.write((char*)&image_f.v_image.at(i).get_red(), CHAR);
	}
	file_write.close();
	
}

void image::set_color(const unsigned char red,
	const unsigned char green, const unsigned char blue)
{
	for (unsigned int i = 0; i < this->getsize(); i++)
	{
		this->v_image.at(i).set_blue(blue);
		this->v_image.at(i).set_green(green);
		this->v_image.at(i).set_red(red);
	}
	/*
	for (unsigned int i = 0; i < header_f.getsize(); i++)
	{
		file_write.write((char*)&header_f.v_image.at(i).get_green(), CHAR);

		file_write.write((char*)&header_f.v_image.at(i).get_red(), CHAR);

		file_write.write((char*)&header_f.v_image.at(i).get_blue(), CHAR);

		//file_write.write((char*)&header_f.v_image.at(i).get_green(), CHAR);

		//file_write.write((char*)&header_f.v_image.at(i).get_red(), CHAR);
	}
	*/
}

void image::randomize_color()
{
	for (unsigned int i = 0; i < this->getsize(); i++)
	{
		//if even, set to green
		if (i % 2 == 0)
		{
			this->v_image.at(i).set_blue(NONE);

			this->v_image.at(i).set_green(MAX);

			this->v_image.at(i).set_red(NONE);
		}
		//if odd, set to blue
		else if (i % 3 == 0)
		{ 
			this->v_image.at(i).set_blue(MAX);

			this->v_image.at(i).set_green(NONE);

			this->v_image.at(i).set_red(NONE);
		}
		//if neither, set to red
		else
		{
			this->v_image.at(i).set_blue(NONE);

			this->v_image.at(i).set_green(NONE);

			this->v_image.at(i).set_red(MAX);
		}
	}
}

 void image::copy_to_file_create_new(std::string name, image& file_to_copy ,image& copied_file)
 {
	
 }

 void image::copy_to_file(const image& file_to_copy, image& copied_file)
 {
	// copied_file.

 }

 header image::create_header(char id_length, char color_map_type, 
	 char image_type, short color_map_origin, 
	 short color_map_length, char color_map_depth, 
	 short x_origin, short y_origin, 
	 short width, short height, 
	 char pixel_depth, char image_descriptor)
 {
	 //std::ofstream file_write(name, std::ios_base::binary);

	 //write header file
	 /*
	 * read id length: 1 byte
	 * read color map type: 1 byte
	 * read image type: 1 byte
	 * read color map origin: 2 bytes
	 * color map length: 2 bytes
	 * color map depth: 1 byte
	 * x origin: 2 byte
	 * y origin: 2 bytes
	 * read width: 2 bytes
	 * read height: 2 bytes
	 * read pixel depth: 1 bytes
	 * read image descriptor: 1 byte
	 */
	 //image header_f;
	 //image pixels;

	 header header_f;

	 header_f.id_length = id_length;
	 header_f.color_map_type = color_map_type;
	 header_f.image_type = image_type;
	 header_f.color_map_origin = color_map_origin;
	 header_f.color_map_length = color_map_length;
	 header_f.color_map_depth = color_map_depth;
	 header_f.x_origin = x_origin;
	 header_f.y_origin = y_origin;
	 header_f.width = width;
	 header_f.height = height;
	 header_f.pixel_depth = pixel_depth;
	 header_f.image_descriptor = image_descriptor;

	 return header_f;
 }

 image image::multiply(image& top, image& bottom)
 {
	 //iterate through each file and get every pixel and its colors if theyre the same size
	 //just to be safe, lets iterate through only the bottom.
	 //multiply each pixels colors by eachother
	 //set the new objects pixels colors to the multiplied ones and return new object

	 float normal_blue;
	 float normal_green;
	 float normal_red;

	 color<float> normalize_color;


	 for (unsigned int i = 0; i < top.getsize(); i++)
	 {
		 normal_blue = normalize_color.normalize(bottom.v_image.at(i).get_blue(), top.v_image.at(i).get_blue());
		 normal_green = normalize_color.normalize(bottom.v_image.at(i).get_green(), top.v_image.at(i).get_green());
		 normal_red = normalize_color.normalize(bottom.v_image.at(i).get_red(), top.v_image.at(i).get_red());
		 
		 bottom.v_image.at(i).set_blue((unsigned char)(normal_blue));
		 bottom.v_image.at(i).set_green((unsigned char)(normal_green));
		 bottom.v_image.at(i).set_red((unsigned char)(normal_red));
	 }
	// cout << top.getsize() << endl;
	// cout << bottom.getsize() << endl;

	 return bottom;
 }

 image image::subtract(image& top, image& bottom)
 {
	 unsigned char sub_blue = 0;
	 unsigned char sub_green = 0;
	 unsigned char sub_red = 0;
	 //subtract top layer from bottom layer
	 for (unsigned int i = 0; i < bottom.getsize(); i++)
	 {
		 sub_blue = bottom.v_image.at(i).get_blue() - top.v_image.at(i).get_blue();
		 if (bottom.v_image.at(i).get_blue() - top.v_image.at(i).get_blue() < 0)
		 {
			 sub_blue = NONE;
		 }
		 else if (bottom.v_image.at(i).get_blue() - top.v_image.at(i).get_blue() > 255)
		 {
			 sub_blue = MAX;
		 }
		 sub_green = bottom.v_image.at(i).get_green() - top.v_image.at(i).get_green();
		 if (bottom.v_image.at(i).get_green() - top.v_image.at(i).get_green() < 0)
		 {
			 sub_green = NONE;
		 }
		 else if (bottom.v_image.at(i).get_green() - top.v_image.at(i).get_green() > 255)
		 {
			 sub_green = MAX;
		 }
		 sub_red = bottom.v_image.at(i).get_red() - top.v_image.at(i).get_red();
		 if (bottom.v_image.at(i).get_red() - top.v_image.at(i).get_red() < 0)
		 {
			 sub_red = NONE;
		 }
		 else if (bottom.v_image.at(i).get_red() - top.v_image.at(i).get_red() > 255)
		 {
			 sub_red = MAX;
		 }
		 
		 bottom.v_image.at(i).set_blue((unsigned char)(sub_blue));
		 bottom.v_image.at(i).set_green((unsigned char)(sub_green));
		 bottom.v_image.at(i).set_red((unsigned char)(sub_red));
	 }
	 //cout << top.getsize() << endl;
	 //cout << bottom.getsize() << endl;

	 return bottom;
 }
 //c= 255-(255-top pixel)*(255-bottom pixel)
 image image::screen(image& top, image& bottom)
 {
	 double screen_blue = 0;
	 double screen_green = 0;
	 double screen_red = 0;
	 double screen_blue_b = 0;
	 double screen_green_b = 0;
	 double screen_red_b = 0;


	 color <int> c_color;
	 for (unsigned int i = 0; i < bottom.getsize(); i++)
	 {
		 //get screen for blue
		 screen_blue = (double)top.v_image.at(i).get_blue(); //gets blue
		 screen_blue = screen_blue / 255.0f; //normalizes
		 screen_blue = 1 - screen_blue; //gets inversion
		 
		 screen_blue_b = (double)bottom.v_image.at(i).get_blue(); //gets blue
		 screen_blue_b = screen_blue_b / 255.0f; //normalizes
		 screen_blue_b = 1 - screen_blue_b; //inverts

		 screen_blue = screen_blue * screen_blue_b; //multiplies
		 screen_blue = 1 - screen_blue; //inverts product
		 screen_blue = screen_blue * 255.0f; //denormalize
		 screen_blue = screen_blue + .5f;//error correction

		 //double check
		 if ((int)screen_blue < 0)
		 {
			 screen_blue = 0;
		 }
		 else if ((int)screen_blue > 255)
		 {
			 screen_blue = 255;
		 }

		 //get screen for green
		 screen_green = (double)top.v_image.at(i).get_green(); //gets green
		 screen_green = screen_green / 255.0f; //normalizes
		 screen_green = 1 - screen_green; //gets inversion

		 screen_green_b = (double)bottom.v_image.at(i).get_green(); //gets green bottom
		 screen_green_b = screen_green_b / 255.0f; //normalizes
		 screen_green_b = 1 - screen_green_b; //inverts

		 screen_green = screen_green * screen_green_b; //multiplies
		 screen_green = 1 - screen_green; //inverts product
		 screen_green = screen_green * 255.0f; //denormalize
		 screen_green = screen_green + .5f;//error correction

		 //double check
		 if ((int)screen_green < 0)
		 {
			 screen_green = 0;
		 }
		 else if ((int)screen_green > 255)
		 {
			 screen_green = 255;
		 }

		 //get screen for red
		 screen_red = (double)top.v_image.at(i).get_red(); //gets green
		 screen_red = screen_red / 255.0f; //normalizes
		 screen_red = 1 - screen_red; //gets inversion

		 screen_red_b = (double)bottom.v_image.at(i).get_red(); //gets green bottom
		 screen_red_b = screen_red_b / 255.0f; //normalizes
		 screen_red_b = 1 - screen_red_b; //inverts

		 screen_red = screen_red * screen_red_b; //multiplies
		 screen_red = 1 - screen_red; //inverts product
		 screen_red = screen_red * 255.0f; //denormalize
		 screen_red = screen_red + .5f;//error correction

		 //double check
		 if ((int)screen_red < 0)
		 {
			 screen_red= 0;
		 }
		 else if ((int)screen_red> 255)
		 {
			 screen_red = 255;
		 }

		 bottom.v_image.at(i).set_blue((unsigned char)(screen_blue));
		 bottom.v_image.at(i).set_green((unsigned char)(screen_green));
		 bottom.v_image.at(i).set_red((unsigned char)(screen_red));
	 }
	 return bottom;
 }

 image image::overlay(image& top, image& bottom)
 {
	 double overlay_blue = 0;
	 double overlay_green = 0;
	 double overlay_red = 0;
	 double overlay_blue_b = 0;
	 double overlay_green_b = 0;
	 double overlay_red_b = 0;
	 for (unsigned int i = 0; i < bottom.getsize(); i++)
	 {
		 //blue layer
		 overlay_blue = (double)top.v_image.at(i).get_blue();
		 overlay_blue = overlay_blue / 255.0f;

		 overlay_blue_b = (double)bottom.v_image.at(i).get_blue();
		 overlay_blue_b = overlay_blue_b / 255.0f;

		 if (overlay_blue_b <= .5f)
		 {
			 overlay_blue_b = 2 * overlay_blue * overlay_blue_b;
			 overlay_blue_b = overlay_blue_b * 255.0f;
			 overlay_blue_b = overlay_blue_b + .5f;
		 }
		 else if (overlay_blue_b >= .5f)
		 {
			 overlay_blue = 1 - overlay_blue;
			 overlay_blue_b = 1 - overlay_blue_b;

			 overlay_blue_b = overlay_blue_b * overlay_blue;

			 overlay_blue_b = 2 * overlay_blue_b;

			 overlay_blue_b = 1 - overlay_blue_b;

			 overlay_blue_b = overlay_blue_b * 255.0f;

			 overlay_blue_b = overlay_blue_b + .5f;
		 }

		 if ((int)overlay_blue_b > 255)
		 {
			 overlay_blue_b = 255;
		 }
		 else if ((int)overlay_blue_b < 0)
		 {
			 overlay_blue_b = 0;
		 }

		 //green layer
		 overlay_green = (double)top.v_image.at(i).get_green();
		 overlay_green = overlay_green / 255.0f;

		 overlay_green_b = (double)bottom.v_image.at(i).get_green();
		 overlay_green_b = overlay_green_b / 255.0f;

		 if (overlay_green_b <= .5f)
		 {
			 overlay_green_b = 2 * overlay_green* overlay_green_b;
			 overlay_green_b = overlay_green_b * 255.0f;
			 overlay_green_b = overlay_green_b + .5f;
		 }
		 else if (overlay_green_b >= .5f)
		 {
			 overlay_green = 1 - overlay_green;
			 overlay_green_b = 1 - overlay_green_b;

			 overlay_green_b = overlay_green_b * overlay_green;

			 overlay_green_b = 2 * overlay_green_b;

			 overlay_green_b = 1 - overlay_green_b;

			 overlay_green_b = overlay_green_b * 255.0f;

			 overlay_green_b = overlay_green_b + .5f;
		 }

		 if ((int)overlay_green_b > 255)
		 {
			 overlay_green_b = 255;
		 }
		 else if ((int)overlay_green_b < 0)
		 {
			 overlay_green_b = 0;
		 }

		 //red layer
		 overlay_red = (double)top.v_image.at(i).get_red();
		 overlay_red = overlay_red / 255.0f;

		 overlay_red_b = (double)bottom.v_image.at(i).get_red();
		 overlay_red_b = overlay_red_b / 255.0f;

		 if (overlay_red_b <= .5f)
		 {
			 overlay_red_b = 2 * overlay_red * overlay_red_b;
			 overlay_red_b = overlay_red_b * 255.0f;
			 overlay_red_b = overlay_red_b + .5f;
		 }
		 else if (overlay_red_b >= .5f)
		 {
			 overlay_red = 1 - overlay_red;
			 overlay_red_b = 1 - overlay_red_b;

			 overlay_red_b = overlay_red_b * overlay_red;

			 overlay_red_b = 2 * overlay_red_b;

			 overlay_red_b = 1 - overlay_red_b;

			 overlay_red_b = overlay_red_b * 255.0f;

			 overlay_red_b = overlay_red_b + .5f;
		 }

		 if ((int)overlay_red_b > 255)
		 {
			 overlay_red_b = 255;
		 }
		 else if ((int)overlay_red_b < 0)
		 {
			 overlay_red_b = 0;
		 }
		 bottom.v_image.at(i).set_blue((unsigned char)overlay_blue_b);
		 bottom.v_image.at(i).set_green((unsigned char)overlay_green_b);
		 bottom.v_image.at(i).set_red((unsigned char)overlay_red_b);
	 }


	 return bottom;
 }

 void image::edit_header()
 {
	 this->id_length = ID_LENGTH;
	 this->color_map_type = COLOR_MAP_TYPE;
	 this->image_type = DATA_TYPE_CODE;
	 this->color_map_length = COLOR_MAP_LENGTH;
	 this->pixel_depth = BPP;
	 
 }

 void image::add_color(unsigned char red_, unsigned char green_, unsigned char blue_)
 {
	 int blue = 0;
	 int green = 0;
	 int red = 0;
	 for (unsigned int i = 0; i < this->getsize(); i++)
	 {
		 blue = this->v_image.at(i).get_blue();
		 green = this->v_image.at(i).get_green();
		 red = this->v_image.at(i).get_red();

		 if (blue + blue_ > 255)
		 {
			 blue = 255;
		 }
		 else
		 {
			 blue = blue + blue_;
		 }
		 if (green + green_ > 255)
		 {
			 green = 255;
		 }
		 else
		 {
			 green = green + green_;
		 }
		 if (red + red_ > 255)
		 {
			 red = 255;
		 }
		 else
		 {
			 red = red + red_;
		 }

		 this->v_image.at(i).set_blue((unsigned char)blue);
		 this->v_image.at(i).set_green((unsigned char)green);
		 this->v_image.at(i).set_red((unsigned char)red);
	 }
	 /*
	 for (unsigned int i = 0; i < header_f.getsize(); i++)
	 {
		 file_write.write((char*)&header_f.v_image.at(i).get_green(), CHAR);

		 file_write.write((char*)&header_f.v_image.at(i).get_red(), CHAR);

		 file_write.write((char*)&header_f.v_image.at(i).get_blue(), CHAR);

		 //file_write.write((char*)&header_f.v_image.at(i).get_green(), CHAR);

		 //file_write.write((char*)&header_f.v_image.at(i).get_red(), CHAR);
	 }
	 */

 }

 void image::clear()
 {
	 this->v_image.clear();
 }

 void image::create_blank_file(std::string name, header& header_f)
 {
	// enum COLOR {BLUE = 255, RED = 255, GREEN = 255};
	 image image_f;
	 //std::ofstream file_write(name, std::ios_base::binary);
	 pixel pixel_Data;
	 /*
	 * read id length: 1 byte
	 * read color map type: 1 byte
	 * read image type: 1 byte
	 * read color map origin: 2 bytes
	 * color map length: 2 bytes
	 * color map depth: 1 byte
	 * x origin: 2 byte
	 * y origin: 2 bytes
	 * read width: 2 bytes
	 * read height: 2 bytes
	 * read pixel depth: 1 bytes
	 * read image descriptor: 1 byte
	 */
	 image_f.id_length = header_f.id_length;
	 image_f.color_map_type = header_f.color_map_type;
	 image_f.image_type = header_f.image_type;
	 image_f.color_map_origin = header_f.color_map_origin;
	 image_f.color_map_length = header_f.color_map_length;
	 image_f.color_map_depth = header_f.color_map_depth;
	 image_f.x_origin = header_f.x_origin;
	 image_f.y_origin = header_f.y_origin;
	 image_f.width = header_f.width;
	 image_f.height = header_f.height;
	 image_f.pixel_depth = header_f.pixel_depth;
	 image_f.image_descriptor = header_f.image_descriptor;

	 for (unsigned int i = 0; i < (image_f.height)*(image_f.width); i++)
	 {
		 
		 pixel_Data.set_blue(MAX);
		 pixel_Data.set_green(MAX);
		 pixel_Data.set_red(MAX);
		 
		 image_f.addpixel(pixel_Data);
	 }

	 write_with_name(name, image_f);
 }

