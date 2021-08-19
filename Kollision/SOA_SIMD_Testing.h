#pragma once
#include "RandomGenerator.h"
#include "SoAKollision.h"
#include "Timer.h"

void SOA_SIMD_Testing_1vAll(int64_t num_entries, std::chrono::duration<double>& time, float& colproperty) {
	SIMDOBB testbox = random_SIMDOBB();

	OBBs testboxes(num_entries);
	random_SOA_OBBs(testboxes);

	std::vector<float> results(num_entries);

	std::chrono::duration<double> elapsedTime = std::chrono::microseconds(0);
	std::chrono::time_point<std::chrono::system_clock> a = std::chrono::system_clock::now();
	SoA_OBB_Test_1vAll(testbox, testboxes, results.data());
	std::chrono::time_point<std::chrono::system_clock> b = std::chrono::system_clock::now();

	time += b - a;

	int64_t count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		bool res = std::isnan(results[i]) ? true : false;
		if (res) {
			++count;
		}
	}
	colproperty += (100.0 / (float)num_entries) * (float)count;
}

void SOA_SIMD_Testing_1vAll(int64_t num_entries) {
	float colproperty = 0.0f;
	std::chrono::duration<double> time = std::chrono::microseconds(0);
	for (int i = 0; i < ITERATIONS; ++i) {
		SOA_SIMD_Testing_1vAll(num_entries, time, colproperty);
	}
	auto elapsedTime = duration_cast<std::chrono::microseconds>(time);
	std::cout << "elapsed time (SOA_SIMD_Testing_1vAll): " << elapsedTime.count() / (double)(ITERATIONS) << "mu" << std::endl;
	std::cout << "Kollisionswahrscheinlichkeit: " << colproperty / (float)ITERATIONS << std::endl;
}

void SOA_SIMD_Testing_1v1(int64_t num_entries) {

	OBBs testboxes1(num_entries);
	random_SOA_OBBs(testboxes1);

	OBBs testboxes2(num_entries);
	random_SOA_OBBs(testboxes2);

	std::unique_ptr<float[]> results = std::make_unique<float[]>(num_entries);

	TIMERSTART(SOA_OBBOBB_1v1)
	SoA_OBB_Test_1v1(testboxes1, testboxes2, results.get());
	TIMERSTOP(SOA_OBBOBB_1v1)

	int64_t count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (results[i]) {
			++count;
		}
	}
	std::cout << "Prozentualer Anteil der Kollision: " << (100.0 / (double)num_entries) * (double)count << '\n';

	std::cout << '\n';
}

