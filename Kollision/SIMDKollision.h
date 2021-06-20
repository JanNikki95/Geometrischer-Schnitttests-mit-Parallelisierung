#pragma once
#include <algorithm>
#include "SIMDOBB.h"

// Reines Seperating Axis Theorem
bool TestOBBOBB_V1(const SIMDOBB& a, const SIMDOBB& b) {

	SIMDPoint3D a_vertex[8] = {
		a.center() + (a.ex() * a.ux()) + (a.ey() * a.uy()) + (a.ez() * a.uz()),
		a.center() + (a.ex() * a.ux()) + (a.ey() * a.uy()) - (a.ez() * a.uz()),
		a.center() + (a.ex() * a.ux()) - (a.ey() * a.uy()) + (a.ez() * a.uz()),
		a.center() + (a.ex() * a.ux()) - (a.ey() * a.uy()) - (a.ez() * a.uz()),
		a.center() - (a.ex() * a.ux()) + (a.ey() * a.uy()) + (a.ez() * a.uz()),
		a.center() - (a.ex() * a.ux()) + (a.ey() * a.uy()) - (a.ez() * a.uz()),
		a.center() - (a.ex() * a.ux()) - (a.ey() * a.uy()) + (a.ez() * a.uz()),
		a.center() - (a.ex() * a.ux()) - (a.ey() * a.uy()) - (a.ez() * a.uz())
	};

	SIMDPoint3D b_vertex[8] = {
		b.center() + (b.ex() * b.ux()) + (b.ey() * b.uy()) + (b.ez() * b.uz()),
		b.center() + (b.ex() * b.ux()) + (b.ey() * b.uy()) - (b.ez() * b.uz()),
		b.center() + (b.ex() * b.ux()) - (b.ey() * b.uy()) + (b.ez() * b.uz()),
		b.center() + (b.ex() * b.ux()) - (b.ey() * b.uy()) - (b.ez() * b.uz()),
		b.center() - (b.ex() * b.ux()) + (b.ey() * b.uy()) + (b.ez() * b.uz()),
		b.center() - (b.ex() * b.ux()) + (b.ey() * b.uy()) - (b.ez() * b.uz()),
		b.center() - (b.ex() * b.ux()) - (b.ey() * b.uy()) + (b.ez() * b.uz()),
		b.center() - (b.ex() * b.ux()) - (b.ey() * b.uy()) - (b.ez() * b.uz())
	};

	SIMDVektor3D L = a.ux();
	float min_a = dot(L, a_vertex[0]), max_a = dot(L, a_vertex[0]);
	float min_b = dot(L, b_vertex[0]), max_b = dot(L, b_vertex[0]);

	for (size_t i = 1; i < 8; ++i) {
		float projection_a = dot(L, a_vertex[i]);
		float projection_b = dot(L, b_vertex[i]);

		min_a = std::min(projection_a, min_a);
		max_a = std::max(projection_a, max_a);

		min_b = std::min(projection_b, min_b);
		max_b = std::max(projection_b, max_b);
	}
	if (max_a < min_b || min_a > max_b) return false;

	L = a.uy();
	min_a = dot(L, a_vertex[0]), max_a = dot(L, a_vertex[0]);
	min_b = dot(L, b_vertex[0]), max_b = dot(L, b_vertex[0]);

	for (size_t i = 1; i < 8; ++i) {
		float projection_a = dot(L, a_vertex[i]);
		float projection_b = dot(L, b_vertex[i]);

		min_a = std::min(projection_a, min_a);
		max_a = std::max(projection_a, max_a);

		min_b = std::min(projection_b, min_b);
		max_b = std::max(projection_b, max_b);
	}
	if (max_a < min_b || min_a > max_b) return false;

	L = a.uz();
	min_a = dot(L, a_vertex[0]), max_a = dot(L, a_vertex[0]);
	min_b = dot(L, b_vertex[0]), max_b = dot(L, b_vertex[0]);

	for (size_t i = 1; i < 8; ++i) {
		float projection_a = dot(L, a_vertex[i]);
		float projection_b = dot(L, b_vertex[i]);

		min_a = std::min(projection_a, min_a);
		max_a = std::max(projection_a, max_a);

		min_b = std::min(projection_b, min_b);
		max_b = std::max(projection_b, max_b);
	}
	if (max_a < min_b || min_a > max_b) return false;

	L = b.ux();
	min_a = dot(L, a_vertex[0]), max_a = dot(L, a_vertex[0]);
	min_b = dot(L, b_vertex[0]), max_b = dot(L, b_vertex[0]);

	for (size_t i = 1; i < 8; ++i) {
		float projection_a = dot(L, a_vertex[i]);
		float projection_b = dot(L, b_vertex[i]);

		min_a = std::min(projection_a, min_a);
		max_a = std::max(projection_a, max_a);

		min_b = std::min(projection_b, min_b);
		max_b = std::max(projection_b, max_b);
	}
	if (max_a < min_b || min_a > max_b) return false;

	L = b.uy();
	min_a = dot(L, a_vertex[0]), max_a = dot(L, a_vertex[0]);
	min_b = dot(L, b_vertex[0]), max_b = dot(L, b_vertex[0]);

	for (size_t i = 1; i < 8; ++i) {
		float projection_a = dot(L, a_vertex[i]);
		float projection_b = dot(L, b_vertex[i]);

		min_a = std::min(projection_a, min_a);
		max_a = std::max(projection_a, max_a);

		min_b = std::min(projection_b, min_b);
		max_b = std::max(projection_b, max_b);
	}
	if (max_a < min_b || min_a > max_b) return false;

	L = b.uz();
	min_a = dot(L, a_vertex[0]), max_a = dot(L, a_vertex[0]);
	min_b = dot(L, b_vertex[0]), max_b = dot(L, b_vertex[0]);

	for (size_t i = 1; i < 8; ++i) {
		float projection_a = dot(L, a_vertex[i]);
		float projection_b = dot(L, b_vertex[i]);

		min_a = std::min(projection_a, min_a);
		max_a = std::max(projection_a, max_a);

		min_b = std::min(projection_b, min_b);
		max_b = std::max(projection_b, max_b);
	}
	if (max_a < min_b || min_a > max_b) return false;

	L = cross(a.ux(), b.ux());
	min_a = dot(L, a_vertex[0]), max_a = dot(L, a_vertex[0]);
	min_b = dot(L, b_vertex[0]), max_b = dot(L, b_vertex[0]);

	for (size_t i = 1; i < 8; ++i) {
		float projection_a = dot(L, a_vertex[i]);
		float projection_b = dot(L, b_vertex[i]);

		min_a = std::min(projection_a, min_a);
		max_a = std::max(projection_a, max_a);

		min_b = std::min(projection_b, min_b);
		max_b = std::max(projection_b, max_b);
	}
	if (max_a < min_b || min_a > max_b) return false;

	L = cross(a.ux(), b.uy());
	min_a = dot(L, a_vertex[0]), max_a = dot(L, a_vertex[0]);
	min_b = dot(L, b_vertex[0]), max_b = dot(L, b_vertex[0]);

	for (size_t i = 1; i < 8; ++i) {
		float projection_a = dot(L, a_vertex[i]);
		float projection_b = dot(L, b_vertex[i]);

		min_a = std::min(projection_a, min_a);
		max_a = std::max(projection_a, max_a);

		min_b = std::min(projection_b, min_b);
		max_b = std::max(projection_b, max_b);
	}
	if (max_a < min_b || min_a > max_b) return false;

	L = cross(a.ux(), b.uz());
	min_a = dot(L, a_vertex[0]), max_a = dot(L, a_vertex[0]);
	min_b = dot(L, b_vertex[0]), max_b = dot(L, b_vertex[0]);

	for (size_t i = 1; i < 8; ++i) {
		float projection_a = dot(L, a_vertex[i]);
		float projection_b = dot(L, b_vertex[i]);

		min_a = std::min(projection_a, min_a);
		max_a = std::max(projection_a, max_a);

		min_b = std::min(projection_b, min_b);
		max_b = std::max(projection_b, max_b);
	}
	if (max_a < min_b || min_a > max_b) return false;

	L = cross(a.uy(), b.ux());
	min_a = dot(L, a_vertex[0]), max_a = dot(L, a_vertex[0]);
	min_b = dot(L, b_vertex[0]), max_b = dot(L, b_vertex[0]);

	for (size_t i = 1; i < 8; ++i) {
		float projection_a = dot(L, a_vertex[i]);
		float projection_b = dot(L, b_vertex[i]);

		min_a = std::min(projection_a, min_a);
		max_a = std::max(projection_a, max_a);

		min_b = std::min(projection_b, min_b);
		max_b = std::max(projection_b, max_b);
	}
	if (max_a < min_b || min_a > max_b) return false;

	L = cross(a.uy(), b.uy());
	min_a = dot(L, a_vertex[0]), max_a = dot(L, a_vertex[0]);
	min_b = dot(L, b_vertex[0]), max_b = dot(L, b_vertex[0]);

	for (size_t i = 1; i < 8; ++i) {
		float projection_a = dot(L, a_vertex[i]);
		float projection_b = dot(L, b_vertex[i]);

		min_a = std::min(projection_a, min_a);
		max_a = std::max(projection_a, max_a);

		min_b = std::min(projection_b, min_b);
		max_b = std::max(projection_b, max_b);
	}
	if (max_a < min_b || min_a > max_b) return false;

	L = cross(a.uy(), b.uz());
	min_a = dot(L, a_vertex[0]), max_a = dot(L, a_vertex[0]);
	min_b = dot(L, b_vertex[0]), max_b = dot(L, b_vertex[0]);

	for (size_t i = 1; i < 8; ++i) {
		float projection_a = dot(L, a_vertex[i]);
		float projection_b = dot(L, b_vertex[i]);

		min_a = std::min(projection_a, min_a);
		max_a = std::max(projection_a, max_a);

		min_b = std::min(projection_b, min_b);
		max_b = std::max(projection_b, max_b);
	}
	if (max_a < min_b || min_a > max_b) return false;

	L = cross(a.uz(), b.ux());
	min_a = dot(L, a_vertex[0]), max_a = dot(L, a_vertex[0]);
	min_b = dot(L, b_vertex[0]), max_b = dot(L, b_vertex[0]);

	for (size_t i = 1; i < 8; ++i) {
		float projection_a = dot(L, a_vertex[i]);
		float projection_b = dot(L, b_vertex[i]);

		min_a = std::min(projection_a, min_a);
		max_a = std::max(projection_a, max_a);

		min_b = std::min(projection_b, min_b);
		max_b = std::max(projection_b, max_b);
	}
	if (max_a < min_b || min_a > max_b) return false;

	L = cross(a.uz(), b.uy());
	min_a = dot(L, a_vertex[0]), max_a = dot(L, a_vertex[0]);
	min_b = dot(L, b_vertex[0]), max_b = dot(L, b_vertex[0]);

	for (size_t i = 1; i < 8; ++i) {
		float projection_a = dot(L, a_vertex[i]);
		float projection_b = dot(L, b_vertex[i]);

		min_a = std::min(projection_a, min_a);
		max_a = std::max(projection_a, max_a);

		min_b = std::min(projection_b, min_b);
		max_b = std::max(projection_b, max_b);
	}
	if (max_a < min_b || min_a > max_b) return false;

	L = cross(a.uz(), b.uz());
	min_a = dot(L, a_vertex[0]), max_a = dot(L, a_vertex[0]);
	min_b = dot(L, b_vertex[0]), max_b = dot(L, b_vertex[0]);

	for (size_t i = 1; i < 8; ++i) {
		float projection_a = dot(L, a_vertex[i]);
		float projection_b = dot(L, b_vertex[i]);

		min_a = std::min(projection_a, min_a);
		max_a = std::max(projection_a, max_a);

		min_b = std::min(projection_b, min_b);
		max_b = std::max(projection_b, max_b);
	}
	if (max_a < min_b || min_a > max_b) return false;

	return true;
}

