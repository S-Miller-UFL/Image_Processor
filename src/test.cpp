#include "test.h"

bool test::test_compare_images(const image& image_1, const image& image_2) const
{
	if (image_1.getsize() != image_2.getsize())
	{
		return false;
	}
	else
	{
		for (unsigned int i = 0; i < image_1.getsize(); i++)
		{
			if (image_1.get_pixel(i).get_blue() != image_2.get_pixel(i).get_blue())
			{
				return false;
			}
			if (image_1.get_pixel(i).get_green() != image_2.get_pixel(i).get_green())
			{
				return false;
			}
			if (image_1.get_pixel(i).get_red() != image_2.get_pixel(i).get_red())
			{
				return false;
			}

		}
	}
	return true;
}
