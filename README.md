# Super Cubeman Odyssey

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)


**Author**: Charles Xu - [`xucharles97@gmail.com`](mailto:xucharles97@gmail.com) [`cyx2@illinois.edu`](mailto:cyx2@illinois.edu)

This repo was originally hosted on Github Classroom during the Spring 2020 semester of CS 126. It was copied to this Github page on August 14, 2022 for preservation purposes. 

## Introduction

This is a platfomer game created using the Box2D and Cinder libraries for my CS 126 final project. 

## Gameplay

The controls for this game are fairly straightforward - press the up arrow key to jump, and press left and right arrow keys to go in the corresponding directions.

There are two main advanced movement options programmed into this game - you can jump once off the ground and then again in midair. Landing on the ground allows you to regain both your jumps.

The other mechanic is a "Wall-Cling Reset". When you jump onto the side of a wall and cling to it, then let go and jump again, you'll regain both of your jumps without having to touch the ground.

## Levels

The levels were meant to have the player start on one side of the screen and reach a door on the other side. Arriving at the door will prompt the next level to load. Due to errors with the LevelMaker functionality, this was never fully implemented. Refer to the Presentation branch for a working demo of a single level