void SOA_SIMD_Durchsatz() {
	int64_t num_entries = 1 << 24;

	SIMDOBB a = random_SIMDOBB();
	OBBs b(num_entries);
	random_SOA_OBBs(b);

	std::vector<float> results_vector(num_entries);
	float* results = results_vector.data();

	int64_t i = 0;
	auto duration = TIME;
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

	__m256 cx_a = _mm256_set1_ps(a.center().x());
	__m256 cy_a = _mm256_set1_ps(a.center().y());
	__m256 cz_a = _mm256_set1_ps(a.center().z());

	__m256 uxx_a = _mm256_set1_ps(a.ux().x());
	__m256 uxy_a = _mm256_set1_ps(a.ux().y());
	__m256 uxz_a = _mm256_set1_ps(a.ux().z());

	__m256 uyx_a = _mm256_set1_ps(a.uy().x());
	__m256 uyy_a = _mm256_set1_ps(a.uy().y());
	__m256 uyz_a = _mm256_set1_ps(a.uy().z());

	__m256 uzx_a = _mm256_set1_ps(a.uz().x());
	__m256 uzy_a = _mm256_set1_ps(a.uz().y());
	__m256 uzz_a = _mm256_set1_ps(a.uz().z());

	__m256 ex_a = _mm256_set1_ps(a.ex());
	__m256 ey_a = _mm256_set1_ps(a.ey());
	__m256 ez_a = _mm256_set1_ps(a.ez());

	do {

		__m256 cx_b = _mm256_load_ps(b.cx.get() + i);
		__m256 cy_b = _mm256_load_ps(b.cy.get() + i);
		__m256 cz_b = _mm256_load_ps(b.cz.get() + i);

		__m256 uxx_b = _mm256_load_ps(b.uxx.get() + i);
		__m256 uxy_b = _mm256_load_ps(b.uxy.get() + i);
		__m256 uxz_b = _mm256_load_ps(b.uxz.get() + i);

		__m256 uyx_b = _mm256_load_ps(b.uyx.get() + i);
		__m256 uyy_b = _mm256_load_ps(b.uyy.get() + i);
		__m256 uyz_b = _mm256_load_ps(b.uyz.get() + i);

		__m256 uzx_b = _mm256_load_ps(b.uzx.get() + i);
		__m256 uzy_b = _mm256_load_ps(b.uzy.get() + i);
		__m256 uzz_b = _mm256_load_ps(b.uzz.get() + i);

		__m256 ex_b = _mm256_load_ps(b.ex.get() + i);
		__m256 ey_b = _mm256_load_ps(b.ey.get() + i);
		__m256 ez_b = _mm256_load_ps(b.ez.get() + i);

		__m256 Dx = cx_a - cx_b;
		__m256 Dy = cy_a - cy_b;
		__m256 Dz = cz_a - cz_b;

		__m256 Sxx = (uxx_a * uxx_b) + (uxy_a * uxy_b) + (uxz_a * uxz_b);
		__m256 Sxy = (uxx_a * uyx_b) + (uxy_a * uyy_b) + (uxz_a * uyz_b);
		__m256 Sxz = (uxx_a * uzx_b) + (uxy_a * uzy_b) + (uxz_a * uzz_b);

		__m256 Syx = (uyx_a * uxx_b) + (uyy_a * uxy_b) + (uyz_a * uxz_b);
		__m256 Syy = (uyx_a * uyx_b) + (uyy_a * uyy_b) + (uyz_a * uyz_b);
		__m256 Syz = (uyx_a * uzx_b) + (uyy_a * uzy_b) + (uyz_a * uzz_b);

		__m256 Szx = (uzx_a * uxx_b) + (uzy_a * uxy_b) + (uzz_a * uxz_b);
		__m256 Szy = (uzx_a * uyx_b) + (uzy_a * uyy_b) + (uzz_a * uyz_b);
		__m256 Szz = (uzx_a * uzx_b) + (uzy_a * uzy_b) + (uzz_a * uzz_b);

		__m256 D_ux_a = (uxx_a * Dx) + (uxy_a * Dy) + (uxz_a * Dz);
		__m256 D_uy_a = (uyx_a * Dx) + (uyy_a * Dy) + (uyz_a * Dz);
		__m256 D_uz_a = (uzx_a * Dx) + (uzy_a * Dy) + (uzz_a * Dz);
		__m256 D_ux_b = (uxx_b * Dx) + (uxy_b * Dy) + (uxz_b * Dz);
		__m256 D_uy_b = (uyx_b * Dx) + (uyy_b * Dy) + (uyz_b * Dz);
		__m256 D_uz_b = (uzx_b * Dx) + (uzy_b * Dy) + (uzz_b * Dz);

			// Achse Ax
		__m256 d1 = abs(D_ux_a);
		__m256 ra1 = ex_a;
		__m256 rb1 = abs(D_uy_a);

			// Achse Ay
		__m256 d2 = abs(D_uy_a);
		__m256 ra2 = ey_a;
		__m256 rb2 = abs((ex_b * Syx)) + abs((ey_b * Syy)) + abs((ez_b * Syz));

			// Achse Az
		__m256 d3 = abs(D_uz_a);
		__m256 ra3 = ez_a;
		__m256 rb3 = abs((ex_b * Szx)) + abs((ey_b * Szy)) + abs((ez_b * Szz));

			// Achse Bx
		__m256 d4 = abs(D_ux_b);
		__m256 ra4 = abs(ex_a * Sxx) + abs(ey_a * Syx) + abs(ez_a * Szx);
		__m256 rb4 = ex_b;

			// Achse By
		__m256 d5 = abs(D_uy_b);
		__m256 ra5 = abs(ex_a * Sxy) + abs(ey_a * Syy) + abs(ez_a * Szy);
		__m256 rb5 = ey_b;

			// Achse Bz
		__m256 d6 = abs(D_uz_b);
		__m256 ra6 = abs(ex_a * Sxz) + abs(ey_a * Syz) + abs(ez_a * Szz);
		__m256 rb6 = ez_b;

			// Achse Ax x Bx
		__m256 d7 = abs((Syx * D_uz_a) - (Szx * D_uy_a));
		__m256 ra7 = abs(ey_a * Szx) + abs(ez_a * Syx);
		__m256 rb7 = abs(ey_b * Sxz) + abs(ez_b * Sxy);

			// Achse Ax x By
		__m256 d8 = abs((Syy * D_uz_a) - (Szy * D_uy_a));
		__m256 ra8 = abs(ey_a * Szy) + abs(ez_a * Syy);
		__m256 rb8 = abs(ex_b * Sxz) + abs(ez_b * Sxx);

			// Achse Ax x Bz
		__m256 d9 = abs((Syz * D_uz_a) - (Szz * D_uy_a));
		__m256 ra9 = abs(ey_a * Szz) + abs(ez_a * Syz);
		__m256 rb9 = abs(ex_b * Sxy) + abs(ey_b * Sxx);

			// Achse Ay x Bx
		__m256 d10 = abs((Szx * D_ux_a) - (Sxx * D_uz_a));
		__m256 ra10 = abs(ex_a * Szx) + abs(ez_a * Sxx);
		__m256 rb10 = abs(ey_b * Syz) + abs(ez_b * Syy);

			// Achse Ay x By
		__m256 d11 = abs((Szy * D_ux_a) - (Sxy * D_uz_a));
		__m256 ra11 = abs(ex_a * Szy) + abs(ez_a * Sxy);
		__m256 rb11 = abs(ex_b * Syz) + abs(ez_b * Syx);

			// Achse Ay x Bz
		__m256 d12 = abs((Szz * D_ux_a) - (Sxz * D_uz_a));
		__m256 ra12 = abs(ex_a * Szz) + abs(ez_a * Sxz);
		__m256 rb12 = abs(ex_b * Syy) + abs(ey_b * Syx);

			// Achse Az x Bx
		__m256 d13 = abs((Sxx * D_uy_a) - (Syx * D_ux_a));
		__m256 ra13 = abs(ex_a * Syx) + abs(ey_a * Sxx);
		__m256 rb13 = abs(ey_b * Szz) + abs(ez_b * Szy);

			// Achse Az x By
		__m256 d14 = abs((Sxy * D_uy_a) - (Syy * D_ux_a));
		__m256 ra14 = abs(ex_a * Syy) + abs(ey_a * Sxy);
		__m256 rb14 = abs(ex_b * Szz) + abs(ez_b * Szx);

			// Achse Az x Bz
		__m256 d15 = abs((Sxz * D_uy_a) - (Syz * D_ux_a));
		__m256 ra15 = abs(ex_a * Syz) + abs(ey_a * Sxz);
		__m256 rb15 = abs(ex_b * Szy) + abs(ey_b * Szx);

		__m256 cmp1 = d1 <= (ra1 + rb1);
		__m256 cmp2 = d2 <= (ra2 + rb2);
		__m256 cmp3 = d3 <= (ra3 + rb3);
		__m256 cmp4 = d4 <= (ra4 + rb4);
		__m256 cmp5 = d5 <= (ra5 + rb5);
		__m256 cmp6 = d6 <= (ra6 + rb6);
		__m256 cmp7 = d7 <= (ra7 + rb7);
		__m256 cmp8 = d8 <= (ra8 + rb8);
		__m256 cmp9 = d9 <= (ra9 + rb9);
		__m256 cmp10 = d10 <= (ra10 + rb10);
		__m256 cmp11 = d11 <= (ra11 + rb11);
		__m256 cmp12 = d12 <= (ra12 + rb12);
		__m256 cmp13 = d13 <= (ra13 + rb13);
		__m256 cmp14 = d14 <= (ra14 + rb14);
		__m256 cmp15 = d15 <= (ra15 + rb15);

		__m256 res1 = _mm256_and_ps(cmp1, cmp2);
		__m256 res2 = _mm256_and_ps(cmp3, cmp4);
		__m256 res3 = _mm256_and_ps(cmp5, cmp6);
		__m256 res4 = _mm256_and_ps(cmp7, cmp8);
		__m256 res5 = _mm256_and_ps(cmp9, cmp10);
		__m256 res6 = _mm256_and_ps(cmp11, cmp12);
		__m256 res7 = _mm256_and_ps(cmp13, cmp14);

		__m256 res2_1 = _mm256_and_ps(res1, cmp15);
		__m256 res2_2 = _mm256_and_ps(res2, res3);
		__m256 res2_3 = _mm256_and_ps(res4, res5);
		__m256 res2_4 = _mm256_and_ps(res6, res7);

		__m256 res3_1 = _mm256_and_ps(res2_1, res2_2);
		__m256 res3_2 = _mm256_and_ps(res2_3, res2_4);

		__m256 res4_1 = _mm256_and_ps(res3_1, res3_2);

		_mm256_store_ps(results + i, res4_1);
		i += 8;
	} while ((std::chrono::system_clock::now() - start) < duration && i < num_entries);

	std::cout << "Durchsatz für SoA SIMD Schnitttest\n";
	std::cout << "Counter: " << i << '\n';
}