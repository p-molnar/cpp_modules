#ifndef FIXED_HPP
#define FIXED_HPP

#define BIT_SIZE 8
#define ABS(N) ((N < 0) ? (-N) : (N))

#include <iostream>

void print_bin(int bin);

class Fixed
{
private:
	int num;
	int width;
	static const int fractional_bits = 8;

	int toFixedPoint(const int n, const int width, const int bin_point_pos);
	int toFixedPoint(const float n, const int width, const int bin_point_pos);

public:
	// constructors
	Fixed(void);
	Fixed(const float val);
	Fixed(const int n);

	// copy & assign operators
	Fixed(Fixed const &obj);
	Fixed &operator=(const Fixed &obj);

	// destructor
	~Fixed(void);

	int getRawBits(void) const;
	int getWidth(void) const;
	int getFractionalBits(void) const;
	void setRawBits(const int n);

	float toFloat(void) const;
	int toInt(void) const;

	// logical operator overloads
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;

	// arithmetic operator overloads
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	Fixed operator++(void);
	Fixed operator++(int);
	Fixed operator--(void);
	Fixed operator--(int);

	static Fixed &min(Fixed &obj1, Fixed &obj2);
	static const Fixed &min(const Fixed &obj1, const Fixed &obj2);
	static Fixed &max(Fixed &obj1, Fixed &obj2);
	static const Fixed &max(const Fixed &obj1, const Fixed &obj2);

	// utility function
	static int getTwosComplement(int n, int width, int bin_point_pos);
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif
