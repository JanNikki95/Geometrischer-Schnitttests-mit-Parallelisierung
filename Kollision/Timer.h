#pragma once
#include <iostream>
#include <cstdint>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using namespace std::chrono_literals;

#define ITERATIONS 1000
#define TIME    1s

#define TIMERSTART(label)                                                  \
        std::chrono::time_point<std::chrono::system_clock> a##label, b##label; \
        a##label = std::chrono::system_clock::now();


#define TIMERSTARTITERATIONS(label, iterations)                             \
        std::chrono::duration<double> timer##label = std::chrono::microseconds(0);                         \
        for (uint64_t i##lable = 0; i##lable < (iterations); ++i##lable) {                       \
            std::chrono::time_point<std::chrono::system_clock> a##label = std::chrono::system_clock::now();



#define TIMERSTOP(label)                                                   \
        b##label = std::chrono::system_clock::now();                           \
        std::cout << "#elapsed time ("<< #label <<"): "                       \
                  << std::chrono::duration_cast<std::chrono::microseconds>(b##label - a##label).count()  << "mu" << std::endl;


#define TIMERSTOPITERATIONS(label, iterations)                              \
            std::chrono::time_point<std::chrono::system_clock> b##label = std::chrono::system_clock::now(); \
            timer##label += b##label - a##label;                              \
        }                                                                      \
        auto mu_double##label = duration_cast<std::chrono::microseconds>(timer##label);  \
        std::cout << "elapsed time (" << #label << "): "                    \
        << mu_double##label.count() / (double)(iterations) << "mu" << std::endl;
