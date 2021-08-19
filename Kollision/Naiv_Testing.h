#pragma once
#include <iostream>
#include <omp.h>
#include "Kollision.h"
#include "RandomGenerator.h"
#include "Timer.h"

void Naive_Testing_1vAll_V1(int64_t num_entries, bool parallel, std::chrono::duration<double>& time, float& colproperty) {
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);
	OBB testbox = random_OBB();
	std::vector<OBB> testboxes = random_OBBs(num_entries);

	std::chrono::duration<double> elapsedTime = std::chrono::microseconds(0);
	std::chrono::time_point<std::chrono::system_clock> a = std::chrono::system_clock::now();
	#pragma omp parallel for if(parallel)
	for (int64_t i = 0; i < num_entries; ++i) {
		res[i] = TestOBBOBB_V1(testbox, testboxes[i]);
	}
	std::chrono::time_point<std::chrono::system_clock> b = std::chrono::system_clock::now();

	time += b - a;

	int64_t count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (res[i]) {
			++count;
		}
	}
	colproperty += (100.0 / (float)num_entries) * (float)count;
}

void Naive_Testing_1vAll_V1(int64_t num_entries, bool parallel) {
	float colproperty = 0.0f;
	std::chrono::duration<double> time = std::chrono::microseconds(0);
	for (int i = 0; i < ITERATIONS; ++i) {
		Naive_Testing_1vAll_V1(num_entries, parallel, time, colproperty);
	}
	auto elapsedTime = duration_cast<std::chrono::microseconds>(time);
	std::cout << "elapsed time (Naive_OBBOBB_1vAll_V1): " << elapsedTime.count() / (double)(ITERATIONS) << "mu" << std::endl;
	std::cout << "Kollisionswahrscheinlichkeit: " << colproperty / (float)ITERATIONS << std::endl;
}


void Naive_Testing_1vAll_V2(int64_t num_entries, bool parallel, std::chrono::duration<double>& time, float& colproperty) {
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);
	OBB testbox = random_OBB();
	std::vector<OBB> testboxes = random_OBBs(num_entries);

	std::chrono::duration<double> elapsedTime = std::chrono::microseconds(0);
	std::chrono::time_point<std::chrono::system_clock> a = std::chrono::system_clock::now();
	#pragma omp parallel for if(parallel)
	for (int64_t i = 0; i < num_entries; ++i) {
		res[i] = TestOBBOBB_V2(testbox, testboxes[i]);
	}
	std::chrono::time_point<std::chrono::system_clock> b = std::chrono::system_clock::now();

	time += b - a;

	int64_t count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (res[i]) {
			++count;
		}
	}
	colproperty += (100.0 / (float)num_entries) * (float)count;
}

void Naive_Testing_1vAll_V2(int64_t num_entries, bool parallel) {
	float colproperty = 0.0f;
	std::chrono::duration<double> time = std::chrono::microseconds(0);
	for (int i = 0; i < ITERATIONS; ++i) {
		Naive_Testing_1vAll_V2(num_entries, parallel, time, colproperty);
	}
	auto elapsedTime = duration_cast<std::chrono::microseconds>(time);
	std::cout << "elapsed time (Naive_OBBOBB_1vAll_V2): " << elapsedTime.count() / (double)(ITERATIONS) << "mu" << std::endl;
	std::cout << "Kollisionswahrscheinlichkeit: " << colproperty / (float)ITERATIONS << std::endl;
}


void Naive_Testing_1vAll_V3(int64_t num_entries, bool parallel, std::chrono::duration<double>& time, float& colproperty) {
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);
	OBB testbox = random_OBB();
	std::vector<OBB> testboxes = random_OBBs(num_entries);

	std::chrono::duration<double> elapsedTime = std::chrono::microseconds(0);
	std::chrono::time_point<std::chrono::system_clock> a = std::chrono::system_clock::now();
	#pragma omp parallel for if(parallel)
	for (int64_t i = 0; i < num_entries; ++i) {
		res[i] = TestOBBOBB_V3(testbox, testboxes[i]);
	}
	std::chrono::time_point<std::chrono::system_clock> b = std::chrono::system_clock::now();

	time += b - a;

	int64_t count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (res[i]) {
			++count;
		}
	}
	colproperty += (100.0 / (float)num_entries) * (float)count;
}

