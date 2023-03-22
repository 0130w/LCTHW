#include <unistd.h>

int main(int argc, char **agrv)
{
    int i = 0;

    while(i < 100) {
        usleep(3000);
    }

    return 0;
}


