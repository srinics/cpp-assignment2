#!/bin/bash
op="$1"
binary_name="linux-out"
lib_dir1=Library1
lib_dir2=Library2
if [ "$op" = "clean" ]; then
	rm -rf $lib_dir1/*.o $lib_dir2/*.o
	rm -rf $lib_dir1/*.so $lib_dir2/*.so
	rm -rf $binary_name
	exit 0;
fi

g++ --shared $lib_dir1/File1.cpp -o $lib_dir1/liblibrary1.so --std=c++11 -fPIC -Wl,--no-as-needed -ldl
g++ --shared $lib_dir2/LoadLib.cpp -o $lib_dir2/liblibrary2.so --std=c++11  -ldl -fPIC -Wl,--no-as-needed -ldl
g++ Main.cpp -o $binary_name -L$lib_dir1 -L$lib_dir2 -I$lib_dir1 -I$lib_dir2 $lib_dir2/liblibrary2.so --std=c++11 -Wl,--no-as-needed -ldl
