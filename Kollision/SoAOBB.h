#pragma once
#include <iostream>
#include <immintrin.h>
#include <memory>
#include "SIMDOBB.h"
#include "SIMDKollision.h"

constexpr float float_true = std::bit_cast<float>(-1);

struct OBBs {

	struct Deleter { // deleter
		void operator()(float* p) const {
			_mm_free(p);
		}
	};

	std::unique_ptr<float[], Deleter> cx;
	std::unique_ptr<float[], Deleter> cy;
	std::unique_ptr<float[], Deleter> cz;

	std::unique_ptr<float[], Deleter> uxx;
	std::unique_ptr<float[], Deleter> uxy;
	std::unique_ptr<float[], Deleter> uxz;

	std::unique_ptr<float[], Deleter> uyx;
	std::unique_ptr<float[], Deleter> uyy;
	std::unique_ptr<float[], Deleter> uyz;

	std::unique_ptr<float[], Deleter> uzx;
	std::unique_ptr<float[], Deleter> uzy;
	std::unique_ptr<float[], Deleter> uzz;

	std::unique_ptr<float[], Deleter> ex;
	std::unique_ptr<float[], Deleter> ey;
	std::unique_ptr<float[], Deleter> ez;

	int64_t length;

	OBBs(int64_t num_entries) : 
		cx(static_cast<float*>(_mm_malloc(sizeof(float) * num_entries, 32))),
		cy(static_cast<float*>(_mm_malloc(sizeof(float) * num_entries, 32))),
		cz(static_cast<float*>(_mm_malloc(sizeof(float) * num_entries, 32))),
		uxx(static_cast<float*>(_mm_malloc(sizeof(float)* num_entries, 32))),
		uxy(static_cast<float*>(_mm_malloc(sizeof(float)* num_entries, 32))),
		uxz(static_cast<float*>(_mm_malloc(sizeof(float)* num_entries, 32))),
		uyx(static_cast<float*>(_mm_malloc(sizeof(float)* num_entries, 32))),
		uyy(static_cast<float*>(_mm_malloc(sizeof(float)* num_entries, 32))),
		uyz(static_cast<float*>(_mm_malloc(sizeof(float)* num_entries, 32))),
		uzx(static_cast<float*>(_mm_malloc(sizeof(float)* num_entries, 32))),
		uzy(static_cast<float*>(_mm_malloc(sizeof(float)* num_entries, 32))),
		uzz(static_cast<float*>(_mm_malloc(sizeof(float)* num_entries, 32))),
		ex(static_cast<float*>(_mm_malloc(sizeof(float)* num_entries, 32))),
		ey(static_cast<float*>(_mm_malloc(sizeof(float)* num_entries, 32))),
		ez(static_cast<float*>(_mm_malloc(sizeof(float)* num_entries, 32))),
		length(num_entries) { }
};

void print_SoA_OBB(const OBBs& b) {

	for (int64_t i = 0; i < b.length; ++i) {

		std::cout << "Center:\t( " << b.cx[i] << ", " << b.cy[i] << ", " << b.cz[i] << " )" << '\n';
		std::cout << "ux:\t( " << b.uxx[i] << ", " << b.uxy[i] << ", " << b.uxz[i] << " )" << '\n';
		std::cout << "uy:\t( " << b.uyx[i] << ", " << b.uyy[i] << ", " << b.uyz[i] << " )" << '\n';
		std::cout << "uz:\t( " << b.uzx[i] << ", " << b.uzy[i] << ", " << b.uzz[i] << " )" << '\n';
		std::cout << "ex:\t" << b.ex[i] << '\n';
		std::cout << "ey:\t" << b.ey[i] << '\n';
		std::cout << "ez:\t" << b.ez[i] << '\n';
		std::cout << '\n';
	}
}

__m256 operator+(const __m256& lhs, const __m256& rhs) {
	return _mm256_add_ps(lhs, rhs);
}
__m256 operator-(const __m256& lhs, const __m256& rhs) {
	return _mm256_sub_ps(lhs, rhs);
}
__m256 operator*(const __m256& lhs, const __m256& rhs) {
	return _mm256_mul_ps(lhs, rhs);
}
__m256 operator<=(const __m256& lhs, const __m256& rhs) {
	return _mm256_cmp_ps(lhs, rhs, _CMP_LE_OQ);
}

__m256 abs_mask() {
	__m256i minus1 = _mm256_set1_epi32(-1);
	return _mm256_castsi256_ps(_mm256_srli_epi32(minus1, 1));
}
__m256 abs(__m256 v) {
	return _mm256_and_ps(abs_mask(), v);
}

