echo off
if exist ..\DEV_ENV rmdir /S /Q ..\DEV_ENV
cd ..
mkdir DEV_ENV
cd DEV_ENV
cmake ../ -G "Visual Studio 17 2022"
