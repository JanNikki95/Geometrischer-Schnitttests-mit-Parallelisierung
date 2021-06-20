#pragma once
#include <ostream>
#include <climits>
#include "Vektor3D.h"
#include "Point3D.h"

class Matrix4x4 {
private:
	
	union {

		float v_[16];
		
		struct {
			float xx_, xy_, xz_, xw_;
			float yx_, yy_, yz_, yw_;
			float zx_, zy_, zz_, zw_;
			float wx_, wy_, wz_, ww_;
		};
	};

public:

	Matrix4x4() :
		xx_(1.0f), xy_(0.0f), xz_(0.0f), xw_(0.0f),
		yx_(0.0f), yy_(1.0f), yz_(0.0f), yw_(0.0f),
		zx_(0.0f), zy_(0.0f), zz_(1.0f), zw_(0.0f),
		wx_(0.0f), wy_(0.0f), wz_(0.0f), ww_(1.0f) { }

	Matrix4x4(float* v) :
		xx_(v[0]), xy_(v[1]), xz_(v[2]), xw_(v[3]),
		yx_(v[4]), yy_(v[5]), yz_(v[6]), yw_(v[7]),
		zx_(v[8]), zy_(v[9]), zz_(v[10]), zw_(v[11]),
		wx_(v[12]), wy_(v[13]), wz_(v[14]), ww_(v[15]) { }

	Matrix4x4(
		float xx, float xy, float xz, float xw,
		float yx, float yy, float yz, float yw,
		float zx, float zy, float zz, float zw,
		float wx, float wy, float wz, float ww ) : 
		xx_(xx), xy_(xy), xz_(xz), xw_(xw),
		yx_(yx), yy_(yy), yz_(yz), yw_(yw),
		zx_(zx), zy_(zy), zz_(zz), zw_(zw),
		wx_(wx), wy_(wy), wz_(wz), ww_(ww) { }

	float xx() const {
		return xx_;
	}

	float xy() const {
		return xy_;
	}

	float xz() const {
		return xz_;
	}

	float xw() const {
		return xw_;
	}

	float yx() const {
		return yx_;
	}

	float yy() const {
		return yy_;
	}

	float yz() const {
		return yz_;
	}

	float yw() const {
		return yw_;
	}

	float zx() const {
		return zx_;
	}

	float zy() const {
		return zy_;
	}

	float zz() const {
		return zz_;
	}

	float zw() const {
		return zw_;
	}

	float wx() const {
		return wx_;
	}

	float wy() const {
		return wy_;
	}

	float wz() const {
		return wz_;
	}

	float ww() const {
		return ww_;
	}

	const float* operator[](size_t idx) const {
		return &(v_[4 * idx]);
	}

	void transpose() {
		std::swap(yx_, xy_);
		std::swap(zx_, xz_);
		std::swap(wx_, xw_);
		std::swap(zy_, yz_);
		std::swap(wy_, yw_);
		std::swap(wz_, zw_);
	}

	float determinant() const {
		return xx_ * ((yy_ * zz_ * ww_) + (yz_ * zw_ * wy_) + (yw_ * zy_ * wz_) - (yw_ * zz_ * wy_) - (yy_ * zw_ * wz_) - (yz_ * zy_ * ww_))
			- xy_ * ((yx_ * zz_ * ww_) + (yz_ * zw_ * wx_) + (yw_ * zx_ * wz_) - (yw_ * zz_ * wx_) - (yx_ * zw_ * wz_) - (yz_ * zx_ * ww_))
			+ xz_ * ((yx_ * zy_ * ww_) + (yy_ * zw_ * wx_) + (yw_ * zx_ * wy_) - (yw_ * zy_ * wx_) - (yx_ * zw_ * wy_) - (yy_ * zx_ * ww_))
			- xw_ * ((yx_ * zy_ * wz_) + (yy_ * zz_ * wx_) + (yz_ * zx_ * wy_) - (yz_ * zy_ * wx_) - (yx_ * zz_ * wy_) - (yy_ * zx_ * wz_));
	}

