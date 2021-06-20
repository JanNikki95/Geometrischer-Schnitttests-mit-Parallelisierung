#pragma once
#include "Point3D.h"
#include "OBB.h"

float Durchdringungstiefe(const OBB& a, const OBB& b) {
	float result = FLT_MAX;
	float I_min, I_max;

	Point3D a_vertex[8] = {
		a.center() + (a.ex() * a.ux()) + (a.ey() * a.uy()) + (a.ez() * a.uz()),
		a.center() + (a.ex() * a.ux()) + (a.ey() * a.uy()) - (a.ez() * a.uz()),
		a.center() + (a.ex() * a.ux()) - (a.ey() * a.uy()) + (a.ez() * a.uz()),
		a.center() + (a.ex() * a.ux()) - (a.ey() * a.uy()) - (a.ez() * a.uz()),
		a.center() - (a.ex() * a.ux()) + (a.ey() * a.uy()) + (a.ez() * a.uz()),
		a.center() - (a.ex() * a.ux()) + (a.ey() * a.uy()) - (a.ez() * a.uz()),
		a.center() - (a.ex() * a.ux()) - (a.ey() * a.uy()) + (a.ez() * a.uz()),
		a.center() - (a.ex() * a.ux()) - (a.ey() * a.uy()) - (a.ez() * a.uz())
	};

	Point3D b_vertex[8] = {
		b.center() + (b.ex() * b.ux()) + (b.ey() * b.uy()) + (b.ez() * b.uz()),
		b.center() + (b.ex() * b.ux()) + (b.ey() * b.uy()) - (b.ez() * b.uz()),
		b.center() + (b.ex() * b.ux()) - (b.ey() * b.uy()) + (b.ez() * b.uz()),
		b.center() + (b.ex() * b.ux()) - (b.ey() * b.uy()) - (b.ez() * b.uz()),
		b.center() - (b.ex() * b.ux()) + (b.ey() * b.uy()) + (b.ez() * b.uz()),
		b.center() - (b.ex() * b.ux()) + (b.ey() * b.uy()) - (b.ez() * b.uz()),
		b.center() - (b.ex() * b.ux()) - (b.ey() * b.uy()) + (b.ez() * b.uz()),
		b.center() - (b.ex() * b.ux()) - (b.ey() * b.uy()) - (b.ez() * b.uz())
	};

	Vektor3D L = a.ux();
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
	I_min = std::max(min_a, min_b);
	I_max = std::min(max_a, max_b);
	if (I_min > I_max) {
		return 0.0f;
	}
	else {
		result = std::min(result, I_max - I_min);
	}

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
	I_min = std::max(min_a, min_b);
	I_max = std::min(max_a, max_b);
	if (I_min > I_max) {
		return 0.0f;
	}
	else {
		result = std::min(result, I_max - I_min);
	}

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
	I_min = std::max(min_a, min_b);
	I_max = std::min(max_a, max_b);
	if (I_min > I_max) {
		return 0.0f;
	}
	else {
		result = std::min(result, I_max - I_min);
	}

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
	I_min = std::max(min_a, min_b);
	I_max = std::min(max_a, max_b);
	if (I_min > I_max) {
		return 0.0f;
	}
	else {
		result = std::min(result, I_max - I_min);
	}

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
	I_min = std::max(min_a, min_b);
	I_max = std::min(max_a, max_b);
	if (I_min > I_max) {
		return 0.0f;
	}
	else {
		result = std::min(result, I_max - I_min);
	}

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
	I_min = std::max(min_a, min_b);
	I_max = std::min(max_a, max_b);
	if (I_min > I_max) {
		return 0.0f;
	}
	else {
		result = std::min(result, I_max - I_min);
	}

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
	I_min = std::max(min_a, min_b);
	I_max = std::min(max_a, max_b);
	if (I_min > I_max) {
		return 0.0f;
	}
	else {
		result = std::min(result, I_max - I_min);
	}

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
	I_min = std::max(min_a, min_b);
	I_max = std::min(max_a, max_b);
	if (I_min > I_max) {
		return 0.0f;
	}
	else {
		result = std::min(result, I_max - I_min);
	}

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
	I_min = std::max(min_a, min_b);
	I_max = std::min(max_a, max_b);
	if (I_min > I_max) {
		return 0.0f;
	}
	else {
		result = std::min(result, I_max - I_min);
	}

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
	I_min = std::max(min_a, min_b);
	I_max = std::min(max_a, max_b);
	if (I_min > I_max) {
		return 0.0f;
	}
	else {
		result = std::min(result, I_max - I_min);
	}

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
	I_min = std::max(min_a, min_b);
	I_max = std::min(max_a, max_b);
	if (I_min > I_max) {
		return 0.0f;
	}
	else {
		result = std::min(result, I_max - I_min);
	}

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
	I_min = std::max(min_a, min_b);
	I_max = std::min(max_a, max_b);
	if (I_min > I_max) {
		return 0.0f;
	}
	else {
		result = std::min(result, I_max - I_min);
	}

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
	I_min = std::max(min_a, min_b);
	I_max = std::min(max_a, max_b);
	if (I_min > I_max) {
		return 0.0f;
	}
	else {
		result = std::min(result, I_max - I_min);
	}

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
	I_min = std::max(min_a, min_b);
	I_max = std::min(max_a, max_b);
	if (I_min > I_max) {
		return 0.0f;
	}
	else {
		result = std::min(result, I_max - I_min);
	}

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
	I_min = std::max(min_a, min_b);
	I_max = std::min(max_a, max_b);
	if (I_min > I_max) {
		return 0.0f;
	}
	else {
		result = std::min(result, I_max - I_min);
	}

	return result;
}