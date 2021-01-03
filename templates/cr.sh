file="$1"
filename=${file%.*}
cpp_ext=${file##*.}
obj_ext="o"

#g++ -save-temps -std=c++11 -o $filename.$obj_ext $filename.$cpp_ext && ./$filename.$obj_ext
#-save-temps
g++ -std=c++11 -fno-elide-constructors -o $filename.$obj_ext $filename.$cpp_ext && ./$filename.$obj_ext