// Seperating Axis Theorem speziell für OBBs
bool TestOBBOBB_V2(const SIMDOBB& a, const SIMDOBB& b)  {
	SIMDVektor3D D = a.center() - b.center();

	SIMDVektor3D L = a.ux();
	float distance = std::abs(dot(L, D));
	float ra = a.ex();
	float rb = std::abs(b.ex() * dot(L, b.ux()))
		+ std::abs(b.ey() * dot(L, b.uy()))
		+ std::abs(b.ez() * dot(L, b.uz()));
	if (distance > ra + rb) return false;


	L = a.uy();
	distance = std::abs(dot(L, D));
	ra = a.ey();
	rb = std::abs(b.ex() * dot(L, b.ux()))
		+ std::abs(b.ey() * dot(L, b.uy()))
		+ std::abs(b.ez() * dot(L, b.uz()));
	if (distance > ra + rb) return false;

	L = a.uz();
	distance = std::abs(dot(L, D));
	ra = a.ez();
	rb = std::abs(b.ex() * dot(L, b.ux()))
		+ std::abs(b.ey() * dot(L, b.uy()))
		+ std::abs(b.ez() * dot(L, b.uz()));
	if (distance > ra + rb) return false;

	L = b.ux();
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * dot(L, a.ux()))
		+ std::abs(a.ey() * dot(L, a.uy()))
		+ std::abs(a.ez() * dot(L, a.uz()));
	rb = b.ex();
	if (distance > ra + rb) return false;


	L = b.uy();
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * dot(L, a.ux()))
		+ std::abs(a.ey() * dot(L, a.uy()))
		+ std::abs(a.ez() * dot(L, a.uz()));
	rb = b.ey();
	if (distance > ra + rb) return false;


	L = b.uz();
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * dot(L, a.ux()))
		+ std::abs(a.ey() * dot(L, a.uy()))
		+ std::abs(a.ez() * dot(L, a.uz()));
	rb = b.ez();
	if (distance > ra + rb) return false;


	L = cross(a.ux(), b.ux());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ey() * dot(a.uz(), b.ux()))
		+ std::abs(a.ez() * dot(a.uy(), b.ux()));
	rb = std::abs(b.ey() * dot(a.ux(), b.uz()))
		+ std::abs(b.ez() * dot(a.ux(), b.uy()));
	if (distance > ra + rb) return false;

	L = cross(a.ux(), b.uy());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ey() * dot(a.uz(), b.uy()))
		+ std::abs(a.ez() * dot(a.uy(), b.uy()));
	rb = std::abs(b.ex() * dot(a.ux(), b.uz()))
		+ std::abs(b.ez() * dot(a.ux(), b.ux()));
	if (distance > ra + rb) return false;


	L = cross(a.ux(), b.uz());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ey() * dot(a.uz(), b.uz()))
		+ std::abs(a.ez() * dot(a.uy(), b.uz()));
	rb = std::abs(b.ex() * dot(a.ux(), b.uy()))
		+ std::abs(b.ey() * dot(a.ux(), b.ux()));
	if (distance > ra + rb) return false;


	L = cross(a.uy(), b.ux());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * dot(a.uz(), b.ux()))
		+ std::abs(a.ez() * dot(a.ux(), b.ux()));
	rb = std::abs(b.ey() * dot(a.uy(), b.uz()))
		+ std::abs(b.ez() * dot(a.uy(), b.uy()));
	if (distance > ra + rb) return false;


	L = cross(a.uy(), b.uy());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * dot(a.uz(), b.uy()))
		+ std::abs(a.ez() * dot(a.ux(), b.uy()));
	rb = std::abs(b.ex() * dot(a.uy(), b.uz()))
		+ std::abs(b.ez() * dot(a.uy(), b.ux()));
	if (distance > ra + rb) return false;


	L = cross(a.uy(), b.uz());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * dot(a.uz(), b.uz()))
		+ std::abs(a.ez() * dot(a.ux(), b.uz()));
	rb = std::abs(b.ex() * dot(a.uy(), b.uy()))
		+ std::abs(b.ey() * dot(a.uy(), b.ux()));
	if (distance > ra + rb) return false;


	L = cross(a.uz(), b.ux());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * dot(a.uy(), b.ux()))
		+ std::abs(a.ey() * dot(a.ux(), b.ux()));
	rb = std::abs(b.ey() * dot(a.uz(), b.uz()))
		+ std::abs(b.ez() * dot(a.uz(), b.uy()));
	if (distance > ra + rb) return false;


	L = cross(a.uz(), b.uy());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * dot(a.uy(), b.uy()))
		+ std::abs(a.ey() * dot(a.ux(), b.uy()));
	rb = std::abs(b.ex() * dot(a.uz(), b.uz()))
		+ std::abs(b.ez() * dot(a.uz(), b.ux()));
	if (distance > ra + rb) return false;


	L = cross(a.uz(), b.uz());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * dot(a.uy(), b.uz()))
		+ std::abs(a.ey() * dot(a.ux(), b.uz()));
	rb = std::abs(b.ex() * dot(a.uz(), b.uy()))
		+ std::abs(b.ey() * dot(a.uz(), b.ux()));
	if (distance > ra + rb) return false;

	return true;
}

