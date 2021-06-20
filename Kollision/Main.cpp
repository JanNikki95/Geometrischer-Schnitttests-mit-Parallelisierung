#include <iostream>
#include "Naiv_Testing.h"
#include "AOS_SIMD_Testing.h"
#include "SOA_SIMD_Testing.h"
#include "Durchdringungstiefe.h"

using namespace std;

int main() {

	int64_t num_entries = 0;
	cout << "Geben Sie die Anzahl der Boxen an: ";
	cin >> num_entries;
	cout << '\n';
	
	// Zeitmessung für naive Verfahren
	Naive_Testing_1vAll_V1(num_entries, false);
	Naive_Testing_1vAll_V2(num_entries, false);
	Naive_Testing_1vAll_V3(num_entries, false);
	Naive_Testing_1vAll_V4(num_entries, false);
	Naive_Testing_1vAll_V5(num_entries, false);
	Naive_Testing_1vAll_OBBV2(num_entries, false);
	Naive_Testing_1vAll_OBBV4(num_entries, false);

	// Zeitmessung für SIMD Verfahren in AoS Design
	AOS_SIMD_Testing_1vAll_V1(num_entries, false);
	AOS_SIMD_Testing_1vAll_V2(num_entries, false);
	AOS_SIMD_Testing_1vAll_V3(num_entries, false);
	AOS_SIMD_Testing_1vAll_V4(num_entries, false);
	AOS_SIMD_Testing_1vAll_V5(num_entries, false);
	AOS_SIMD_Testing_1vAll_OBBV2(num_entries, false);
	AOS_SIMD_Testing_1vAll_OBBV4(num_entries, false);

	// Zeitmessung für SIMD Verfahren in SoA Design
	SOA_SIMD_Testing_1vAll(num_entries);

	/*Naive_Durchsatz_V1();
	Naive_Durchsatz_V2();
	Naive_Durchsatz_V3();
	Naive_Durchsatz_V4();
	Naive_Durchsatz_V5();
	Naive_Durchsatz_OBBV2();
	Naive_Durchsatz_OBBV4();*/

	/*AoS_SIMD_Durchsatz_V1();
	AoS_SIMD_Durchsatz_V2();
	AoS_SIMD_Durchsatz_V3();
	AoS_SIMD_Durchsatz_V4();
	AoS_SIMD_Durchsatz_V5();
	AoS_SIMD_Durchsatz_OBBV2();
	AoS_SIMD_Durchsatz_OBBV4();*/

	//SOA_SIMD_Durchsatz();

	system("Pause");
}