void Naive_Testing_1vAll_V3(int64_t num_entries, bool parallel) {
	float colproperty = 0.0f;
	std::chrono::duration<double> time = std::chrono::microseconds(0);
	for (int i = 0; i < ITERATIONS; ++i) {
		Naive_Testing_1vAll_V3(num_entries, parallel, time, colproperty);
	}
	auto elapsedTime = duration_cast<std::chrono::microseconds>(time);
	std::cout << "elapsed time (Naive_OBBOBB_1vAll_V3): " << elapsedTime.count() / (double)(ITERATIONS) << "mu" << std::endl;
	std::cout << "Kollisionswahrscheinlichkeit: " << colproperty / (float)ITERATIONS << std::endl;
}


void Naive_Testing_1vAll_V4(int64_t num_entries, bool parallel, std::chrono::duration<double>& time, float& colproperty) {
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);
	OBB testbox = random_OBB();
	std::vector<OBB> testboxes = random_OBBs(num_entries);

	std::chrono::duration<double> elapsedTime = std::chrono::microseconds(0);
	std::chrono::time_point<std::chrono::system_clock> a = std::chrono::system_clock::now();
	#pragma omp parallel for if(parallel)
	for (int64_t i = 0; i < num_entries; ++i) {
		res[i] = TestOBBOBB_V4(testbox, testboxes[i]);
	}
	std::chrono::time_point<std::chrono::system_clock> b = std::chrono::system_clock::now();

	time += b - a;

	int64_t count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (res[i]) {
			++count;
		}
	}
	colproperty += (100.0 / (float)num_entries) * (float)count;
}

void Naive_Testing_1vAll_V4(int64_t num_entries, bool parallel) {
	float colproperty = 0.0f;
	std::chrono::duration<double> time = std::chrono::microseconds(0);
	for (int i = 0; i < ITERATIONS; ++i) {
		Naive_Testing_1vAll_V4(num_entries, parallel, time, colproperty);
	}
	auto elapsedTime = duration_cast<std::chrono::microseconds>(time);
	std::cout << "elapsed time (Naive_OBBOBB_1vAll_V4): " << elapsedTime.count() / (double)(ITERATIONS) << "mu" << std::endl;
	std::cout << "Kollisionswahrscheinlichkeit: " << colproperty / (float)ITERATIONS << std::endl;
}


void Naive_Testing_1vAll_V5(int64_t num_entries, bool parallel, std::chrono::duration<double>& time, float& colproperty) {
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);
	OBB testbox = random_OBB();
	std::vector<OBB> testboxes = random_OBBs(num_entries);

	std::chrono::duration<double> elapsedTime = std::chrono::microseconds(0);
	std::chrono::time_point<std::chrono::system_clock> a = std::chrono::system_clock::now();
#pragma omp parallel for if(parallel)
	for (int64_t i = 0; i < num_entries; ++i) {
		res[i] = TestOBBOBB_V5(testbox, testboxes[i]);
	}
	std::chrono::time_point<std::chrono::system_clock> b = std::chrono::system_clock::now();

	time += b - a;

	int64_t count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (res[i]) {
			++count;
		}
	}
	colproperty += (100.0 / (float)num_entries) * (float)count;
}

