# snake
Snake in c++ utilizing ncurses

Most logic is in the Snake class. The Snake class has a vector of SnakePart objects (found in the SnakePart class).

# goal
Fix to show 5 snake parts (only shows 3, even though the vector is 5 long)

# requirements
ncurses
cmake (min version 3.1)

# compile instructions
1) Clone src folder into a root folder
2) Make a directory called build in the root folder and cd into the directory
3) Run 'cmake ..' and then 'make'
4) Binary is compiled at "./build/src/snake"
