#ifndef FRACTION
#define FRACTION
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

namespace ariel
{

class Fraction{
private:
        int number1;
        int number2;
public:
    /// constructors
    Fraction();
    Fraction(int num1 , int num2);

    void reduce();
    int gcd(int a, int b);
    void double_to_fraction(double temp);
    ///gets
    int get_number1();
    int get_number2();

    /// one operator
    Fraction operator+(const Fraction& temp) const;
    Fraction operator+(double temp ) const;
    Fraction operator-(const Fraction& temp) const;
    Fraction operator-(double temp) const;
    Fraction operator*(double temp) const;
    friend Fraction operator*(double temp ,const Fraction& frank);
    Fraction operator/(const Fraction& temp) const;
    Fraction operator*(const Fraction& temp) const;


    /// add operator to object
    Fraction operator+=(const Fraction& temp);
    Fraction operator-=(const Fraction& temp);
    Fraction& operator++(); //prefix increment
    const Fraction operator++(int); //postfix increment
    Fraction& operator--(); //prefix increment
    const Fraction operator--(int); //postfix increment


    /// bool operators comper
     bool operator>(double temp) const;
     bool operator>(const Fraction& temp1) const;
     bool operator>=(const Fraction& temp1) const;

    /// overload operator
    friend ostream& operator<<(ostream& r,const Fraction& f);
};



}
#endif