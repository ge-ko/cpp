This is a standard empty cpp project.

Folder structure:
````shell
cd <projects>/cpp/
tree <project>/
empty/
├── .gitignore              # files to ignore from adding to the git repo
├── Makefile                # make file -- run make or make check or make clean
├── bin                     # binary files, like executables
│   ├── <project>.app       # runs the program
│   └── test.app            # runs the tests
├── build                   # build output filrs, like object files
├── include                 # project include files
│   └── catch.hpp           # catch 2 test framework -- everything is in one header file
├── lib                     # external libs to link to
├── main                    # program entry points
│   ├── main.cpp            # main function of the program
│   └── test.cpp            # main unit test file
├── readme.md               # this readme file
├── src                     # project source code
└── test                    # unit tests
````
