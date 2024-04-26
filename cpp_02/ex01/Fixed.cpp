#include "Fixed.hpp"

const int Fixed::fraction_bits = 8;

Fixed::Fixed(void)
: number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->number = number << this->fraction_bits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->number = roundf(number * (1 << this->fraction_bits));
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->number = obj.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->number = obj.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->number);
}

void	Fixed::setRawBits(int const raw)
{
	this->number = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << this->fraction_bits));
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->fraction_bits);
}

std::ostream& operator<<(std::ostream& output_stream, const Fixed& fixed)
{
	output_stream << fixed.toFloat();
	return (output_stream);
}
