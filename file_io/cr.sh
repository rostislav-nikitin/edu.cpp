file="$1"
filename=${file%.*}
cpp_ext=${file##*.}
obj_ext="o"

g++ -std=c++17 -o $filename.$obj_ext -Wl,-Map=$filename.map $filename.$cpp_ext -lstdc++fs && ./$filename.$obj_ext $2 $3
