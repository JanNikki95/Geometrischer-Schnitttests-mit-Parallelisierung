#pragma once
#include <ostream>
#include "Vektor3D.h"
#include "Matrix4x4.h"


class Quaternion {
private:

	union {
		struct {
			float x_;
			float y_;
			float z_;
			float w_;
		};
		struct {
			Vektor3D vec_;
			float scalar_;
		};
		float v_[4];
	};

public:
	Quaternion() : x_(0.0f), y_(0.0f), z_(0.0f), w_(1.0f) { }

	Quaternion(float x, float y, float z, float w) : x_(x), y_(y), z_(z), w_(w) { }

	Quaternion(Vektor3D axis, float angle) {
		
		if (std::abs(axis.lenSq() - 1.0f) >= FLT_EPSILON) {
			axis.normalize();
		}
		
		float s = sinf(angle * 0.5f);

		vec_ = s * axis;
		scalar_ = cosf(angle * 0.5f);
	}

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

	Vektor3D vector() {
		return v_;
	}

	float scalar() {
		return scalar_;
	}

	float lenSq() {
		return x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_;
	}

	float len() {
		float lenSq = this->lenSq();

		if (lenSq < FLT_EPSILON) {
			return 0.0f;
		}

		return sqrtf(lenSq);
	}

	void normalize() {
		float lenSq = this->lenSq();

		if (lenSq < FLT_EPSILON) {
			return;
		}
		float recip = 1.0f / sqrtf(lenSq);

		x_ *= recip;
		y_ *= recip;
		z_ *= recip;
		w_ *= recip;
	}

	void conjugate() {
		x_ *= -1.0f;
		y_ *= -1.0f;
		z_ *= -1.0f;
	}

	void invert() {
		float lenSq = this->lenSq();

		if (lenSq < FLT_EPSILON) {
			return;
		}

		float recip = 1.0f / lenSq;

		x_ *= -1.0f * recip;
		y_ *= -1.0f * recip;
		z_ *= -1.0f * recip;
		w_ *= recip;
	}

	Vektor3D rotationAxis() const {

		Vektor3D res(x_, y_, z_);

		float recip = 1.0f / (sqrtf((x_ * x_) + (y_ * y_) + (z_ * z_)));

		return recip * res;
	}

	float rotationAngle() const {
		float tmp = sqrtf((x_ * x_) + (y_ * y_) + (z_ * z_));

		return 2.0f * atan2f(tmp, w_);
	}

	Matrix4x4 toMatrix() {

		float ww = w_ * w_;
		float xx = x_ * x_;
		float yy = y_ * y_;
		float zz = z_ * z_;

		float wx = w_ * x_;
		float wy = w_ * y_;
		float wz = w_ * z_;

		float xy = x_ * y_;
		float xz = x_ * z_;

		float yz = y_ * z_;

		return Matrix4x4(
			ww + xx - yy - zz, 2 * xy - 2 * wz, 2 * xz + 2 * wy, 0,
			2 * xy + 2 * wz, ww - xx + yy - zz, 2 * yz - 2 * wx, 0,
			2 * xz - 2 * wy, 2 * yz + 2 * wx, ww - xx - yy + zz, 0,
			0, 0, 0, ww + xx + yy + zz
		);
	}
};

std::ostream& operator<<(std::ostream& os, Quaternion q) {
	os << "( " << q.x() << ", " << q.y() << ", " << q.z() << ", " << q.w() << " )\n";
	return os;
}

Quaternion operator+(Quaternion lhs, Quaternion rhs) {
	return Quaternion(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z(), lhs.w() + rhs.w());
}

Quaternion operator-(Quaternion lhs, Quaternion rhs) {
	return Quaternion(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z(), lhs.w() - rhs.w());
}

Quaternion operator-(Quaternion q) {
	return Quaternion(-q.x(), -q.y(), -q.z(), -q.w());
}

Quaternion operator*(Quaternion q, float s) {
	return Quaternion(q.x() * s, q.y() * s, q.z() * s, q.w() * s);
}

Quaternion operator*(float s, Quaternion q) {
	return q * s;
}

bool operator==(Quaternion lhs, Quaternion rhs) {
	return (
		std::abs(lhs.x() - rhs.x()) <= FLT_EPSILON &&
		std::abs(lhs.y() - rhs.y()) <= FLT_EPSILON &&
		std::abs(lhs.z() - rhs.z()) <= FLT_EPSILON &&
		std::abs(lhs.w() - rhs.w()) <= FLT_EPSILON
	);
}

bool operator!=(Quaternion lhs, Quaternion rhs) {
	return !(lhs == rhs);
}

