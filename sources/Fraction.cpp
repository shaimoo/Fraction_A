#include "Fraction.hpp"
using namespace std;
namespace ariel{

    Fraction::Fraction():number1(0),number2(1){}
    Fraction::Fraction(int num1, int num2):number1(num1),number2(num2) {
        if (num2 == 0 ){
            throw "cant split at 0 ";
        }
     }

    ostream& operator<<(ostream& r, const Fraction &f) {
    r << "(" << f.number1 << "/" << f.number2  << ")";
    return r;
}

Fraction Fraction::operator+(double temp) const{
    Fraction result(1,1);
    result.double_to_fraction(temp);
    return (*this)+result;
}

Fraction Fraction::operator+(const Fraction &temp) const {
    int mone = number1 * temp.number2  + number2 * temp.number1;
    int mehane = number2 * temp.number2;
    if (mone == mehane){
        return Fraction(1,1);
    }
    Fraction result(mone,mehane);
    result.reduce();
    return result;
}


Fraction Fraction::operator-(const Fraction &temp) const {
    int mone = number1 * temp.number2  - number2 * temp.number1;
    int mehane = number2 * temp.number2;
    if (mone == mehane){
        return Fraction(1,1);
    }
    Fraction result(mone,mehane);
    result.reduce();
    if(result.number2<0){
        result.number2 *= -1;
        result.number1 *= -1;
    }
    return result;
}

Fraction Fraction::operator+=(const Fraction &temp)  {
    *this = *this+temp;
    return *this;
}

Fraction Fraction::operator-=(const Fraction &temp)  {
    *this = *this-temp;
    return *this;
}

Fraction& Fraction::operator++() {
    number1 += number2;
    return *this;
}

const Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    number1 += number2;
    return temp;
}

Fraction &Fraction::operator--() {
    number1-= number2;
    return *this;
}

const Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    number1-= number2;
    return temp;
}

Fraction Fraction::operator/(const Fraction &temp) const {
    if (temp.number1 == 0 ){
        throw "cant divide by zero";
    }
    Fraction result(number1*temp.number2,number2*temp.number1);
    result.reduce();
    return result;

}

Fraction Fraction::operator*(const Fraction &temp)  const {
    Fraction result(number1*temp.number1,number2*temp.number2);
    result.reduce();
    return result;

}

Fraction Fraction::operator-(double temp) const {
    Fraction result(1,1);
    result.double_to_fraction(temp);
    return (*this)-result;
}

int Fraction::get_number1() {
    return number1;
}

int Fraction::get_number2() {
    return number2;
}


    Fraction Fraction::operator*(double temp) const {
        Fraction result(1,1);
        result.double_to_fraction(temp);
        return result;
    }





    bool Fraction::operator>=(const Fraction &temp1) const {
    double x = double(temp1.number1) / double(temp1.number2);
    double y = double(number1)/double (number2);
    return y>=x;
}

bool Fraction::operator>(double temp) const {
    double result = double(number1)/double(number2);
    return result>temp;
}

bool Fraction::operator>(const Fraction &temp1) const {
    double result = double(temp1.number1)/double(temp1.number2);
    return *this>result;
}

    Fraction operator*(double temp, const Fraction &frank) {
        return frank*temp;
    }


    void Fraction::reduce() {
        int gcdVal = gcd(number1, number2); // Use different variable name
        number1 /= gcdVal;
        number2 /= gcdVal;

    }

    int Fraction::gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    void Fraction::double_to_fraction(double temp) {
        double epsilon = 1e-8; // small epsilon value for double comparison
        if (temp > 0) {
            int full = static_cast<int>(temp);
            temp -= full;
            int mone = 0, mehane = 1;
            int digit = 0;
            while (std::abs(temp) > epsilon) {
                temp *= 10;
                digit = static_cast<int>(temp + epsilon);
                mone = mone * 10 + digit;
                mehane *= 10;
                temp -= digit;
            }
            number1 = mone + full * mehane;
            number2 = mehane;
        } else if (temp < 0) {
            // Handling negative values of temp
            int full = static_cast<int>(std::abs(temp));
            temp = std::abs(temp) - full;
            int mone = 0, mehane = 1;
            int digit = 0;
            while (std::abs(temp) > epsilon) {
                temp *= 10;
                digit = static_cast<int>(std::abs(temp + epsilon));
                mone = mone * 10 + digit;
                mehane *= 10;
                temp -= digit;
            }
            number1 = -(mone + full * mehane);
            number2 = mehane;
        } else {
            number1 = 0;
            number2 = 1; // set denominator to 1 for whole numbers
        }
    }


}