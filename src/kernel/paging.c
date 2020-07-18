#include "paging.h"

void paging_init(void) {
    for(int i = 0; i < 1024; i++) {
        page_dir[i] = 2;
        first_page_table[i] = (i * 0x1000) | 3;
    }
    page_dir[0] = (int) first_page_table | 3;
    //page_dir[768] = (int) first_page_table | 3;
    load_page_dir(page_dir);
    paging_enable();
}
