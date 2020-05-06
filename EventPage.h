namespace RPG {
    //! Possible values for RPG::EventPage::charsetDir and RPG::Character::facing
	enum Facing { // Moved from Character.h
		FACE_UP, //!< %Character looks up
		FACE_RIGHT, //!< %Character looks to the right
		FACE_DOWN, //!< %Character looks down
		FACE_LEFT //!< %Character looks to the left
	};

	//! One-byte version of RPG::Facing
	typedef unsigned char Facing_T;

	//! Possible values for the RPG::EventPage::charsetFrame member
	enum EventFrame {
		EF_LEFT,
		EF_MIDDLE,
		EF_RIGHT
	};

	//! Possible values for the RPG::EventPage::moveSpeed member
	enum EventMoveSpeed {
		EMS_ONE_EIGHTH_NORMAL = 1,
		EMS_ONE_FOURTH_NORMAL,
		EMS_ONE_HALF_NORMAL,
		EMS_NORMAL,
		EMS_TWICE_NORMAL,
		EMS_FOUR_TIMES_NORMAL
	};

	typedef unsigned char EventMoveSpeed_T;

	//! Event trigger
	enum EventTrigger {
		ET_ACTION_KEY,
		ET_PLAYER_TOUCH,
		ET_EVENT_TOUCH,
		ET_AUTOSTART,
		ET_PARALLEL,
		ET_NONE
	};

	typedef unsigned char EventTrigger_T;

	//! Possible values for RPG::Character::layer
	enum Layer {
		LAYER_BELOW_HERO, //!< Below hero
		LAYER_SAME_LEVEL_AS_HERO, //!< Same level as hero
		LAYER_ABOVE_HERO //!< Above hero
	};

	//! One-byte version of RPG::Layer
	typedef unsigned char Layer_T;

	//! Possible values for RPG::Character::animationType
	enum AnimationType {
		ANI_NORMAL, //!< "Non-continuous"
		ANI_STEPPING, //!< "Continuous" (always stepping)
		ANI_FIXED_DIR_NORMAL, //!< "Non-continous", fixed direction
		ANI_FIXED_DIR_STEPPING, //!< "Continuous", fixed direction
		ANI_FIXED_GRAPHIC, //!< Fixed graphic (no stepping, fixed direction)
		ANI_SPIN_AROUND //!< Spinning around
	};

	//! One-byte version of RPG::AnimationType
	typedef unsigned char AnimationType_T;

	//! Movement type
	enum MovementType {
		MOVE_STATIONARY,
		MOVE_RANDOM,
		MOVE_VERTICAL,
		MOVE_HORIZONTAL,
		MOVE_TO_HERO,
		MOVE_AWAY_HERO,
		MOVE_CUSTOM
	};

	//! One-byte version of RPG::MovementType
	typedef unsigned char MovementType_T;



	/*! \brief Used for pages within a map event, along with their conditions, script list, commands, etc.

		\sa RPG::EventData
		\sa RPG::EventPrecondition
		\sa RPG::Facing
		\sa RPG::EventFrame
		\sa RPG::MoveRoute
	*/
	class EventPage {
		public:
			void **vTable;
			int id; //!< ID of the event page (1-100)
				int _unknown_08;
				int _unknown_0C;
				UnknownPointer *_unknown_10;
			EventScriptList *scriptLines; //!< The event script lines! (See RPG::EventScriptList)
			EventPrecondition *preconditions; //!< The event's preconditions (See RPG::MapEventPrecondition)
			DStringPtr charsetFilename; //!< The filename of the charset used for the event graphic
			int charsetId; //!< The ID of the character within the charset (0-7)
			Facing charsetDir; //!< The direction the charset is facing in
			EventFrame charsetFrame; //!< The starting frame of animation for the charset (See RPG::EventFrame)
			bool isTransparent; //!< Is the event graphic transparent?
			MovementType_T movementType; //!< The page's movement type.
			int moveFrequency; //!< The event's movement frequency (1-8)
			EventTrigger_T triggerType; //!< The page event trigger type.
			Layer_T layer; //!< The event layer.
			bool forbidEventOverlap; //!< If the event forbids overlap
			AnimationType_T animationType; //!< The event animation type.
			EventMoveSpeed moveSpeed; //!< The event's movement frequency (See RPG::EventMoveSpeed)
			MoveRoute *moveRoute; //!< The move route of the event

			// WHERE'S MOVEMENT TYPE, FORBID EVENT OVERLAP, TRIGGER CONDITION, EVENT LAYER
			// AAAAH WHY AM I YELLING
	};
}
