///  @file bfs.c
/// Blood File System implementation
///
/// bfs was created for bOS to be its base file system.
/// Main goals were simplicity and readability.
/// It is block based file system. Each block has 4096 bytes.
/// Maximal file size is 2^32 bytes. Maximal number of files is TODO: check this
///
/// Publication http://pages.cs.wisc.edu/~remzi/OSTEP/file-implementation.pdf
/// was a great help. A lot of ideas were used from that document.

#include <include/base_types.h>
#include "bfs_inode.h"

#define BLOCK_SIZE 64
#define BLOCKS_NUM 64

typedef struct {
    PDWORD inodeBitmap;     ///> inode_bitmap is a pointer to table where inode_bitmap[i] tells if inode is already in use
    PDWORD dataBitmap;      ///> data_bitmap is a pointer to table where data_bitmap[i] tells if data is already in use
    PInode inodes;          ///> pointer to a table of all inodes on partition
    PBYTE data;             ///> block of memory to store data. It is divided
                            ///> to BLOCKS_NUM and each block has BLOCK_SIZE bytes
} MasterBlock, *PMasterBlock;

/// Initialize given file system
///
/// @param[in,out] fs file system object to initialize
/// @return ERROR_OK on success
///         ERROR_MEM_ALLOC on memory allocation error
DWORD BfsInit()
{

}

/// Deinitialize given file system
///
/// @param[in,out] fs file system object to deinitialize
/// @return ERROR_OK on success
DWORD BfsExit(Pbfs_DESC fs)
{

}

/// Open file using given mode
///
/// @param[in,out] fs file system object to perform actions on
/// @param[in]     file_id an identifier of file to open
/// @param[in]     mode a set of flags used to open file
/// @return ERROR_OK on success
///         ERROR_MEM_ALLOC on memory allocation error
DWORD bfs_open(Pbfs_DESC fs, DWORD file_id, DWORD mode);

/// Read [size] bytes from [file_id] to [data] buffer
/// 
/// @param[in]     fs file system object to perform actions on
/// @param[in]     file_id an identifier of existing file
/// @param[out]    data buffer to store readed file data
/// @param[in,out] size number of bytes to read from file.
///                Later it stores number of readed bytes.
/// @return ERROR_OK on success
DWORD bfs_read(Pbfs_DESC fs, DWORD file_id, PBYTE data, PDWORD size);

/// Write [size] bytes to [file_id] from [data] buffer
/// 
/// @param[in]     fs file system object to perform actions on
/// @param[in]     file_id an identifier of existing file
/// @param[out]    data buffer containing data to write
/// @param[in,out] size number of bytes to write to file
///                Later it stores number of writed bytes.
/// @return ERROR_OK on success
DWORD bfs_write(Pbfs_DESC fs, DWORD file_id, PCBYTE data, DWORD size);



static DWORD bfs_file_exist(DWORD file_id)
{
    if (file_id == NULL)
        return ERROR_NULL_ARG;
    if 
}

DWORD bfs_init(Pbfs_DESC fs)
{
    fs = malloc(sizeof(bfs_DESC));
    if (fs == NULL)
        return ERROR_MEM_ALLOC;
    ZeroMemory(fs, sizeof(bfs_DESC));
    return ERROR_OK;
}

DWORD bfs_exit(Pbfs_DESC fs)
{
    if (fs == NULL)
        return ERROR_NULL_ARG;
    free(fs);
    return ERROR_OK;
}

DWORD bfs_open(Pbfs_DESC fs, DWORD file, DWORD mode)
{
    if (fs == NULL)
        return ERROR_NULL_ARG;

}

DWORD bfs_read(Pbfs_DESC fs, DWORD file, PBYTE data, PDWORD size)
{
    if (fs == NULL)
        return ERROR_NULL_ARG;
}

DWORD bfs_write(Pbfs_DESC fs, DWORD file, PCBYTE data, DWORD size)
{
    if (fs == NULL)
        return ERROR_NULL_ARG;
}
