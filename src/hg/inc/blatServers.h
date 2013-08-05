/* blatServers.h was originally generated by the autoSql program, which also 
 * generated blatServers.c and blatServers.sql.  This header links the database and
 * the RAM representation of objects. */

#ifndef BLATSERVERS_H
#define BLATSERVERS_H

struct blatServers
/* Description of online BLAT servers */
    {
    struct blatServers *next;  /* Next in singly linked list. */
    char *db;	/* Database name */
    char *host;	/* Host (machine) name */
    int port;	/* TCP/IP port on host */
    signed char isTrans;	/* 0 for nucleotide/1 for translated nucleotide */
    };

void blatServersStaticLoad(char **row, struct blatServers *ret);
/* Load a row from blatServers table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct blatServers *blatServersLoad(char **row);
/* Load a blatServers from row fetched with select * from blatServers
 * from database.  Dispose of this with blatServersFree(). */

struct blatServers *blatServersLoadAll(char *fileName);
/* Load all blatServers from a tab-separated file.
 * Dispose of this with blatServersFreeList(). */

struct blatServers *blatServersLoadWhere(struct sqlConnection *conn, char *table, char *where);
/* Load all blatServers from table that satisfy where clause. The
 * where clause may be NULL in which case whole table is loaded
 * Dispose of this with blatServersFreeList(). */

struct blatServers *blatServersCommaIn(char **pS, struct blatServers *ret);
/* Create a blatServers out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new blatServers */

void blatServersFree(struct blatServers **pEl);
/* Free a single dynamically allocated blatServers such as created
 * with blatServersLoad(). */

void blatServersFreeList(struct blatServers **pList);
/* Free a list of dynamically allocated blatServers's */

void blatServersOutput(struct blatServers *el, FILE *f, char sep, char lastSep);
/* Print out blatServers.  Separate fields with sep. Follow last field with lastSep. */

#define blatServersTabOut(el,f) blatServersOutput(el,f,'\t','\n');
/* Print out blatServers as a line in a tab-separated file. */

#define blatServersCommaOut(el,f) blatServersOutput(el,f,',',',');
/* Print out blatServers as a comma separated list including final comma. */

#endif /* BLATSERVERS_H */
