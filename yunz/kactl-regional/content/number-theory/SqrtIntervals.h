/**
 * Uses: iterate distinct values of floor(n/i) in $O(\sqrt{n})$: sum of floor(n/i), divisor sums, Dirichlet-style / Mobius sums.
 * Author: Kelly Dance, ChatGPT
 * Description: break 1..n into inclusive intervals in sorted order, constant on $\lfloor \frac{n}{i} \rfloor$ or $\lceil \frac{n}{i} \rceil$.
 * Source: https://github.com/kelly-dance/mactl/blob/main/content/various/SqrtIntervals.h
 * Time: $O(\sqrt N)$
 * Status: stress-tested
 */
#pragma once

auto fdivSplit = [](int n) {
    vector<pii> segs;
    for (int q, r, l = 1; l <= n; l = r+1) {
        q = n/l, r = n/q;
        segs.pb({l, r});
    }
    return segs;
};
auto cdivSplit = [](int n) {
    auto segs = fdivSplit(n-1);
    segs.pb({n, n});
    return segs;
};