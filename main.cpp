#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
    int gcd(int a, int b) {
        return (b == 0 ? a : gcd(b, a % b));
    }
    Fraction recalc() {
        int cd = gcd(numerator_, denominator_);
        int temp_num = (numerator_ / cd);
        int temp_den = (denominator_ / cd);
        if (numerator_ > 0 && denominator_ < 0) {
            temp_num *= -1;
            temp_den *= -1;
        }
        Fraction result(temp_num, temp_den);
        return result;
    }
    Fraction reverse() const {
        int temp_num = denominator_;
        int temp_den = numerator_;
        Fraction result(temp_num, temp_den);
        return result;
    }
    Fraction negative() const {
        int temp_num = numerator_;
        int temp_den = denominator_;
        Fraction result(temp_num * -1, temp_den);
        return result;
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
    Fraction operator +(const Fraction &other) {
        int num = (numerator_ * other.denominator_) + (other.numerator_ * denominator_);
        int den = (denominator_ * other.denominator_);
        Fraction result(num, den);
        return result.recalc();
    }
    Fraction operator *(const Fraction &other) {
        int num = (numerator_ * other.numerator_);
        int den = (denominator_ * other.denominator_);
        Fraction result(num, den);
        return result.recalc();
    }
    Fraction operator -(const Fraction &other) {
        Fraction result = (*this) + other.negative();
        return result.recalc();
    }
    Fraction operator /(const Fraction &other) {
        Fraction result = (*this) * other.reverse();
        return result.recalc();
    }
    Fraction operator ++() {
        Fraction result = (*this) + Fraction(1,1);
        return result.recalc();
    }
    Fraction operator --() {
        Fraction result = (*this) + Fraction(-1,1);
        return result.recalc();
    }
    Fraction operator ++(int) {
        return ++(*this);        
    }
    Fraction operator --(int) {
        return --(*this);
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
    std::cout << (f3 * f2) << "\n" << "Значение дроби 1 = " << f3 << "\n";
    std::cout << f1 << "--" << " * " << f2 << " = ";
    f3 = f1--;
    std::cout << (f3 * f2) << "\n" << "Значение дроби 1 = " << f3 << "\n";
    
	return 0;
}