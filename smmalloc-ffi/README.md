# smmalloc-ffi -- a simple memory allocator for C/C++/native code

Build the `smmalloc-ffi` crate, which produces shared and static libs. Arrange linking so that uses
of `malloc`, `free`, and `realloc` will link to those functions.

Dynamic linking on Linux:

```
LD_PRELOAD=./libsmmalloc_ffi.so ./prog
```

Dynamic linking on macOS:

```
DYLD_INSERT_LIBRARIES=./libsmmalloc_ffi.dylib ./prog
```
