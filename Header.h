#pragma once
#include <cmath>
#include <iostream>
#define M_PI 3.14159265358979323846

using namespace std;

class Complex  // класс "Комплексное число"
{
private:
    double re, im;  // действительная и мнимая части

public:
    // конструкторы

    Complex(const double& r = 0, const double& i = 0) {
        re = r;
        im = i;
    }

    Complex(const Complex& c) = default;  // конструктор копирования

    double getRe() const { return re; }           // геттер для re
    void setRe(const double& re_n) { re = re_n; }  // сеттер для er

    double getIm() const { return im; }           // геттер для im
    void setIm(const double& im_n) { im = im_n; }  // сеттер для im

    // Модуль комплексного числа
    double abs() const { return sqrt(re * re + im * im); }

    // оператор присваивания
    Complex operator=(const Complex& c) {
        re = c.re;
        im = c.im;

        return (*this);
    }

    // оператор +=
    Complex& operator+=(const Complex& c) {
        re += c.re;
        im += c.im;
        return *this;
    }

    Complex& operator-=(const Complex& c) {
        re -= c.re;
        im -= c.im;
        return *this;
    }

    // оператор сложения
    Complex operator+(const Complex& c) const { return Complex(re + c.re, im + c.im); }
    // RVO
    // оператор вычитания
    Complex operator-(const Complex& c) const { return Complex(re - c.re, im - c.im); }

    Complex operator-() const {
        Complex c(-re, -im);
        return c;
    }

    Complex operator+() const {
        Complex c(re, im);
        return c;
    }

    // оператор умножения
    Complex operator*(const Complex& c) const {
        return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    }

    Complex& operator*=(const Complex& c) {
        *this = *this * c;
        return *this;
    }

    // оператор деления ДА КАК СДЕЛАТЬ ДОСТАЛО
    Complex operator/(const Complex& c) const {
        double k = c.re * c.re + c.im * c.im;
        return Complex((re * c.re + im * c.im) / k, (im * c.re - re * c.im) / k);
    }

    Complex& operator/=(const Complex& c) {
        *this = *this / c;
        return *this;
    }


    double argRad() const {
        if ((re == 0.0) && (im == 0.0)) return 0.0;
        if (re == 0.0) {
            if (im > 0)
                return M_PI / 2.0;
            else
                return -M_PI / 2.0;
        }
        else if (re > 0.0)
            return atan(im / re);
        else {
            if (im >= 0)
                return M_PI + atan(im / re);
            else
                return -M_PI + atan(im / re);
        }
    }

    Complex pow(int n) {
        Complex temp(*this);
        for (int i = 1; i < n; i++) {
            temp *= *this;
        }
        return temp;
    }

    bool operator==(Complex C) const { return (re == C.getRe()) && (im == C.getIm()); }

    bool operator!=(Complex C) const { return (re != C.getRe()) || (im != C.getIm()); }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.re << " + " << c.im << "i";
        return out;
    }
};