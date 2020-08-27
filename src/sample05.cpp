#include <stdio.h>
#include <string.h>

#include <chrono>
#include <iterator>

using namespace std;

#define COUNT 1000000

bool sample05(const string &s, const string &prefix) {
  return s.starts_with(prefix);
}

int main() {
  chrono::system_clock::time_point start, end;

  start = chrono::system_clock::now();

  string target = "abc";
  string find = "a";

  for (int i = 0; i < COUNT; i++) {
    sample05(target, find);
  }

  end = chrono::system_clock::now();

  double time = static_cast<double>(
      chrono::duration_cast<chrono::microseconds>(end - start).count());

  printf("time %lf[ms]\n", time / COUNT);

  return 0;
}