// Seperating Axis Theorem speziell für OBBs
// mit Zwischenspeicherung
bool TestOBBOBB_V3(const SIMDOBB& a, const SIMDOBB& b) {
	SIMDVektor3D D = a.center() - b.center();

	float Sxx;	float Syx; float Szx;
	float Sxy;	float Syy; float Szy;
	float Sxz;	float Syz; float Szz;

	SIMDVektor3D L = a.ux();
	float distance = std::abs(dot(L, D));
	float ra = a.ex();

	Sxx = dot(L, b.ux());
	Sxy = dot(L, b.uy());
	Sxz = dot(L, b.uz());

	float rb = std::abs(b.ex() * Sxx)
		+ std::abs(b.ey() * Sxy)
		+ std::abs(b.ez() * Sxz);
	if (distance > ra + rb) return false;

	L = a.uy();
	distance = std::abs(dot(L, D));
	ra = a.ey();

	Syx = dot(L, b.ux());
	Syy = dot(L, b.uy());
	Syz = dot(L, b.uz());

	rb = std::abs(b.ex() * Syx)
		+ std::abs(b.ey() * Syy)
		+ std::abs(b.ez() * Syz);
	if (distance > ra + rb) return false;


	L = a.uz();
	distance = std::abs(dot(L, D));
	ra = a.ez();

	Szx = dot(L, b.ux());
	Szy = dot(L, b.uy());
	Szz = dot(L, b.uz());

	rb = std::abs(b.ex() * Szx)
		+ std::abs(b.ey() * Szy)
		+ std::abs(b.ez() * Szz);
	if (distance > ra + rb) return false;


	L = b.ux();
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * Sxx)
		+ std::abs(a.ey() * Syx)
		+ std::abs(a.ez() * Szx);
	rb = b.ex();
	if (distance > ra + rb) return false;


	L = b.uy();
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * Sxy)
		+ std::abs(a.ey() * Syy)
		+ std::abs(a.ez() * Szy);
	rb = b.ey();
	if (distance > ra + rb) return false;

	L = b.uz();
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * Sxz)
		+ std::abs(a.ey() * Syz)
		+ std::abs(a.ez() * Szz);
	rb = b.ez();
	if (distance > ra + rb) return false;


	L = cross(a.ux(), b.ux());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ey() * Szx)
		+ std::abs(a.ez() * Syx);
	rb = std::abs(b.ey() * Sxz)
		+ std::abs(b.ez() * Sxy);
	if (distance > ra + rb) return false;

	L = cross(a.ux(), b.uy());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ey() * Szy)
		+ std::abs(a.ez() * Syy);
	rb = std::abs(b.ex() * Sxz)
		+ std::abs(b.ez() * Sxx);
	if (distance > ra + rb) return false;


	L = cross(a.ux(), b.uz());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ey() * Szz)
		+ std::abs(a.ez() * Syz);
	rb = std::abs(b.ex() * Sxy)
		+ std::abs(b.ey() * Sxx);
	if (distance > ra + rb) return false;


	L = cross(a.uy(), b.ux());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * Szx)
		+ std::abs(a.ez() * Sxx);
	rb = std::abs(b.ey() * Syz)
		+ std::abs(b.ez() * Syy);
	if (distance > ra + rb) return false;

	L = cross(a.uy(), b.uy());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * Szy)
		+ std::abs(a.ez() * Sxy);
	rb = std::abs(b.ex() * Syz)
		+ std::abs(b.ez() * Syx);
	if (distance > ra + rb) return false;


	L = cross(a.uy(), b.uz());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * Szz)
		+ std::abs(a.ez() * Sxz);
	rb = std::abs(b.ex() * Syy)
		+ std::abs(b.ey() * Syx);
	if (distance > ra + rb) return false;


	L = cross(a.uz(), b.ux());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * Syx)
		+ std::abs(a.ey() * Sxx);
	rb = std::abs(b.ey() * Szz)
		+ std::abs(b.ez() * Szy);
	if (distance > ra + rb) return false;

	L = cross(a.uz(), b.uy());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * Syy)
		+ std::abs(a.ey() * Sxy);
	rb = std::abs(b.ex() * Szz)
		+ std::abs(b.ez() * Szx);
	if (distance > ra + rb) return false;

	L = cross(a.uz(), b.uz());
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * Syz)
		+ std::abs(a.ey() * Sxz);
	rb = std::abs(b.ex() * Szy)
		+ std::abs(b.ey() * Szx);

	if (distance > ra + rb) return false;

	return true;
}

