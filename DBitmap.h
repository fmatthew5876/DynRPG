namespace RPG {
	class DBitmap;
	struct DBitmapVTable {
		void (*_unknown_v0)(DBitmap*);
		void (*_unknown_v1)(DBitmap*);
		void (*_unknown_v2)(DBitmap*);
		void (*_unknown_v3)(DBitmap*);
		void (*_unknown_v4)(DBitmap*);
		void (*_unknown_v5)(DBitmap*);
		void (*_unknown_v6)(DBitmap*);
		void (*_unknown_v7)(DBitmap*);
		void (*GetHeight)(DBitmap*);
		void (*_unknown_v9)(DBitmap*);
		void (*_unknown_v10)(DBitmap*);
		void (*GetWidth)(DBitmap*);
		void (*_unknown_v12)(DBitmap*);
		void (*SetHeight)(DBitmap*, int);
		void (*_unknown_v14)(DBitmap*);
		void (*_unknown_v15)(DBitmap*);
		void (*SetWidth)(DBitmap*, int);
		void (*_unknown_v17)(DBitmap*);
		void (*_unknown_v18)(DBitmap*);
		void (*_unknown_v19)(DBitmap*);
		void (*_unknown_v20)(DBitmap*);
		void (*_unknown_v21)(DBitmap*);
		void (*_unknown_v22)(DBitmap*);
		void (*_unknown_v23)(DBitmap*);
		void (*_unknown_v24)(DBitmap*);
		void (*_unknown_v25)(DBitmap*);
		void (*_unknown_v26)(DBitmap*);
		void (*_unknown_v27)(DBitmap*);
	};

	//! Wrapper class for windows' HBITMAPs
	class DBitmap {
		public:
			DBitmapVTable *vTable;
			int unknownData[9];
			void* unknownImage;
			void* unknownObject;
			int unknownData2[10];

			//! Returns the HBITMAP
			inline HBITMAP getHBITMAP() {
				HBITMAP ret;
				asm volatile("call *%%esi" : "=a" (ret) : "S" (0x428140), "a" (this) : "edx", "ecx", "cc", "memory");
				return ret;
			}

			//! Returns the HDC
			inline HDC getHDC() {
				HDC ret;
				asm volatile("call *%%esi; call *%%edi" : "=a" (ret) : "S" (0x4280F8), "D" (0x423634), "a" (this) : "edx", "ecx", "cc", "memory");
				return ret;
			}
	};
}
