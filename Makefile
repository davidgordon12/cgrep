FLAGS := -Iinclude
TARGET := cgrep.exe

source_files := src/*.cpp

compile:
	g++ $(source_files) $(FLAGS) -o $(TARGET)