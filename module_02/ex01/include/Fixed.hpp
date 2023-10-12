#ifndef FIXED_HPP
#define FIXED_HPP

#define BIT_SIZE 8

class Fixed
{
private:
	int fixed_point_val;
	static const int fractional_bits = 8;

	int toFixedPoint(const int val,
					 const int width,
					 const int bin_point_pos);

	int toFixedPoint(const float val,
					 const int width,
					 const int precision_point_pos);

	int getTwosComplement(int binary);

public:
	Fixed(const float val);
	Fixed(const int val);
	Fixed(Fixed &num);

	float operator<<(int fixed_point_val);
	Fixed &operator=(const Fixed &fraction);

	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

#endif
