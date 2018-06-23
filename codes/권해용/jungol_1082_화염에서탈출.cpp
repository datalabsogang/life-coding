#include <iostream>
#include <queue>
#include <vector>
#include <string>

struct Object
{
	int x,y;
	int id; // also time it takes
	Object(int x=0, int y=0, int id=0):x(x),y(y),id(id){}
};

void initialize_objects(int (&forest)[50][50],
												Object& man,
												std::vector<Object>& fires,
												Object& home);

void initialize_queue(std::queue<Object>& obj_queue,
											Object& man,
											std::vector<Object>& fires);

void process_fire(int (&forest)[50][50],
									std::queue<Object>& obj_queue,			
									Object& fire,
									int (&move)[4][2]);

void process_man(int (&forest)[50][50],
									std::queue<Object>& obj_queue,			
									Object& man,
									int (&move)[4][2]);

void check_success(int& is_success,
										int (&forest)[50][50],
										Object& home);

// tools
bool is_valid(Object& obj, int (&forest)[50][50]);

int main(void)
{
	int forest[50][50] = {-99};
	std::queue<Object> obj_queue;
	Object man, home;
	std::vector<Object> fires;
	int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	initialize_objects(forest, man, fires, home);
	initialize_queue(obj_queue, man, fires);

	while(!obj_queue.empty())
	{
		Object obj = obj_queue.front();
		obj_queue.pop();
		//std::cout << "id: " << obj.id << std::endl;
		//std::cout << obj.y << " " << obj.x << std::endl;
		if (obj.id == -2)
			process_fire(forest, obj_queue, obj, move);
		else
			process_man(forest, obj_queue, obj, move);
	}

	//
	int is_success = forest[home.y][home.x];

	if(is_success == -3)
		std::cout << "impossible" << std::endl;
	else
		std::cout << is_success << std::endl;

	return 0;

}

void initialize_objects(int (&forest)[50][50],
												Object& man,
												std::vector<Object>& fires,
												Object& home)
{
	int R,C;
	std::cin >> R >> C;
	std::string buffer;

	for (int irow=0; irow < R; irow++)
	{
		std::cin >> buffer;
		for (int icol=0; icol < C; icol++)
		{
			if(buffer[icol] == 'S') // man
			{
				forest[irow][icol] = 0;
				man = Object(icol,irow,0);
			}
			else if(buffer[icol] == '*') // fire
			{
				forest[irow][icol] = -2;
				fires.push_back(Object(icol,irow,-2));
			}
			else if(buffer[icol] == 'X') // stone
			{
				forest[irow][icol] = -2;
			}
			else if(buffer[icol] == 'D') // home
			{
				forest[irow][icol] = -3;
				home = Object(icol,irow,0);
			}
			else if(buffer[icol] == '.') // grass
			{
				forest[irow][icol] = -1;
			}
			else
			{
				std::cout << "Error in setting forest" << std::endl;
			}
		}	
	}
}

void initialize_queue(std::queue<Object>& obj_queue,
											Object& man,
											std::vector<Object>& fires)
{
	// care order! (fire , man) (O) (man, fire) (X)
	for (int i=0; i < fires.size(); i++)
		obj_queue.push(fires[i]);

	obj_queue.push(man);
}


void process_fire(int (&forest)[50][50],
									std::queue<Object>& obj_queue,			
									Object& fire,
									int (&move)[4][2])
{
	for (int i = 0; i < 4; i++)
	{
		Object cfire(fire.x + move[i][0], fire.y + move[i][1], -2);
		if (cfire.x >= 0 && cfire.y >= 0 && forest[cfire.y][cfire.x] == -1)
		{
			forest[cfire.y][cfire.x] = cfire.id;
			obj_queue.push(cfire);
		}
	}
}

void process_man(int (&forest)[50][50],
									std::queue<Object>& obj_queue,			
									Object& man,
									int (&move)[4][2])
{
	for (int i = 0; i < 4; i++)
	{
		Object cman(man.x + move[i][0], man.y + move[i][1], man.id+1);
		if (cman.x >= 0 && cman.y >= 0 
			&& (forest[cman.y][cman.x] == -1 ||
				forest[cman.y][cman.x] == -3))
		{
			forest[cman.y][cman.x] = cman.id;
			obj_queue.push(cman);
		}
	}
}


