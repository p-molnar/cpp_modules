#ifndef FIXED_HPP
#define FIXED_HPP

#define BIT_SIZE 8

#include <iostream>

void print_bin(int bin);

class Fixed
{
private:
	int fixed_point_val;
	int width;
	static const int fractional_bits = 8;

	int toFixedPoint(const int n, const int width, const int bin_point_pos);
	int toFixedPoint(const float n, const int width, const int bin_point_pos);
	int getTwosComplement(int binary, int width, const int bin_point_pos);

public:
	Fixed(void);
	Fixed(const float val);
	Fixed(const int n);
	Fixed(Fixed const &obj);
	Fixed &operator=(const Fixed &obj);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(const int n);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif
