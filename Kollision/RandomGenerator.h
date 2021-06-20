#pragma once
#include <random>
#include <vector>
#include <omp.h>
#include "Matrix4x4.h"
#include "OBB.h"
#include "SIMDOBB.h"
#include "SoAOBB.h"

#define SPACE -1'000.0f, 1'000.0f
#define BOXSIZE 3000.0f, 4000.0f

Matrix4x4 randomRotation() {

	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_real_distribution<float> randomNumber(0.0f, 1.0f);

	float x1 = randomNumber(engine);
	float x2 = randomNumber(engine);
	float x3 = randomNumber(engine);

	float theta = 2.0f * M_PI * x1;
	float phi = 2.0f * M_PI * x2;
	float z = x3;

	Vektor3D V(
		cosf(phi) * sqrtf(z),
		sinf(phi) * sqrtf(z),
		sqrtf(1 - z)
	);

	Matrix4x4 res = dyaProdukt(V, V);
	res = 2.0f * res;
	res = res - Matrix4x4();

	Matrix4x4 zRotation(cosf(theta), sin(theta),  0.0f, 0.0f,
				-1.0f * sinf(theta), cosf(theta), 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f);

	res = res * zRotation;

	return res;
}

/*
	Erstellung von naiven, zufälligen Boxen
*/

OBB random_OBB() {

	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_real_distribution<float> rndcenter(SPACE);
	std::uniform_real_distribution<float> rndrange(BOXSIZE);

	Point3D center{ rndcenter(engine), rndcenter(engine), rndcenter(engine) };

	float ex = rndrange(engine);
	float ey = rndrange(engine);
	float ez = rndrange(engine);

	Matrix4x4 rndmat = randomRotation();

	Vektor3D ux(rndmat[0][0], rndmat[1][0], rndmat[2][0]);
	Vektor3D uy(rndmat[0][1], rndmat[1][1], rndmat[2][1]);
	Vektor3D uz(rndmat[0][2], rndmat[1][2], rndmat[2][2]);

	return OBB(center, ux, uy, uz, ex, ey, ez);
}

OBB_V2 random_OBB_V2() {

	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_real_distribution<float> rndcenter(SPACE);
	std::uniform_real_distribution<float> rndrange(BOXSIZE);

	Point3D center{ rndcenter(engine), rndcenter(engine), rndcenter(engine) };

	float ex = rndrange(engine);
	float ey = rndrange(engine);
	float ez = rndrange(engine);

	Matrix4x4 rndmat = randomRotation();

	Vektor3D ux(rndmat[0][0], rndmat[1][0], rndmat[2][0]);
	Vektor3D uy(rndmat[0][1], rndmat[1][1], rndmat[2][1]);

	return OBB_V2(center, ux, uy, ex, ey, ez);
}

OBB_V4 random_OBB_V4() {

	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_real_distribution<float> rndcenter(SPACE);
	std::uniform_real_distribution<float> rndrange(BOXSIZE);

	Point3D center{ rndcenter(engine), rndcenter(engine), rndcenter(engine) };

	float ex = rndrange(engine);
	float ey = rndrange(engine);
	float ez = rndrange(engine);

	Matrix4x4 rndmat = randomRotation();

	Vektor3D ux(rndmat[0][0], rndmat[1][0], rndmat[2][0]);
	Vektor3D uy(rndmat[0][1], rndmat[1][1], rndmat[2][1]);
	Vektor3D uz(rndmat[0][2], rndmat[1][2], rndmat[2][2]);

	return OBB_V4(center, ux, uy, uz, ex, ey, ez);
}

auto random_OBBs(int64_t num_entries) {

	std::vector<OBB> obbs(num_entries);

	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_real_distribution<float> rndcenter(SPACE);
	std::uniform_real_distribution<float> rndrange(BOXSIZE);

	#pragma omp parallel for schedule(dynamic)
	for (int64_t i = 0; i < num_entries; ++i) {

		Point3D center{ rndcenter(engine), rndcenter(engine), rndcenter(engine) };

		float ex = rndrange(engine);
		float ey = rndrange(engine);
		float ez = rndrange(engine);

		Matrix4x4 rndmat = randomRotation();

		Vektor3D ux(rndmat[0][0], rndmat[1][0], rndmat[2][0]);
		Vektor3D uy(rndmat[0][1], rndmat[1][1], rndmat[2][1]);
		Vektor3D uz(rndmat[0][2], rndmat[1][2], rndmat[2][2]);

		obbs[i] = OBB(center, ux, uy, uz, ex, ey, ez);
	}

	return obbs;
}

