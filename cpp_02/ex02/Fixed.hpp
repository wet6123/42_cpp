#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					number;
		static const int	fraction_bits;
	public:
		Fixed(void);
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed& obj);
		Fixed&	operator=(const Fixed& obj);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		bool	operator>(const Fixed& fixed) const;
		bool	operator<(const Fixed& fixed) const;
		bool	operator>=(const Fixed& fixed) const;
		bool	operator<=(const Fixed& fixed) const;
		bool	operator==(const Fixed& fixed) const;
		bool	operator!=(const Fixed& fixed) const;
		Fixed	operator+(const Fixed &obj) const;
		Fixed	operator-(const Fixed &obj) const;
		Fixed	operator*(const Fixed &obj) const;
		Fixed	operator/(const Fixed &obj) const;
		Fixed&	operator++(void);
		const	Fixed	operator++(int);
		Fixed&	operator--(void);
		const	Fixed	operator--(int);
		static Fixed	&min(Fixed &ref1, Fixed &ref2);
		static const Fixed	&min(const Fixed &ref1, const Fixed &ref2);
		static Fixed	&max(Fixed &ref1, Fixed &ref2);
		static const Fixed	&max(const Fixed &ref1, const Fixed &ref2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
