
void linear_sieve(int n) {
    phi[1] = 1;
    mu[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!is_composite[i]) {
            primes.push_back(i);
            phi[i] = i - 1;
            mu[i] = -1;
        }
        for (int p : primes) {
            if (p * i > n) break;
            is_composite[p * i] = true;
            if (i % p == 0) {
                phi[p * i] = phi[i] * p;
                mu[p * i] = 0;
                break;
            } else {
                phi[p * i] = phi[i] * (p - 1);
                mu[p * i] = mu[i] * -1;
            }
        }
    }
}
