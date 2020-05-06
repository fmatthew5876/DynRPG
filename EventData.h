namespace RPG {
	/*! \brief Class used for storing event names, ids, the event pages, and script data
	
		\sa RPG::Map
		\sa RPG::Event
		\sa RPG::EventPage
	*/
	class EventData {
		public:
			void **vTable;
			int id; //!< The ID of the event
			DStringPtr name; //!< The name of the event
			int x; //!< The event's x coordinate
			int y; //!< The event's y coordinate
			CatalogPtr<EventPage *> pages; //!< The array of pages on the event, as well as their properties and event commands (zero-based)
				int _unknown_18;
				int _unknown_1C;
				int _unknown_20;
				int _unknown_24;
				int _unknown_28;
				int _unknown_2C;
				int _unknown_30;
			EventTrigger triggerType; //!< Current Event trigger type
	};
}
