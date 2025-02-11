if exist CTEST_UNIT_TEST_ENV rmdir /S /Q CTEST_UNIT_TEST_ENV

mkdir CTEST_UNIT_TEST_ENV

cd CTEST_UNIT_TEST_ENV
cmake ../ -G "Visual Studio 17 2022" -DBuildToRunWithCTest=ON
cmake --build ./ --target RunUnitTests --config Release
ctest ./ --rerun-failed --output-on-failure

PAUSE