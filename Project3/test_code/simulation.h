#ifndef SIMULATION_H
#define SIMULATION_H

#include <world_type.h>

using namespace std;

bool 
initWorld(world_t &world, const string &speciesFile,
	const string &worldFile);
// MODIFIES: world
// EFFECTS: Initialize "world" given the species summary file
// 			"speciesFile" and the world description file
// 			"worldFile". This initializes all the components of
// 			"world". Return true if initialization is successful.

void 
simulateCreature(world_t &world, unsigned int creatureID, bool verbose);
// MODIFIES: world, cout
// EFFECTS: Simulate one turn of creature indexed by i and update 
// 			the creature,the infected creature, and the grid if 
// 			necessary. The creature programID is always updated. 
// 			The function also prints to the stdout the procedure. 
// 			If verbose is true, it prints more information.

void 
printGrid(const grid_t &grid);
// MODIFIES: cout.
// EFFECTS: Print a grid representation of the creature world.

opcode_t
fineOpcode(const string &operName);
// EFFECTS: Returns a opcode that has the same name as string
// 			"operName".

direction_t
findDir(const string &dir);
// EFFECTS: Returns a direction that has the same name as string 
// 			"dir".

species_t *
findSpecies(world_t &world, const string &name);
// EFFECTS: Returns a pointer that points to species named "name".

point_t 
adjacentPoint(point_t pt, direction_t dir);
// EFFECTS: Returns a point that results from moving one square 
// 			in the direction "dir" from the point "pt".

direction_t 
leftFrom(direction_t dir);
// EFFECTS: Returns the direction that results from turning 
// 			left from the given direction "dir".

direction_t 
rightFrom(direction_t dir);
// EFFECTS: Returns the direction that results from turning 
// 			right from the given direction "dir".

instruction_t 
getInstruction(const creature_t &creature);
// EFFECTS: Returns the current instruction of "creature".

creature_t 
*getCreature(const grid_t &grid, point_t location);
// REQUIRES: location is inside the grid.
// EFFECTS: Returns a pointer to the creature at "location" in "grid".

void
hop(world_t world, unsigned int creatureID);
// MODIFIES: world
// EFFECTS: Updates "world" after one creature with "creatureID" 
// 			takes the action "HOP".

void
left(world_t world, unsigned int creatureID);
// MODIFIES: world
// EFFECTS: Updates "world" after one creature with "creatureID" 
// 			takes the action "LEFT".


void
right(world_t world, unsigned int creatureID);
// MODIFIES: world
// EFFECTS: Updates "world" after one creature with "creatureID" 
// 			takes the action "RIGHT".


void
infect(world_t world, unsigned int creatureID);
// MODIFIES: world
// EFFECTS: Updates "world" after one creature with "creatureID" 
// 			takes the action "INFECT".


void
ifempty(world_t world, unsigned int creatureID, unsigned int address);
// MODIFIES: world
// EFFECTS: Updates "world" after one creature with "creatureID" 
// 			takes the action "IFEMPTY" and jumps to another action 
// 			expressed by "address".

void
ifwall(world_t world, unsigned int creatureID, unsigned int address);
// MODIFIES: world
// EFFECTS: Updates "world" after one creature with "creatureID" 
// 			takes the action "IFWALL" and jumps to another action 
// 			expressed by "address".


void
ifsame(world_t world, unsigned int creatureID, unsigned int address);
// MODIFIES: world
// EFFECTS: Updates "world" after one creature with "creatureID" 
// 			takes the action "IFSAME" and jumps to another action 
// 			expressed by "address".


void
ifenemy(world_t world, unsigned int creatureID, unsigned int address);
// MODIFIES: world
// EFFECTS: Updates "world" after one creature with "creatureID" 
// 			takes the action "IFENEMY" and jumps to another action 
// 			expressed by "address".


void
go(world_t world, unsigned int creatureID, unsigned int address);
// MODIFIES: world
// EFFECTS: Updates "world" after one creature with "creatureID" 
// 			takes the action "GO" and jumps to another action 
// 			expressed by "address".


#endif
