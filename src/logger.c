#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "./includes/logger.h"

FILE * fp;

void open_logfile() {
    fp = fopen("../data/logfile", "w");
};

void close_logfile() {
    fclose(fp);
}
