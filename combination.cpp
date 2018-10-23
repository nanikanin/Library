#include <cstdint>

uint64_t combination(unsigned int n, unsigned int r) {
  if (r * 2 > n) r = n - r;
  uint64_t dividend = 1;
  uint64_t divisor = 1;
  for (unsigned int i = 1; i <= r; ++i) {
    dividend *= (n - i + 1);
    divisor *= i;
  }
  return dividend / divisor;
}

uint64_t combination2(uint64_t n, uint64_t k) {
    uint64_t r = 1;
    for (uint64_t d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}