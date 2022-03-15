#pragma once
class pixel
{
public:

	const unsigned char& get_blue() const;
	const unsigned char& get_green() const;
	const unsigned char& get_red() const;
	unsigned char& get_blue();
	unsigned char& get_green();
	unsigned char& get_red();
	void set_blue(const unsigned char);
	void set_green(const unsigned char);
	void set_red(const unsigned char);

	void add_blue(const unsigned char);
	void add_green(const unsigned char);
	void add_red(const unsigned char);

private:

	unsigned char blue;
	unsigned char green;
	unsigned char red;

};
