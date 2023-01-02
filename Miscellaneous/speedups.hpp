// Safe
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2")

// Unsafe
#pragma GCC optimize("Ofast,unroll-loops,strict-overflow,no-stack-protector,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx2,popcnt,lzcnt,abm,bmi,bmi2,tune=native")
#pragma GCC ivdep