// Seperating Axis Theorem speziell für OBBs
// mit Zwischenspeicherung
// ohne Kreuzprodukt
bool TestOBBOBB_V4(const SIMDOBB& a, const SIMDOBB& b) {
	SIMDVektor3D D = a.center() - b.center();

	float Sxx;	float Syx; float Szx;
	float Sxy;	float Syy; float Szy;
	float Sxz;	float Syz; float Szz;

	float Dax, Day, Daz;
	float Dbx, Dby, Dbz;

	SIMDVektor3D L = a.ux();
	Dax = dot(L, D);
	float distance = std::abs(Dax);
	float ra = a.ex();

	Sxx = dot(L, b.ux());
	Sxy = dot(L, b.uy());
	Sxz = dot(L, b.uz());

	float rb = std::abs(b.ex() * Sxx)
		+ std::abs(b.ey() * Sxy)
		+ std::abs(b.ez() * Sxz);
	if (distance > ra + rb) return false;

	L = a.uy();
	Day = dot(L, D);
	distance = std::abs(Day);
	ra = a.ey();

	Syx = dot(L, b.ux());
	Syy = dot(L, b.uy());
	Syz = dot(L, b.uz());

	rb = std::abs(b.ex() * Syx)
		+ std::abs(b.ey() * Syy)
		+ std::abs(b.ez() * Syz);
	if (distance > ra + rb) return false;


	L = a.uz();
	Daz = dot(L, D);
	distance = std::abs(Daz);
	ra = a.ez();

	Szx = dot(L, b.ux());
	Szy = dot(L, b.uy());
	Szz = dot(L, b.uz());

	rb = std::abs(b.ex() * Szx)
		+ std::abs(b.ey() * Szy)
		+ std::abs(b.ez() * Szz);
	if (distance > ra + rb) return false;


	L = b.ux();
	Dbx = dot(L, D);
	distance = std::abs(Dbx);
	ra = std::abs(a.ex() * Sxx)
		+ std::abs(a.ey() * Syx)
		+ std::abs(a.ez() * Szx);
	rb = b.ex();
	if (distance > ra + rb) return false;


	L = b.uy();
	Dby = dot(L, D);
	distance = std::abs(Dby);
	ra = std::abs(a.ex() * Sxy)
		+ std::abs(a.ey() * Syy)
		+ std::abs(a.ez() * Szy);
	rb = b.ey();
	if (distance > ra + rb) return false;

	L = b.uz();
	Dbz = dot(L, D);
	distance = std::abs(Dbz);
	ra = std::abs(a.ex() * Sxz)
		+ std::abs(a.ey() * Syz)
		+ std::abs(a.ez() * Szz);
	rb = b.ez();
	if (distance > ra + rb) return false;

	// Achse X x X
	distance = std::abs(Syx * Daz - Szx * Day);
	ra = std::abs(a.ey() * Szx)
		+ std::abs(a.ez() * Syx);
	rb = std::abs(b.ey() * Sxz)
		+ std::abs(b.ez() * Sxy);
	if (distance > ra + rb) return false;

	// Achse X x Y
	distance = std::abs(Syy * Daz - Szy * Day);
	ra = std::abs(a.ey() * Szy)
		+ std::abs(a.ez() * Syy);
	rb = std::abs(b.ex() * Sxz)
		+ std::abs(b.ez() * Sxx);
	if (distance > ra + rb) return false;


	// Achse X x Z
	distance = std::abs(Syz * Daz - Szz * Day);
	ra = std::abs(a.ey() * Szz)
		+ std::abs(a.ez() * Syz);
	rb = std::abs(b.ex() * Sxy)
		+ std::abs(b.ey() * Sxx);
	if (distance > ra + rb) return false;


	// Achse Y x X
	distance = std::abs(Szx * Dax - Sxx * Daz);
	ra = std::abs(a.ex() * Szx)
		+ std::abs(a.ez() * Sxx);
	rb = std::abs(b.ey() * Syz)
		+ std::abs(b.ez() * Syy);
	if (distance > ra + rb) return false;

	// Achse Y x Y
	distance = std::abs(Szy * Dax - Sxy * Daz);
	ra = std::abs(a.ex() * Szy)
		+ std::abs(a.ez() * Sxy);
	rb = std::abs(b.ex() * Syz)
		+ std::abs(b.ez() * Syx);
	if (distance > ra + rb) return false;


	// Achse Y x Z
	distance = std::abs(Szz * Dax - Sxz * Daz);
	ra = std::abs(a.ex() * Szz)
		+ std::abs(a.ez() * Sxz);
	rb = std::abs(b.ex() * Syy)
		+ std::abs(b.ey() * Syx);
	if (distance > ra + rb) return false;


	// Achse Z x X
	distance = std::abs(Sxx * Day - Syx * Dax);
	ra = std::abs(a.ex() * Syx)
		+ std::abs(a.ey() * Sxx);
	rb = std::abs(b.ey() * Szz)
		+ std::abs(b.ez() * Szy);
	if (distance > ra + rb) return false;

	// Achse Z x Y
	distance = std::abs(Sxy * Day - Syy * Dax);
	ra = std::abs(a.ex() * Syy)
		+ std::abs(a.ey() * Sxy);
	rb = std::abs(b.ex() * Szz)
		+ std::abs(b.ez() * Szx);
	if (distance > ra + rb) return false;

	// Achse Z x Z
	distance = std::abs(Sxz * Day - Syz * Dax);
	ra = std::abs(a.ex() * Syz)
		+ std::abs(a.ey() * Sxz);
	rb = std::abs(b.ex() * Szy)
		+ std::abs(b.ey() * Szx);

	if (distance > ra + rb) return false;

	return true;
}

