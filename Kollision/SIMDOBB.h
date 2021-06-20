#pragma once
#include "SIMDVektor3D.h"
#include "SIMDPoint3D.h"
#include "SIMDQuaternion.h"

class SIMDOBB {
private:
	SIMDPoint3D c_;

	union {
		struct {
			SIMDVektor3D ux_;
			SIMDVektor3D uy_;
			SIMDVektor3D uz_;
		};
		SIMDVektor3D u_[3];
	};

	union {
		struct {
			float ex_;
			float ey_;
			float ez_;
		};
		float e_[3];
	};

public:

	SIMDOBB() : c_(NAN, NAN, NAN),
		ux_(NAN, NAN, NAN), uy_(NAN, NAN, NAN), uz_(NAN, NAN, NAN),
		ex_(NAN), ey_(NAN), ez_(NAN) { }
	
	SIMDOBB(SIMDPoint3D center,
		SIMDVektor3D ux, SIMDVektor3D uy, SIMDVektor3D uz,
		float ex, float ey, float ez) :
		c_(center), ux_(ux), uy_(uy), uz_(uz), ex_(ex), ey_(ey), ez_(ez) { }

	SIMDPoint3D center() const {
		return c_;
	}

	SIMDVektor3D ux() const {
		return ux_;
	}

	SIMDVektor3D uy() const {
		return uy_;
	}

	SIMDVektor3D uz() const {
		return uz_;
	}

	float ex() const {
		return ex_;
	}

	float ey() const {
		return ey_;
	}

	float ez() const {
		return ez_;
	}

};

// OBB ohne uz
class SIMDOBB_V2 {
private:
	SIMDPoint3D c_;

	SIMDVektor3D ux_;
	SIMDVektor3D uy_;

	float ex_;
	float ey_;
	float ez_;

public:

	SIMDOBB_V2() : c_(NAN, NAN, NAN),
		ux_(NAN, NAN, NAN), uy_(NAN, NAN, NAN),
		ex_(NAN), ey_(NAN), ez_(NAN) { }

	SIMDOBB_V2(SIMDPoint3D center,
		SIMDVektor3D ux, SIMDVektor3D uy,
		float ex, float ey, float ez) :
		c_(center), ux_(ux), uy_(uy), ex_(ex), ey_(ey), ez_(ez) { }

	SIMDPoint3D center() const {
		return c_;
	}

	SIMDVektor3D ux() const {
		return ux_;
	}

	SIMDVektor3D uy() const {
		return uy_;
	}

	float ex() const {
		return ex_;
	}

	float ey() const {
		return ey_;
	}

	float ez() const {
		return ez_;
	}

};

// OBB mit Quaternion
class SIMDOBB_V4 {
private:
	SIMDPoint3D c_;

	SIMDQuaternion orientation_;

	float ex_;
	float ey_;
	float ez_;

public:

	SIMDOBB_V4() : c_(NAN, NAN, NAN),
		orientation_(NAN, NAN, NAN, NAN),
		ex_(NAN), ey_(NAN), ez_(NAN) { }

	SIMDOBB_V4(SIMDPoint3D center,
		SIMDVektor3D ux, SIMDVektor3D uy, SIMDVektor3D uz,
		float ex, float ey, float ez) :
		c_(center), ex_(ex), ey_(ey), ez_(ez) {
	
		orientation_ = toSIMDQuaternion(Matrix4x4(ux.x(), uy.x(), uz.x(), 0.0f,
												  ux.y(), uy.y(), uz.y(), 0.0f,
											      ux.z(), uy.z(), uz.z(), 0.0f,
											      0.0f, 0.0f, 0.0f, 1.0f));

	}

	SIMDPoint3D center() const {
		return c_;
	}

	SIMDQuaternion orientation() const {
		return orientation_;
	}

	float ex() const {
		return ex_;
	}

	float ey() const {
		return ey_;
	}

	float ez() const {
		return ez_;
	}

};


std::ostream& operator<<(std::ostream& os, const SIMDOBB& b) {
	os << "Center:\t" << b.center() << '\n';
	os << "Ux:\t" << b.ux() << '\n';
	os << "Uy:\t" << b.uy() << '\n';
	os << "Uz:\t" << b.uz() << '\n';
	os << "Ex:\t" << b.ex() << '\n';
	os << "Ey:\t" << b.ey() << '\n';
	os << "Ez:\t" << b.ez() << '\n';
	return os;
}