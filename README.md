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

This should produce a `lib` directory which contains the shared object file.

## License

The project as a whole is licensed under the [GNU Lesser General Public License v3.0](./LICENSE).
The following files are modified or copied from an external source:

[__rmsd.c__](./src/rmsd.c) and [__rmsd.h__](./src/rmsd.h)

These files provide an implementation of the [Kabasch algorithm](https://en.wikipedia.org/wiki/Kabsch_algorithm) to find the least-squares rotation matrix for a superposition between two sets of vectors. The original source is licensed under the [GNU Lesser General Public License v2.1](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html) and is located at https://boscoh.com/code/.

[__utest.h__](./src/utest.h)

This file is the unit testing framework used in this project. The original source is licensed under the [Unlicense](https://unlicense.org/) and is located at https://github.com/sheredom/utest.h.