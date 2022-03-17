#include <iostream>
#include "test.h"

bool test::test_compare_images(const image& image_1, const image& image_2) const
{
	bool correct = true;
	if (image_1.getsize() != image_2.getsize())
	{
		std::cout << "images are not same size!" << std::endl;
		return false;
	}
	
	else
	{
		for (unsigned int i = 0; i < image_1.getsize(); i++)
		{
			if (image_1.get_pixel(i).get_blue() != image_2.get_pixel(i).get_blue())
			{
				/*
				std::cout << "image 1, pixel number " << i << " value for blue is: " << (int)image_1.get_pixel(i).get_blue() << std::endl;
				std::cout << "image 2, pixel number " << i << " value for blue is: " << (int)image_2.get_pixel(i).get_blue() << std::endl;
				std::cout << std::endl;
				*/
				correct = false;
			}
			if (image_1.get_pixel(i).get_green() != image_2.get_pixel(i).get_green())
			{
				/*
				std::cout << "image 1, pixel number " << i << " value for green is: " << (int)image_1.get_pixel(i).get_green() << std::endl;
				std::cout << "image 2, pixel number " << i << " value for green is: " << (int)image_2.get_pixel(i).get_green() << std::endl;
				std::cout << std::endl;
				*/
				correct = false;
			}
			if (image_1.get_pixel(i).get_red() != image_2.get_pixel(i).get_red())
			{
				/*
				std::cout << "image 1, pixel number " << i << " value for red is: " << (int)image_1.get_pixel(i).get_red() << std::endl;
				std::cout << "image 2, pixel number " << i << " value for red is: " << (int)image_2.get_pixel(i).get_red() << std::endl;
				std::cout << std::endl;
				*/

				correct = false;
			}

		}
	}
		return correct;
}