void Naive_Testing_1vAll_V5(int64_t num_entries, bool parallel) {
	float colproperty = 0.0f;
	std::chrono::duration<double> time = std::chrono::microseconds(0);
	for (int i = 0; i < ITERATIONS; ++i) {
		Naive_Testing_1vAll_V5(num_entries, parallel, time, colproperty);
	}
	auto elapsedTime = duration_cast<std::chrono::microseconds>(time);
	std::cout << "elapsed time (Naive_OBBOBB_1vAll_V5): " << elapsedTime.count() / (double)(ITERATIONS) << "mu" << std::endl;
	std::cout << "Kollisionswahrscheinlichkeit: " << colproperty / (float)ITERATIONS << std::endl;
}


void Naive_Testing_1vAll_OBBV2(int64_t num_entries, bool parallel, std::chrono::duration<double>& time, float& colproperty) {
	OBB_V2 testbox = random_OBB_V2();
	std::vector<OBB_V2> testboxes = random_OBBs_V2(num_entries);
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);

	std::chrono::duration<double> elapsedTime = std::chrono::microseconds(0);
	std::chrono::time_point<std::chrono::system_clock> a = std::chrono::system_clock::now();
	#pragma omp parallel for if(parallel)
	for (int64_t i = 0; i < num_entries; ++i) {
		res[i] = TestOBBOBB_V4(testbox, testboxes[i]);
	}
	std::chrono::time_point<std::chrono::system_clock> b = std::chrono::system_clock::now();

	time += b - a;

	int64_t count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (res[i]) {
			++count;
		}
	}
	colproperty += (100.0 / (float)num_entries) * (float)count;
}

void Naive_Testing_1vAll_OBBV2(int64_t num_entries, bool parallel) {
	float colproperty = 0.0f;
	std::chrono::duration<double> time = std::chrono::microseconds(0);
	for (int i = 0; i < ITERATIONS; ++i) {
		Naive_Testing_1vAll_OBBV2(num_entries, parallel, time, colproperty);
	}
	auto elapsedTime = duration_cast<std::chrono::microseconds>(time);
	std::cout << "elapsed time (Naive_Testing_1vAll_OBBV2): " << elapsedTime.count() / (double)(ITERATIONS) << "mu" << std::endl;
	std::cout << "Kollisionswahrscheinlichkeit: " << colproperty / (float)ITERATIONS << std::endl;
}


void Naive_Testing_1vAll_OBBV4(int64_t num_entries, bool parallel, std::chrono::duration<double>& time, float& colproperty) {
	OBB_V4 testbox = random_OBB_V4();
	std::vector<OBB_V4> testboxes = random_OBBs_V4(num_entries);
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);

	std::chrono::duration<double> elapsedTime = std::chrono::microseconds(0);
	std::chrono::time_point<std::chrono::system_clock> a = std::chrono::system_clock::now();
	#pragma omp parallel for if(parallel)
	for (int64_t i = 0; i < num_entries; ++i) {
		res[i] = TestOBBOBB_V4(testbox, testboxes[i]);
	}
	std::chrono::time_point<std::chrono::system_clock> b = std::chrono::system_clock::now();
	time += b - a;

	int64_t count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (res[i]) {
			++count;
		}
	}
	colproperty += (100.0 / (float)num_entries) * (float)count;
}

void Naive_Testing_1vAll_OBBV4(int64_t num_entries, bool parallel) {
	float colproperty = 0.0f;
	std::chrono::duration<double> time = std::chrono::microseconds(0);
	for (int i = 0; i < ITERATIONS; ++i) {
		Naive_Testing_1vAll_OBBV4(num_entries, parallel, time, colproperty);
	}
	auto elapsedTime = duration_cast<std::chrono::microseconds>(time);
	std::cout << "elapsed time (Naive_Testing_1vAll_OBBV4): " << elapsedTime.count() / (double)(ITERATIONS) << "mu" << std::endl;
	std::cout << "Kollisionswahrscheinlichkeit: " << colproperty / (float)ITERATIONS << std::endl;
}



