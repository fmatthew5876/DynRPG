namespace RPG {

struct Object;
struct IdObject;

struct ObjectVTable {
	void (*InitSaveChunk)(Object*,int,Chunk*); //!< Takes the Chunk and points it to the given field from the id.
	void (*Reset)(Object*); //<! Reset object state
	void (*ReadInitialize)(Object*); //<! Construct the object
	void (*ReadSaveChunksFromFile)(Object*); //<! Reads save chunks - can be overridden to refresh non save state after reading
	void (*WriteSaveChunksToFile)(Object*); //<! Writes save chunks
	void (*SerializedRead)(Object*); //<! Reads save chunks and does other stuff?
	void (*SerializedWrite)(Object*); //<! Writes save chunks and does other stuff?
};

struct IdObjectVTable : ObjectVTable {
	void (*SetId)(Object*); //<! Sets the object Id
};

struct Object {
	ObjectVTable* vTable;
};

struct IdObject: Object {
	int id;
};

}
