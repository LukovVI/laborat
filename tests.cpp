#include "catch.hpp"
#include "Header.h"
#include <complex>
#include <cmath>

bool is_equal(double x, double y) { return std::fabs(x - y) < 0.0000001; };

double listRe[] = { 4, 5.2, 6, -4, -8.9, 0, 3, 3.453, 7, -2.544, -4, 99 };
double listIm[] = { -3, 6.23, -8.32, 9.9, -3.22, 10.01, -1, -8.65, 2, -2, 8.232, 99 };

TEST_CASE("tescom", "[Complex]") {
	SECTION("KONCTRYKTOR, GETTER") {
		for (int i = 0; i < 12; i++) {
			Complex x(listRe[i], listIm[i]);
			REQUIRE(x.getRe() == listRe[i]);
			REQUIRE(x.getIm() == listIm[i]);
		}
	}
	SECTION("KOPIROVANIE") {
		for (int i = 0; i < 12; i++) {
			Complex x(listRe[i], listIm[i]);
			Complex y = x;
			REQUIRE(y.getRe() == listRe[i]);
			REQUIRE(y.getIm() == listIm[i]);
		}
	}
	SECTION("SETTER") {
		for (int i = 0; i < 12; i++) {
			Complex x;
			x.setRe(listRe[i]);
			x.setIm(listIm[i]);
			REQUIRE(x.getRe() == listRe[i]);
			REQUIRE(x.getIm() == listIm[i]);
		}
	}
	SECTION("ABS") {
		for (int i = 0; i < 12; i++) {
			Complex x(listRe[i], listIm[i]);
			std::complex<double> y(listRe[i], listIm[i]);
			REQUIRE(is_equal(x.abs(), std::abs(y)));
		}
	}
	SECTION("+=") {
		for (int i = 0; i < 12; i++) {
			Complex x(listRe[i], listIm[i]);
			Complex y(listRe[i/2], listIm[i/2]);
			x += y;
			REQUIRE(x.getRe() == listRe[i] + listRe[i/2]);
			REQUIRE(x.getIm() == listIm[i] + listIm[i/2]);
		}
	}
	SECTION("-=") {
		for (int i = 0; i < 12; i++) {
			Complex x(listRe[i], listIm[i]);
			Complex y(listRe[i / 2], listIm[i / 2]);
			x -= y;
			REQUIRE(x.getRe() == listRe[i] - listRe[i / 2]);
			REQUIRE(x.getIm() == listIm[i] - listIm[i / 2]);
		}
	}
	SECTION("+") {
		for (int i = 0; i < 12; i++) {
			Complex x(listRe[i], listIm[i]);
			Complex y(listRe[i / 2], listIm[i / 2]);
			REQUIRE((x+y).getRe() == listRe[i] + listRe[i / 2]);
			REQUIRE((x+y).getIm() == listIm[i] + listIm[i / 2]);
		}
	}
	SECTION("-") {
		for (int i = 0; i < 12; i++) {
			Complex x(listRe[i], listIm[i]);
			Complex y(listRe[i / 2], listIm[i / 2]);
			REQUIRE((x - y).getRe() == listRe[i] - listRe[i / 2]);
			REQUIRE((x - y).getIm() == listIm[i] - listIm[i / 2]);
		}
	}
	SECTION("-uno") {
		for (int i = 0; i < 12; i++) {
			Complex x(listRe[i], listIm[i]);
			REQUIRE((-x).getRe() == -listRe[i]);
			REQUIRE((-x).getIm() == -listIm[i]);
		}
	}
	SECTION("*") {
		for (int i = 0; i < 12; i++) {
			Complex x(listRe[i], listIm[i]);
			Complex y(listRe[i / 2], listIm[i / 2]);
			std::complex<double> z(listRe[i], listIm[i]);
			std::complex<double> k(listRe[i/2], listIm[i/2]);
			REQUIRE(is_equal((x * y).getRe(), (z * k).real()));
			REQUIRE(is_equal((x * y).getIm(), (z * k).imag()));
		}
	}
	SECTION("*=") {
		for (int i = 0; i < 12; i++) {
			Complex x(listRe[i], listIm[i]);
			Complex y(listRe[i / 2], listIm[i / 2]);
			x *= y;
			std::complex<double> z(listRe[i], listIm[i]);
			std::complex<double> k(listRe[i / 2], listIm[i / 2]);
			z *= k;
			REQUIRE(is_equal(x.getRe(), z.real()));
			REQUIRE(is_equal(x.getIm(), z.imag()));
		}
	}
	SECTION("/") {
		for (int i = 0; i < 12; i++) {
			Complex x(listRe[i], listIm[i]);
			Complex y(listRe[i / 2], listIm[i / 2]);
			std::complex<double> z(listRe[i], listIm[i]);
			std::complex<double> k(listRe[i / 2], listIm[i / 2]);
			REQUIRE(is_equal((x / y).getRe(), (z / k).real()));
			REQUIRE(is_equal((x / y).getIm(), (z / k).imag()));
		}
	}
	SECTION("/=") {
		for (int i = 0; i < 12; i++) {
			Complex x(listRe[i], listIm[i]);
			Complex y(listRe[i / 2], listIm[i / 2]);
			x /= y;
			std::complex<double> z(listRe[i], listIm[i]);
			std::complex<double> k(listRe[i / 2], listIm[i / 2]);
			z /= k;
			REQUIRE(is_equal(x.getRe(), z.real()));
			REQUIRE(is_equal(x.getIm(), z.imag()));
		}
	}
	SECTION("ARGRAD") {
		for (int i = 0; i < 12; i++) {
			Complex x(listRe[i], listIm[i]);
			std::complex<double> z(listRe[i], listIm[i]);
			REQUIRE(is_equal(x.argRad(), std::arg(z)));
		}
	}
	SECTION("ARGRAD") {
		for (int i = 0; i < 12; i++) {
			Complex x(listRe[i], listIm[i]);
			std::complex<double> z(listRe[i], listIm[i]);
			REQUIRE(is_equal((x.pow(2)).getRe(), real(pow(z, 2))));
			REQUIRE(is_equal((x.pow(2)).getIm(), imag(pow(z, 2))));
			REQUIRE(is_equal((x.pow(3)).getRe(), real(pow(z, 3))));
			REQUIRE(is_equal((x.pow(3)).getIm(), imag(pow(z, 3))));
		}
	}
	SECTION("==") {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				Complex x(listRe[i], listIm[i]);
				Complex y(listRe[j], listIm[j]);
				if (i == j) {
					REQUIRE(!(x != y));
					REQUIRE(x == y);
				}
				else {
					REQUIRE(x != y);
					REQUIRE(!(x == y));
				}
				
			}
		}
	}
}