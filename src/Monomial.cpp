#include "../include/Monomial.hpp"

Monomial::Monomial() : coeff(1), t() {}

Monomial::Monomial(int32_t coeff, const Term &t) : coeff(coeff), t(t) {}

Monomial::Monomial(const mpz_class &coeff, const Term &t)
    : coeff(coeff), t(t) {}

Monomial::Monomial(const Monomial &other) : coeff(other.coeff), t(other.t) {}

Monomial::Monomial(const Term &t) : coeff(1), t(t) {}

Monomial &Monomial::operator=(const Monomial &other) {
  coeff = other.coeff;
  t = other.t;
  return *this;
}

Monomial Monomial::operator*(const Monomial &other) const {
  return Monomial(coeff * other.coeff, t * other.t);
}

Monomial Monomial::operator*(int32_t factor) const {
  return Monomial(coeff*factor, t);
}

Monomial Monomial::operator+(const Monomial &other) const {
  return Monomial(coeff + other.coeff, t);
}

Monomial Monomial::operator-(const Monomial &other) const {
  return Monomial(coeff - other.coeff, t);
}

Monomial &Monomial::operator*=(const Monomial &other) {
  t = t * other.t;
  return *this;
}

Monomial &Monomial::operator*=(int32_t factor) {
  coeff *= factor;
  return *this;
}

Monomial &Monomial::operator+=(const Monomial &other) {
  coeff += other.coeff;
  return *this;
}

Monomial &Monomial::operator-=(const Monomial &other) {
  coeff -= other.coeff;
  return *this;
}

Monomial Monomial::operator-() const { return Monomial(-coeff, t); }

bool Monomial::operator<(const Monomial &other) const {
  return t < other.t || (t == other.t && coeff < other.coeff);
}
bool Monomial::operator<=(const Monomial &other) const {
  return t <= other.t || (t == other.t && coeff <= other.coeff);
}
bool Monomial::operator>(const Monomial &other) const {
  return t > other.t || (t == other.t && coeff > other.coeff);
}
bool Monomial::operator>=(const Monomial &other) const {
  return t >= other.t || (t == other.t && coeff >= other.coeff);
}
bool Monomial::operator==(const Monomial &other) const {
  return t == other.t && coeff == other.coeff;
}

bool Monomial::is_zero() const { return coeff == 0; }

Monomial operator*(int32_t factor, const Monomial& m) {
  return m*factor;
}