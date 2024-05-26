#include "Zombie.hpp"

int main(void)
{
	Zombie* zombie = newZombie("ZombieHeap");
	zombie->announce();
	randomChump("ZombieStack");
	delete zombie;
	return (0);
}
