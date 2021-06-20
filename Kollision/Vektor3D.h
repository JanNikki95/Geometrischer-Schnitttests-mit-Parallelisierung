#pragma once
#include <ostream>
#include <climits>

#define M_PI 3.14159265358979f

#define RADIANTODEGREE(a) (a) * 57.2958f

class Vektor3D {
private:

	union {
		struct {
			float x_;
			float y_;
			float z_;
		};
		float v_[3];
	};

public:

	constexpr Vektor3D() : x_(NAN), y_(NAN), z_(NAN) { }
	constexpr Vektor3D(float x, float y, float z) : x_(x), y_(y), z_(z) { }
	constexpr Vektor3D(float* v) : x_(v[0]), y_(v[1]), z_(v[2]) { }

	constexpr float x() const {
		return x_;
	}

	constexpr float y() const {
		return y_;
	}

	constexpr float z() const {
		return z_;
	}

	constexpr float operator[](size_t idx) const {
		return v_[idx];
	}

	constexpr Vektor3D& operator+=(Vektor3D rhs) {
		x_ += rhs.x();
		y_ += rhs.y();
		z_ += rhs.z();

		return *this;
	}

	constexpr Vektor3D& operator-=(Vektor3D rhs) {
		x_ -= rhs.x();
		y_ -= rhs.y();
		z_ -= rhs.z();

		return *this;
	}

	constexpr Vektor3D& operator*=(float s) {
		x_ *= s;
		y_ *= s;
		z_ *= s;

		return *this;
	}

	constexpr float lenSq() const {
		return x_ * x_ + y_ * y_ + z_ * z_;
	}

	constexpr float len() const {
		float lenSq = this->lenSq();

		if (lenSq < FLT_EPSILON) {
			return 0.0f;
		}

		return sqrtf(lenSq);
	}

	constexpr void normalize() {
		float lenSq = this->lenSq();

		if (lenSq < FLT_EPSILON) {
			return;
		}

		float invLen = 1.0f / sqrtf(lenSq);
		x_ *= invLen;
		y_ *= invLen;
		z_ *= invLen;
	}
};

std::ostream& operator<<(std::ostream& os, Vektor3D v) {
	os << "( " << v.x() << ", " << v.y() << ", " << v.z() << " )";
	return os;
}

Vektor3D operator+(Vektor3D lhs, Vektor3D rhs) {
	return Vektor3D(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
}

Vektor3D operator-(Vektor3D lhs, Vektor3D rhs) {
	return Vektor3D(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
}

Vektor3D operator*(Vektor3D v, float s) {
	return Vektor3D(v.x() * s, v.y() * s, v.z() * s);
}

Vektor3D operator*(float s, Vektor3D v) {
	return v * s;
}

float dot(Vektor3D lhs, Vektor3D rhs) {
	return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z();
}

float lenSq(Vektor3D v) {
	return v.lenSq();
}

float len(Vektor3D v) {
	float lenSq = v.lenSq();

	if (lenSq < FLT_EPSILON) {
		return 0.0f;
	}

	return sqrtf(lenSq);
}

Vektor3D normalized(Vektor3D v) {
	float lenSq = v.lenSq();

	if (lenSq < FLT_EPSILON) {
		return v;
	}

	float invLen = 1.0f / sqrtf(lenSq);
	return Vektor3D(v.x() * invLen, v.y() * invLen, v.z() * invLen);
}

float angle(Vektor3D lhs, Vektor3D rhs) {
	float sqMagL = lhs.lenSq();
	float sqMagR = rhs.lenSq();

	if (sqMagL < FLT_EPSILON || sqMagR < FLT_EPSILON) {
		return 0.0f;
	}

	float numer = dot(lhs, rhs);
	float denom = sqrtf(sqMagL) * sqrtf(sqMagR);
	return acosf(numer / denom);
}

Vektor3D cross(Vektor3D lhs, Vektor3D rhs) {

	return Vektor3D(lhs.y() * rhs.z() - lhs.z() * rhs.y(),
					lhs.z() * rhs.x() - lhs.x() * rhs.z(),
					lhs.x() * rhs.y() - lhs.y() * rhs.x());
}

bool operator==(Vektor3D lhs, Vektor3D rhs) {
	Vektor3D diff = lhs - rhs;
	return lenSq(diff) < FLT_EPSILON;
}

bool operator!=(Vektor3D lhs, Vektor3D rhs) {
	return !(lhs == rhs);
}