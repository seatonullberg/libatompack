# libatompack
A pure C library for atomic structure generation. https://seatonullberg.github.io/libatompack/

## Installation

This library is intended to be used as a shared object file or 'dylib' which other programs can [dynamically link](https://en.wikipedia.org/wiki/Dynamic_linker#:~:text=In%20computing%2C%20a%20dynamic%20linker,jump%20tables%20and%20relocating%20pointers.) to.

### Build from Source (Linux / Mac)

Start by cloning the git repository and using the [Makefile](./Makefile) build system.

```bash
$ git clone --recurse-submodules https://github.com/seatonullberg/libatompack.git # clone the repo and its dependencies
$ cd libatompack
$ make test # run the test suite
$ make      # build the shared library
```

This should produce a `bin` directory which contains the shared object file.