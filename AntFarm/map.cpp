#include <iostream>
#include <vector>

std::string Map_back[16] = {
	"fddddddddggggggggggggggggggggg",
	"dddddddddggggggggggggggggggggg",
	"dddddddddggggggggggggggggggbgg",
	"dddddddddggggggggggggggggggggg",
	"dddddddddggggggggggggggggggggg",
	"dddddddddggggggggggggggggggbgg",
	"dddddddddggggggggggggggggggggg",
	"dddddddddgggggggggggggggggbggg",
	"gggggggggggggggggggggggggggggg",
	"gggggggggggggggggggggcgggggggg",
	"gggggggggggggggggggggcgggggggg",
	"gggggggggggggggggggggcgggggggb",
	"gggggggggggggggggggggcgggggggg",
	"gggggggggggggggggggggcgggggggb",
	"gggggggggggggggggggggcgggggggg",
	"ggggggggggggggrgggrggggggggggg"
};

std::string Map_ants[16] = {
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000"
};

int food = 0;
int branches = 0;
std::vector<int> ant_x;
std::vector<int> ant_y;
