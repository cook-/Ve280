//---------------------------------------------------------
struct world_t
{
	unsigned int numSpecies;
	species_t species[MAXSPECIES];

	unsigned int numCreatures;
	creature_t creature[MAXCREATURES];

	grid_t grid;
};
//---------------------------------------------------------
struct grid_t
{
	unsigned int height;
	unsigned int width;
	creature_t *squares[MAXHEIGHT][MAXWIDTH];
};
//---------------------------------------------------------
struct species_t
{
	string name;
	unsigned int programSize;
	instruction_t program[MAXPROGRAM];
};

		struct instruction_t
		{
			opcode_t op;
			unsigned int address;
		};

				enum opcode_t { HOP, LEFT, RIGHT, INFECT, IFEMPTY, IFENEMY,
								IFSAME, IFWALL, GO };
				const string opName[] = { "hop", "left", "right", "infect",
										  "ifempty", "ifenemy", "ifsame", 
										  "ifwall", "go" };
//---------------------------------------------------------
struct creature_t
{
	point_t location;
	direction_t direction;
	species_t *species;
	unsigned int programID;
};

		struct point_t
		{
			int r;
			int c;
		};

		enum direction_t { EAST, SOUTH, WEST, NORTH };
		const string directName[] = { "east", "south", "west", "north" };
		const string directShortName[] = { "e", "s", "w", "n" };


