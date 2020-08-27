#include <stdio.h>
#include <string.h>

#include <chrono>
#include <iterator>

using namespace std;

#define COUNT 1000000

bool sample02(const string &s, const string &prefix) {
  if (s.size() < prefix.size()) return false;
  if (s.rfind(prefix, 0) == 0) return true;
  return false;
}

int main() {
  chrono::system_clock::time_point start, end;

  start = chrono::system_clock::now();

  string target = "abc";
  string find = "a";

  for (int i = 0; i < COUNT; i++) {
    sample02(target, find);
  }

  end = chrono::system_clock::now();

  double time = static_cast<double>(
      chrono::duration_cast<chrono::microseconds>(end - start).count() /
      1000.0);

  printf("time %lf[ms]\n", time / COUNT);

  return 0;
}