void Naive_Durchsatz_V1() {
	int64_t num_entries = 1 << 25; // 33.554.432
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);
	OBB testbox = random_OBB();
	std::vector<OBB> testboxes = random_OBBs(num_entries);


	int counter = 0;
	auto duration = TIME;
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

	do {
		res[counter] = TestOBBOBB_V1(testbox, testboxes[counter]);
		++counter;
	} while ((std::chrono::system_clock::now() - start) < duration && counter < num_entries);

	std::cout << "Durchsatz für naiven V1 OBBOBB-Schnitttest\n";
	std::cout << "Counter: " << counter << '\n';
}

void Naive_Durchsatz_V2() {
	int64_t num_entries = 1 << 25; // 33.554.432
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);
	OBB testbox = random_OBB();
	std::vector<OBB> testboxes = random_OBBs(num_entries);


	int counter = 0;
	auto duration = TIME;
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

	do {
		res[counter] = TestOBBOBB_V2(testbox, testboxes[counter]);
		++counter;
	} while ((std::chrono::system_clock::now() - start) < duration && counter < num_entries);

	std::cout << "Durchsatz für naiven V2 OBBOBB-Schnitttest\n";
	std::cout << "Counter: " << counter << '\n';
}

void Naive_Durchsatz_V3() {
	int64_t num_entries = 1 << 25; // 33.554.432
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);
	OBB testbox = random_OBB();
	std::vector<OBB> testboxes = random_OBBs(num_entries);


	int counter = 0;
	auto duration = TIME;
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

	do {
		res[counter] = TestOBBOBB_V3(testbox, testboxes[counter]);
		++counter;
	} while ((std::chrono::system_clock::now() - start) < duration && counter < num_entries);

	std::cout << "Durchsatz für naiven V3 OBBOBB-Schnitttest\n";
	std::cout << "Counter: " << counter << '\n';
}

void Naive_Durchsatz_V4() {
	int64_t num_entries = 1 << 25; // 33.554.432
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);
	OBB testbox = random_OBB();
	std::vector<OBB> testboxes = random_OBBs(num_entries);


	int64_t counter = 0;
	auto duration = TIME;
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    
	do {
		TestOBBOBB_V4(testbox, testboxes[counter]);
		++counter;
	} while ((std::chrono::system_clock::now() - start) < duration && counter < num_entries);

	std::cout << "Durchsatz für naiven V4 OBBOBB-Schnitttest\n";
	std::cout << "Counter: " << counter << '\n';
}

void Naive_Durchsatz_V5 () {
	int64_t num_entries = 1 << 25; // 33.554.432
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);
	OBB testbox = random_OBB();
	std::vector<OBB> testboxes = random_OBBs(num_entries);


	int64_t counter = 0;
	auto duration = TIME;
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

	do {
		TestOBBOBB_V5(testbox, testboxes[counter]);
		++counter;
	} while ((std::chrono::system_clock::now() - start) < duration && counter < num_entries);

	std::cout << "Durchsatz für naiven V5 OBBOBB-Schnitttest\n";
	std::cout << "Counter: " << counter << '\n';
}

void Naive_Durchsatz_OBBV2() {
	int64_t num_entries = 1 << 25; // 33.554.432
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);
	OBB_V2 testbox = random_OBB_V2();
	std::vector<OBB_V2> testboxes = random_OBBs_V2(num_entries);


	int64_t counter = 0;
	auto duration = TIME;
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

	do {
		TestOBBOBB_V4(testbox, testboxes[counter]);
		++counter;
	} while ((std::chrono::system_clock::now() - start) < duration && counter < num_entries);

	std::cout << "Durchsatz für naiven OBBOBB-Schnitttest für OBBs ohne die Achse uz\n";
	std::cout << "Counter: " << counter << '\n';
}

