#include <iostream>
#include <queue>

struct Horse
{
	int x,y;
	float number_try;

	Horse(int x, int y) : x(x), y(y) {}
};

struct Man
{
	int x,y;

};

struct Board
{
	int n_rows, n_cols;
};

bool is_out_of_bound(Horse horse, Board board)
{
	return ( horse.x >= 1 ) && ( horse.y >= 1 )
		&& ( board.n_cols >= horse.x ) 
		&& ( board.n_rows >= horse.y );
}

bool is_caught(Horse horse, Man man)
{
	return ( horse.x == man.x ) && ( horse.y == man.y );
}

int main(void)
{
	Man man(0,0);
	Horse horse;
	Board board;

	int jump[8][2] = {{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2, 1}, {2, -1}};

	std::cin >> board.n_rows;
	std::cin >> board.n_cols;
	std::cin >> horse.x;
	std::cin >> horse.y;
	std::cin >> man.x;
	std::cin >> man.y;

	std::queue<horse> queue;

	Horse* cur_horse = &horse;

	while( !is_caught(*cur_horse, man) )
	{
		for ( int i = 0; i < 8; i++ )
		{
			Horse tmp_horse(horse.x + jump[i][0], horse.y + jump[i][1]);
			if ( !is_out_of_bound(horse, board) )
				queue.push(tmp_horse)
		}
		
		cur_horse = &queue.front()

		queue.pop()
		
	}


	std::cout << cur_horse->number_try << std::endl;

	return 0;
}
