namespace RPG {
	/*! \brief Used to store the party information in SceneFile save games.
	*/
	class Title {
		public:
			void **vTable;
			double timestamp;
			DString hero_name;
			int hero_level;
			int hero_hp;
			DString face1_name;
			int face1_id;
			DString face2_name;
			int face2_id;
			DString face3_name;
			int face3_id;
			DString face4_name;
			int face4_id;
	};
}