void Naive_Durchsatz_OBBV4() {
	int64_t num_entries = 1 << 25; // 33.554.432
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);
	OBB_V2 testbox = random_OBB_V2();
	std::vector<OBB_V2> testboxes = random_OBBs_V2(num_entries);


	int64_t counter = 0;
	auto duration = TIME;
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

	do {
		TestOBBOBB_V4(testbox, testboxes[counter]);
		++counter;
	} while ((std::chrono::system_clock::now() - start) < duration && counter < num_entries);

	std::cout << "Durchsatz für naiven OBBOBB-Schnitttest für OBBs mit Quaternion als Orientierung\n";
	std::cout << "Counter: " << counter << '\n';
}


void Naive_Testing_1v1_V1(int64_t num_entries, bool parallel) {
	std::vector<OBB> testboxes1 = random_OBBs(num_entries);
	std::vector<OBB> testboxes2 = random_OBBs(num_entries);
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);

	TIMERSTARTITERATIONS(OBBOBB_1v1_V1, ITERATIONS)
	#pragma omp parallel for if(parallel)
	for (int64_t i = 0; i < num_entries; ++i) {
		res[i] = TestOBBOBB_V1(testboxes1[i], testboxes2[i]);
	}
	TIMERSTOPITERATIONS(OBBOBB_1v1_V1, ITERATIONS)

	int64_t	count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (res[i]) {
			++count;
		}
	}
	std::cout << "Prozentualer Anteil der Kollision: " << (100.0 / (double)num_entries) * (double)count << '\n';

	std::cout << '\n';
}

void Naive_Testing_1v1_V2(int64_t num_entries, bool parallel) {
	std::vector<OBB> testboxes1 = random_OBBs(num_entries);
	std::vector<OBB> testboxes2 = random_OBBs(num_entries);
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);

	TIMERSTARTITERATIONS(OBBOBB_1v1_V2, ITERATIONS)
	#pragma omp parallel for if(parallel)
	for (int64_t i = 0; i < num_entries; ++i) {
		res[i] = TestOBBOBB_V2(testboxes1[i], testboxes2[i]);
	}
	TIMERSTOPITERATIONS(OBBOBB_1v1_V2, ITERATIONS)

		int64_t	count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (res[i]) {
			++count;
		}
	}
	std::cout << "Prozentualer Anteil der Kollision: " << (100.0 / (double)num_entries) * (double)count << '\n';

	std::cout << '\n';
}

void Naive_Testing_1v1_V3(int64_t num_entries, bool parallel) {
	std::vector<OBB> testboxes1 = random_OBBs(num_entries);
	std::vector<OBB> testboxes2 = random_OBBs(num_entries);
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);

	TIMERSTARTITERATIONS(OBBOBB_1v1_V3, ITERATIONS)
	#pragma omp parallel for if(parallel)
	for (int64_t i = 0; i < num_entries; ++i) {
		res[i] = TestOBBOBB_V3(testboxes1[i], testboxes2[i]);
	}
	TIMERSTOPITERATIONS(OBBOBB_1v1_V3, ITERATIONS)

		int64_t	count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (res[i]) {
			++count;
		}
	}
	std::cout << "Prozentualer Anteil der Kollision: " << (100.0 / (double)num_entries) * (double)count << '\n';

	std::cout << '\n';
}

void Naive_Testing_1v1_V4(int64_t num_entries, bool parallel) {
	std::vector<OBB> testboxes1 = random_OBBs(num_entries);
	std::vector<OBB> testboxes2 = random_OBBs(num_entries);
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);

	TIMERSTARTITERATIONS(OBBOBB_1v1_V4, ITERATIONS)
	#pragma omp parallel for if(parallel)
	for (int64_t i = 0; i < num_entries; ++i) {
		res[i] = TestOBBOBB_V4(testboxes1[i], testboxes2[i]);
	}
	TIMERSTOPITERATIONS(OBBOBB_1v1_V4, ITERATIONS)

		int64_t	count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (res[i]) {
			++count;
		}
	}
	std::cout << "Prozentualer Anteil der Kollision: " << (100.0 / (double)num_entries) * (double)count << '\n';

	std::cout << '\n';
}