	void invert() {
		float det = 1.0f / this->determinant();

		float cof_xx =  1.0f * ((yy_ * zz_ * ww_) + (yz_ * zw_ * wy_) + (yw_ * zy_ * wz_) - (yw_ * zz_ * wy_) - (yy_ * zw_ * wz_) - (yz_ * zy_ * ww_));
		float cof_xy = -1.0f * ((yx_ * zz_ * ww_) + (yz_ * zw_ * wx_) + (yw_ * zx_ * wz_) - (yw_ * zz_ * wx_) - (yx_ * zw_ * wz_) - (yz_ * zx_ * ww_));
		float cof_xz =  1.0f * ((yx_ * zy_ * ww_) + (yy_ * zw_ * wx_) + (yw_ * zx_ * wy_) - (yw_ * zy_ * wx_) - (yx_ * zw_ * wy_) - (yy_ * zx_ * ww_));
		float cof_xw = -1.0f * ((yx_ * zy_ * wz_) + (yy_ * zz_ * wx_) + (yz_ * zx_ * wy_) - (yz_ * zy_ * wx_) - (yx_ * zz_ * wy_) - (yy_ * zx_ * wz_));

		float cof_yx = -1.0f * ((xy_ * zz_ * ww_) + (xz_ * zw_ * wy_) + (xw_ * zy_ * wz_) - (xw_ * zz_ * wy_) - (xy_ * zw_ * wz_) - (xz_ * zy_ * ww_));
		float cof_yy =  1.0f * ((xx_ * zz_ * ww_) + (xz_ * zw_ * wx_) + (xw_ * zx_ * wz_) - (xw_ * zz_ * wx_) - (xx_ * zw_ * wz_) - (xz_ * zx_ * ww_));
		float cof_yz = -1.0f * ((xx_ * zy_ * ww_) + (xy_ * zw_ * wx_) + (xw_ * zx_ * wy_) - (xw_ * zy_ * wx_) - (xx_ * zw_ * wy_) - (xy_ * zx_ * ww_));
		float cof_yw =  1.0f * ((xx_ * zy_ * wz_) + (xy_ * zz_ * wx_) + (xz_ * zx_ * wy_) - (xz_ * zy_ * wx_) - (xx_ * zz_ * wy_) - (xy_ * zx_ * wz_));

		float cof_zx =  1.0f * ((xy_ * yz_ * ww_) + (xz_ * yw_ * wy_) + (xw_ * yy_ * wz_) - (xw_ * yz_ * wy_) - (xy_ * yw_ * wz_) - (xz_ * yy_ * ww_));
		float cof_zy = -1.0f * ((xx_ * yz_ * ww_) + (xz_ * yw_ * wx_) + (xw_ * yx_ * wz_) - (xw_ * yz_ * wx_) - (xx_ * yw_ * wz_) - (xz_ * yx_ * ww_));
		float cof_zz =  1.0f * ((xx_ * yy_ * ww_) + (xy_ * yw_ * wx_) + (xw_ * yx_ * wy_) - (xw_ * yy_ * wx_) - (xx_ * yw_ * wy_) - (xy_ * yx_ * ww_));
		float cof_zw = -1.0f * ((xx_ * yy_ * wz_) + (xy_ * yz_ * wx_) + (xz_ * yx_ * wy_) - (xz_ * yy_ * wx_) - (xx_ * yz_ * wy_) - (xy_ * yx_ * wz_));
		
		float cof_wx = -1.0f * ((xy_ * yz_ * zw_) + (xz_ * yw_ * zy_) + (xw_ * yy_ * zz_) - (xw_ * yz_ * zy_) - (xy_ * yw_ * zz_) - (xz_ * yy_ * zw_));
		float cof_wy =  1.0f * ((xx_ * yz_ * zw_) + (xz_ * yw_ * zx_) + (xw_ * yx_ * zz_) - (xw_ * yz_ * zx_) - (xx_ * yw_ * zz_) - (xz_ * yx_ * zw_));
		float cof_wz = -1.0f * ((xx_ * yy_ * zw_) + (xy_ * yw_ * zx_) + (xw_ * yx_ * zy_) - (xw_ * yy_ * zx_) - (xx_ * yw_ * zy_) - (xy_ * yx_ * zw_));
		float cof_ww =  1.0f * ((xx_ * yy_ * zz_) + (xy_ * yz_ * zx_) + (xz_ * yx_ * zy_) - (xz_ * yy_ * zx_) - (xx_ * yz_ * zy_) - (xy_ * yx_ * zz_));
	
		xx_ = det * cof_xx;
		xy_ = det * cof_yx;
		xz_ = det * cof_zx;
		xw_ = det * cof_wx;

		yx_ = det * cof_xy;
		yy_ = det * cof_yy;
		yz_ = det * cof_zy;
		yw_ = det * cof_wy;
		
		zx_ = det * cof_xz;
		zy_ = det * cof_yz;
		zz_ = det * cof_zz;
		zw_ = det * cof_wz;

		wx_ = det * cof_xw;
		wy_ = det * cof_yw;
		wz_ = det * cof_zw;
		ww_ = det * cof_ww;
	}
};

