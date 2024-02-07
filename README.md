# Heterogeneous Collections in C

This branch contains a C-implemented heterogeneous list. The concepts
employed to create the illusion of polymorphism in C are documented in
[this article](https://docs.afneville.com/dev/c-oop.html).

The result is a container type that is able to store objects of varying
supported types. This list will pretty print itself by applying a
uniform polymorphic print function to each member, which in turn handle
their own display.

```
[ 4, 'a', 14.200000, "Hello" ]
```

The examples can be built with Make and reside in the `bin/` directory.

```sh
make
```