void Naive_Testing_1v1_V5(int64_t num_entries, bool parallel) {
	std::vector<OBB> testboxes1 = random_OBBs(num_entries);
	std::vector<OBB> testboxes2 = random_OBBs(num_entries);
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);

	TIMERSTARTITERATIONS(OBBOBB_1v1_V5, ITERATIONS)
	#pragma omp parallel for if(parallel)
	for (int64_t i = 0; i < num_entries; ++i) {
		res[i] = TestOBBOBB_V5(testboxes1[i], testboxes2[i]);
	}
	TIMERSTOPITERATIONS(OBBOBB_1v1_V5, ITERATIONS)

		int64_t	count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (res[i]) {
			++count;
		}
	}
	std::cout << "Prozentualer Anteil der Kollision: " << (100.0 / (double)num_entries) * (double)count << '\n';

	std::cout << '\n';
}

void Naive_Testing_1v1_V6(int64_t num_entries, bool parallel) {
	std::vector<OBB> testboxes1 = random_OBBs(num_entries);
	std::vector<OBB> testboxes2 = random_OBBs(num_entries);
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);

	TIMERSTARTITERATIONS(OBBOBB_1v1_V6, ITERATIONS)
	#pragma omp parallel for if(parallel)
	for (int64_t i = 0; i < num_entries; ++i) {
		res[i] = TestOBBOBB_V6(testboxes1[i], testboxes2[i]);
	}
	TIMERSTOPITERATIONS(OBBOBB_1v1_V6, ITERATIONS)

		int64_t	count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (res[i]) {
			++count;
		}
	}
	std::cout << "Prozentualer Anteil der Kollision: " << (100.0 / (double)num_entries) * (double)count << '\n';

	std::cout << '\n';
}

void Naive_Testing_1v1_OBBV2(int64_t num_entries, bool parallel) {
	std::vector<OBB_V2> testboxes1 = random_OBBs_V2(num_entries);
	std::vector<OBB_V2> testboxes2 = random_OBBs_V2(num_entries);
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);

	TIMERSTARTITERATIONS(OBBOBB_1v1_V4_OBB_V2, ITERATIONS)
	#pragma omp parallel for if(parallel)
	for (int64_t i = 0; i < num_entries; ++i) {
		res[i] = TestOBBOBB_V4(testboxes1[i], testboxes2[i]);
	}
	TIMERSTOPITERATIONS(OBBOBB_1v1_V4_OBB_V2, ITERATIONS)

	int64_t count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (res[i]) {
			++count;
		}
	}
	std::cout << "Prozentualer Anteil der Kollision: " << (100.0 / (double)num_entries) * (double)count << '\n';

	std::cout << '\n';
}

void Naive_Testing_1v1_OBBV4(int64_t num_entries, bool parallel) {
	std::vector<OBB_V4> testboxes1 = random_OBBs_V4(num_entries);
	std::vector<OBB_V4> testboxes2 = random_OBBs_V4(num_entries);
	std::unique_ptr<bool[]> res = std::make_unique<bool[]>(num_entries);

	TIMERSTARTITERATIONS(OBBOBB_1v1_V4_OBB_V4, ITERATIONS)
		for (int64_t i = 0; i < num_entries; ++i) {
			res[i] = TestOBBOBB_V4(testboxes1[i], testboxes2[i]);
		}
	TIMERSTOPITERATIONS(OBBOBB_1v1_V4_OBB_V4, ITERATIONS)

	int64_t count = 0;
	for (int64_t i = 0; i < num_entries; ++i) {
		if (res[i]) {
			++count;
		}
	}
	std::cout << "Prozentualer Anteil der Kollision: " << (100.0 / (double)num_entries) * (double)count << '\n';

	std::cout << '\n';
}
