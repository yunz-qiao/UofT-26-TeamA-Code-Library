#include "../utilities/template.h"

#include "../../content/data-structures/XorBasis.h"

int main() {
	mt19937_64 rng(2);
	rep(it,0,3000) {
		int bits = (int)(rng() % 7) + 1, n = (int)(rng() % 8);
		bool hi = rng() % 4 == 0; // occasionally test top bits
		vector<ull> a(n);
		for (ull& x : a) { x = rng() % (1ULL << bits); if (hi) x <<= (64 - bits); }
		XorBasis xb;
		set<ull> span;
		rep(m,0,1 << n) {
			ull x = 0;
			rep(i,0,n) if (m >> i & 1) x ^= a[i];
			span.insert(x);
		}
		set<ull> cur = {0};
		for (ull x : a) {
			bool nw = !cur.count(x);
			assert(xb.insert(x) == nw);
			if (nw) { set<ull> c2 = cur; for (ull y : cur) c2.insert(y ^ x); cur = c2; }
		}
		assert(cur == span && (1ULL << xb.r) == span.size());
		rep(q,0,20) {
			ull x = rng() % (1ULL << bits); if (hi) x <<= (64 - bits);
			assert(xb.can(x) == (bool)span.count(x));
			ull best = 0; for (ull y : span) best = max(best, x ^ y);
			assert(xb.maxXor(x) == best);
		}
		vector<ull> v(all(span));
		rep(k,0,sz(v)) assert(xb.kth(k) == v[k]);
		for (ull y : span) assert(xb.can(y)); // still valid after kth
	}
	cout << "Tests passed!" << endl;
}
