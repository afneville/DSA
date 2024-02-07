# Associative Array Implementation

A C-implemented associative array, using a hash map as the underlying
concrete data structure. The map can be configured with a number of
options, including the collision resolution method and the reallocation
policy. The `inc/dict.h` header file contains the types and function
declarations for the data structure.

A sample program is provided, which can be built and run with the steps:

```sh
make
./bin/dict_test
```
