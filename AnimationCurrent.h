namespace RPG {
	/*! \brief Used to access the data for the battle animation currently playing

		\sa RPG::AnimationInBattle
		\sa RPG::Animation
	*/

	class AnimationFlashEffect {
		int red;
		int green;
		int blue;
		int intensity;
	};

	class AnimationShakeEffect {
		AnimationScope_T scope;
		unsigned char _unknown_02;
	};

	class AnimationCurrent {
		public:
			void **vTable;
			Animation *anim; //!< Animation structure of the current battle animation. 0 if BattleCharSets
			DStringPtr filename; //!< Filename of the animation that has been stored in memory
			Image *image; //!< The actual image data of the battle animation stored in memory. Only use with monsters
#if RPG_RT_ENGINE == 2003
			Image *imageLarge; //!< The image data if it's a large battle animation, which has been stored in memory. Only use with monsters
#endif
			AnimationFlashEffect* targetFlashEffects; //<! For each frame, says what the target flash effect should be.
			AnimationFlashEffect* screenFlashEffects; //<! For each frame, says what the screen flash effect should be.
#if RPG_RT_ENGINE == 2003
			AnimationShakeEffect* shakeEffects; //<! For each frame, says what the shake effect scope should be.
			bool isMirrored; //!< Is the animation currently mirrored?
#endif

	};

}
