FLAGS :=
TARGET := bin/cgrep.exe

run:
	mkdir -p target
	g++ src/*.cpp -o $(TARGET)