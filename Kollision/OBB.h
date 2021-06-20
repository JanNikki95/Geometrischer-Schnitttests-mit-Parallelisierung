#pragma once
#include "Point3D.h"
#include "Quaternion.h"

class OBB {
private:
	Point3D c_;

	union {
		struct {
			Vektor3D ux_;
			Vektor3D uy_;
			Vektor3D uz_;
		};
		Vektor3D u_[3];
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

	OBB() : 
		c_(NAN, NAN, NAN),
		ux_(NAN, NAN, NAN), uy_(NAN, NAN, NAN), uz_(NAN, NAN, NAN),
		ex_(NAN), ey_(NAN), ez_(NAN) { }

	OBB(Point3D center, Vektor3D ux, Vektor3D uy, Vektor3D uz, float ex, float ey, float ez) :
		c_(center), 
		ux_(ux), uy_(uy), uz_(uz),
		ex_(ex), ey_(ey), ez_(ez) { }

	Point3D center() const {
		return c_;
	}

	Vektor3D ux() const {
		return ux_;
	}

	Vektor3D uy() const {
		return uy_;
	}

	Vektor3D uz() const {
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
class OBB_V2 {
private:
	Point3D c_;

	Vektor3D ux_;
	Vektor3D uy_;

	float ex_;
	float ey_;
	float ez_;

public:

	OBB_V2() :
		c_(NAN, NAN, NAN),
		ux_(NAN, NAN, NAN), uy_(NAN, NAN, NAN),
		ex_(NAN), ey_(NAN), ez_(NAN) { }

	OBB_V2(Point3D center, Vektor3D ux, Vektor3D uy, float ex, float ey, float ez) :
		c_(center),
		ux_(ux), uy_(uy),
		ex_(ex), ey_(ey), ez_(ez) { }

	Point3D center() const {
		return c_;
	}

	Vektor3D ux() const {
		return ux_;
	}

	Vektor3D uy() const {
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
class OBB_V4 {
private:
	Point3D c_;

	Quaternion orientation_;
	
	float ex_;
	float ey_;
	float ez_;
public:

	OBB_V4() :
		c_(NAN, NAN, NAN),
		orientation_(NAN, NAN, NAN, NAN),
		ex_(NAN), ey_(NAN), ez_(NAN) { }

	OBB_V4(Point3D center, Vektor3D ux, Vektor3D uy, Vektor3D uz, float ex, float ey, float ez) :
		c_(center),
		ex_(ex), ey_(ey), ez_(ez) {

		orientation_ = toQuaternion( Matrix4x4(	ux.x(), uy.x(), uz.x(), 0.0f,
												ux.y(), uy.y(), uz.y(), 0.0f, 
												ux.z(), uy.z(), uz.z(), 0.0f,
												0.0f,	0.0f,	0.0f,	1.0f) );
	
	}

	Point3D center() const {
		return c_;
	}

	Quaternion orientation() const {
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

std::ostream& operator<<(std::ostream& os, const OBB& b) {
	os << "Center:\t" << b.center() << '\n';
	os << "Ux:\t" << b.ux() << '\n';
	os << "Uy:\t" << b.uy() << '\n';
	os << "Uz:\t" << b.uz() << '\n';
	os << "Ex:\t" << b.ex() << '\n';
	os << "Ey:\t" << b.ey() << '\n';
	os << "Ez:\t" << b.ez() << '\n';
	return os;
}