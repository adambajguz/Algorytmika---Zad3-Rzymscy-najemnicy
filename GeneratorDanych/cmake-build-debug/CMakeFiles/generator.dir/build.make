# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Admin\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\172.4343.16\bin\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Admin\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\172.4343.16\bin\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "X:\Moje dokumenty\Dokumenty Adama\Dokumenty PB\Semestr III - prace\Algorytmy i struktury danych\Ps\Ps3\!generator"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "X:\Moje dokumenty\Dokumenty Adama\Dokumenty PB\Semestr III - prace\Algorytmy i struktury danych\Ps\Ps3\!generator\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/generator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/generator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/generator.dir/flags.make

CMakeFiles/generator.dir/main.c.obj: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="X:\Moje dokumenty\Dokumenty Adama\Dokumenty PB\Semestr III - prace\Algorytmy i struktury danych\Ps\Ps3\!generator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/generator.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\generator.dir\main.c.obj   -c "X:\Moje dokumenty\Dokumenty Adama\Dokumenty PB\Semestr III - prace\Algorytmy i struktury danych\Ps\Ps3\!generator\main.c"

CMakeFiles/generator.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/generator.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "X:\Moje dokumenty\Dokumenty Adama\Dokumenty PB\Semestr III - prace\Algorytmy i struktury danych\Ps\Ps3\!generator\main.c" > CMakeFiles\generator.dir\main.c.i

CMakeFiles/generator.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/generator.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "X:\Moje dokumenty\Dokumenty Adama\Dokumenty PB\Semestr III - prace\Algorytmy i struktury danych\Ps\Ps3\!generator\main.c" -o CMakeFiles\generator.dir\main.c.s

CMakeFiles/generator.dir/main.c.obj.requires:

.PHONY : CMakeFiles/generator.dir/main.c.obj.requires

CMakeFiles/generator.dir/main.c.obj.provides: CMakeFiles/generator.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\generator.dir\build.make CMakeFiles/generator.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/generator.dir/main.c.obj.provides

CMakeFiles/generator.dir/main.c.obj.provides.build: CMakeFiles/generator.dir/main.c.obj


# Object files for target generator
generator_OBJECTS = \
"CMakeFiles/generator.dir/main.c.obj"

# External object files for target generator
generator_EXTERNAL_OBJECTS =

generator.exe: CMakeFiles/generator.dir/main.c.obj
generator.exe: CMakeFiles/generator.dir/build.make
generator.exe: CMakeFiles/generator.dir/linklibs.rsp
generator.exe: CMakeFiles/generator.dir/objects1.rsp
generator.exe: CMakeFiles/generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="X:\Moje dokumenty\Dokumenty Adama\Dokumenty PB\Semestr III - prace\Algorytmy i struktury danych\Ps\Ps3\!generator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable generator.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\generator.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/generator.dir/build: generator.exe

.PHONY : CMakeFiles/generator.dir/build

CMakeFiles/generator.dir/requires: CMakeFiles/generator.dir/main.c.obj.requires

.PHONY : CMakeFiles/generator.dir/requires

CMakeFiles/generator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\generator.dir\cmake_clean.cmake
.PHONY : CMakeFiles/generator.dir/clean

CMakeFiles/generator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "X:\Moje dokumenty\Dokumenty Adama\Dokumenty PB\Semestr III - prace\Algorytmy i struktury danych\Ps\Ps3\!generator" "X:\Moje dokumenty\Dokumenty Adama\Dokumenty PB\Semestr III - prace\Algorytmy i struktury danych\Ps\Ps3\!generator" "X:\Moje dokumenty\Dokumenty Adama\Dokumenty PB\Semestr III - prace\Algorytmy i struktury danych\Ps\Ps3\!generator\cmake-build-debug" "X:\Moje dokumenty\Dokumenty Adama\Dokumenty PB\Semestr III - prace\Algorytmy i struktury danych\Ps\Ps3\!generator\cmake-build-debug" "X:\Moje dokumenty\Dokumenty Adama\Dokumenty PB\Semestr III - prace\Algorytmy i struktury danych\Ps\Ps3\!generator\cmake-build-debug\CMakeFiles\generator.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/generator.dir/depend
