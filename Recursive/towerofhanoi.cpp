/*
	by Rahul Singh, 01 October 2022

	Tower of Hanoi

	The objective of the puzzle is to move the entire stack to the last rod, obeying the following rules:
	-> Only one disk may be moved at a time.
	-> Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
	-> No disk may be placed on top of a disk that is smaller than it.

	The minimal number of moves required to solve a Tower of Hanoi puzzle is 2^n − 1, where n is the number of disks.

  Algorithm

  START
    Procedure Hanoi(disk, source, dest, aux)
      IF disk == 1, THEN
        move disk from source to dest
      ELSE
        Hanoi(disk - 1, source, aux, dest)
        move disk from source to dest
        Hanoi(disk - 1, aux, dest, source)
      END IF
    END Procedure
  STOP

  Time complexity: O(2^N)
  Auxiliary Space: O(N)
*/

#include <bits/stdc++.h>

int moves = 0;
 
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	if (n == 0) {
		return;
	}
	
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
	std::cout << std::setfill('0') << std::setw(4) << ++moves;
  std::cout << ":  ";
  std::cout << std::setfill('0') << std::setw(2) << n;
  std::cout << "  :: " << from_rod << " -> " << to_rod << std::endl;
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
	int disk;

	std::cout << "Enter number of disk (max 12): ";
	std::cin >> disk;

  if (disk > 12) {
    std::cout << "Error: disk limit exceeded!" << std::endl;
    return 1;
  }

	// A, B and C are names of rods
  std::cout << "move: disk ::  rods" << std::endl;
	towerOfHanoi(disk, 'A', 'C', 'B');
	return 0;
}