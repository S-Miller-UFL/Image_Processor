#include "image.h"
#include <fstream>
#include <iostream>
#include <vector>
//////////////////////////////////
//constant macros
//MUST REMAIN DEFINED AS THEY CURRENTLY ARE
#define ID_LENGTH 0
#define COLOR_MAP_TYPE 0
#define DATA_TYPE_CODE 2
#define COLOR_MAP_LENGTH 0
#define BPP 24
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
	const short BYTE_SIZE = 1;
	//color_obj get_color;
	//pixel get_pixel;
	//read image header
	std::ifstream image(file_name, std::ios_base::binary); //declare ifstream object

	image.read(&file.id_length, 1);//read id length

	image.read(&file.color_map_type, 1); //read color map type

	image.read(&file.image_type, 1); //read image type

	image.read((char*)&file.color_map_origin, 2); //read color map origin

	image.read((char*)&file.color_map_length, 2); //read color map length

	image.read(&file.color_map_depth, 1); //read color map depth

	image.read((char*)&file.x_origin, 2); //read x origin

	image.read((char*)&file.y_origin, 2); //read y origin

	image.read((char*)&file.width, 2); //read width

	image.read((char*)&file.height, 2); //read height

	image.read(&file.pixel_depth, 1); //read pixel depth

	image.read(&file.image_descriptor, 1); //read image descriptor

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
		image.read((char*)&blue, BYTE_SIZE);
		image.read((char*)&green, BYTE_SIZE);
		image.read((char*)&red, BYTE_SIZE);
		pixel_Data.set_blue(blue);
		pixel_Data.set_green(green);
		pixel_Data.set_red(red);
		file.addpixel(pixel_Data);
	}
	
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
	enum bytes { CHAR = 1, SHORT = 2 };
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
	//image header_f;
	//image pixels;
	
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
	unsigned char BLUE = 255;
	unsigned char GREEN = 255;
	unsigned char RED = 255;
	for (unsigned int i = 0; i < this->getsize(); i++)
	{
		//if even, set to green
		if (i % 2 == 0)
		{
			BLUE = 0;
			GREEN = 255;
			RED = 0;
			this->v_image.at(i).set_blue((unsigned char)0);
			//cout << sizeof((unsigned char)0) << endl;
			//cout << sizeof(this->v_image.at(i).get_blue()) << endl;
			this->v_image.at(i).set_green((unsigned char)255);

			this->v_image.at(i).set_red((unsigned char)0);
		}
		//if odd, set to blue
		else if (i % 3 == 0)
		{
			BLUE = 0;
			GREEN = 0;
			RED = 255;
			this->v_image.at(i).set_blue((unsigned char)255);

			this->v_image.at(i).set_green((unsigned char)0);

			this->v_image.at(i).set_red((unsigned char)0);
		}
		//if neither, set to red
		else
		{
			BLUE = 0;
			RED = 0;
			GREEN = 255;
			this->v_image.at(i).set_blue((unsigned char)0);

			this->v_image.at(i).set_green((unsigned char)0);

			this->v_image.at(i).set_red((unsigned char)255);

		}
	}
}
/*
image image::create_new_header(string name, char id_length, char color_map_type, char image_type, short color_map_origin, short color_map_length, char color_map_depth, short x_origin, short y_origin, short width, short height, char pixel_depth, char image_descriptor)
{
	std::ofstream file_write(name, ios_base::binary);

	enum BYTES { CHAR = 1, SHORT = 2 };

	file_write.write(&id_length, CHAR);

	file_write.write(&color_map_type, CHAR);

	file_write.write(&image_type, CHAR);

	file_write.write((char*)&color_map_origin, SHORT);

	file_write.write((char*)&color_map_length, SHORT);

	file_write.write(&color_map_depth, CHAR);

	file_write.write((char*)&x_origin, SHORT);

	file_write.write((char*)&y_origin, SHORT);

	file_write.write((char*)&width, SHORT);

	file_write.write((char*)&height, SHORT);

	file_write.write(&pixel_depth, SHORT);

	file_write.write(&image_descriptor, CHAR);


}
*/
 void image::copy_to_file_create_new(std::string name, image& file_to_copy ,image& copied_file)
 {
	
 }

 void image::copy_to_file(const image& file_to_copy, image& copied_file)
 {
	// copied_file.

 }

 header image::create_header(char id_length, char color_map_type, char image_type, short color_map_origin, short color_map_length, char color_map_depth, short x_origin, short y_origin, short width, short height, char pixel_depth, char image_descriptor)
 {
	 enum bytes { CHAR = 1, SHORT = 2 };
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

 void image::create_blank_file(std::string name, header& header_f)
 {
	 enum COLOR {BLUE = 255, RED = 255, GREEN = 255};
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
		 pixel_Data.set_blue(BLUE);
		 pixel_Data.set_green(GREEN);
		 pixel_Data.set_red(RED);
		 image_f.addpixel(pixel_Data);
	 }

	 write_with_name(name, image_f);
 }

