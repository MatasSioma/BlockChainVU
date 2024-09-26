# 0.1
userInput := getInputString()
Iš vartotojo paprašo įvesties konsolėje arba failo pavadimo iš kur imti informaciją, kurią reikia hashuoti.

readInput(&userInputData, userInput)
Gavus string tipo kintamaji, kiekviena raidė paverčiama į binary jos forma ir populiuojamas vector masyvas (userInputData).

arrOfBinData (.size() == 32) := TransformTo256(&userInputData)
Transformuoja vector tipo bitų masyvą į 256 bitus (32 byte'us). Jei vector dydis < 32, kopijuoja ir apverčia pirmus n byte'us, kol dydis = 32.
Jei dydis > 32, tuo pačiu pricipu kopijuoja elementus kol masyvo dydis yra 32 kartotinis. Tuomet rekursyviai apjungia pirmus 2 32 byte'ų blokus, kol masyvo ilgis tampa 32.

magnify(&userInputData) //Kad mažas pokytis reikštų daug (avalanche effect)
Kiekvieną bytę'ą pakelia kvadratu ir kaip naują reikšmę, į jo vietą, įrašo skaičiaus kavadarto liekana, dalinant iš 256 (užtikrinti kad skaičius nebus didesnis negu 8 byte'ai)
Paskaičiuoja priešingą byte'o vietą masyve ir jam priskiria reikšmę, kuri yra loginės operacijos ~XOR (ne "exlusive" ARBA) rezultatas prišingam ir šiuo metu apdorojamam byte'ui.

joinTwoArr(&arr, &output)
Apjungia du masyvus naudojant bitwise XOR operaciją, ir rezultata išsaugo 'output' kontamąjame

output (vecotr<bitset<8>>) := hashStr(userInputDataStr)
"aePcvgOuOJ1ubrOKwUZZUemayZPeGwtp" - pseudo atsistiktinis 32 byte'ų rinkinys
Iš vartotojo gavus String tipo kintamąjį, panaudojus readInput() gauname 32 byte'ų masyvą.
Tada panaudojant magnify() funckija, vartotojo duomenis pavertus į tinkamo ilgio masyvą su TransformTo256(), "maišome bitus" kaip aprašyta magnify funkcijos apraše.

Tuomet apjungiame vartotojo 32 byte'ų ilgio masyvą su minėtu atsistiktiniu* 32 byte'ų rinkiu su joinTwoArr() funkcija.
Gauname rezultatą, kuris vėl praleidžimas per magnify() funkcija.

-> Hash'as sugeneruotas

## Analizė

4 ekspermentas:
![alt text](v0.1-konstitucija.png)

O(2nlog(n)) ?
2n - 2 kart naudojama magnify()
log(n) - TransformTo256()

Problemos:
Pakeitus "mažą" dalį įvesties hash'as nepasikeičia kardinaliai. T.y. Matomi pasikartojantys byte'ai. Visgi, hash'as nėra tas pats.

