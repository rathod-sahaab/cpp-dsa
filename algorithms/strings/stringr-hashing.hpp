#ifndef STRING_HASHING_HPP
#define STRING_HASHING_HPP
#include <bits/stdc++.h>
/// @param: p, prime number greater than number of distinct characters in string
long long hash_string(const std::string &str, const int p = 31) {

  const int modulator = 1e9 + 9;
  long long hash_value = 0;
  long long p_pow = 1;
  for (char c : str) {
    hash_value = (hash_value + (c - 'a' + 1) * p_pow) % modulator;
    p_pow = (p_pow * p) % modulator;
  }
  return hash_value;
  return 0;
}

#endif // STRING_HASHING_HPP
