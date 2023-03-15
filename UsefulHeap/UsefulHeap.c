#include "UsefulHeap.h"

void HeapInit(Heap *ph, PriorityComp pc)
{
    ph->numOfData = 0;
    ph->comp = pc;
}

int HIsEmpty(Heap *ph)
{
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx)
{
    return idx/2;
}

int GetLChildIDX(int idx)
{
    return idx*2;
}

int GetRchildIDX(int idx)
{
    return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap *ph, int idx)
{
    if (GetLChildIDX(idx) > ph->numOfData)
        return 0;
    else if (GetLchildIDX(idx) == ph->numOfData)
        return GetLChildIDX(idx);
    else
    {
        if (ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRchildIDX(idx)]) < 0)
            return GetRchildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}

