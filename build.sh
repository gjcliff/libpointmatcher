trash-put build
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=~/.local/include/libpointmatcher ..
make -j20
make install
cd ..
