#include <stdio.h>
#include <stdarg.h>
#include <string.h>
/*
 *  sunus lee
 *  Mar 10, 2012
 *  call this function in this format: 
 *  p = strjoin(buf, "^^", "string1", "string2", "string3", NULL);
 *  the parameters MUST END WITH NULL.
 *  No safety check for this function, buf MUST BE BIG ENOUGH!
 */
/*
 *  update**
 *  sunus lee
 *  Mar 15, 2012
 *  you do NOT need to manually add the last parameters(NULL)
 *  anymore, i wrote a warpper to do this for you already!
 *  now just call strjoin(buf, "^^", "str1", "str2", "str3");
 */
#define strjoin(...)    _strjoin(__VA_ARGS__, NULL)
char *_strjoin(char *buf, char *delim, ...)
{
    char *p, *res, *d;
    int i = 0;
    va_list ap;
    va_start(ap, delim);
    res = buf;
    p = va_arg(ap, char *);
    while(p)
    {
        while(*res++ = *p++) 
            /* do nothing */;
        res--;
        if(p = va_arg(ap, char *))
        {
            d = delim;
            while(*res++ = *d++) 
                /* do nothing */;
            res--;
        }
    }
    *res = '\0';
    va_end(ap);
    return buf;
}

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
char *strbetween(char *buf, const char *str, const char *start, const char *end)
{
    char *s, *e;
    char *res = buf;
    s = strstr(str, start);
    if(!s)
        return NULL;
    e = strstr(s, end);
    if(!e)
        return NULL;
    s += strlen(start);
    while(s < e)
        *buf++ = *s++;
    *buf = 0;
    return res;
}

int main()
{
    char buf[200] = "i am buf";
    char *p;
    p = strjoin(buf, "^_^", buf, "i am sunus", "vivian is me", "i play counter-strike.");
    printf("p is :\n%s", p);
    p = strjoin(buf, "^_^", "first line", "i am sunus", "vivian is me", "i play counter-strike.");
    printf("p is :\n%s", p);
    p = strbetween(buf, "sdfhasdfh<start>haha i am the target!<end> tsdfsdfmess", "<start>", "<end>");
    printf("buf:\n%s", p);
    return 0;
}

