#pragma once
#include <ostream>
#include <climits>
#include <immintrin.h>
#include "Matrix4x4.h"

class SIMDQuaternion {
private:

	union {
		struct {
			float w_, z_, y_, x_;
		};
		__m128 v_;
	};

public:

	SIMDQuaternion() : x_(0.0f), y_(0.0f), z_(0.0f), w_(1.0f) { }

	SIMDQuaternion(float x, float y, float z, float w) : x_(x), y_(y), z_(z), w_(w) { }

	float x() {
		return x_;
	}

	float y() {
		return y_;
	}

	float z() {
		return z_;
	}

	float w() {
		return w_;
	}
};

Matrix4x4 toMatrix(SIMDQuaternion q) {
	float ww = q.w() * q.w();
	float xx = q.x() * q.x();
	float yy = q.y() * q.y();
	float zz = q.z() * q.z();

	float wx = q.w() * q.x();
	float wy = q.w() * q.y();
	float wz = q.w() * q.z();

	float xy = q.x() * q.y();
	float xz = q.x() * q.z();

	float yz = q.y() * q.z();

	return Matrix4x4(
		1.0f - 2.0f * yy - 2.0f * zz, 2.0f * xy - 2.0f * wz, 2.0f * xz + 2.0f * wy, 0.0f,
		2.0f * xy + 2.0f * wz, 1.0f - 2.0f * xx - 2.0f * zz, 2.0f * yz - 2.0f * wx, 0.0f,
		2.0f * xz - 2.0f * wy, 2.0f * yz + 2.0f * wx, 1.0f - 2.0f * xx - 2.0f * yy, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

}

SIMDQuaternion toSIMDQuaternion(const Matrix4x4& mat) {
	float s, w, x, y, z;
	float t = mat.xx() + mat.yy() + mat.zz();

	if (t >= 0.0f) {
		s = sqrt(t + 1.0f);
		w = 0.5f * s;
		s = 0.5f / s;
		x = (mat.zy() - mat.yz()) * s;
		y = (mat.xz() - mat.zx()) * s;
		z = (mat.yx() - mat.xy()) * s;
	}
	else if ((mat.xx() > mat.yy()) && (mat.xx() > mat.zz())) {
		s = sqrt(1.0f + mat.xx() - mat.yy() - mat.zz());
		x = s * 0.5f;
		s = 0.5f / s;
		y = (mat.yx() + mat.xy()) * s;
		z = (mat.xz() + mat.zx()) * s;
		w = (mat.zy() - mat.yz()) * s;
	}
	else if (mat.yy() > mat.zz()) {
		s = sqrt(1.0f + mat.yy() - mat.xx() - mat.zz());
		y = s * 0.5f;
		s = 0.5f / s;
		x = (mat.yx() + mat.xy()) * s;
		z = (mat.zy() + mat.yz()) * s;
		w = (mat.xz() - mat.zx()) * s;
	}
	else { // by z
		s = sqrt(1.0f + mat.zz() - mat.xx() - mat.yy());
		z = s * 0.5f;
		s = 0.5f / s;
		x = (mat.xz() + mat.zx()) * s;
		y = (mat.zy() + mat.yz()) * s;
		w = (mat.yx() - mat.xy()) * s;
	}

	return SIMDQuaternion(x, y, z, w);
}