std::ostream& operator<<(std::ostream& os, Matrix4x4 mat) {

	for (size_t i = 0; i < 4; ++i) {
		for (size_t j = 0; j < 4; ++j) {
			os << mat[i][j] << '\t';
		}
		os << '\n';
	}

	return os;
}

bool operator==(const Matrix4x4& lhs, const Matrix4x4& rhs) {

	for (size_t i = 0; i < 16; ++i) {
		if (fabsf(lhs[i] - rhs[i]) > FLT_EPSILON) {
			return false;
		}
	}

	return true;
}

bool operator!=(const Matrix4x4& lhs, const Matrix4x4& rhs) {
	return !(lhs == rhs);
}

Matrix4x4 operator+(const Matrix4x4& lhs, const Matrix4x4& rhs) {
	return Matrix4x4(
		lhs.xx() + rhs.xx(), lhs.xy() + rhs.xy(), lhs.xz() + rhs.xz(), lhs.xw() + rhs.xw(), 
		lhs.yx() + rhs.yx(), lhs.yy() + rhs.yy(), lhs.yz() + rhs.yz(), lhs.yw() + rhs.yw(),
		lhs.zx() + rhs.zx(), lhs.zy() + rhs.zy(), lhs.zz() + rhs.zz(), lhs.zw() + rhs.zw(),
		lhs.wx() + rhs.wx(), lhs.wy() + rhs.wy(), lhs.wz() + rhs.wz(), lhs.ww() + rhs.ww()
	);
}

Matrix4x4 operator-(const Matrix4x4& lhs, const Matrix4x4& rhs) {
	return Matrix4x4(
		lhs.xx() - rhs.xx(), lhs.xy() - rhs.xy(), lhs.xz() - rhs.xz(), lhs.xw() - rhs.xw(),
		lhs.yx() - rhs.yx(), lhs.yy() - rhs.yy(), lhs.yz() - rhs.yz(), lhs.yw() - rhs.yw(),
		lhs.zx() - rhs.zx(), lhs.zy() - rhs.zy(), lhs.zz() - rhs.zz(), lhs.zw() - rhs.zw(),
		lhs.wx() - rhs.wx(), lhs.wy() - rhs.wy(), lhs.wz() - rhs.wz(), lhs.ww() - rhs.ww()
	);
}

Matrix4x4 operator*(const Matrix4x4& mat, float s) {
	return Matrix4x4(
		mat.xx() * s, mat.xy() * s, mat.xz() * s, mat.xw() * s,
		mat.yx() * s, mat.yy() * s, mat.yz() * s, mat.yw() * s,
		mat.zx() * s, mat.zy() * s, mat.zz() * s, mat.zw() * s,
		mat.wx() * s, mat.wy() * s, mat.wz() * s, mat.ww() * s
	);
}

Matrix4x4 operator*(float s, const Matrix4x4& mat) {
	return mat * s;
}

