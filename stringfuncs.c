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
#define sstrjoin(...)    _sstrjoin(__VA_ARGS__, NULL)
char *_sstrjoin(char *buf, char *delim, ...)
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
/* 
 * get the No.'n' substring between 'start' and 'end'
 * n starts from 1.
 */
char *sstrbetween(char *buf, const char *str, const char *start, const char *end, int n)
{
    int step;
    char *s, *e;
    char *res = buf;
    step = strlen(start);
    while(n--)
    {
        s = strstr(str, start);
        str = (s + step);
    };
    if(!s)
        return NULL;
    e = strstr(s, end);
    if(!e)
        return NULL;
    s += step;
    while(s < e)
        *buf++ = *s++;
    *buf = 0;
    return res;
}

char *sstrrep(char *str, const char *old, const char *new, int times)
{
    int all, stepo, stepn;
    char *s;
    char *res = str;
    static char b[1024];
    char *buf = b;
    all = (times == 0 ? 1 : 0);
    stepo = strlen(old);
    stepn = strlen(new);
    while(times-- || all)
    {
        s = strstr(str, old);
        if(!s)
        {
            break;
        }
        while(str < s)
        {
            *buf++ = *str++;
        }
        while(*buf++ = *new++)
            ;
        buf--;
        new -= (stepn + 1);
        str = (s + stepo);
    }
    while(*buf++ = *str++) ;
    *buf = 0;
    strcpy(res, b);
    return res;
}
int main()
{
    char buf[300] = " 32                         <h3><a href=33                                 \"mailto:sunuslee@gmail.com\">sunuslee@gmail.com</a></h3><!-- __mail__ -->34 35                         <h3>13821789599</h3><!-- __phone__ -->";
    char *p;
    p = sstrrep(buf, "<h3>", "replace", 1);
    printf("buf:\n%s", p);

    return 0;
}