// Seperating Axis Theorem speziell für OBBs
// mit Zwischenspeicherung
// OBB ohne uz
bool TestOBBOBB_V4(const SIMDOBB_V2& a, const SIMDOBB_V2& b) {
	SIMDVektor3D D = a.center() - b.center();

	float Sxx;	float Syx; float Szx;
	float Sxy;	float Syy; float Szy;
	float Sxz;	float Syz; float Szz;

	float Dax, Day, Daz;
	float Dbx, Dby, Dbz;

	SIMDVektor3D L = a.ux();
	Dax = dot(L, D);
	float distance = std::abs(Dax);
	float ra = a.ex();

	SIMDVektor3D b_uz = cross(b.ux(), b.uy());

	Sxx = dot(L, b.ux());
	Sxy = dot(L, b.uy());
	Sxz = dot(L, b_uz);

	float rb = std::abs(b.ex() * Sxx)
		+ std::abs(b.ey() * Sxy)
		+ std::abs(b.ez() * Sxz);
	if (distance > ra + rb) return false;

	L = a.uy();
	Day = dot(L, D);
	distance = std::abs(Day);
	ra = a.ey();

	Syx = dot(L, b.ux());
	Syy = dot(L, b.uy());
	Syz = dot(L, b_uz);

	rb = std::abs(b.ex() * Syx)
		+ std::abs(b.ey() * Syy)
		+ std::abs(b.ez() * Syz);
	if (distance > ra + rb) return false;

	SIMDVektor3D a_uz = cross(a.ux(), a.uy());

	L = a_uz;
	Daz = dot(L, D);
	distance = std::abs(Daz);
	ra = a.ez();

	Szx = dot(L, b.ux());
	Szy = dot(L, b.uy());
	Szz = dot(L, b_uz);

	rb = std::abs(b.ex() * Szx)
		+ std::abs(b.ey() * Szy)
		+ std::abs(b.ez() * Szz);
	if (distance > ra + rb) return false;


	L = b.ux();
	Dbx = dot(L, D);
	distance = std::abs(Dbx);
	ra = std::abs(a.ex() * Sxx)
		+ std::abs(a.ey() * Syx)
		+ std::abs(a.ez() * Szx);
	rb = b.ex();
	if (distance > ra + rb) return false;


	L = b.uy();
	Dby = dot(L, D);
	distance = std::abs(Dby);
	ra = std::abs(a.ex() * Sxy)
		+ std::abs(a.ey() * Syy)
		+ std::abs(a.ez() * Szy);
	rb = b.ey();
	if (distance > ra + rb) return false;

	L = b_uz;
	Dbz = dot(L, D);
	distance = std::abs(Dbz);
	ra = std::abs(a.ex() * Sxz)
		+ std::abs(a.ey() * Syz)
		+ std::abs(a.ez() * Szz);
	rb = b.ez();
	if (distance > ra + rb) return false;


	// Achse X x X
	distance = std::abs(Syx * Daz - Szx * Day);
	ra = std::abs(a.ey() * Szx)
		+ std::abs(a.ez() * Syx);
	rb = std::abs(b.ey() * Sxz)
		+ std::abs(b.ez() * Sxy);
	if (distance > ra + rb) return false;

	// Achse X x Y
	distance = std::abs(Syy * Daz - Szy * Day);
	ra = std::abs(a.ey() * Szy)
		+ std::abs(a.ez() * Syy);
	rb = std::abs(b.ex() * Sxz)
		+ std::abs(b.ez() * Sxx);
	if (distance > ra + rb) return false;


	// Achse X x Z
	distance = std::abs(Syz * Daz - Szz * Day);
	ra = std::abs(a.ey() * Szz)
		+ std::abs(a.ez() * Syz);
	rb = std::abs(b.ex() * Sxy)
		+ std::abs(b.ey() * Sxx);
	if (distance > ra + rb) return false;


	// Achse Y x X
	distance = std::abs(Szx * Dax - Sxx * Daz);
	ra = std::abs(a.ex() * Szx)
		+ std::abs(a.ez() * Sxx);
	rb = std::abs(b.ey() * Syz)
		+ std::abs(b.ez() * Syy);
	if (distance > ra + rb) return false;

	// Achse Y x Y
	distance = std::abs(Szy * Dax - Sxy * Daz);
	ra = std::abs(a.ex() * Szy)
		+ std::abs(a.ez() * Sxy);
	rb = std::abs(b.ex() * Syz)
		+ std::abs(b.ez() * Syx);
	if (distance > ra + rb) return false;


	// Achse Y x Z
	distance = std::abs(Szz * Dax - Sxz * Daz);
	ra = std::abs(a.ex() * Szz)
		+ std::abs(a.ez() * Sxz);
	rb = std::abs(b.ex() * Syy)
		+ std::abs(b.ey() * Syx);
	if (distance > ra + rb) return false;


	// Achse Z x X
	distance = std::abs(Sxx * Day - Syx * Dax);
	ra = std::abs(a.ex() * Syx)
		+ std::abs(a.ey() * Sxx);
	rb = std::abs(b.ey() * Szz)
		+ std::abs(b.ez() * Szy);
	if (distance > ra + rb) return false;

	// Achse Z x Y
	distance = std::abs(Sxy * Day - Syy * Dax);
	ra = std::abs(a.ex() * Syy)
		+ std::abs(a.ey() * Sxy);
	rb = std::abs(b.ex() * Szz)
		+ std::abs(b.ez() * Szx);
	if (distance > ra + rb) return false;

	// Achse Z x Z
	distance = std::abs(Sxz * Day - Syz * Dax);
	ra = std::abs(a.ex() * Syz)
		+ std::abs(a.ey() * Sxz);
	rb = std::abs(b.ex() * Szy)
		+ std::abs(b.ey() * Szx);

	if (distance > ra + rb) return false;

	return true;
}

