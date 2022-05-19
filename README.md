# Pairing-Heap

In acest proiect am implementat o structura de date avansata: un Pairing Heap.
Acesta are proprietatea ca in radacina se va afla intotdeauna valoarea minima, iar reuniunea a doua heapuri se va face in functie de compararea nodurilor din radacina. Adica intotdeauna heapul cu radacina mai mica va deveni radacina heapului nou compus, iar cel cu radacina mai mare se va atasa de cel cu radacina mai mica, astfel incat sa nu strice ordinea crescatoare.
Una dintre surse reprezinta solutia problemei 'mergeheap' de pe infoarena, unde se cerea aflarea valorii maxime din heap, iar cea de-a doua solutie este implementarea propriu-zisa a unui pairing heap. Diferenta dintre cele doua consta in compararea nodurilor in mod diferit: adica in implementarea solutiei pentru problema data se va ordona astfel incat sa se afle descrescator, iar in implementarea structurii de date se va prefera ordonarea crescatoare.
