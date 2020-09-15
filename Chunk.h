namespace RPG {

enum ChunkTypeCode {
	SAVE_INT = 0, //<! Saves an integer up to 4 bytes
	SAVE_SHORT = 1, //<! A smaller integer whose size is sizeBytes and value stored directly in object.
	SAVE_ARRAY = 2, //<! An array of data, where sizeBytes indicates the size of the whole array and object points to the data
	SAVE_STRING = 3, //<! A string, where object points to the DString
	SAVE_CATALOG = 4, //<! A catalog, where we call it's virtual function and recurse
	SAVE_STRUCT = 5, //<! An RPG_Object, where we call it's virtual function and recurse
	SAVE_BYTE = 6, //<! A single byte
	SAVE_DOUBLE = 7, //<! A single double
	SAVE_NONE = 8, //<! Invalid chunk type - not saved
};

typedef unsigned char ChunkTypeCode_T;

struct ChunkVTable {};

struct Chunk {
	ChunkVTable* vTable;
	ChunkTypeCode_T type;
	void* object; //<! Pointer to the object, LCF code casts this back to the object based on type.
	int sizeBytes; //<! Used only for short, enum, byte, and double - single value and arrays - says how many bytes to read / write
	int defaultIntValue; //<! Chunk skipped if type is int and value == this
	unsigned char defaultByteValue; //<! Chunk skipped if type is byte and value == this
	double defaultDoubleValue; //<! Chunk skipped if type is double and value == this
	bool skipIfEmptyString; //!< Chunk Skipped if true and string is empty.
};

}