Matrix4x4 operator*(const Matrix4x4& lhs, const Matrix4x4& rhs) {

	return Matrix4x4(
		lhs.xx() * rhs.xx() + lhs.xy() * rhs.yx() + lhs.xz() * rhs.zx() + lhs.xw() * rhs.wx(),
		lhs.xx() * rhs.xy() + lhs.xy() * rhs.yy() + lhs.xz() * rhs.zy() + lhs.xw() * rhs.wy(),
		lhs.xx() * rhs.xz() + lhs.xy() * rhs.yz() + lhs.xz() * rhs.zz() + lhs.xw() * rhs.wz(),
		lhs.xx() * rhs.xw() + lhs.xy() * rhs.yw() + lhs.xz() * rhs.zw() + lhs.xw() * rhs.ww(),

		lhs.yx()* rhs.xx() + lhs.yy() * rhs.yx() + lhs.yz() * rhs.zx() + lhs.yw() * rhs.wx(),
		lhs.yx()* rhs.xy() + lhs.yy() * rhs.yy() + lhs.yz() * rhs.zy() + lhs.yw() * rhs.wy(),
		lhs.yx()* rhs.xz() + lhs.yy() * rhs.yz() + lhs.yz() * rhs.zz() + lhs.yw() * rhs.wz(),
		lhs.yx()* rhs.xw() + lhs.yy() * rhs.yw() + lhs.yz() * rhs.zw() + lhs.yw() * rhs.ww(),

		lhs.zx()* rhs.xx() + lhs.zy() * rhs.yx() + lhs.zz() * rhs.zx() + lhs.zw() * rhs.wx(),
		lhs.zx()* rhs.xy() + lhs.zy() * rhs.yy() + lhs.zz() * rhs.zy() + lhs.zw() * rhs.wy(),
		lhs.zx()* rhs.xz() + lhs.zy() * rhs.yz() + lhs.zz() * rhs.zz() + lhs.zw() * rhs.wz(),
		lhs.zx()* rhs.xw() + lhs.zy() * rhs.yw() + lhs.zz() * rhs.zw() + lhs.zw() * rhs.ww(),

		lhs.wx()* rhs.xx() + lhs.wy() * rhs.yx() + lhs.wz() * rhs.zx() + lhs.ww() * rhs.wx(),
		lhs.wx()* rhs.xy() + lhs.wy() * rhs.yy() + lhs.wz() * rhs.zy() + lhs.ww() * rhs.wy(),
		lhs.wx()* rhs.xz() + lhs.wy() * rhs.yz() + lhs.wz() * rhs.zz() + lhs.ww() * rhs.wz(),
		lhs.wx()* rhs.xw() + lhs.wy() * rhs.yw() + lhs.wz() * rhs.zw() + lhs.ww() * rhs.ww()
	);

}

Vektor3D transformVector(const Matrix4x4& mat, Vektor3D v) {
	return Vektor3D(
		v.x() * mat.xx() + v.y() * mat.xy() + v.z() * mat.xz(),
		v.x() * mat.yx() + v.y() * mat.yy() + v.z() * mat.yz(),
		v.x() * mat.zx() + v.y() * mat.zy() + v.z() * mat.zz()
	);
}

Point3D transformPoint(const Matrix4x4& mat, Point3D p) {
	return Vektor3D(
		p.x() * mat.xx() + p.y() * mat.xy() + p.z() * mat.xz() + mat.xw(),
		p.x() * mat.yx() + p.y() * mat.yy() + p.z() * mat.yz() + mat.yw(),
		p.x() * mat.zx() + p.y() * mat.zy() + p.z() * mat.zz() + mat.zw()
	);
}

Matrix4x4 transposed(const Matrix4x4& mat) {
	return Matrix4x4(
		mat.xx(), mat.yx(), mat.zx(), mat.wx(),
		mat.xy(), mat.yy(), mat.zy(), mat.wy(),
		mat.xz(), mat.yz(), mat.zz(), mat.wz(),
		mat.xw(), mat.yw(), mat.zw(), mat.ww()
	);
}

