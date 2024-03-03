# A Rubiks Cube Solver
This aim of this project is to take a shuffled configurations of a a classic 3x3x3 Rubiks cube and return the sequence of moves to be performed inorder to solve 

### The General Configuration of the cube is represented as follows : 

### The sides:

         U
       L F R B
         D    
### Color wise:
     
               W W W
               W W W
               W W W
     
       G G G   R R R   B B B   O O O
       G G G   R R R   B B B   O O O
       G G G   R R R   B B B   O O O
     
               Y Y Y
               Y Y Y
               Y Y Y

The General Model of the cube is represented as a 3D array where cube[i][j][k] represents the color of the cubie on the i<sup>th</sup> face at j<sup>th</sup> row and k<sup>th</sup> column

The Rotational movements of the Cubes follow the same conventions as the standard one (eg: R,U',L2 etc).

### Three Differents Algorithms have been used to solve the cube namely :
- Depth First Search (DFS)
- Breadth First Search (BFS)
- Iterative Deepening Depth First Search (IDDFS)

