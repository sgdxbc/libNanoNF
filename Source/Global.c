//

#include "Global.h"

static Heap *globalCurrent = NULL;

void SetCurrentHeap(Heap *heap)
{
    globalCurrent = heap;
}

Raw GlobalMalloc(Size size)
{
    return AllocateObject(globalCurrent, size);
}

Raw GlobalRealloc(Raw object, Size size)
{
    if (!object)
    {
        return NULL;
    }
    return ResizeObject(globalCurrent, object, size);
}

Raw GlobalCalloc(Size count, Size size)
{
    return AllocateZeroedObjectList(globalCurrent, count, size);
}

void GlobalFree(Raw object)
{
    if (object)
    {
        return ReleaseObject(globalCurrent, object);
    }
}