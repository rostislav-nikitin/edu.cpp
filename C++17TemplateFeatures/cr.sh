file="$1"
filename=${file%.*}
cpp_ext=${file##*.}
obj_ext="o"

#g++ -save-temps -std=c++11 -o $filename.$obj_ext $filename.$cpp_ext && ./$filename.$obj_ext
g++ -std=c++17 -save-temps -O0 -o $filename.$obj_ext -Wl,-Map=$filename.map $filename.$cpp_ext && ./$filename.$obj_ext
