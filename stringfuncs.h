/*
 *  sunus lee
 *  Mar 10, 2012
 *  call this function in this format: 
 *  p = strjoin(buf, "^^", "string1", "string2", "string3", NULL);
 *  the parameters MUST END WITH NULL.
 *  No safety check for this function, buf MUST BE BIG ENOUGH!
 */
char *strjoin(char *buf, char *delim, ...);

/*
 * sunus lee
 * Mar 17, 2012
 * this function returns the first substring between 'start' and 'end',
 * and store it in buf.
 * buf must be big enought,
 * if nothing found, returns NULL
 * eg:
 * p = strbetween(buf, "sdfhasdfh<start>haha i am the target!<end> tsdfsdfmess", "<start>", "<end>");
 */
char *strbetween(char *buf, const char *str, const char *start, const char *end);

/*
 * sunus lee
 * Mar 18, 2012
 * find the substring 'old' and replace it with 'new' 'times' times.
 * if times == 0, replace all 'old' substring with new
 * return str on success, NULL on error:
 * if can not find 'times' times substring, return NULL as well
 */
char *sstrrep(char *str, const char *old, const char *new, int times);

