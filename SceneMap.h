namespace RPG {

	/*! \brief The Map scene.
		\sa RPG::sceneMap
	*/
	class SceneMap : public SceneBase {
		public:
			bool initialized; //!< Has the map scene been initialized?
	};

static RPG::SceneMap *&sceneMap = (**reinterpret_cast<RPG::SceneMap ***>(0x4CDC1C));

}
