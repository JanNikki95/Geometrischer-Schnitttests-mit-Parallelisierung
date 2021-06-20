#pragma once
#include <immintrin.h>
#include <memory>

struct Vektors3D {
	std::unique_ptr<float[]> x;
	std::unique_ptr<float[]> y;
	std::unique_ptr<float[]> z;

	Vektors3D(int64_t length) :
		x(std::make_unique<float[]>(length)),
		y(std::make_unique<float[]>(length)),
		z(std::make_unique<float[]>(length)) { }

};


void dot(const Vektors3D& vs, const Vektors3D& ws, size_t length, float* results) {
	__m256 xvs, xws, yvs, yws, zvs, zws, xmul, ymul, zmul, res;

	for (size_t i = 0; i < length; i += 8) {
		xvs = _mm256_loadu_ps(vs.x.get() + i);
		xws = _mm256_loadu_ps(ws.x.get() + i);

		yvs = _mm256_loadu_ps(vs.y.get() + i);
		yws = _mm256_loadu_ps(ws.y.get() + i);

		zvs = _mm256_loadu_ps(vs.z.get() + i);
		zws = _mm256_loadu_ps(ws.z.get() + i);

		xmul = _mm256_mul_ps(xvs, xws);
		ymul = _mm256_mul_ps(yvs, yws);
		zmul = _mm256_mul_ps(zvs, zws);

		res = _mm256_add_ps(xmul, ymul);
		res = _mm256_add_ps(res, zmul);

		_mm256_store_ps(results + i, res);
	}

}