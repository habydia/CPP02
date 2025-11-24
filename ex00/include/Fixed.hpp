#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
  private:
	int fixedPointValue;
	static const int fractionalBits = 8;

  public:
	// default constructor
	Fixed();
	// copy constructor
	Fixed(const Fixed &other);
	~Fixed();
	// COPY assignment operator overload
	Fixed &operator=(const Fixed &other);
	// destructor

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif // FIXED_HPP