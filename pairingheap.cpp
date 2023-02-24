///                            PAIRING HEAP                            ///

#include <fstream>
using namespace std;

ifstream in("pairingheap.in");
ofstream out("pairingheap.out");

class PairNode
{
public:
    int val;
    PairNode *copilSt;
    PairNode *frateUrm;
    PairNode *ant;

    PairNode(int Val = 0, PairNode* copil = NULL, PairNode*  frate = NULL)
    {
        this->val = Val;
        this->copilSt = copil;
        this->frateUrm = frate;
        this->ant = NULL;
    }

    PairNode(PairNode &n)
    {
        this->val = n.val;
        this->copilSt = n.copilSt;
        this->frateUrm = n.frateUrm;
    }

    ~PairNode()
    {
        delete this->copilSt;
        delete this->frateUrm;
    }

    void adauga(PairNode *n)
    {
        if(copilSt == NULL)
            copilSt = n;
          else {
            n->frateUrm = copilSt;
            copilSt = n;
          }
    }
};

class PairingHeap{
private:
    PairNode *rad;
public:
    PairingHeap()
    {
        rad = NULL;
    }

    PairingHeap(int x)
    {
        rad = new PairNode(x);
    }

    ~PairingHeap()
    {
        delete rad;
    }

    bool Vid()
    {
        return rad == NULL;
    }

    void join(PairingHeap& heap2)
    {
        if(this->rad == NULL)
            this->rad = heap2.rad;
         else if(this->rad->val < heap2.rad->val) {
            if(this->rad->copilSt != NULL)
                this->rad->copilSt->ant = heap2.rad;

            heap2.rad->frateUrm = this->rad->copilSt;
            this->rad->copilSt = heap2.rad;
          }
           else {
                if(heap2.rad->copilSt != NULL)
                    heap2.rad->copilSt->ant = this->rad;

                this->rad->frateUrm = heap2.rad->copilSt;
                heap2.rad->copilSt = this->rad;
                this->rad = heap2.rad;
           }
        heap2.rad = NULL;
    }

    void inserare(int x)
    {
        PairingHeap temp(x);
        this->join(temp);
    }

    int minim()
    {
        return this->rad->val;
    }

    void sterge() {
        if(this->rad == NULL)
            return;

        PairNode *pn1, *pn2, *rad_veche;

        pn1 = rad->copilSt;
        pn2 = NULL;

        if(rad->copilSt != NULL)
            rad->copilSt->ant = NULL;

        rad->copilSt = NULL;

        delete rad;

        rad = NULL;

        rad_veche = rad;

        while(pn1 != NULL)
        {
            PairNode *temp;

            pn2 = pn1->frateUrm;

            if(pn2 != NULL){
                temp = pn2->frateUrm;

                if(pn1->val < pn2->val) {
                    if(rad_veche == NULL)
                        this->rad = pn1;
                      else {
                        rad_veche->frateUrm = pn1;
                        pn1->ant = rad_veche;
                      }
                    rad_veche = pn1;
                    pn2->frateUrm = pn1->copilSt;

                    if(pn1->copilSt != NULL)
                        pn1->copilSt->ant = pn2;

                    pn1->copilSt = pn2;
                    pn2->ant = NULL;
                    pn1->frateUrm = NULL;
                }
                  else {
                    if(rad_veche == NULL){
                        this->rad = pn2;
                        pn2->ant = NULL;
                    }
                     else {
                        rad_veche->frateUrm = pn2;
                        pn2->ant = rad_veche;
                    }

                    rad_veche = pn2;
                    pn1->frateUrm = pn2->copilSt;

                    if(pn2->copilSt != NULL)
                        pn2->copilSt->ant = pn1;

                    pn2->copilSt = pn1;
                    pn1->ant = NULL;
                    pn2->frateUrm = NULL;
                }
            }
              else {
                if(rad_veche != NULL)
                    rad_veche->frateUrm = pn1;

                pn1->ant = rad_veche;
                rad_veche = pn1;
                break;
              }
            pn1 = temp;
        }
        if(rad_veche != NULL) {
            pn1 = rad_veche->ant;

            while(pn1 != NULL)
            {
                PairNode *temp;

                temp = pn1->ant;

                if(pn1->val < rad_veche->val) {
                    rad_veche->frateUrm = pn1->copilSt;
                    rad_veche->ant = NULL;

                    if(pn1->copilSt != NULL)
                        pn1->copilSt->ant = rad_veche;

                    pn1->copilSt = rad_veche;
                    pn1->frateUrm = NULL;
                    rad_veche = pn1;
                }
                  else {
                    pn1->frateUrm = rad_veche->copilSt;
                    pn1->ant = NULL;

                    if(rad_veche->copilSt != NULL)
                        rad_veche->copilSt->ant = pn1;

                    rad_veche->copilSt = pn1;
                  }
                pn1 = temp;
            }
            rad = rad_veche;
        }
    }
};


int main()
{
    int op, ind, ind2, val, nr_heap, nr_op;

    in>>nr_heap>>nr_op;

    PairingHeap pheap[nr_heap+1];

    while(nr_op)
    {
        in>>op;
        switch(op)
        {
            case 1:
                in>>ind>>val;
                pheap[ind].inserare(val);
                break;
            case 2:
                in>>ind;
                out<<pheap[ind].minim()<<"\n";
                pheap[ind].sterge();
                break;
            case 3:
                in>>ind>>ind2;
                pheap[ind].join(pheap[ind2]);
                break;
            default:
                break;
        }
        nr_op--;
    }
    return 0;
}
