# Hex-Game

## Introduction

Hex is a strategy board game for two players, Red and Blue, played on a hexagonal grid. The goal for each player is to form a connected path of their own markers linking the opposing sides of the board marked by their colours. The first player to complete his or her connection wins the game.

The game board is represented as a two-dimensional array of integers, where '1' represents Red player's moves, '-1' for Blue player's moves and '0' represents blank cells.

## Objectives

The objective of this project is to write a computer program that allows human players or computer players to play a hex game on any size of m*m rhombus board where m>2. The program should be in pure text mode and no graphic output is allowed. The program should also be able to determine if either player wins the game.

## Getting Started

This project provides a C++ code base that can be used to build the program. You may extend the base code but the game board must be in pure text mode as shown in the example below.

[Imgur](https://imgur.com/UevgJNe.jpg)
[In this example, Red player made two moves (6, 3) and (2,6) while Blue player made moves (4,5) and (3,2).]

<img src="https://i.imgur.com/3d3CEwZ.png" height="85%" width="85%" alt="RDP event fail logs to iP Geographic information"/>


 1 2 3 4 5 6 7 8 
 ----------------------
1 | | | | | | R | | |
2 | | B | | | | | | |
3 | | | | | B | | | |
4 | | | | | | | | | |
5 | | | | | | | | | |
6 | | | R | | | | | |
7 | | | | | | | | | |
8 | | | | | | | | | |
 ----------------------

## Winning the game

The following two figures show two examples of winning status. 

![In this example, Red player wins.](https://photos.google.com/share/AF1QipNC0KaT-pZ1B-4PkatjBAGGb6ge8BfxYsUJlTeCLIqulfrT40RpV7Ehh3r1S-q_yw/photo/AF1QipOxF684JiQj6fTiX4be6nqltX-wmv7A03oHtVNn?key=MXp0Z1RRaTNhU1BDQWNGalFRSGFPbmZyb3gyNUh3)

 1 2 3 4 5 6 7 8 
 --------------------------------
1 | | R | | B | R | | | B |
 2 | | R | | | R | R | B | B |
 3 | B | R | R | B | B | | B | B |
 4 | R | B | R | | B | | B | R |
 5 | R | B | R | R | R | R | | |
 6 | R | R | B | | R | | B | |
 7 | B | B | R | | R |...


![In this example, Blue player wins.](https://photos.google.com/share/AF1QipNC0KaT-pZ1B-4PkatjBAGGb6ge8BfxYsUJlTeCLIqulfrT40RpV7Ehh3r1S-q_yw/photo/AF1QipO4muM_iEe1xZTTXtnnhRsExDvBdp3evkg7E1vG?key=MXp0Z1RRaTNhU1BDQWNGalFRSGFPbmZyb3gyNUh3)

 1 2 3 4 5 6 7 8 
 --------------------------------
1 | | | B | | B | | | B |
 2 | | | B | | | B | B | B |
 3 | B | B | B | B | B | | B | B |
 4 | B | B | B | | B | | B | B |
 5 | B | B | B | B | B | B | | |
 6 | B | B | B | | B | | B | |
 7 | B | B | B | | B |...



## Conclusion

Hex is a simple but deep game with sharp tactics and a profound mathematical underpinning. This project provides an opportunity to build a program that allows human players or computer players to play the game on any size of m*m rhombus board where m>2. The program should be able to determine if either player wins the game. The provided C++ code base can be used as a starting point, but feel free to extend it as needed to meet the objectives of the project.

## Requirements
To run the program, you will need a C++ compiler and any necessary dependencies for the provided code. Please refer to the provided code for specific requirements.

## Usage
To run the program, compile the code using your C++ compiler and run the executable file. The program will prompt you for the size of the board and the players' names. From there, players will take turns making moves on the board until one player wins.



