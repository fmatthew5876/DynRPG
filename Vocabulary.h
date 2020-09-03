namespace RPG {
    /*! \brief Accesses the array of Strings in the database.
	
		\return The RPG::DStringPtr to a particular string.
		
		Example:
		\code
std::string victoryMessage = RPG::vocabulary[3]
		\endcode
	
		Indexes are:
		
		String Page 1
		
			 0: Message at the Beginning of Each Battle
			 1: Initiative Message
			 2: Escape Failure Message
			 3: Victory Message
			 4: Defeat Message
			 5: Experience Gain Message (Field 2)
			 6: Money Acquisition Message (Field 1)
			 7: Money Acquisition Message (Field 3)
			 8: Item Discovery Message
		
		The following are not in the Strings tab... (but accessible via Resource Hacker)
		
			 9: attacks
			10: A critical hit! (target = monster)
			11: A critical hit! (target = hero)
			12: defends.
			13: is waiting and watching.
			14: is building strength.
			15: pounces.
			16: runs away!
			17: transformed
			18: HP is lost (target = monster)
			19: Dodged (target = monster)
			20: HP is lost (target = hero)
			21: dodged (target = hero)
			22: got out of the way (magic)
			23: needs more practice (magic)
			24: was not affected (magic)
			25: dodged (physical)
			26: used
			27: recovered!
			28: raises!
			29: drops
			30: is taken!
			31: is taken!
			32: Defense increases!
			33: Defense decreases!
		
		Strings Page 2
		
			34: Level Up (Field 2)
			35: Skill Learned (Field 2)
			36: ??
			37: ??
			38: ??
			39: ??
			40: ??
		
		Strings Page 4
		
			41: Items Possessed
			42: Item Equipped
			43: Currency
		
		Strings Page 5
		
			44: Fight
			45: Auto-Fight
			46: Escape
		
		????
		
			47: "Attack"
			48: "Defend"
		
		Strings Page 5 (continued)
		
			49: Item
			50: Skill
			51: Equipment
			52: Save
			53: Quit
			54: New Game
			55: Load Game
			56: Quit Game
			57: Level
			58: HP
			59: MP
			60: Normal Status
			61: Experience
			62: Level (Short Form)
			63: HP (Short Form)
			64: MP (Short Form)
			65: MP Consumed
			66: Attack
			67: Defense
			68: Intelligence
			69: Agility
			70: Weapon
			71: Shield
			72: Armor
			73: Helmet
			74: Accessory
			75: Choosing a Save Slot
			76: Choosing Which Slot to Load
			77: Confirm Quit
			78: File
			79: Yes
			80: No
			81: Status
			82: Order
			83: Row
			84: Wait ON
			85: Wait OFF
		
		????
		
			86: ??
		
		String Page 1 (continued)
		
			87:  "Miss" Message
	*/
	struct Vocabulary;
	struct ShopVocabulary;

	struct ShopVocabulary {
		void** vTable;
		RPG::DStringPtr greeting;
		RPG::DStringPtr reGreeting;
		RPG::DStringPtr buy;
		RPG::DStringPtr sell;
		RPG::DStringPtr leave;
		RPG::DStringPtr buySelect;
		RPG::DStringPtr buyNumber;
		RPG::DStringPtr purchased;
		RPG::DStringPtr sellSelect;
		RPG::DStringPtr sellNumber;
		RPG::DStringPtr sold;
	};

	struct InnVocabulary {
		void** vTable;
		RPG::DStringPtr greeting1;
		RPG::DStringPtr greeting2;
		RPG::DStringPtr greeting3;
		RPG::DStringPtr accept;
		RPG::DStringPtr cancel;
	};

	struct VocabularyVTable {
		void (*_unknown_v0)(Vocabulary*);
		void (*Reset)(Vocabulary*);
	};
	struct Vocabulary {
		VocabularyVTable* vTable;
#if RPG_RT_ENGINE == 2000
		RPG::DStringPtr battleMonsterAppear;
		RPG::DStringPtr battleStart;
#endif
		RPG::DStringPtr battleInitiative;
#if RPG_RT_ENGINE == 2000
		RPG::DStringPtr battleEscapeSuccess;
#endif
		RPG::DStringPtr battleEscapeFailure;
		RPG::DStringPtr battleVictory;
		RPG::DStringPtr battleDefeat;
		RPG::DStringPtr battleExpGain;
		RPG::DStringPtr battleMoneyGain;
		RPG::DStringPtr battleMoneyGain2;
		RPG::DStringPtr battleItemGain; //Confirmed 2k3
		RPG::DStringPtr battleActionAttack;
		RPG::DStringPtr battleCriticalHitFromHero;
		RPG::DStringPtr battleCriticalHitFromMonster;
		RPG::DStringPtr battleActionDefends;
		RPG::DStringPtr battleActionWaiting;
		RPG::DStringPtr battleActionCharging;
		RPG::DStringPtr battleActionSelfDestruct;
		RPG::DStringPtr battleActionEscape;
		RPG::DStringPtr battleActionTransformed;
		RPG::DStringPtr battleDamageOnMonster;
		RPG::DStringPtr battleNoDamageOnMonster;
		RPG::DStringPtr battleDamageOnHero;
		RPG::DStringPtr battleNoDamageOnHero;
		RPG::DStringPtr battleSkillFailA;
		RPG::DStringPtr battleSkillFailB;
		RPG::DStringPtr battleSkillFailC;
		RPG::DStringPtr battlePhysicalMiss;
		RPG::DStringPtr battleItemUsed;
		RPG::DStringPtr battleHpMpRecovered;
		RPG::DStringPtr battleStatRaised;
		RPG::DStringPtr battleStatDropped;
		RPG::DStringPtr battleAbsorbedOnMonster;
		RPG::DStringPtr battleAbsorbedOnHero;
		RPG::DStringPtr battleAttributeUp;
		RPG::DStringPtr battleAttributeDown;
		RPG::DStringPtr battleLevelUp;
		RPG::DStringPtr battleSkillLearned;
		ShopVocabulary* shop1;
		ShopVocabulary* shop2;
		ShopVocabulary* shop3;
		InnVocabulary* innA;
		InnVocabulary* innB;
		RPG::DStringPtr itemsPossessed;
		RPG::DStringPtr itemEquipped;
		RPG::DStringPtr currency;
		RPG::DStringPtr battleCmdFight;
		RPG::DStringPtr battleCmdAutoBattle;
		RPG::DStringPtr battleCmdEscape;
		RPG::DStringPtr optionAttack;
		RPG::DStringPtr optionDefend;
		RPG::DStringPtr optionItem;
		RPG::DStringPtr optionSkill;
		RPG::DStringPtr optionEquipment;
		RPG::DStringPtr optionSave;
		RPG::DStringPtr optionQuit;
		RPG::DStringPtr newGame;
		RPG::DStringPtr loadGame;
		RPG::DStringPtr exitGame;
		RPG::DStringPtr statLevel;
		RPG::DStringPtr statHP;
		RPG::DStringPtr statMP;
		RPG::DStringPtr statNormalStatus;
		RPG::DStringPtr statExp;
		RPG::DStringPtr statLevelShort;
		RPG::DStringPtr statHPShort;
		RPG::DStringPtr statMPShort;
		RPG::DStringPtr statMPCost;
		RPG::DStringPtr statAtk;
		RPG::DStringPtr statDef;
		RPG::DStringPtr statInt;
		RPG::DStringPtr statAgi;
		RPG::DStringPtr equipWeapon;
		RPG::DStringPtr equipShield;
		RPG::DStringPtr equipArmor;
		RPG::DStringPtr equipHelmet;
		RPG::DStringPtr equipAccessory;
		RPG::DStringPtr chooseSaveSlot;
		RPG::DStringPtr chooseLoadSlot;
		RPG::DStringPtr confirmQuit;
		RPG::DStringPtr saveFile;
		RPG::DStringPtr yes;
		RPG::DStringPtr no;
		RPG::DStringPtr optionStatus;
		RPG::DStringPtr optionOrder;
		RPG::DStringPtr optionRow;
		RPG::DStringPtr optionWaitOn;
		RPG::DStringPtr optionWaitOff;
#if RPG_RT_ENGINE == 2003
		RPG::DStringPtr battleStart2k3;
		RPG::DStringPtr battleMiss2k3;
#endif
	};

	static RPG::Vocabulary *vocabulary = (**reinterpret_cast<RPG::Vocabulary ***>(0x4CDCB4));
}
