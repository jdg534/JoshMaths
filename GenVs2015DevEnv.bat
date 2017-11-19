if exist DEV_ENV rmdir /S /Q DEV_ENV

mkdir DEV_ENV

cd DEV_ENV
cmake ../ -DEnableUnitTesting=ON -G "Visual Studio 14 2015"


PAUSE