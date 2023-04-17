#include "sources//Fraction.hpp"
#include "doctest.h"
#include <stdexcept>

namespace  ariel{
Fraction a(5,5),b(10,60);

TEST_CASE("testing operator +"){
    CHECK_NOTHROW(Fraction c =a+b);
    Fraction c =a+b;
    CHECK_EQ(c.get_number1(),7);
    CHECK_EQ(c.get_number2(),6);

}
    TEST_CASE("testing operator ++"){
        Fraction c =a++;
        CHECK_EQ(c.get_number1(),5);
        CHECK_EQ(a.get_number1(),10);
        CHECK_EQ(c.get_number2(),a.get_number2());
        CHECK_NOTHROW(c++);
    }
    TEST_CASE("testing operator ++"){
        Fraction c = ++b;
        CHECK_EQ(c.get_number1(),70);
        CHECK_EQ(c.get_number2(),b.get_number2());
        CHECK_NOTHROW(++c);
    }

    TEST_CASE("testing operator -"){
        CHECK_NOTHROW(Fraction c =a-b);
        Fraction c =a-b;
        CHECK_EQ(c.get_number1(),5);
        CHECK_EQ(c.get_number2(),6);
    }
    TEST_CASE("testing operator --"){
        Fraction c = --b;
        CHECK_NOTHROW(--c);
        CHECK_EQ(c.get_number1(),-50);
    }
    TEST_CASE("testing operator --"){
        Fraction c = b--;
        CHECK_NOTHROW(c--);
        CHECK_EQ(c.get_number1(),-50);
    }
    TEST_CASE("testing operator *"){
        CHECK_NOTHROW(1.23*a);
        CHECK_NOTHROW(a*1.23);
        CHECK_NOTHROW(a*b);
        a=a*0;
        CHECK_EQ(a.get_number1(),0);
    }
    TEST_CASE("testing operator /"){
        CHECK_NOTHROW(a/b);
        Fraction c = a/b;
        CHECK_EQ(c.get_number1(),0);
    }

    TEST_CASE("check split zero"){
        CHECK_THROWS(Fraction(0,0));
    }

    TEST_CASE("testing operator +="){
        Fraction c = b;
        CHECK_NOTHROW(c+=c);
        b+=b;
        CHECK_EQ(c.get_number1(),b.get_number1());
    }

    TEST_CASE("testing operator -="){
        Fraction c = b;
        CHECK_NOTHROW(c-=c);
        c-=c;
        CHECK_EQ(c.get_number1(),0);
    }
    TEST_CASE("testing operator >"){
        Fraction c = b;
        CHECK(a>c);
    }
    TEST_CASE("testing operator >="){
        Fraction c = b;
        CHECK_FALSE(c>=a);
        CHECK(a>=a);
    }
    TEST_CASE("testing operator <<"){
        Fraction c = a+b;
        CHECK_NOTHROW(cout << "a: " << a << "b: " << b << "c:"<< c);
        CHECK(a>=a);
    }
    TEST_CASE("testing operator + double"){
        CHECK_NOTHROW(a+5.45);
    }
    TEST_CASE("testing operator - double"){
        CHECK_NOTHROW(a-5.45);
    }
}