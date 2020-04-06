#include "node.h"
/*for merge
get the head of each node,
compare the two, add the smaller one then for that one head= head->getNext()
then compare again until they equal nullptr

for the reverse:
i don't see how to do this without two temporary nodes?

Node *I ->a->b->c->d
t1=i; ->setnext(t1->getnext) until temp1->getnext = nullptr
t2=i; ->setnext until t2->getnext = t1
                t2  t1
Node *I ->a->b->c--->d
t1->setnext(t2)
                t2<--t1
Node *I ->a->b->c<--->d
then back to t1=i; ti->setnext until ->getnext= t2
            t1  t2
Node *I ->a->b->c<--->d
same deal make t2->setnext = t1
and continue
wait but that gives the issue- if i dont set the Node *I to d, i lose d
but if i dont leave node *I, then i cant do my thing that i'm doing rn
aaaa
*/
