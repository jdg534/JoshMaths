if exist DEV_ENV rmdir /S /Q DEV_ENV

mkdir DEV_ENV

cd DEV_ENV
cmake ../ -G "Visual Studio 17 2022"


PAUSE