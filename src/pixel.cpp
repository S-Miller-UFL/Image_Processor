#include "pixel.h"
unsigned char& pixel::get_blue()
{
	return this-> blue;
}

unsigned char& pixel::get_green()
{
	return this-> green;
}

unsigned char& pixel::get_red()
{
	return this-> red;
}
const unsigned char& pixel::get_blue() const
{
	return this-> blue;
}

const unsigned char& pixel::get_green() const
{
	return this-> green;
}

const unsigned char& pixel::get_red() const
{
	return this-> red;
}
void pixel::set_blue(const unsigned char value)
{
	this->blue = value;
}

void pixel::set_green(const unsigned char value)
{
	this->green = value;
}

void pixel::set_red(const unsigned char value)
{
	this->red = value;
}

void pixel::add_blue(const unsigned char value)
{
	this->blue = this->blue + value;
}

void pixel::add_green(const unsigned char value)
{
	this->green = this->green + value;
}

void pixel::add_red(const unsigned char value)
{
	this->red = this->red + value;
}

