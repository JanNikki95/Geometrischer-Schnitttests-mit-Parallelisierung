#include <iostream>
#include "Naiv_Testing.h"
#include "AOS_SIMD_Testing.h"
#include "SOA_SIMD_Testing.h"
#include "Durchdringungstiefe.h"

using namespace std;

int main() {

	int64_t num_entries = 1000;
	cout << "Die Anzahl der Boxen: ";
	cout << num_entries << '\n';
	
	// Zeitmessung für naive Verfahren
	//Naive_Testing_1vAll_V1(num_entries, false);
	//Naive_Testing_1vAll_V2(num_entries, false);
	//Naive_Testing_1vAll_V2(10 * num_entries, false);
	//Naive_Testing_1vAll_V3(num_entries, false);
	//Naive_Testing_1vAll_V3(10 * num_entries, false);
	//Naive_Testing_1vAll_V4(num_entries, false);
	//Naive_Testing_1vAll_V4(10 * num_entries, false);
	//Naive_Testing_1vAll_V5(num_entries, false);
	//Naive_Testing_1vAll_V5(10 * num_entries, false);
	//Naive_Testing_1vAll_OBBV2(num_entries, false);
	//Naive_Testing_1vAll_OBBV2(10 * num_entries, false);
	//Naive_Testing_1vAll_OBBV4(num_entries, false);
	//Naive_Testing_1vAll_OBBV4(10 * num_entries, false);

	// Zeitmessung für SIMD Verfahren in AoS Design
	//AOS_SIMD_Testing_1vAll_V1(num_entries, false);
	//AOS_SIMD_Testing_1vAll_V1(10 * num_entries, false);
	//AOS_SIMD_Testing_1vAll_V2(num_entries, false);
	//AOS_SIMD_Testing_1vAll_V2(10 * num_entries, false);
	//AOS_SIMD_Testing_1vAll_V3(num_entries, false);
	//AOS_SIMD_Testing_1vAll_V3(10 * num_entries, false);
	//AOS_SIMD_Testing_1vAll_V4(num_entries, false);
	//AOS_SIMD_Testing_1vAll_V4(10 * num_entries, false);
	//AOS_SIMD_Testing_1vAll_V5(num_entries, false);
	//AOS_SIMD_Testing_1vAll_V5(10 * num_entries, false);
	//AOS_SIMD_Testing_1vAll_OBBV2(num_entries, false);
	//AOS_SIMD_Testing_1vAll_OBBV2(10 * num_entries, false);
	//AOS_SIMD_Testing_1vAll_OBBV4(num_entries, false);
	//AOS_SIMD_Testing_1vAll_OBBV4(10 * num_entries, false);
	

	// Zeitmessung für SIMD Verfahren in SoA Design
	SOA_SIMD_Testing_1vAll(400);
	SOA_SIMD_Testing_1vAll(500);
	

	system("Pause");
}