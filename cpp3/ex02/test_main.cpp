int main(void)
{
	std::string ClapTrapName;
	std::string ScavTrapName;
	std::string FragTrapName;

	std::cout << "Enter ClapTrap name: ";
	std::cin >> ClapTrapName;
	std::cout << "Enter ScavTrap name: ";
	std::cin >> ScavTrapName;
	std::cout << "Enter FragTrap name: ";
	std::cin >> FragTrapName;

	ClapTrap clap(ClapTrapName);
	ScavTrap scav(ScavTrapName);
	FragTrap frag(FragTrapName);

	// Test ClapTrap
	clap.attack("Enemy1");
	clap.takeDamage(10);
	clap.beRepaired(5);

	// Test ScavTrap
	scav.attack("Enemy2");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();

	// Test FragTrap
	frag.attack("Enemy3");
	frag.takeDamage(30);
	frag.beRepaired(15);
	frag.highFivesGuys();

	return 0;
}