Quaternion operator*(Quaternion lhs, Quaternion rhs) {
	return Quaternion(
		 rhs.x() * lhs.w() + rhs.y() * lhs.z() - rhs.z() * lhs.y() + rhs.w() * lhs.x(),
		-rhs.x() * lhs.z() + rhs.y() * lhs.w() + rhs.z() * lhs.x() + rhs.w() * lhs.y(),
		 rhs.x() * lhs.y() - rhs.y() * lhs.x() + rhs.z() * lhs.w() + rhs.w() * lhs.z(),
		-rhs.x() * lhs.x() - rhs.y() * lhs.y() - rhs.z() * lhs.z() + rhs.w() * lhs.w()
	);
}

Vektor3D operator*(Quaternion q, Vektor3D v) {
	return q.vector() * 2.0f * dot(q.vector(), v) +
		v * (q.scalar() * q.scalar() - dot(q.vector(), q.vector())) +
		cross(q.vector(), v) * 2.0f * q.scalar();
}


Quaternion angleAxis(float angle, Vektor3D axis) {
	Vektor3D norm = normalized(axis);
	float s = sinf(angle * 0.5f);

	return Quaternion(
			norm.x() * s,
			norm.y() * s,
			norm.z() * s,
			cosf(angle * 0.5f)
	);
}

float dot(Quaternion lhs, Quaternion rhs) {
	return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z() + lhs.w() * rhs.w();
}

float lenSq(Quaternion q) {
	return q.lenSq();
}

float len(Quaternion q) {
	float lenSq = q.lenSq();

	if (lenSq < FLT_EPSILON) {
		return 0.0f;
	}

	return sqrtf(lenSq);
}

Quaternion normalized(Quaternion q) {
	float lenSq = q.lenSq();

	if (lenSq < FLT_EPSILON) {
		return Quaternion();
	}
	float recip = 1.0f / sqrtf(lenSq);

	return Quaternion(q.x() * recip, q.y() * recip, q.z() * recip, q.w() * recip);
}

Quaternion conjugate(Quaternion q) {
	return Quaternion(-q.x(), -q.y(), -q.z(), q.w());
}

Quaternion inverse(Quaternion q) {
	float lenSq = q.lenSq();

	if (lenSq < FLT_EPSILON) {
		return Quaternion();
	}

	float recip = 1.0f / lenSq;
	return Quaternion(
		-q.x() * recip,
		-q.y() * recip,
		-q.z() * recip,
		 q.w() * recip
	);
}

 Matrix4x4 toMatrix(Quaternion q) {
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
		1.0f - 2.0f * yy - 2.0f * zz,	2.0f * xy - 2.0f * wz,			2.0f * xz + 2.0f * wy,				0.0f,
		2.0f * xy + 2.0f * wz,			1.0f - 2.0f * xx - 2.0f * zz,	2.0f * yz - 2.0f * wx,				0.0f,
		2.0f * xz - 2.0f * wy,			2.0f * yz + 2.0f * wx,			1.0f - 2.0f * xx - 2.0f * yy ,		0.0f,
		0.0f,							0.0f,							0.0f,								1.0f
	);

}

Quaternion toQuaternion(const Matrix4x4& mat) {
	float s, w, x, y, z;
	float t = mat.xx() + mat.yy() + mat.zz();
	
	if (t >= 0.0f) { 
		s = sqrt(t + 1.0f);
		w = 0.5 * s;
		s = 0.5 / s;
		x = (mat.zy() - mat.yz()) * s;
		y = (mat.xz() - mat.zx()) * s;
		z = (mat.yx() - mat.xy()) * s;
	}
	else if ((mat.xx() > mat.yy()) && (mat.xx() > mat.zz())) {
		s = sqrt(1.0f + mat.xx() - mat.yy() - mat.zz());
		x = s * 0.5;
		s = 0.5 / s;
		y = (mat.yx() + mat.xy()) * s;
		z = (mat.xz() + mat.zx()) * s;
		w = (mat.zy() - mat.yz()) * s;
	}
	else if (mat.yy() > mat.zz()) {
		s = sqrt(1.0f + mat.yy() - mat.xx() - mat.zz());
		y = s * 0.5;
		s = 0.5 / s;
		x = (mat.yx() + mat.xy()) * s;
		z = (mat.zy() + mat.yz()) * s;
		w = (mat.xz() - mat.zx()) * s;
	}
	else { // by z
		s = sqrt(1.0f + mat.zz() - mat.xx() - mat.yy());
		z = s * 0.5;
		s = 0.5 / s;
		x = (mat.xz() + mat.zx()) * s;
		y = (mat.zy() + mat.yz()) * s;
		w = (mat.yx() - mat.xy()) * s;
	}

	return Quaternion(x, y, z, w);
}

Vektor3D rotationAxis(Quaternion q) {

	Vektor3D res(q.x(), q.y(), q.z());

	float recip = 1.0f / (sqrtf((q.x() * q.x()) + (q.y() * q.y()) + (q.z() * q.z())));

	return recip * res;
}

float rotationAngle(Quaternion q)  {
	float tmp = sqrtf((q.x() * q.x()) + (q.y() * q.y()) + (q.z() * q.z()));

	return 2.0f * atan2f(tmp, q.w());
}