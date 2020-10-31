all:
	g++ main.cpp \
	 -I "C:\Strawberry\c\i686-w64-mingw32\include" \
	 -L"C:\Strawberry\c\i686-w64-mingw32\lib"  \
	 -L"C:\Strawberry\c\lib"   \
	 -lOpenGL32  -lglu32   -lGLAux  -lglut    -o  main 
	./main
	
	
#	 -lglut32 