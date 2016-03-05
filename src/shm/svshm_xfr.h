#ifndef __SVSHM_XFR_H
#define __SVSHM_XFR_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <map>
#include <string>
#include "binary_sems.h"

using std::map;
using std::string;

#define SHM_KEY 0x12345
#define SEM_KEY 0x56789

#define OBJ_PERMS (S_IRUSR | S_IRGRP | S_IWGRP)

#define WRITE_SEM 0
#define READ_SEM  1

struct shmseg{
    map<string,Context> *url_map;
};

#endif