namespace RPG {
	//! Not implemented yet
	typedef void AuroraBoard;

	class SceneBase;
	struct SceneBaseVTable {
		void (*_unknown_v0)(SceneBase*);
		void (*Reset)(SceneBase*);
	};

	/*! \brief The base class for all scenes.
	 * Should be called Scene, but that name is already taken by Scene enum
	*/
	class SceneBase {
		public:
			SceneBaseVTable *vTable;
			AuroraBoard *AuroraBoard1; //!< Not even a little bit implemented...
			AuroraBoard *AuroraBoard2; //!< Not even a little bit implemented...
	};

}