// Seperating Axis Theorem speziell für OBBs
// mit Zwischenspeicherung
// OBBs mit Quaternions
bool TestOBBOBB_V4(const SIMDOBB_V4& a, const SIMDOBB_V4& b) {
	SIMDVektor3D D = a.center() - b.center();

	float Sxx;	float Syx; float Szx;
	float Sxy;	float Syy; float Szy;
	float Sxz;	float Syz; float Szz;

	float Dax, Day, Daz;
	float Dbx, Dby, Dbz;

	Matrix4x4 a_mat = toMatrix(a.orientation());
	Matrix4x4 b_mat = toMatrix(b.orientation());

	SIMDVektor3D a_ux(a_mat[0][0], a_mat[1][0], a_mat[2][0]);
	SIMDVektor3D a_uy(a_mat[0][1], a_mat[1][1], a_mat[2][1]);
	SIMDVektor3D a_uz(a_mat[0][2], a_mat[1][2], a_mat[2][2]);

	SIMDVektor3D b_ux(b_mat[0][0], b_mat[1][0], b_mat[2][0]);
	SIMDVektor3D b_uy(b_mat[0][1], b_mat[1][1], b_mat[2][1]);
	SIMDVektor3D b_uz(b_mat[0][2], b_mat[1][2], b_mat[2][2]);

	SIMDVektor3D L = a_ux;
	Dax = dot(L, D);
	float distance = std::abs(Dax);
	float ra = a.ex();

	Sxx = dot(L, b_ux);
	Sxy = dot(L, b_uy);
	Sxz = dot(L, b_uz);

	float rb = std::abs(b.ex() * Sxx)
		+ std::abs(b.ey() * Sxy)
		+ std::abs(b.ez() * Sxz);
	if (distance > ra + rb) return false;

	L = a_uy;
	Day = dot(L, D);
	distance = std::abs(Day);
	ra = a.ey();

	Syx = dot(L, b_ux);
	Syy = dot(L, b_uy);
	Syz = dot(L, b_uz);

	rb = std::abs(b.ex() * Syx)
		+ std::abs(b.ey() * Syy)
		+ std::abs(b.ez() * Syz);
	if (distance > ra + rb) return false;


	L = a_uz;
	Daz = dot(L, D);
	distance = std::abs(Daz);
	ra = a.ez();

	Szx = dot(L, b_ux);
	Szy = dot(L, b_uy);
	Szz = dot(L, b_uz);

	rb = std::abs(b.ex() * Szx)
		+ std::abs(b.ey() * Szy)
		+ std::abs(b.ez() * Szz);
	if (distance > ra + rb) return false;


	L = b_ux;
	Dbx = dot(L, D);
	distance = std::abs(Dbx);
	ra = std::abs(a.ex() * Sxx)
		+ std::abs(a.ey() * Syx)
		+ std::abs(a.ez() * Szx);
	rb = b.ex();
	if (distance > ra + rb) return false;


	L = b_uy;
	Dby = dot(L, D);
	distance = std::abs(Dby);
	ra = std::abs(a.ex() * Sxy)
		+ std::abs(a.ey() * Syy)
		+ std::abs(a.ez() * Szy);
	rb = b.ey();
	if (distance > ra + rb) return false;

	L = b_uz;
	Dbz = dot(L, D);
	distance = std::abs(Dbz);
	ra = std::abs(a.ex() * Sxz)
		+ std::abs(a.ey() * Syz)
		+ std::abs(a.ez() * Szz);
	rb = b.ez();
	if (distance > ra + rb) return false;

	// Achse X x X
	distance = std::abs(Syx * Daz - Szx * Day);
	ra = std::abs(a.ey() * Szx)
		+ std::abs(a.ez() * Syx);
	rb = std::abs(b.ey() * Sxz)
		+ std::abs(b.ez() * Sxy);
	if (distance > ra + rb) return false;

	// Achse X x Y
	distance = std::abs(Syy * Daz - Szy * Day);
	ra = std::abs(a.ey() * Szy)
		+ std::abs(a.ez() * Syy);
	rb = std::abs(b.ex() * Sxz)
		+ std::abs(b.ez() * Sxx);
	if (distance > ra + rb) return false;


	// Achse X x Z
	distance = std::abs(Syz * Daz - Szz * Day);
	ra = std::abs(a.ey() * Szz)
		+ std::abs(a.ez() * Syz);
	rb = std::abs(b.ex() * Sxy)
		+ std::abs(b.ey() * Sxx);
	if (distance > ra + rb) return false;


	// Achse Y x X
	distance = std::abs(Szx * Dax - Sxx * Daz);
	ra = std::abs(a.ex() * Szx)
		+ std::abs(a.ez() * Sxx);
	rb = std::abs(b.ey() * Syz)
		+ std::abs(b.ez() * Syy);
	if (distance > ra + rb) return false;

	// Achse Y x Y
	distance = std::abs(Szy * Dax - Sxy * Daz);
	ra = std::abs(a.ex() * Szy)
		+ std::abs(a.ez() * Sxy);
	rb = std::abs(b.ex() * Syz)
		+ std::abs(b.ez() * Syx);
	if (distance > ra + rb) return false;


	// Achse Y x Z
	distance = std::abs(Szz * Dax - Sxz * Daz);
	ra = std::abs(a.ex() * Szz)
		+ std::abs(a.ez() * Sxz);
	rb = std::abs(b.ex() * Syy)
		+ std::abs(b.ey() * Syx);
	if (distance > ra + rb) return false;


	// Achse Z x X
	distance = std::abs(Sxx * Day - Syx * Dax);
	ra = std::abs(a.ex() * Syx)
		+ std::abs(a.ey() * Sxx);
	rb = std::abs(b.ey() * Szz)
		+ std::abs(b.ez() * Szy);
	if (distance > ra + rb) return false;

	// Achse Z x Y
	distance = std::abs(Sxy * Day - Syy * Dax);
	ra = std::abs(a.ex() * Syy)
		+ std::abs(a.ey() * Sxy);
	rb = std::abs(b.ex() * Szz)
		+ std::abs(b.ez() * Szx);
	if (distance > ra + rb) return false;

	// Achse Z x Z
	distance = std::abs(Sxz * Day - Syz * Dax);
	ra = std::abs(a.ex() * Syz)
		+ std::abs(a.ey() * Sxz);
	rb = std::abs(b.ex() * Szy)
		+ std::abs(b.ey() * Szx);

	if (distance > ra + rb) return false;

	return true;
}

