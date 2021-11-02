#include <sys/types.h>
#include <pwd.h>
#include <stddef.h>
#include <string.h>

/*
* This demo olny show how the syscall getpwnam to implement
*/
struct passwd* getpwnam(const char *name)
{
    struct passwd *ptr = NULL;
    setpwent();

    while ((ptr = getpwent()) != NULL) {
        if (strcmp(name, ptr->pw_name) == 0) {
            break;
        }
    }

    endpwent();
    return ptr; //ptr is NULL if no match found
}