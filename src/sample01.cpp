#include <stdio.h>
#include <string.h>

#include <chrono>
#include <iterator>

using namespace std;

#define COUNT 1000000

bool sample01(const string &s, const string &prefix) {
  auto size = prefix.size();
  if (s.size() < size) return false;
  return equal(begin(prefix), end(prefix), begin(s));
}

int main() {
  chrono::system_clock::time_point start, end;

  start = chrono::system_clock::now();

  string target = "abc";
  string find = "a";

  for (int i = 0; i < COUNT; i++) {
    sample01(target, find);
  }

  end = chrono::system_clock::now();

  double time = static_cast<double>(
      chrono::duration_cast<chrono::microseconds>(end - start).count() /
      1000.0);

  printf("time %lf[ms]\n", time / COUNT);

  return 0;
}
