namespace RPG {

/*! \brief Information about map chipset
	\sa RPG::map
*/
class Chipset {
	public:
		int _unknown_0;
		int _unknown_4;
		DStringPtr name;
		DStringPtr chipsetName;
		short terrain[162]; //<! Terrain id for each map tile.
		unsigned char lowerPassability[162]; //<! Passability bits for each lower tile
		unsigned char upperPassability[144]; //<! Passability bits for each upper tile
		int animationType;
		int animationSpeed;
};

} // namespace RPG
