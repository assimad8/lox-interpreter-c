#ifndef clox_memory_h
#define clox_memory_h

#define GROW_ARRAY
#define GROW_CAPACITY(capacity) \
    ((capacity)<8?8:(capacity)*2)
#define GROW_ARRAY(type,pointer,oldCount,newCount) \
    (type*)reallocate(pointer,sizeof(type)*(oldCount),\
    sizeof(type)*newCount)

#define FREE_ARRAY(type,pointer,capacity) \
    GROW_ARRAY(type,pointer,sizeof(pointer)*capacity,0)

#endif //clox_memory_h