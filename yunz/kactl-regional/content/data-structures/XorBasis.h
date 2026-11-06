/**
 * Author: Steven Qiao
 * Date: 2026-11-06
 * License: CC0
 * Source: Folklore
 * Description: Linear basis over GF(2). $r$ = rank, so there are $2^r$ distinct
 * subset xors (including the empty subset, 0). insert returns false if $x$ was
 * already representable. kth reduces the basis in place (still valid afterwards).
 * Usage: XorBasis xb; xb.insert(5); xb.maxXor(); xb.kth(0) == 0;
 * Time: O(B) per operation
 * Status: stress-tested
 * Uses: maximum subset xor, check if a value is a xor of some subset, number of distinct subset xors ($2^r$), k-th smallest subset xor, max xor path in graph (basis of cycle xors), range xor-basis queries (prefix bases).
 */
#pragma once

typedef unsigned long long ull;
struct XorBasis {
	static const int B = 64;
	ull b[B] = {}; int r = 0;
	bool insert(ull x) {
		for (int i = B; i--;) if (x >> i & 1) {
			if (!b[i]) return b[i] = x, ++r;
			x ^= b[i];
		}
		return 0;
	}
	bool can(ull x) {
		for (int i = B; i--;) if (x >> i & 1) x ^= b[i];
		return !x;
	}
	ull maxXor(ull x = 0) { // max of x ^ (subset xor)
		for (int i = B; i--;) x = max(x, x ^ b[i]);
		return x;
	}
	ull kth(ull k) { // k-th smallest subset xor, 0-indexed, k < 2^r
		ull res = 0; int t = 0;
		rep(i,0,B) if (b[i]) {
			for (int j = i; j--;) if (b[i] >> j & 1) b[i] ^= b[j];
			if (k >> t++ & 1) res ^= b[i];
		}
		return res;
	}
};
