Talevici Adela-Laura 324CA

# PROBLEMA 1 - NUMARARE

Pentru a rezolva aceasta problema am folosit o functie de sortare topologica
(am folosit acest site // https://www.geeksforgeeks.org/topological-sorting/
pentru a face functia respectiva) . Aceasta functie calculeaza gradul intern
pentru fiecare nod si utilizeaza o coada pentru a determina ordinea topologica
a nodurilor.Se citesc doua grafuri orientate , efectuez o sortare topologica pe
primul graf si calculez numarul de drumuri de la nodul 1 la nodul N care
apartin si primului si celui de al doilea graf.
Pentru asta am initializat un vector "dp" pentru a stoca numarul de drumuri de
la fiecare nod la nodul N. Nodul N are un drum catre sine insusi deci dp[N]
este initializat cu 1 . Parcurg apoi in ordine topologica inversa nodurile si
actualizez valorile din vector pentru a include drumurile valabile care exista
in ambele grafuri.

* Complexitate temporala : O(N + M)
* Complexitate spatiala : O(N + M)

# PROBLEMA 2 - TRENURI

Aceasta problema determina lungimea celui mai lung drum intr un graf aciclic
directionat care reprezinta reteaua de trenuri dintre doua orase specificate.
Graf ul este reprezentat ca un unorder_map unde cheia este orasul si valoarea
este un vector de orase adiacente."inDegree" tine evidenta numarului de arce
care intra in fiecare oras. "Distance" este utilizat pentru a stoca distantele
de la orasul de plecare la fiecare oras. "cities" este un unordered_set pentru
a tine evidenta oraselor . Am utilizat algoritmul lui Kahn pentru a efectua
sortarea topologica . Orasele care au numarul de arce care intra in fiecare
oras(adica inDegree) zero sunt adaugate intr o coada si este construita ordinea
topologica . Parcurgand orasele in ordinea topologica , actualizez distantele
parcurse pentru orasele adiacente si calculez drumul cel mai lung.

* Complexitate temporala : O (N + M). (N -nr orase,M - nr de rute) 
* Complexitate spatiala : O(N + M).

# PROBLEMA 3 - DRUMURI OBLIGATORII

Aceasta problema determina costul minim al unui drum ce trece prin trei puncte
specifice intr un graf.Pentru a calcula cea mai scurta distanta de la fiecare
punct de plecare catre toate celelalte noduri din graf am utilizat algoritmul
lui Dijkstra (am folosit acest site
https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
pentru a face functia respectiva). Am utilizat o structura Edge care reprezinta
o muchie din graf , in care am stocat nodul destinatie al muchiei(to) si costul
muchiei(cost). Am aplicat Dijkstra de 3 ori (pentru a calcula costul minim al
drumului ce trece prin "X","Y","Z"): de la "x" spre toate nodurile , de la "y"
spre toate nodurile si de la "z" spre toate nodurile pe graful transpus(pentru
a calcula distanta de la "z" la un nod intermediar).Graful este construit
utilizând o listă de adiacență pentru a stoca muchiile. Pentru fiecare muchie,
se adaugă în listă nodul destinație și costul muchiei. De asemenea, construim
un graf transpus pentru a calcula drumurile de întoarcere necesare pentru
nodul "z". Dupa ce avem toate distantele calculate, iteram prin toate nodurile
pentru a determina costul total al drumului care trece prin fiecare nod
intermediar.

* Complexitate temporala: O((N + M) * log N) (N-nr noduri , M-nr muchii)
* Complexitate spatiala: O(N + M).
