namespace RPG {
	//! Not implemented yet

	class AuroraBoard;
	struct AuroraBoardVTable {
	};

	/*! \brief The base class for all scenes.
	 * Should be called Scene, but that name is already taken by Scene enum
	*/
	class AuroraBoard {
		public:
			AuroraBoardVTable *vTable;
			DBitmap* bitmap;
			int unknown08;
			int maybeBrightness;
	};

}