// Seperating Axis Theorem speziell für OBBs
// mit Zwischenspeicherung
// ohne Kreuzprodukt
// mit Branch Elimination
bool TestOBBOBB_V5(const SIMDOBB& a, const SIMDOBB& b) {
	SIMDVektor3D D = a.center() - b.center();

	float Sxx;	float Syx; float Szx;
	float Sxy;	float Syy; float Szy;
	float Sxz;	float Syz; float Szz;

	float Dax, Day, Daz;

	float distance[15];
	float ra[15];
	float rb[15];

	// Ax
	Dax = dot(a.ux(), D);
	distance[0] = std::abs(Dax);
	ra[0] = a.ex();

	Sxx = dot(a.ux(), b.ux());
	Sxy = dot(a.ux(), b.uy());
	Sxz = dot(a.ux(), b.uz());

	rb[0] = std::abs(b.ex() * Sxx)
		+ std::abs(b.ey() * Sxy)
		+ std::abs(b.ez() * Sxz);


	//Ay
	Day = dot(a.uy(), D);
	distance[1] = std::abs(Day);
	ra[1] = a.ey();

	Syx = dot(a.uy(), b.ux());
	Syy = dot(a.uy(), b.uy());
	Syz = dot(a.uy(), b.uz());

	rb[1] = std::abs(b.ex() * Syx)
		+ std::abs(b.ey() * Syy)
		+ std::abs(b.ez() * Syz);


	// Az
	Daz = dot(a.uz(), D);
	distance[2] = std::abs(Daz);
	ra[2] = a.ez();

	Szx = dot(a.uz(), b.ux());
	Szy = dot(a.uz(), b.uy());
	Szz = dot(a.uz(), b.uz());

	rb[2] = std::abs(b.ex() * Szx)
		+ std::abs(b.ey() * Szy)
		+ std::abs(b.ez() * Szz);


	// Bx
	distance[3] = std::abs(dot(b.ux(), D));
	ra[3] = std::abs(a.ex() * Sxx)
		+ std::abs(a.ey() * Syx)
		+ std::abs(a.ez() * Szx);
	rb[3] = b.ex();


	// By
	distance[4] = std::abs(dot(b.uy(), D));
	ra[4] = std::abs(a.ex() * Sxy)
		+ std::abs(a.ey() * Syy)
		+ std::abs(a.ez() * Szy);
	rb[4] = b.ey();


	// Bz
	distance[5] = std::abs(dot(b.uz(), D));
	ra[5] = std::abs(a.ex() * Sxz)
		+ std::abs(a.ey() * Syz)
		+ std::abs(a.ez() * Szz);
	rb[5] = b.ez();


	// Achse X x X
	distance[6] = std::abs(Syx * Daz - Szx * Day);
	ra[6] = std::abs(a.ey() * Szx)
		+ std::abs(a.ez() * Syx);
	rb[6] = std::abs(b.ey() * Sxz)
		+ std::abs(b.ez() * Sxy);


	// Achse X x Y
	distance[7] = std::abs(Syy * Daz - Szy * Day);
	ra[7] = std::abs(a.ey() * Szy)
		+ std::abs(a.ez() * Syy);
	rb[7] = std::abs(b.ex() * Sxz)
		+ std::abs(b.ez() * Sxx);



	// Achse X x Z
	distance[8] = std::abs(Syz * Daz - Szz * Day);
	ra[8] = std::abs(a.ey() * Szz)
		+ std::abs(a.ez() * Syz);
	rb[8] = std::abs(b.ex() * Sxy)
		+ std::abs(b.ey() * Sxx);



	// Achse Y x X
	distance[9] = std::abs(Szx * Dax - Sxx * Daz);
	ra[9] = std::abs(a.ex() * Szx)
		+ std::abs(a.ez() * Sxx);
	rb[9] = std::abs(b.ey() * Syz)
		+ std::abs(b.ez() * Syy);


	// Achse Y x Y
	distance[10] = std::abs(Szy * Dax - Sxy * Daz);
	ra[10] = std::abs(a.ex() * Szy)
		+ std::abs(a.ez() * Sxy);
	rb[10] = std::abs(b.ex() * Syz)
		+ std::abs(b.ez() * Syx);



	// Achse Y x Z
	distance[11] = std::abs(Szz * Dax - Sxz * Daz);
	ra[11] = std::abs(a.ex() * Szz)
		+ std::abs(a.ez() * Sxz);
	rb[11] = std::abs(b.ex() * Syy)
		+ std::abs(b.ey() * Syx);



	// Achse Z x X
	distance[12] = std::abs(Sxx * Day - Syx * Dax);
	ra[12] = std::abs(a.ex() * Syx)
		+ std::abs(a.ey() * Sxx);
	rb[12] = std::abs(b.ey() * Szz)
		+ std::abs(b.ez() * Szy);


	// Achse Z x Y
	distance[13] = std::abs(Sxy * Day - Syy * Dax);
	ra[13] = std::abs(a.ex() * Syy)
		+ std::abs(a.ey() * Sxy);
	rb[13] = std::abs(b.ex() * Szz)
		+ std::abs(b.ez() * Szx);


	// Achse Z x Z
	distance[14] = std::abs(Sxz * Day - Syz * Dax);
	ra[14] = std::abs(a.ex() * Syz)
		+ std::abs(a.ey() * Sxz);
	rb[14] = std::abs(b.ex() * Szy)
		+ std::abs(b.ey() * Szx);


	if ((distance[0] <= ra[0] + rb[0]) &
		(distance[1] <= ra[1] + rb[1]) &
		(distance[2] <= ra[2] + rb[2]) &
		(distance[3] <= ra[3] + rb[3]) &
		(distance[4] <= ra[4] + rb[4]) &
		(distance[5] <= ra[5] + rb[5]) &
		(distance[6] <= ra[6] + rb[6]) &
		(distance[7] <= ra[7] + rb[7]) &
		(distance[8] <= ra[8] + rb[8]) &
		(distance[9] <= ra[9] + rb[9]) &
		(distance[10] <= ra[10] + rb[10]) &
		(distance[11] <= ra[11] + rb[11]) &
		(distance[12] <= ra[12] + rb[12]) &
		(distance[13] <= ra[13] + rb[13]) &
		(distance[14] <= ra[14] + rb[14])) {

		return true;
	}
	else {
		return false;
	}
}

