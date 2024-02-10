# Data Structures & Algorithms

![](./resources/general_tree.svg)

This repository contains a set of _data structures_ and _abstract data
type_ implementations. I have written a short disambiguation of these
and other terms, which you can read
[here](https://docs.afneville.com/cs/dsa/introduction.html).

The most recent version of these implementations is written in C++,
which (like C) supports direct, unfettered access to virtual memory with
the additional benefit of many useful abstraction mechanisms. I have
conformed to relevant
[named requirements](https://en.cppreference.com/w/cpp/named_req) and
implemented custom iterators, enabling these implementations to be used
in place of their standard library equivalents. Here is an example of
the `std::sort` algorithm working on the `Vector` container defined in
this repository:

```cpp
Vector<int> v {10,37,84,22,13,45,67,68};
std::sort(v.begin(), v.end());
for (auto i : v)
    std::cout << i << ' '; // 10 13 22 37 45 67 68 84
```

## Branches

There is often more than a single way to create a data structure and I
have struggled to combine all of the imaginable features into a single
implementation. These branches point to a handful of the different
approaches that I have previously explored:

- [Heterogeneous List (C)](https://github.com/afneville/DSA/tree/heterogeneous_list)
- [Associative Array (C)](https://github.com/afneville/DSA/tree/associative_array)
- [Fundamental Implementations (C)](https://github.com/afneville/DSA/tree/fundamental_data_structures)

## Implemented Containers

Most of the sequence containers of the STL can be implemented with an
array list or a linked list. A double-ended queue requires a
doubly-linked list for quick operation at its ends, but both queues and
stacks can be efficiently implemented with a forward singly-linked list
with an additional pointer to the rear.

- [x] Vector
- [x] Array List
- [x] Forward List
- [x] List
- [x] Deque

I also plan to implement some data structures emulating the STL's
associative containers. I have previously created less useful
implementations for both of these (indicated with a branch).

- [ ] Map
- [ ] Set

Finally, I will recreate some of the STL's container adaptors using
already-defined containers.

- [ ] Stack
- [ ] Queue
- [ ] Priority Queue

## Build & Test

As each of the types is written as a class template, the complete
template must be available to the compiler at the point an instance is
required; the templates cannot be compiled ahead of time. Resultantly,
for each type, the whole template, including complete member function
definition, is present in a `.hpp` file in the `templates/` directory. I
have created full, type-parameterised unit tests for all user defined
types. Each test suite resides in its own source file in the `tests/`
directory.

```text
.
|-- CMakeLists.txt
|-- README.md
|-- templates
|   |-- deque.hpp
|   |-- ...
|   `-- vector.hpp
`-- tests
    |-- list_tests.cpp
    |-- ...
    `-- vector_tests.cpp
```

I have used [CMake](https://docs.afneville.com/dev/unix/cmake.html) to
build the project. An executable in the `build/` directory is generated
for each test suite. The test suites can be run independently and
verbosely, or a summary of the tests outcomes can be produce via
`ctest`.

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build
```
