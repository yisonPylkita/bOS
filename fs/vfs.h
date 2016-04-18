#pragma once

#include "base_types.h"
#include "list.h"

typedef struct {
    ACCESS_MASK access;   ///> access rights for file
    DWORD uid;      ///> owner user UID
    DWORD gid;      ///> owner group GID
    DWORD links;    ///> how many hard links refers to this file
    PDWORD;  ///> list of memory blocks that contain file data
    DWORD size;     ///> size of file in bytes
} VSFS_INODE, *VSFS_PINODE;

DWORD CreateFile(LPCWSTR filePath);
DWORD OpenFile(PDWORD fd, LPCWSTR filePath);
DWORD ReadFile(DWORD fd, PBYTE buff, PDWORD size);
DWORD WriteFile(DWORD fd, CPBYTE buff, PDWORD size);
//DWORD UnlinkFile(DWORD );
