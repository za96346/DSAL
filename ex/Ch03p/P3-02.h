//	Prototype Declarations
LIST* createList(int (*compare)(void* argu1, void* argu2));
LIST* destroyList(LIST* list);

int addNode(LIST* pList, void* dataInPtr);

bool removeNode(LIST* pList,
                void* keyPtr,
                void** dataOutPtr);

bool searchList(LIST* pList,
                void* pArgu,
                void** pDataOut);

bool retrieveNode(LIST* pList,
                  void* pArgu,
                  void** dataOutPtr);

bool traverse(LIST* pList,
              int fromWhere,
              void** dataOutPtr);

int listCount(LIST* pList);
bool emptyList(LIST* pList);
bool fullList(LIST* pList);

static int _insert(LIST* pList,
                   NODE* pPre,
                   void* dataInPtr);

static void _delete(LIST* pList,
                    NODE* pPre,
                    NODE* pLoc,
                    void** dataOutPtr);
static bool _search(LIST* pList,
                    NODE** pPre,
                    NODE** pLoc,
                    void* pArgu);
//	End of List ADT Definitions
