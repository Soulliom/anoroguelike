#include "../include/Map.h"

void Map::displayMap(Player t_Player, Character::Position t_Exit, std::vector<Enemy*> t_v_Enemy, std::vector<Character::Position> t_v_Block) {
	bool b_blank = true;

	for (int y = 0; y <= border.height; y++) {
		std::cout << "   "; //Create Border
		if (y == border.height || y == 0) {
			std::cout << "+---------------------------------------------------------------------------------------------------------------+\n";
		}
		else {
			for (int x = 0; x <= border.width; x++) {
				if ( t_Player.pos.x + static_cast<int>(t_Player.stats.perception * 1.5) >= x) {
					//Reset Blank
					b_blank = true;

					//Print Objects
					//Player
					if (b_blank) {
						if (t_Player.pos.x == x && t_Player.pos.y == y) {
							std::cout << "&";
							b_blank = false;
						}
					}

					//Exit 
					if (b_blank) {
						if (t_Exit.x == x && t_Exit.y == y) {
							std::cout << "H";
							b_blank = false;
						}
					}

					//Blocks
					if (b_blank) {
						for (unsigned int b = 0; b < t_v_Block.size(); b++) {
							if (x == t_v_Block.at(b).x && y == t_v_Block.at(b).y) {
								std::cout << "#";
								b_blank = false;
								break;
							}
						}
					}
					//Enemy
					if (b_blank) {
						for (unsigned int e = 0; e < t_v_Enemy.size(); e++) {
							if (x == t_v_Enemy.at(e)->pos.x && y == t_v_Enemy.at(e)->pos.y) {
								std::cout << e + 1;
								b_blank = false;
								break;
							}
						}
					}

					if (b_blank) {
						for (unsigned int e = 0; e < t_v_Enemy.size(); e++) {
							if (x == t_v_Enemy.at(e)->pos.x && y == t_v_Enemy.at(e)->pos.y) {
								std::cout << e + 1;
								b_blank = false;
								break;
							}
						}
					}

					//Check for blanks
					if (b_blank) {
						std::cout << ".";
					}
					std::cout << " ";
					
				}
				else {
					std::cout << "  ";
				}
			}
			std::cout << std::endl;
		}
	}
}
