class Fixed
{
private:
	int fixed_point_val;
	static const int fractional_bits = 8;

public:
	Fixed(void);
	Fixed(Fixed &num);
	Fixed &operator=(const Fixed &fraction);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};