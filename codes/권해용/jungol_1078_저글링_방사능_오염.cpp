#include <iostream>
#include <string>
#include <queue>

struct Point
{
	Point(int icol, int irow):icol(icol), irow(irow) {}
	short irow, icol;
};

int main(void)
{
  
	short zerglings[101][101] = {0};
	
	short move[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

	short n_cols, n_rows;
	
	short irrd_icol;
	short irrd_irow;

	std::queue<Point> zerg_queue;

	std::cin >> n_cols;
	std::cin >> n_rows;

	for ( int irow=1; irow <= n_rows; irow++ )
	{
		std::string row;
		std::cin >> row;

		for ( int icol=1; icol <= n_cols; icol++ ) 
			if ( row[icol-1] == '1' )
				zerglings[icol][irow] = 1;
	}

	std::cin >> irrd_icol;
	std::cin >> irrd_irow;

	zerglings[irrd_icol][irrd_irow] = 3;

  // queueing
	
	zerg_queue.push(Point(irrd_icol, irrd_irow));

	short final_time = 0;

	while(!zerg_queue.empty())
	{
		Point point = zerg_queue.front();
		zerg_queue.pop();

		for ( int i = 0; i < 4; i++ )
		{
			Point neighbor(point.icol + move[i][0],
										point.irow + move[i][1]);

			//std::cout << neighbor.icol << std::endl;
			//std::cout << neighbor.irow << std::endl;

			if (( neighbor.icol >= 1 && neighbor.icol <= 100 ) 
				&& ( neighbor.irow >= 1 && neighbor.irow <= 100 )
				&& zerglings[neighbor.icol][neighbor.irow] == 1 )
			{

				 zerglings[neighbor.icol][neighbor.irow] 
					 = zerglings[point.icol][point.irow] + 1;
			  //std::cout << "push neighbor" << std::endl;
				zerg_queue.push(neighbor);
			}
		}

		final_time = zerglings[point.icol][point.irow];
	}

	/////
	// search number of outlier
 	/////
 	
	short no_irrd = 0;

  for ( int irow=1; irow <= n_rows; irow++ )
	{
		for ( int icol=1; icol <= n_cols; icol++ ) 
		{
			//std::cout << zerglings[icol][irow];
			if ( zerglings[icol][irow] == 1)
				no_irrd += 1;
		}
		//std::cout << std::endl;
	}

	std::cout << final_time << std::endl;
	std::cout << no_irrd << std::endl;

	return 0;
}

