# startWith_benchmark_test_cpp

ref: [stackoverflow - How do I check if a C++ std::string starts with a certain string, and convert a substring to an int?](https://stackoverflow.com/questions/1878001/)

---

## How to calculate

use [std::chrono](http://www.sanko-shoko.net/note.php?id=rnfd) and 1,000,000 times average.

`$ gpp -g -Wall -std=c++20 samplexx.cpp -o main && ./main`: each samples

## Ways

```cpp
string target = "abc";
string prefix = "a";
```

sample01

```cpp
equal(begin(prefix), end(prefix), begin(target));
```

sample02

```cpp
target.rfind(prefix, 0) == 0
```

sample03

```cpp
strncmp(target.c_str(), prefix.c_str(), prefix.size());
```

sample04

```cpp
target.substr(0, prefix.size()) == prefix
```

sample05(this method is usable from c++20)

```cpp
s.starts_with(prefix)
```

## Result

<details>
<summary>sample01</summary>
```
time 0.000066[ms]
time 0.000067[ms]
time 0.000067[ms]
time 0.000066[ms]
time 0.000067[ms]
```
</details>

<details>
<summary>sample02</summary>
```
time 0.000028[ms]
time 0.000028[ms]
time 0.000028[ms]
time 0.000028[ms]
time 0.000028[ms]
```
</details>

<details>
<summary>sample03</summary>
```
time 0.000013[ms]
time 0.000013[ms]
time 0.000013[ms]
time 0.000013[ms]
time 0.000012[ms]
```
</details>

<details>
<summary>sample04</summary>
```
time 0.000154[ms]
time 0.000157[ms]
time 0.000157[ms]
time 0.000154[ms]
time 0.000154[ms]
```
</details>

<details>
<summary>sample05</summary>
```
time 0.000064[ms]
time 0.000066[ms]
time 0.000063[ms]
time 0.000064[ms]
time 0.000066[ms]
```
</details>

| samplexx | time (5 times ave) [ms] |
| -------: | ----------------------: |
| sample01 |               0.0000666 |
| sample02 |               0.0000280 |
| sample03 |               0.0000128 |
| sample04 |               0.0001552 |
| sample05 |               0.0000646 |
