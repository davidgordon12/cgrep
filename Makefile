FLAGS := -Iinclude
TARGET := cgrep.exe

args := public: -o 

source_files := src/*.cpp

compile:
	g++ $(source_files) $(FLAGS) -o $(TARGET)

run: compile
	cgrep.exe $(args)