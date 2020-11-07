namespace RPG {

class TestPlayer;

struct TestPlayerVTable : IdObjectVTable {
	int (*Create)(TestPlayer*);
};

class TestPlayer {
public:
	TestPlayerVTable* vTable;
	int unknown_04;
	int unknonw_08;
	int actorid;
	int level;
	short weapon;
	short shield;
	short armor;
	short helmet;
	short accessory;
};

} // namespace RPG
