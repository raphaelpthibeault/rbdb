#ifndef DB_PAGES_H
#define DB_PAGES_H

#include <stdint.h>

typedef struct {
    uint32_t file;
    uint32_t offset;
} DB_LSN;

/* Generic Metadata Page Header
 */
typedef struct db_metadata {
    DB_LSN lsn;                     /* 0-7: LSN */
    uint32_t pgno;                  /* 8-11: current page number */
    uint32_t magic;                 /* 12-15: magic number */
    uint32_t version;               /* 16-19: version */
    uint32_t pagesize;              /* 20-23: page size */
    uint8_t encrypt_alg;            /* 24: encryption algoritn */
    uint8_t type;                   /* 25: page type */
    uint8_t mf;                     /* 26: Meta-only flag */
    uint8_t _;                      /* 27: unused */
    uint32_t free;                  /* 28-31: free list page number */
    uint32_t last_pgno;             /* 32-35: page number of last page in db */
    uint32_t nparts;                /* 36-39: number of partitions */
    uint32_t key_count;             /* 40-43: cached key count */
    uint32_t record_count;          /* 44-47: cached record count */
    uint32_t flags;                 /* 48-51 */
	uint8_t  uid[20];              /* 52-71: Unique file ID. */
} DB_META;

/* B-Tree Metadata Page Layout ; size of 512
 */
typedef struct bt_metadata {
    DB_META dbmeta;                 /* 0-71: generic metadata header */
    uint32_t _;                     /* 72-75: unused */
    uint32_t minkey;                /* 76-79: B-Tree minkey */
    uint32_t re_len;                /* 80-83 Recno: fixed-length record length */
    uint32_t re_pad;                /* 84-87 Recno: fixed-length record pad */
    uint32_t root;                  /* 88-91 root page */
    uint32_t __[92];                /* 92-459: unused space */
    uint32_t crypto_magic;          /* 460-463: crypto magic number */
    uint32_t trash[3];              /* 464-75: trash space, not for use */
    uint32_t iv[4];                 /* 476-491: crypto iv */
    uint32_t chksum[5];             /* 492-511: page checksum */
} BT_META;

#endif // DB_PAGES_H