// Seperating Axis Theorem speziell für OBBs
// mit Zwischenspeicherung
// ohne Kreuzprodukt
// robust gegen NAN
bool TestOBBOBB_V6(const SIMDOBB& a, const SIMDOBB& b) {
	SIMDVektor3D D = a.center() - b.center();

	float Sxx;	float Syx; float Szx;
	float Sxy;	float Syy; float Szy;
	float Sxz;	float Syz; float Szz;


	SIMDVektor3D L = a.ux();
	float distance = std::abs(dot(L, D));
	float ra = a.ex();

	Sxx = dot(L, b.ux());
	Sxy = dot(L, b.uy());
	Sxz = dot(L, b.uz());

	float rb = std::abs(b.ex() * Sxx)
		+ std::abs(b.ey() * Sxy)
		+ std::abs(b.ez() * Sxz);
	if (distance <= ra + rb) {}
	else return false;


	L = a.uy();
	distance = std::abs(dot(L, D));
	ra = a.ey();

	Syx = dot(L, b.ux());
	Syy = dot(L, b.uy());
	Syz = dot(L, b.uz());

	rb = std::abs(b.ex() * Syx)
		+ std::abs(b.ey() * Syy)
		+ std::abs(b.ez() * Syz);
	if (distance <= ra + rb) {}
	else return false;


	L = a.uz();
	distance = std::abs(dot(L, D));
	ra = a.ez();

	Szx = dot(L, b.ux());
	Szy = dot(L, b.uy());
	Szz = dot(L, b.uz());

	rb = std::abs(b.ex() * Szx)
		+ std::abs(b.ey() * Szy)
		+ std::abs(b.ez() * Szz);
	if (distance <= ra + rb) {}
	else return false;


	L = b.ux();
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * Sxx)
		+ std::abs(a.ey() * Syx)
		+ std::abs(a.ez() * Szx);
	rb = b.ex();
	if (distance <= ra + rb) {}
	else return false;


	L = b.uy();
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * Sxy)
		+ std::abs(a.ey() * Syy)
		+ std::abs(a.ez() * Szy);
	rb = b.ey();
	if (distance <= ra + rb) {}
	else return false;


	L = b.uz();
	distance = std::abs(dot(L, D));
	ra = std::abs(a.ex() * Sxz)
		+ std::abs(a.ey() * Syz)
		+ std::abs(a.ez() * Szz);
	rb = b.ez();
	if (distance <= ra + rb) {}
	else return false;


	// Achse X x X
	distance = std::abs(dot(a.uy(), b.ux()) * dot(D, a.uz())
		- dot(a.uz(), b.ux()) * dot(D, a.uy()));
	ra = std::abs(a.ey() * Szx)
		+ std::abs(a.ez() * Syx);
	rb = std::abs(b.ey() * Sxz)
		+ std::abs(b.ez() * Sxy);
	if (distance <= ra + rb) {}
	else return false;

	// Achse X x Y
	distance = std::abs(dot(a.uy(), b.uy()) * dot(D, a.uz())
		- dot(a.uz(), b.uy()) * dot(D, a.uy()));
	ra = std::abs(a.ey() * Szy)
		+ std::abs(a.ez() * Syy);
	rb = std::abs(b.ex() * Sxz)
		+ std::abs(b.ez() * Sxx);
	if (distance <= ra + rb) {}
	else return false;


	// Achse X x Z
	distance = std::abs(dot(a.uy(), b.uz()) * dot(D, a.uz())
		- dot(a.uz(), b.uz()) * dot(D, a.uy()));
	ra = std::abs(a.ey() * Szz)
		+ std::abs(a.ez() * Syz);
	rb = std::abs(b.ex() * Sxy)
		+ std::abs(b.ey() * Sxx);
	if (distance <= ra + rb) {}
	else return false;


	// Achse Y x X
	distance = std::abs(dot(a.uz(), b.ux()) * dot(D, a.ux())
		- dot(a.ux(), b.ux()) * dot(D, a.uz()));
	ra = std::abs(a.ex() * Szx)
		+ std::abs(a.ez() * Sxx);
	rb = std::abs(b.ey() * Syz)
		+ std::abs(b.ez() * Syy);
	if (distance <= ra + rb) {}
	else return false;

	// Achse Y x Y
	distance = std::abs(dot(a.uz(), b.uy()) * dot(D, a.ux())
		- dot(a.ux(), b.uy()) * dot(D, a.uz()));
	ra = std::abs(a.ex() * Szy)
		+ std::abs(a.ez() * Sxy);
	rb = std::abs(b.ex() * Syz)
		+ std::abs(b.ez() * Syx);
	if (distance <= ra + rb) {}
	else return false;


	// Achse Y x Z
	distance = std::abs(dot(a.uz(), b.uz()) * dot(D, a.ux())
		- dot(a.ux(), b.uz()) * dot(D, a.uz()));
	ra = std::abs(a.ex() * Szz)
		+ std::abs(a.ez() * Sxz);
	rb = std::abs(b.ex() * Syy)
		+ std::abs(b.ey() * Syx);
	if (distance <= ra + rb) {}
	else return false;


	// Achse Z x X
	distance = std::abs(dot(a.ux(), b.ux()) * dot(D, a.uy())
		- dot(a.uy(), b.ux()) * dot(D, a.ux()));
	ra = std::abs(a.ex() * Syx)
		+ std::abs(a.ey() * Sxx);
	rb = std::abs(b.ey() * Szz)
		+ std::abs(b.ez() * Szy);
	if (distance <= ra + rb) {}
	else return false;

	// Achse Z x Y
	distance = std::abs(dot(a.ux(), b.uy()) * dot(D, a.uy())
		- dot(a.uy(), b.uy()) * dot(D, a.ux()));
	ra = std::abs(a.ex() * Syy)
		+ std::abs(a.ey() * Sxy);
	rb = std::abs(b.ex() * Szz)
		+ std::abs(b.ez() * Szx);
	if (distance <= ra + rb) {}
	else return false;

	// Achse Z x Z
	distance = std::abs(dot(a.ux(), b.uz()) * dot(D, a.uy())
		- dot(a.uy(), b.uz()) * dot(D, a.ux()));
	ra = std::abs(a.ex() * Syz)
		+ std::abs(a.ey() * Sxz);
	rb = std::abs(b.ex() * Szy)
		+ std::abs(b.ey() * Szx);
	if (distance <= ra + rb) {}
	else return false;

	return true;
}