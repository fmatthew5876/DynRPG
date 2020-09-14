namespace RPG {

class Save;

struct SaveVTable : ObjectVTable {
};

struct Save {
	Title* title;
	System* system;
	ScreenEffect* screenEffect;
	void* pictures;
	Hero* hero;
	Vehicle* skiff;
	Vehicle* ship;
	Vehicle* airship;
	Actors* actors;
	Inventory* inventory;
	void* teleports;
	Map* map;
	Panorama* panorama;
	BattleEvent* foregroundInterpreter;
	void* commonEvents;
	AnimationInBattle* animationInBattle;
	BattleEvent* battleInterpreter;
};

} 
