namespace RPG {
	//! Possible values for the RPG::MapProperties::wrapping member
	enum MapWrapping {
		MCL_NONE,
		MCL_VERTICAL,
		MCL_HORIZONTAL,
		MCL_BOTH
	};
	
	//! One-byte version of RPG::MapWrapping
	typedef unsigned char MapWrapping_T;
	
	
	//! Possible values for the RPG::MapProperties::dGenType member
	enum DungeonGenType {
		DGT_SINGLE_PASSAGE,
		DGT_LINKED_ROOMS,
		DGT_MAZE_LIKE,
		DGT_OPEN_ROOM
	};
	
	//! Possible values for the RPG::MapProperties::dGenPassageGranularity member
	enum DungeonGenPassWidth {
		DGPW_ONE_BY_ONE,
		DGPW_TWO_BY_TWO
	};
	
	/*! \brief The current map, it's properties, dungeon generation settings, events, and chipset properties

		\sa RPG::Map
		\sa RPG::MapLmuFile
		\sa RPG::MapEvent
		\sa RPG::MapGraphics
		\sa RPG::MapWrapping
		\sa RPG::DungeonGenType
		\sa RPG::DungeonGenPassWidth
	*/
	class MapProperties {
		public:
			void **vTable;
			int id; //!< The ID of the current map
				int _unknown_08;
				int _unknown_0C;
			int chipsetId;
			int width; //!< The width of the map
			int height; //!< The height of the map
			MapWrapping_T wrapping; //!< The wrapping of the map, set via dropdown
			bool hasPanorama; //!< Does the map use a panorama?
			DStringPtr panoramaFilename; //!< The filename of the panorama's image
			bool horScroll; //!< Is horizontal scrolling enabled?
			bool verScroll;//!< Is vertical scrolling enabled?
			bool horAutoscroll; //!< Is horizontal auto-scrolling enabled?
			int horScrollSpeed; //!< If horizontal scrolling enabled, this is the defined speed
			bool verAutoscroll;//!< Is vertical auto-scrolling enabled?
			int verScrollSpeed; //!< If vertical scrolling enabled, this is the defined speed
			MapLmuFile *currentLmuFile; //!< Lmu file pointer to the current map
				MapLmuFile *_unknown_LmuFile; //!< Lmu file pointer to ???
			NamedCatalogPtr<Event*> events; // Duplicate of map->events[##]->data (data is the same anyway...)
				//NamedCatalogPtr<EventData *> events;  //!< The original definition. Points the array of map events on the current map (one-based) (again??)
			MapGraphics *graphics; //!< The Tileset, along with the cached graphics?
			DListPtr<Image*> charsetGraphics; //!< A list of cached charset images for this map.
			int mapSaveCount; //!< Number of times the map was saved in the editor.
			bool useDungeonGenerator; //!< true if the current map uses the dungeon generator
			DungeonGenType dGenType; //!< Dungeon generation guidelines (see RPG::DungeonGenType)
				int _unknown_54;
				int _unknown_58;
				int _unknown_5C;
				int _unknown_60;
				int _unknown_64;
				int _unknown_68;
			DungeonGenPassWidth dGenPassageGranularity; //!< The passage granularity (1x1 or 2x2)
			int dGenRoomWidth; //!< Room width if dGenType is set to DGT_LINKED_ROOMS
			int dGenRoomHeight; //!< Room height if dGenType is set to DGT_LINKED_ROOMS
			bool dGenSurroundWithWalls; //!< Surround map with wall tiles?
			bool dGenUseUpperWall; //!< Use upper wall in the dungeon generation?
			bool dGenUseFloorB; //!< Use Floor B in the dungeon generation?
			bool dGenUseFloorC; //!< Use Floor C in the dungeon generation?
			bool dGenUseObstacleB; //!< Use Obstacle B in the dungeon generation?
			bool dGenUseObstacleC; //!< Use Obstacle C in the dungeon generation?
			short dGenCeilingTile; //!< The tile ID of the Ceiling
			short dGenLowerWallTile; //!< The tile ID of the Lower Wall
			short dGenUpperWallTile; //!< The tile ID of the Upper Wall
			short dGenFloorATile; //!< The tile ID of Floor A
			short dGenFloorBTile; //!< The tile ID of Floor B
			short dGenFloorCTile; //!< The tile ID of Floor C
			short dGenObstacleATiles[4]; //!< The tile IDs of Obstacle A (Block of 4 upper-layer tiles) (value is 10000 + the tile's ID)
			short dGenObstacleBTiles[4]; //!< The tile IDs of Obstacle B (Block of 4 upper-layer tiles) (value is 10000 + the tile's ID)
			short dGenObstacleCTiles[4]; //!< The tile IDs of Obstacle C (Block of 4 upper-layer tiles) (value is 10000 + the tile's ID)
			int dGenGeneratorX[9];
			int dGenGeneratorY[9];
	};
}
