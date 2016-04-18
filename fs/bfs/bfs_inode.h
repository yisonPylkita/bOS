#pragma once
#include "base_types.h"
#include "list.h"

typedef struct {
    DWORD access;   ///> access rights for file
    DWORD uid;      ///> owner user UID
    DWORD gid;      ///> owner group GID
    DWORD links;    ///> how many hard links refers to this file
    list_head mem;  ///> list of memory blocks that contain file data
    DWORD size;     ///> size of file in bytes
} VSFS_INODE, *VSFS_PINODE;