Matrix4x4 inverse(const Matrix4x4& mat) {
	float recip_det = 1.0f / mat.determinant();

	float cof_xx = 1.0f * 
		((mat.yy() * mat.zz() * mat.ww()) 
		+ (mat.yz() * mat.zw() * mat.wy()) 
		+ (mat.yw() * mat.zy() * mat.wz())
		- (mat.yw() * mat.zz() * mat.wy()) 
		- (mat.yy() * mat.zw() * mat.wz()) 
		- (mat.yz() * mat.zy() * mat.ww()));
	
	float cof_xy = -1.0f * 
		((mat.yx() * mat.zz() * mat.ww())
		+ (mat.yz() * mat.zw() * mat.wx())
		+ (mat.yw() * mat.zx() * mat.wz())
		- (mat.yw() * mat.zz() * mat.wx())
		- (mat.yx() * mat.zw() * mat.wz())
		- (mat.yz() * mat.zx() * mat.ww()));

	float cof_xz = 1.0f * 
		((mat.yx() * mat.zy() * mat.ww()) 
		+ (mat.yy() * mat.zw() * mat.wx()) 
		+ (mat.yw() * mat.zx() * mat.wy()) 
		- (mat.yw() * mat.zy() * mat.wx()) 
		- (mat.yx() * mat.zw() * mat.wy())
		- (mat.yy() * mat.zx() * mat.ww()));

	float cof_xw = -1.0f * 
		((mat.yx() * mat.zy() * mat.wz())
		+ (mat.yy() * mat.zz() * mat.wx()) 
		+ (mat.yz() * mat.zx() * mat.wy())
		- (mat.yz() * mat.zy() * mat.wx()) 
		- (mat.yx() * mat.zz() * mat.wy()) 
		- (mat.yy() * mat.zx() * mat.wz()));

	float cof_yx = -1.0f * 
		((mat.xy() * mat.zz() * mat.ww())
		+ (mat.xz() * mat.zw() * mat.wy())
		+ (mat.xw() * mat.zy() * mat.wz())
		- (mat.xw() * mat.zz() * mat.wy())
		- (mat.xy() * mat.zw() * mat.wz())
		- (mat.xz() * mat.zy() * mat.ww()));

	float cof_yy = 1.0f * 
		((mat.xx() * mat.zz() * mat.ww())
		+ (mat.xz() * mat.zw() * mat.wx()) 
		+ (mat.xw() * mat.zx() * mat.wz()) 
		- (mat.xw() * mat.zz() * mat.wx())
		- (mat.xx() * mat.zw() * mat.wz()) 
		- (mat.xz() * mat.zx() * mat.ww()));

	float cof_yz = -1.0f * 
		((mat.xx() * mat.zy() * mat.ww()) 
		+ (mat.xy() * mat.zw() * mat.wx()) 
		+ (mat.xw() * mat.zx() * mat.wy()) 
		- (mat.xw() * mat.zy() * mat.wx()) 
		- (mat.xx() * mat.zw() * mat.wy()) 
		- (mat.xy() * mat.zx() * mat.ww()));

	float cof_yw = 1.0f *
		((mat.xx() * mat.zy() * mat.wz())
		+ (mat.xy() * mat.zz() * mat.wx()) 
		+ (mat.xz() * mat.zx() * mat.wy())
		- (mat.xz() * mat.zy() * mat.wx()) 
		- (mat.xx() * mat.zz() * mat.wy()) 
		- (mat.xy() * mat.zx() * mat.wz()));

	float cof_zx = 1.0f * 
		((mat.xy() * mat.yz() * mat.ww())
		+ (mat.xz() * mat.yw() * mat.wy())
		+ (mat.xw() * mat.yy() * mat.wz())
		- (mat.xw() * mat.yz() * mat.wy())
		- (mat.xy() * mat.yw() * mat.wz()) 
		- (mat.xz() * mat.yy() * mat.ww()));

	float cof_zy = -1.0f * 
		((mat.xx() * mat.yz() * mat.ww()) 
		+ (mat.xz() * mat.yw() * mat.wx())
		+ (mat.xw() * mat.yx() * mat.wz()) 
		- (mat.xw() * mat.yz() * mat.wx()) 
		- (mat.xx() * mat.yw() * mat.wz()) 
		- (mat.xz() * mat.yx() * mat.ww()));

	float cof_zz = 1.0f * 
		((mat.xx() * mat.yy() * mat.ww()) 
		+ (mat.xy() * mat.yw() * mat.wx()) 
		+ (mat.xw() * mat.yx() * mat.wy()) 
		- (mat.xw() * mat.yy() * mat.wx()) 
		- (mat.xx() * mat.yw() * mat.wy()) 
		- (mat.xy() * mat.yx() * mat.ww()));
	
	float cof_zw = -1.0f *
		((mat.xx() * mat.yy() * mat.wz()) 
		+ (mat.xy() * mat.yz() * mat.wx()) 
		+ (mat.xz() * mat.yx() * mat.wy()) 
		- (mat.xz() * mat.yy() * mat.wx()) 
		- (mat.xx() * mat.yz() * mat.wy()) 
		- (mat.xy() * mat.yx() * mat.wz()));

	float cof_wx = -1.0f *
		((mat.xy() * mat.yz() * mat.zw()) 
		+ (mat.xz() * mat.yw() * mat.zy())
		+ (mat.xw() * mat.yy() * mat.zz()) 
		- (mat.xw() * mat.yz() * mat.zy()) 
		- (mat.xy() * mat.yw() * mat.zz()) 
		- (mat.xz() * mat.yy() * mat.zw()));

	float cof_wy = 1.0f * 
		((mat.xx() * mat.yz() * mat.zw()) 
		+ (mat.xz() * mat.yw() * mat.zx()) 
		+ (mat.xw() * mat.yx() * mat.zz()) 
		- (mat.xw() * mat.yz() * mat.zx()) 
		- (mat.xx() * mat.yw() * mat.zz()) 
		- (mat.xz() * mat.yx() * mat.zw()));

	float cof_wz = -1.0f * 
		((mat.xx() * mat.yy() * mat.zw()) 
		+ (mat.xy() * mat.yw() * mat.zx()) 
		+ (mat.xw() * mat.yx() * mat.zy()) 
		- (mat.xw() * mat.yy() * mat.zx()) 
		- (mat.xx() * mat.yw() * mat.zy())
		- (mat.xy() * mat.yx() * mat.zw()));

	float cof_ww = 1.0f * 
		((mat.xx() * mat.yy() * mat.zz()) 
		+ (mat.xy() * mat.yz() * mat.zx()) 
		+ (mat.xz() * mat.yx() * mat.zy()) 
		- (mat.xz() * mat.yy() * mat.zx()) 
		- (mat.xx() * mat.yz() * mat.zy()) 
		- (mat.xy() * mat.yx() * mat.zz()));

	float xx = recip_det * cof_xx;
	float xy = recip_det * cof_yx;
	float xz = recip_det * cof_zx;
	float xw = recip_det * cof_wx;

	float yx = recip_det * cof_xy;
	float yy = recip_det * cof_yy;
	float yz = recip_det * cof_zy;
	float yw = recip_det * cof_wy;

	float zx = recip_det * cof_xz;
	float zy = recip_det * cof_yz;
	float zz = recip_det * cof_zz;
	float zw = recip_det * cof_wz;

	float wx = recip_det * cof_xw;
	float wy = recip_det * cof_yw;
	float wz = recip_det * cof_zw;
	float ww = recip_det * cof_ww;

	return Matrix4x4(
		xx, xy, xz, xw,
		yx, yy, yz, yw,
		zx, zy, zz, zw,
		wx, wy, wz, ww
	);
}

