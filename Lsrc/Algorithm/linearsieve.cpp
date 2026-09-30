for (int i = 2; i <= n; ++i) {
    if (!is_prime[i]) primes.push_back(i);
    for (int p : primes) {
        if (p * i > n) break;
        is_prime[p * i] = 1;
        if (i % p == 0) break;
    }
}
