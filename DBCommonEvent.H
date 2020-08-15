namespace RPG {

class DBCommonEvent {
	void** vTable;
	int id;
	int unknown_08;
	int unknown_0C;
};

static RPG::NamedCatalogPtr<RPG::DBCommonEvent *> &dbCommonEvents = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::DBCommonEvent *> **>(0x4CDFB4));

}

