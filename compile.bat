DEL rose.compile.exe
rose.parser -I options.h -O rose.compile.serializer.h
CL -I../roselib/include -I"..\premake-comppp\include" -I.. rose.compile.cpp /EHsc /nologo /std:c++17