#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int fpv;							  // fixed point value
	static const int fractional_bits = 8; // number of fractional bits

public:
	Fixed(void);
	Fixed(Fixed &num);
	Fixed &operator=(const Fixed &fraction);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