auto random_OBBs_V2(int64_t num_entries) {

	std::vector<OBB_V2> obbs(num_entries);

	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_real_distribution<float> rndcenter(SPACE);
	std::uniform_real_distribution<float> rndrange(BOXSIZE);

	#pragma omp parallel for schedule(dynamic)
	for (int64_t i = 0; i < num_entries; ++i) {

		Point3D center{ rndcenter(engine), rndcenter(engine), rndcenter(engine) };

		float ex = rndrange(engine);
		float ey = rndrange(engine);
		float ez = rndrange(engine);

		Matrix4x4 rndmat = randomRotation();

		Vektor3D ux(rndmat[0][0], rndmat[1][0], rndmat[2][0]);
		Vektor3D uy(rndmat[0][1], rndmat[1][1], rndmat[2][1]);

		obbs[i] = OBB_V2(center, ux, uy, ex, ey, ez);
	}

	return obbs;
}

/*
	Erstellung von zufälligen SIMD-Boxen in AoS Design
*/

auto random_OBBs_V4(int64_t num_entries) {

	std::vector<OBB_V4> obbs(num_entries);

	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_real_distribution<float> rndcenter(SPACE);
	std::uniform_real_distribution<float> rndrange(BOXSIZE);

	#pragma omp parallel for schedule(dynamic)
	for (int64_t i = 0; i < num_entries; ++i) {

		Point3D center{ rndcenter(engine), rndcenter(engine), rndcenter(engine) };

		float ex = rndrange(engine);
		float ey = rndrange(engine);
		float ez = rndrange(engine);

		Matrix4x4 rndmat = randomRotation();

		Vektor3D ux(rndmat[0][0], rndmat[1][0], rndmat[2][0]);
		Vektor3D uy(rndmat[0][1], rndmat[1][1], rndmat[2][1]);
		Vektor3D uz(rndmat[0][2], rndmat[1][2], rndmat[2][2]);

		obbs[i] = OBB_V4(center, ux, uy, uz, ex, ey, ez);
	}

	return obbs;
}

SIMDOBB random_SIMDOBB() {

	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_real_distribution<float> rndcenter(SPACE);
	std::uniform_real_distribution<float> rndrange(BOXSIZE);

	SIMDPoint3D center{ rndcenter(engine), rndcenter(engine), rndcenter(engine) };

	float ex = rndrange(engine);
	float ey = rndrange(engine);
	float ez = rndrange(engine);

	Matrix4x4 rndmat = randomRotation();

	SIMDVektor3D ux(rndmat[0][0], rndmat[1][0], rndmat[2][0]);
	SIMDVektor3D uy(rndmat[0][1], rndmat[1][1], rndmat[2][1]);
	SIMDVektor3D uz(rndmat[0][2], rndmat[1][2], rndmat[2][2]);

	return SIMDOBB(center, ux, uy, uz, ex, ey, ez);
}

SIMDOBB_V2 random_SIMDOBB_V2() {

	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_real_distribution<float> rndcenter(SPACE);
	std::uniform_real_distribution<float> rndrange(BOXSIZE);

	SIMDPoint3D center{ rndcenter(engine), rndcenter(engine), rndcenter(engine) };

	float ex = rndrange(engine);
	float ey = rndrange(engine);
	float ez = rndrange(engine);

	Matrix4x4 rndmat = randomRotation();

	SIMDVektor3D ux(rndmat[0][0], rndmat[1][0], rndmat[2][0]);
	SIMDVektor3D uy(rndmat[0][1], rndmat[1][1], rndmat[2][1]);

	return SIMDOBB_V2(center, ux, uy, ex, ey, ez);
}

SIMDOBB_V4 random_SIMDOBB_V4() {

	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_real_distribution<float> rndcenter(SPACE);
	std::uniform_real_distribution<float> rndrange(BOXSIZE);

	SIMDPoint3D center{ rndcenter(engine), rndcenter(engine), rndcenter(engine) };

	float ex = rndrange(engine);
	float ey = rndrange(engine);
	float ez = rndrange(engine);

	Matrix4x4 rndmat = randomRotation();

	SIMDVektor3D ux(rndmat[0][0], rndmat[1][0], rndmat[2][0]);
	SIMDVektor3D uy(rndmat[0][1], rndmat[1][1], rndmat[2][1]);
	SIMDVektor3D uz(rndmat[0][2], rndmat[1][2], rndmat[2][2]);

	return SIMDOBB_V4(center, ux, uy, uz, ex, ey, ez);
}

