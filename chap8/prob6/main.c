#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(void) {
    printf("UID  : %d (%s)\n", getuid(), getpwuid(getuid())->pw_name);
    printf("EUID : %d (%s)\n", geteuid(), getpwuid(geteuid())->pw_name);
    printf("GID  : %d (%s)\n", getgid(), getgrgid(getgid())->gr_name);
    printf("EGID : %d (%s)\n", getegid(), getgrgid(getegid())->gr_name);
    return 0;
}

