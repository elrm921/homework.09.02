#include <iostream>
#include <numeric>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
        int gcd = std::gcd(numerator, denominator);
        int recalc_num = (numerator / gcd);
        int recalc_den = (denominator / gcd);
		numerator_ = recalc_num;
		denominator_ = recalc_den;
	}
    friend std::ostream &operator <<(std::ostream &output, const Fraction &fraction) {
        if (fraction.numerator_ % fraction.denominator_ == 0) {
            output << std::to_string(fraction.numerator_ / fraction.denominator_);
        }
        else {
            output << std::to_string(fraction.numerator_) + "/" + std::to_string(fraction.denominator_);
        }
        return output;
    }
    Fraction operator +(const Fraction &other) const {
        int num = (numerator_ * other.denominator_) + (other.numerator_ * denominator_);
        int den = (denominator_ * other.denominator_);
        Fraction result(num, den);
        return result;
    }
    Fraction operator *(const Fraction &other) const {
        int num = (numerator_ * other.numerator_);
        int den = (denominator_ * other.denominator_);
        Fraction result(num, den);
        return result;
    }
    Fraction operator-() const {
        Fraction result = (*this) * Fraction(-1,1);
        return result;
    }
    Fraction operator -(const Fraction &other) const {
        Fraction result = (*this) + (-other);
        return result;
    }
    Fraction operator /(const Fraction &other) const {
        Fraction result = (*this) * Fraction(other.denominator_,other.numerator_);
        return result;
    }
    Fraction operator ++() {
        (*this) = (*this) + Fraction(1,1);
        return *this;
    }
    Fraction operator --() {
        (*this) = (*this) + Fraction(-1,1);
        return *this;
    }
    Fraction operator ++(int) {
        Fraction temp = *this;
        (*this) = (*this) + Fraction(1,1);
        return temp;        
    }
    Fraction operator --(int) {
        Fraction temp = *this;
        (*this) = (*this) + Fraction(-1,1);
        return temp;      
    }
};

int main()
{
    int f11, f12;
    int f21, f22;

    std::cout << "Введите числитель дроби 1: ";
    std::cin >> f11;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> f12;
    std::cout << "Введите числитель дроби 2: ";
    std::cin >> f21;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> f22; 

	Fraction f1(f11, f12);
	Fraction f2(f21, f22);
    Fraction f3(1, 1);

	std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << "\n";
    std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << "\n";
    std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << "\n";
    std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << "\n";
    std::cout << "++" << f1 << " * " << f2 << " = ";
    f3 = ++f1;
    std::cout << (f1 * f2) << "\n" << "Значение дроби 1 = " << f3 << "\n";
    std::cout << f1 << "--" << " * " << f2 << " = ";
    f3 = f1--;
    std::cout << (f1 * f2) << "\n" << "Значение дроби 1 = " << f3 << "\n";
    
	return 0;
}