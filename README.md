# cgrep - Simple grep tool for Windows
Reimplementation of the Linux grep program for Windows. Currently under development.
## Usage
```cgrep [regex] <input> <output>```
## Building
### Prerequisites
- g++
- make (Optional)
### Compiling
Clone the repo. With make installed, run ```make``` in the root 
of the project. <br />
Without make, you can run ```g++ src\main.cpp src\help.cpp src\grep.cc -Iinclude -o cgrep.exe```
### Running
Run cgrep with ```cgrep [regex] <input> <output>``` where input and output are text based files. Optionally, cgrep can be run without any output argument provided. This will automatically log to the console
## Testing
### Preqrequisites
- cmake
- wsl (Or Linux)
### Compiling
Run ```cmake -S . -B build``` to build the code and discover tests included in the binary. <br />
Follow with ```cmake --build build``` then ```cd build && ctest```

* Currently there are no tests implemented