auto random_SIMDOBBs(int64_t num_entries) {

	std::vector<SIMDOBB> obbs(num_entries);

	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_real_distribution<float> rndcenter(SPACE);
	std::uniform_real_distribution<float> rndrange(BOXSIZE);

	#pragma omp parallel for schedule(dynamic)
	for (int64_t i = 0; i < num_entries; ++i) {

		SIMDPoint3D center{ rndcenter(engine), rndcenter(engine), rndcenter(engine) };

		float ex = rndrange(engine);
		float ey = rndrange(engine);
		float ez = rndrange(engine);

		Matrix4x4 rndmat = randomRotation();

		SIMDVektor3D ux(rndmat[0][0], rndmat[1][0], rndmat[2][0]);
		SIMDVektor3D uy(rndmat[0][1], rndmat[1][1], rndmat[2][1]);
		SIMDVektor3D uz(rndmat[0][2], rndmat[1][2], rndmat[2][2]);

		obbs[i] = SIMDOBB(center, ux, uy, uz, ex, ey, ez);
	}

	return obbs;
}

auto random_SIMDOBBs_V2(int64_t num_entries) {

	std::vector<SIMDOBB_V2> obbs(num_entries);

	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_real_distribution<float> rndcenter(SPACE);
	std::uniform_real_distribution<float> rndrange(BOXSIZE);

	#pragma omp parallel for schedule(dynamic)
	for (int64_t i = 0; i < num_entries; ++i) {

		SIMDPoint3D center{ rndcenter(engine), rndcenter(engine), rndcenter(engine) };

		float ex = rndrange(engine);
		float ey = rndrange(engine);
		float ez = rndrange(engine);

		Matrix4x4 rndmat = randomRotation();

		SIMDVektor3D ux(rndmat[0][0], rndmat[1][0], rndmat[2][0]);
		SIMDVektor3D uy(rndmat[0][1], rndmat[1][1], rndmat[2][1]);

		obbs[i] = SIMDOBB_V2(center, ux, uy, ex, ey, ez);
	}

	return obbs;
}

auto random_SIMDOBBs_V4(int64_t num_entries) {

	std::vector<SIMDOBB_V4> obbs(num_entries);

	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_real_distribution<float> rndcenter(SPACE);
	std::uniform_real_distribution<float> rndrange(BOXSIZE);

	#pragma omp parallel for schedule(dynamic)
	for (int64_t i = 0; i < num_entries; ++i) {

		SIMDPoint3D center{ rndcenter(engine), rndcenter(engine), rndcenter(engine) };

		float ex = rndrange(engine);
		float ey = rndrange(engine);
		float ez = rndrange(engine);

		Matrix4x4 rndmat = randomRotation();

		SIMDVektor3D ux(rndmat[0][0], rndmat[1][0], rndmat[2][0]);
		SIMDVektor3D uy(rndmat[0][1], rndmat[1][1], rndmat[2][1]);
		SIMDVektor3D uz(rndmat[0][2], rndmat[1][2], rndmat[2][2]);

		obbs[i] = SIMDOBB_V4(center, ux, uy, uz, ex, ey, ez);
	}

	return obbs;
}

/*
	Erstellung von zufälligen SIMD-Boxen in SoA Design
*/

void random_SOA_OBBs(OBBs& boxes) {

	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_real_distribution<float> rndcenter(SPACE);
	std::uniform_real_distribution<float> rndrange(BOXSIZE);

	for (int64_t i = 0; i < boxes.length; ++i) {

		boxes.cx[i] = rndcenter(engine);
		boxes.cy[i] = rndcenter(engine);
		boxes.cz[i] = rndcenter(engine);

		Matrix4x4 rndmat = randomRotation();

		boxes.uxx[i] = rndmat[0][0];
		boxes.uxy[i] = rndmat[1][0];
		boxes.uxz[i] = rndmat[2][0];

		boxes.uyx[i] = rndmat[0][1];
		boxes.uyy[i] = rndmat[1][1];
		boxes.uyz[i] = rndmat[2][1];

		boxes.uzx[i] = rndmat[0][2];
		boxes.uzy[i] = rndmat[1][2];
		boxes.uzz[i] = rndmat[2][2];

		boxes.ex[i] = rndrange(engine);
		boxes.ey[i] = rndrange(engine);
		boxes.ez[i] = rndrange(engine);

	}
}