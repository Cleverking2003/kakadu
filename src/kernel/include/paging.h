#ifndef PAGING_H
#define PAGING_H

static int page_dir[1024] __attribute__ ((aligned (4096)));
static int first_page_table[1024] __attribute__ ((aligned (4096)));

extern void load_page_dir(int* page_dir);
extern void paging_enable(void);
void paging_init(void);

#endif
