# Word Ladder Game

## Overview

The Word Ladder game, inspired by a puzzle invented by Lewis Carroll in the 19th century, involves transforming a starting word into a target word by changing one letter at a time, with each intermediate step being a valid word. This project uses various C++ Standard Library containers and templates to implement this game, along with a graph data structure to represent possible transformations.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Implementation Details](#implementation-details)
  - [Graph Data Structure](#graph-data-structure)
  - [Building the Graph](#building-the-graph)
  - [Finding the Shortest Path](#finding-the-shortest-path)
- [Dependencies](#dependencies)

## Features

- **Automatic Mode**: Select a starting word and a target word to see the required transformations.
- **Playing Mode**: 
  - User prompts for name and word length.
  - Random selection of starting and target words.
  - User plays the game, ensuring each transformation is valid.
  - Hints are available to suggest the next best move.
  - Game statistics are saved to a CSV file.
- **Analytics Module**:
  - Load user data from CSV.
  - Display various statistics, such as the number of unique words used.

## Installation

To install and run the Word Ladder game, follow these steps:

1. **Clone the repository**:
    ```sh
    git clone https://github.com/MihaiBogdanDeaconu/WordLadderGame
    cd word-ladder-game
    ```

2. **Build the project**:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Run the application**:
    ```sh
    ./WordLadder
    ```

## Usage

After running the application, you will be presented with a menu with the following options:

1. **Automatic Mode**: Enter the starting word and the target word.
2. **Playing Mode**: Enter your name and select the word length. The game will randomly select the starting and target words, and you can begin playing.
3. **Analytics Module**: Enter a player's name to view their game statistics.

### Example 1(Automatic Mode)

```sh
1. Automatic Mode
2. Playing Mode
3. Player Analytics
0. Exit
Option: 1
Starting word: fish
End word: mine
fish wish wise mise mine
```


### Example 2(Playing Mode)
```sh
1. Automatic Mode
2. Playing Mode
3. Player Analytics
0. Exit
Option: 2
Please input your name and then press ENTER!
Player Name: Mihai
Number of letters of the words: 5
Randomly generated, the starting word and the ending words with 5 letters is vagas and feces.
vagas
IF YOU NEED ANY HINT, TYPE "h" in the console. If you want to exit, input 0. Now you can start changing this word: 
vagas vagus magus manus manes mares pares paces faces feces 
vagus
Changed letter: vagus
h
Hint: vagus
h
Hint: vagus
magus
Changed letter: magus
manus
Changed letter: manus
manes
Changed letter: manes
mares
Changed letter: mares
pares
Changed letter: pares
paces
Changed letter: paces
faces
Changed letter: faces
h
Hint: faces
paces
Changed letter: paces
faces
Changed letter: faces
h
Hint: faces
feces
You found the way to the end word!!!
Start word: vagas
End word: feces
Date and time of the game: Sat Jun  1 18:36:07 2024
You used 4 hints.
You used the words: vagus magus manus manes mares pares paces faces paces faces feces 
To reach the end word, you used 11 moves, but the most optimal way is 9 moves
```


### Example 3(Analytics Module)

```sh
1. Automatic Mode
2. Playing Mode
3. Player Analytics
0. Exit
Option: 3
If you want to come back, input 0!
Enter Player Name: Mihai
Player Mihai has played 10 games,
has done 56 moves,
has used 11 hints,
and has used 49 unique words so far, and those are: 
ah aorta at boil bola boll cad cafe caff cap care caro cop faces feces foil foul gaff geant gh glave grade grado grano grant grave ie jap magus malva manes manus mares means meant mill nill paces pares salva salve sip slave soave solve sop vagus ze zola
```

## Implementation Details

### Graph Data Structure

The core of the Word Ladder game is the graph data structure, which represents words as nodes and edges between words that differ by one letter. This is implemented using adjacency lists, with the Graph class being templated to allow any data type in the nodes.

### Building the Graph
To build the graph efficiently, we use the concept of wildcards and a map (similar to a dictionary in Python). Each word pattern (e.g., *AME, S*ME) maps to a list of words matching that pattern. This allows us to quickly find and add edges between words that differ by one letter.

### Finding the Shortest Path
We use the Breadth-First Search (BFS) algorithm to find the shortest path from the starting word to the target word. BFS is ideal for this problem because it explores all nodes at the present depth level before moving on to nodes at the next depth level, ensuring the shortest path is found.


## Dependencies

- C++11 or later
- CMake: For building the project.
- Standard Template Library (STL): For various containers and algorithms.
