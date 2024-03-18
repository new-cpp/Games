
file=*.cpp
headers=*.hpp
echo $file
echo $headers
g++ -std=c++17 -o test.exe $file $headers  -I "C:\mingw32\include" -L "C:\mingw32\lib" -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
