namespace RPG {
	/*! \brief The Enter Hero Name scene.
		\sa RPG::enterName
	*/
	class SceneEnterName : public SceneBase {
		public:
			bool initialized; //!< Has the enter hero name scene initialized?
			Window *winFace; //!< The window that contains the faceset
			WindowName *winName; //!< use winName->string to get the name string itself
			WindowNameInput *winInput; //!< use winInput->fontSet to get the fontset used
			Image *faceImage; //!< The face image itself
			int heroId; //!< The ID of the hero
			int initialFontSet; //!< The initial font set
			bool keepDefaultName; //!< Keep the default name? (??)
	};

	/*! \ingroup game_objects
		\brief Access to the Enter Hero Name scene
	*/
	static RPG::SceneEnterName *&enterName = (**reinterpret_cast<RPG::SceneEnterName ***>(0x4CDBF4));

}
