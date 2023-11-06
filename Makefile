FLAGS := -Iinclude
TARGET := cgrep.exe

args := public:

source_files := src/*.cpp

compile:
	g++ $(source_files) $(FLAGS) -o $(TARGET)

run: compile
	cgrep.exe $(args)