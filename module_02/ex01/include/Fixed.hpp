#ifndef FIXED_HPP
#define FIXED_HPP

#define BITE_SIZE 8
#define ABS(N) ((N < 0) ? (-N) : (N))

#include <iostream>

class Fixed
{
private:
	int fpv;							  // fixed point value
	int width;							  // width of fpv in bits
	static const int fractional_bits = 8; // number of fractional bits

	int toFixedPoint(const int n, const int width, const int bin_point_pos);
	int toFixedPoint(const float n, const int width, const int bin_point_pos);

public:
	Fixed(void);
	Fixed(const int num);
	Fixed(const float num);
	Fixed(Fixed const &obj);
	Fixed &operator=(const Fixed &obj);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(const int n);

	float toFloat(void) const;
	int toInt(void) const;

	static int getTwosComplement(int n, int width, const int bin_point_pos);
	static void printBin(int n);
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif
