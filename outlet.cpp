#include "outlet.h"
#include "sales.h"

bool isOutletEmpty(adrSales p)
{
    return p->info.firstOutlet == nullptr;
}

adrOutlet createElmOutlet(string nama, string pic, string location)
{
    adrOutlet p = new Outlet;
    p.name = nama;
    p.pic = pic;
    p.location = location;
    p->next = nullptr;
    return p;
}

void insertNewOutlet(adrSales &p, adrOutlet q)
{
    if(isOutletEmpty(p)){
        p->info.firstOutlet = q;
    } else {
        adrOutlet fq = p->info.firstOutlet;
        adrOutlet lq = nullptr;
        while(fq != nullptr){
            lq = fq;
            fq = fq->next;
        }
        fq->next = q;
    }
}
