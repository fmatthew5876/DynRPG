namespace RPG {
	//! Stub
	typedef void Stub;

	/*! \brief Possible values for RPG::AnimationInBattle::currentAnimTarget

		The current target of the battle animation
	*/
	enum AnimationTargetParty {
		ATM_NONE = -2,
		ATM_ALL_PARTY = -1,
		ATM_BATTLER_1 = 0,
		ATM_BATTLER_2 = 1,
		ATM_BATTLER_3 = 2,
		ATM_BATTLER_4 = 3,
		ATM_BATTLER_5 = 4,
		ATM_BATTLER_6 = 5,
		ATM_BATTLER_7 = 6,
		ATM_BATTLER_8 = 7,
	};

	/*! \brief Used to access battle animation data while an animation is on screen 

		\sa RPG::AnimationTargetMonster
		\sa RPG::Animation
	*/

	class AnimationInBattle {
		public:
			void **vTable;
				int _unknown_04;
				Stub *_unknown_08; // battlers that are already pointed to in RPG::monsters and RPG::actors
				int monsterGroupId; //!< The ID of the monster group
				//int _unknown_0C;
			bool isAnimationPlaying; //!< Is a battle animation playing?
			AnimationCurrent *currentAnim; //!< The battle animation's data
			int currentAnimationId; //!< The ID of the battle animation currently playing
			AnimationTargetParty currentAnimTarget; //!< The target of the battle animation currently playing (See RPG::AnimationTargetMonster)
			int currentAnimationFrame; //!< Current animation frame playing
	};
}
