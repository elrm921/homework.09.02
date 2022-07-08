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
        if (b == 0) {
            return a;
        }
        else {
            return gcd(b, a % b);
        }
    }
    void recalc() {
        int cd = gcd(numerator_, denominator_);
        int r_num = (numerator_ / cd);
        int r_den = (denominator_ / cd);
        numerator_ = r_num;
        denominator_ = r_den;
    }
    std::string toString() {
        if (numerator_ == 0) {
            return std::to_string(0);
        }
        if ((numerator_ / denominator_ > 0) && (numerator_ % denominator_  == 0)) {
            return std::to_string(numerator_ / denominator_);
        }
        if ((numerator_ > 0 && denominator_ < 0) || (numerator_ < 0 && denominator_ > 0)) {
            return "-" + std::to_string(abs(numerator_)) + "/" + std::to_string(abs(denominator_));
        }
        else {
            return std::to_string(numerator_) + "/" + std::to_string(denominator_);
        }
    }
    Fraction operator +(Fraction other) {
        int r_num = (numerator_ * other.denominator_) + (other.numerator_ * denominator_);
        int r_den = (denominator_ * other.denominator_);
        Fraction result(r_num, r_den);
        result.recalc();
        return result;
    }
    Fraction operator -(Fraction other) {
        int r_num = (numerator_ * other.denominator_) - (other.numerator_ * denominator_);
        int r_den = (denominator_ * other.denominator_);
        Fraction result(r_num, r_den);
        result.recalc();
        return result;
    }
    Fraction operator *(Fraction other) {
        int r_num = (numerator_ * other.numerator_);
        int r_den = (denominator_ * other.denominator_);
        Fraction result(r_num, r_den);
        result.recalc();
        return result;
    }
    Fraction operator /(Fraction other) {
        int r_num = (numerator_ * other.denominator_);
        int r_den = (denominator_ * other.numerator_);
        Fraction result(r_num, r_den);
        result.recalc();
        return result;
    }
    Fraction operator ++(int) {
        numerator_ += 1 * denominator_;
        this->recalc();
        return *this;        
    }
    Fraction operator ++() {
        (*this)++;
        return *this;
    }
    Fraction operator --(int) {
        numerator_ -= 1 * denominator_;
        this->recalc();
        return *this;
    }
    Fraction operator --() {
        (*this)--;
        return *this;
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
    Fraction ff(0, 0);

	std::cout << f1.toString() << " + " << f2.toString() << " = " << (f1 + f2).toString() << "\n";
    std::cout << f1.toString() << " - " << f2.toString() << " = " << (f1 - f2).toString() << "\n";
    std::cout << f1.toString() << " * " << f2.toString() << " = " << (f1 * f2).toString() << "\n";
    std::cout << f1.toString() << " / " << f2.toString() << " = " << (f1 / f2).toString() << "\n";
    std::cout << "++" << f1.toString() << " * " << f2.toString() << " = ";
    ff = ++f1;
    std::cout << (ff * f2).toString() << "\n" << "Значение дроби 1 = " << ff.toString() << "\n";
    std::cout << f1.toString() << "--" << " * " << f2.toString() << " = ";
    ff = f1--;
    std::cout << (ff * f2).toString() << "\n" << "Значение дроби 1 = " << ff.toString() << "\n";
    
	return 0;
}