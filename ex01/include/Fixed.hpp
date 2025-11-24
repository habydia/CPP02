#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>
# include <ostream>
# include <string>

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

	// const constructor for int
	Fixed(const int intValue);
	// const constructor for float
	Fixed(const float floatValue);

	// // COPY assignment operator overload
	// Fixed &operator=(const Fixed &other);
	// destructor
	~Fixed();

	// getters/setters
	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP