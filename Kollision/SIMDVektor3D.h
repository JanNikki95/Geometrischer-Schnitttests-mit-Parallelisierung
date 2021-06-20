#pragma once
#include <ostream>
#include <climits>
#include <immintrin.h>

class SIMDVektor3D {
private:

	union {
		struct {
			float dummy, z_, y_, x_;
		};
		__m128 v_;
	};

public:
	SIMDVektor3D() {
		v_ = _mm_set1_ps(NAN);
	}

	SIMDVektor3D(float x, float y, float z) {
		v_ = _mm_set_ps(x, y, z, 0.0f);
	}

	SIMDVektor3D(__m128 v) : v_(v) {	}

	float x() const {
		return x_;
	}

	float y() const {
		return y_;
	}

	float z() const {
		return z_;
	}

	__m128 vec128() const {
		return v_;
	}

	SIMDVektor3D& operator+=(SIMDVektor3D rhs) {
		v_ = _mm_add_ps(v_, rhs.v_);

		return *this;
	}

	SIMDVektor3D& operator-=(SIMDVektor3D rhs) {
		v_ = _mm_sub_ps(v_, rhs.v_);

		return *this;
	}

	SIMDVektor3D& operator*=(float s) {
		__m128 temp = _mm_set1_ps(s);
		v_ = _mm_mul_ps(v_, temp);

		return *this;
	}

	float lenSq() const {
		return _mm_cvtss_f32(_mm_dp_ps(v_, v_, 0b11100001));
	}


	float len() const {
		float lenSq = this->lenSq();

		if (lenSq < FLT_EPSILON) {
			return 0.0f;
		}

		return sqrtf(lenSq);
	}

	void normalize() {
		__m128 tmp = _mm_set1_ps(this->lenSq());

		tmp = _mm_rsqrt_ps(tmp);

		v_ = _mm_mul_ps(v_, tmp);
	}
};

std::ostream& operator<<(std::ostream& os, SIMDVektor3D v) {
	os << "( " << v.x() << ", " << v.y() << ", " << v.z() << " )";
	return os;
}

SIMDVektor3D operator+(SIMDVektor3D lhs, SIMDVektor3D rhs) {
	return SIMDVektor3D(_mm_add_ps(lhs.vec128(), rhs.vec128()));
}

SIMDVektor3D operator-(SIMDVektor3D lhs, SIMDVektor3D rhs) {
	return SIMDVektor3D(_mm_sub_ps(lhs.vec128(), rhs.vec128()));
}

SIMDVektor3D operator*(SIMDVektor3D v, float s) {
	__m128 temp = _mm_set1_ps(s);
	return SIMDVektor3D(_mm_mul_ps(v.vec128(), temp));
}

SIMDVektor3D operator*(float s, SIMDVektor3D v) {
	return v * s;
}

SIMDVektor3D normalized(SIMDVektor3D v) {

	__m128 tmp = _mm_set1_ps(v.lenSq());

	tmp = _mm_rsqrt_ps(tmp);

	__m128 result = _mm_mul_ps(v.vec128(), tmp);

	return SIMDVektor3D(result);
}

float dot(SIMDVektor3D lhs, SIMDVektor3D rhs) {
	return _mm_cvtss_f32(_mm_dp_ps(lhs.vec128(), rhs.vec128(), 0b11100001));
}

SIMDVektor3D cross(SIMDVektor3D lhs, SIMDVektor3D rhs) {
	__m128 tmp0 = _mm_shuffle_ps(lhs.vec128(), lhs.vec128(), 0b10011100);
	__m128 tmp1 = _mm_shuffle_ps(rhs.vec128(), rhs.vec128(), 0b01111000);
	__m128 tmp2 = _mm_shuffle_ps(lhs.vec128(), lhs.vec128(), 0b01111000);
	__m128 tmp3 = _mm_shuffle_ps(rhs.vec128(), rhs.vec128(), 0b10011100);
	return SIMDVektor3D(_mm_sub_ps(_mm_mul_ps(tmp0, tmp1), _mm_mul_ps(tmp2, tmp3)));
}
