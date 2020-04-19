namespace RPG {
	//! Screen transitions
	enum Transition {
		TRANS_FADE,
		TRANS_DISSOLVE,
		TRANS_DISSOLVE_UP,
		TRANS_DISSOLVE_DOWN,
		TRANS_BLINDS,
		TRANS_VERTICAL_STRIPES,
		TRANS_HORIZONTAL_STRIPES,
		TRANS_RECIDING_SQUARE,
		TRANS_EXPANDING_SQUARE,
		TRANS_SHIFT_UP,
		TRANS_SHIFT_DOWN,
		TRANS_SHIFT_LEFT,
		TRANS_SHIFT_RIGHT,
		TRANS_VERTICAL_SPLIT,
		TRANS_HORIZONTAL_SPLIT,
		TRANS_4_WAY_SPLIT,
		TRANS_ZOOM,
		TRANS_MOSAIC,
		TRANS_WAVER_SCREEN,
		TRANS_INSTANT,
		TRANS_NONE, //!< Used for "Erase" transitions to indicate that the screen should not be erased
		TRANS_DEFAULT = 255 //!< Default transition from the database
	};
	
	//! Possible values for RPG::DBSystem::systemFont
	enum SystemFont {
		SYSF_MSGOTHIC, //!< First font (normally MS Gothic)
		SYSF_MSMINCHO //!< Second font (normally MS Mincho)
	};
	
	enum ItemUsability {
		ITMU_HERO, //!< Item usability corresponds to hero id
		ITMU_CLASS //!< Item usability corresponds to class id
	};
	//! One-byte version of RPG::Transition
	typedef unsigned char Transition_T;
	
	//! \cond
	typedef void TestPlayer;
	//! \endcond
	
	//! Possible values for RPG::DBSystem::menuCommand
	enum MenuCommand {
		MENU_CMD_NONE,
		MENU_CMD_ITEM,
		MENU_CMD_SKILL,
		MENU_CMD_EQUIP,
		MENU_CMD_PARTY,
		MENU_CMD_STATUS,
		MENU_CMD_POSITION,
		MENU_CMD_ORDER,
		MENU_CMD_ATB_MODE
	};
	
	//! Two-byte version of RPG::MenuCommand
	typedef short MenuCommand_T;
	
	/*! \brief Used for the default system data which is defined in the
		database
		
		\note The members of this class either mean default values of a
		property or they are used for properties which aren't supposed to be
		changed in-game, thus the members won't be saved and loaded
		automatically (as it is the case with RPG::System), but only loaded
		once at startup.\n\n
		If you want to access data which could be changed in-game, use the
		members and methods of RPG::System instead.\n\n
		\sa RPG::dbSystem
		\sa RPG::System
		\sa RPG::system
	*/
	class DBSystem {
		public:
			void **vTable;
			DStringPtr boatFilename; //!< Filename of the boat vehicle
			int boatId; //!< Id of the boat in charset
			DStringPtr shipFilename; //!< Filename of the ship vehicle
			int shipId; //!< Id of the ship in charset
			DStringPtr airshipFilename; //!< Filename of the airship vehicle
			int airshipId; //!< Id of the airship in charset
			DStringPtr titleFilename; //!< Filename of the title screen
			DStringPtr gameOverFilename; //!< Filename of the game over screen
			DStringPtr systemGraphicFilename; //!< Default filename of the system graphic
			DArray<short,0,0> startingParty; //!< The starting party on a new game.
			Music *titleBGM; //!< Default title screen music
			Music *battleBGM; //!< Default battle music
			Music *victoryBGM; //!< Default victory music
			Music *innBGM; //!< Default inn music
			Music *skiffBGM; //!< Default skiff music
			Music *shipBGM; //!< Default ship music
			Music *airshipBGM; //!< Default airship music
			Music *gameOverBGM; //!< Default game over music
			Sound *cursorSE; //!< Default cursor moving sound
			Sound *decisionSE; //!< Default decision sound
			Sound *cancelSE; //!< Default cancel sound
			Sound *buzzerSE; //!< Default buzzer sound
			Sound *battleStartSE; //!< Default sound played at battle start
			Sound *fleeSE; //!< Default sound played when a battler escapes
			Sound *enemyAttackSE; //!< Default sound played when a monster attacks
			Sound *enemyDamageSE; //!< Default sound played when a monster is damaged
			Sound *heroDamageSE; //!< Default sound played when an actor is damaged
			Sound *evasionSE; //!< Default sound played when an attack is evaded
			Sound *enemyDeathSE; //!< Default sound played when a monster is killed
			Sound *itemSE; //!< Default sound played when an item is used
			Transition_T teleportEraseTrans; //!< Default screen erasing transition on teleport (see RPG::Transition)
			Transition_T teleportShowTrans; //!< Default screen showing transition on teleport (see RPG::Transition)
			Transition_T battleStartEraseTrans; //!< Default screen erasing transition on battle start (see RPG::Transition)
			Transition_T battleStartShowTrans; //!< Default screen showing transition on battle start (see RPG::Transition)
			Transition_T battleEndEraseTrans; //!< Default screen erasing transition on battle end (see RPG::Transition)
			Transition_T battleEndShowTrans; //!< Default screen showing transition on battle end (see RPG::Translation)
			int systemTiled; //!< Is the window background tiled? (Default value)
			SystemFont systemFont; //!< Default system font
			int selectedCondition; //!< Selected condition in the editor.
			int selectedHero; //!< Selected hero in the editor.
			DStringPtr battleTestBackground;
			//! \cond
			TestPlayer *testPlayer;
			//! \endcond
			int databaseSaveCount; //!< Number of times the database was saved in edtior.
			int ldbVersion; //!< LDB database version. 2000 or 2003.
			// System 2 Tab
			DArray<MenuCommand_T,0,0> menuCommand; //!< Array of Menu Commands, set to the index of the menu item (see RPG::MenuCommand)
				//int _unknown_B0;
				//int _unknown_B4;
			DStringPtr system2GraphicFilename; //!< Default filename of the system2 graphic
			DStringPtr frameGraphicFilename; //!< Default filename of the frame graphic
			bool useFrame; //!< Use a frame?
				bool _unknown_B9;
				bool _unknown_BA;
				bool _unknown_BB;
			bool reverseBattleAnims; //!< Reverse Battle Animations when attacked from Behind
				bool _unknown_BD;
				bool _unknown_BE;
				bool _unknown_BF;
			ItemUsability itemUsability; //!< Whether hero id or class id dictates item usability.
			int battleTestFormation; //!< Formation used for battle test
			int battleTestCondition; //!< Formation used for battle test
			int battleTestAltTerrain; //!< An editor only terrain setting.
			int battleTestTerrain; //!< Formation used for battle test
			
	};
	
	/*! \ingroup game_objects
		\brief Object of "system" data, used for default values and properties
		which are not supposed to be changed in-game.
		\sa RPG::system
	*/
	static RPG::DBSystem *&dbSystem = (**reinterpret_cast<RPG::DBSystem ***>(0x4CDC0C));
}
