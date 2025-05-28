BINUTILS_VERSION=2.44
GCC_VERSION=15.1.0

PWD=$(pwd)

# echo $PWD

export PREFIX="$PWD/cc" # installataion dir
export TARGET=aarch64-none-elf
export PATH="$PREFIX/bin:$PATH"

# binutils
# only clone if not already present
# if [ ! -f binutils-$BINUTILS_VERSION.tar.xz ]; then
#     wget https://ftp.gnu.org/gnu/binutils/binutils-$BINUTILS_VERSION.tar.xz
# fi
# # only untar if not already
# if [ ! -d binutils-$BINUTILS_VERSION ]; then
#     tar -xvf binutils-$BINUTILS_VERSION.tar.xz
# fi
# mkdir -p build-binutils && cd build-binutils
# ../binutils-$BINUTILS_VERSION/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
# make && make install

# cd ..

# gcc

# only clone if not already present
if [ ! -f gcc-$GCC_VERSION.tar.xz ]; then
    wget https://mirrorservice.org/sites/sourceware.org/pub/gcc/releases/gcc-$GCC_VERSION/gcc-$GCC_VERSION.tar.xz
fi
# only untar if not already
if [ ! -d gcc-$GCC_VERSION ]; then
    tar -xvf gcc-$GCC_VERSION.tar.xz
fi

# download GMP, MPFR, MPC
cd gcc-$GCC_VERSION
./contrib/download_prerequisites
cd ..

mkdir -p build-gcc && cd build-gcc
# ../gcc-$GCC_VERSION/contrib/download_prerequisites # download requirements or something
../gcc-$GCC_VERSION/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers --disable-hosted-libstdcxx
make all-gcc
make all-target-libgcc
make all-target-libstdc++-v3
make install-gcc
make install-target-libgcc
make install-target-libstdc++-v3

cd ..


# add to path?