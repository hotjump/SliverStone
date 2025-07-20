# dep

sudo apt-get install libgtest-dev

# make

mkdir build
cd build
cmake ..
make
ctest

# run

testcase --gtest_filter=InsectionNode.Test1