Matrix4x4 dyaProdukt(Vektor3D lhs, Vektor3D rhs) {
	return Matrix4x4(
		lhs.x() * rhs.x(), lhs.x() * rhs.y(), lhs.x() * rhs.z(), 0.0f,
		lhs.y() * rhs.x(), lhs.y() * rhs.y(), lhs.y() * rhs.z(), 0.0f,
		lhs.z() * rhs.x(), lhs.z() * rhs.y(), lhs.z() * rhs.z(), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Matrix4x4 rotationMatrix(Vektor3D axis, float angle) {

	float t1 = 1.0f - cosf(angle);

	if (std::abs(axis.lenSq() - 1.0f) >= FLT_EPSILON) {
		axis.normalize();
	}

	Matrix4x4 m1 = dyaProdukt(axis, axis);

	return  Matrix4x4(
		t1 * m1.xx() + cosf(angle),
		t1 * m1.xy() + sinf(angle) * -axis.z(),
		t1 * m1.xz() + sinf(angle) * axis.y(),
		0.0f,
		t1 * m1.yx() + sinf(angle) * axis.z(),
		t1 * m1.yy() + cosf(angle),
		t1 * m1.yz() + sinf(angle) * -axis.x(),
		0.0f,
		t1 * m1.zx() + sinf(angle) * -axis.y(),
		t1 * m1.zy() + sinf(angle) * axis.x(),
		t1 * m1.zz() + cosf(angle),
		0.0f,
		0.0f,
		0.0f,
		0.0f,
		1.0f
	);
}