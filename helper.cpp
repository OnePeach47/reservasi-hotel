#include <iostream>
#include <fstream>

#include "header.h"

using namespace std;

struct kredensial{
    string usr;
    string pwd;
    string savestate;
};

struct session{
    string usr = 0;
    string savestate = 0;
}sesi;

int cekStructCredential(){
    int i;
    for (i = 0; i <= sizeof(struct kredensial); i++);
    return i;
}
