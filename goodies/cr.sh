file="$1"
filename=${file%.*}
cpp_ext=${file##*.}
obj_ext="o"

#g++ -save-temps -std=c++14 -o $filename.$obj_ext $filename.$cpp_ext && ./$filename.$obj_ext
g++ -std=c++14 -o $filename.$obj_ext -Wl,-Map=$filename.map $filename.$cpp_ext && ./$filename.$obj_ext
