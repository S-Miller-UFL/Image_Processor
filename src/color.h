#pragma once
template <typename T>
struct color
{
	T normalize(const T, const T);
};

template<typename T>
T color<T>::normalize(const T value_, const T value_1)
{
	T temp;
	temp = value_ * value_1;

	temp = temp / 255;
	temp = temp;
	
	return temp;
}
