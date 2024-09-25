# 0.1
userInput := getInputString()
Iš vartotojo paprašo įvesties konsolėje arba failo pavadimo iš kur imti informaciją, kurią reikia hashuoti.

arrOfBinData := readInput(&userInputData, userInput)
Gavus string tipo kintamaji, kiekviena raidė paverčiama į binary jos forma ir populiuojamas vector masyvas (userInputData).

arrOfBinData (.size() == 32) := TransformTo256(&userInputData)
Transformuoja vector tipo bitų masyvą į 256 bitus (32 byte'us). Jei vector dydis < 32, kopijuoja ir apverčia pirmus n byte'us, kol dydis = 32.
Jei dydis > 32, tuo pačiu pricipu kopijuoja elementus kol masyvo dydis yra 32 kartotinis. Tuomet rekursyviai apjungia pirmus 2 32 byte'ų blokus, kol masyvo ilgis tampa 32.

magnify(&userInputData) //Kad mažas pokytis reikštų daug (avalanche effect)
Kiekvieną bytę'ą pakelia kvadratu ir kaip naują reikšmę, į jo vietą, įrašo skaičiaus kavadarto liekana, dalinant iš 256 (užtikrinti kad skaičius nebus didesnis negu 8 byte'ai)
Paskaičiuoja priešingą byte'o vietą masyve ir jam priskiria reikšmę, kuri yra loginės operacijos ~XOR (ne "exlusive" ARBA) rezultatas prišingam ir šiuo metu apdorojamam byte'ui.

main(userInputData, readInput("aePcvgOuOJ1ubrOKwUZZUemayZPeGwtp"))
"aePcvgOuOJ1ubrOKwUZZUemayZPeGwtp" - pseudo atsistiktinis 32 byte'ų rinkinys
Naudojant getInputString(), readInput() gauname du 32 byte'ų ilgio masyvus.
Tada panaudojant magnify() funckija, vartotojo duomenis pavertus į tinkamo ilgio masyvą "maišome bitus" kaip aprašyta magnify funkcijos apraše.
Tuomet panaudojant XOR operacija su minėtu atsistiktiniu* 32 byte'ų rinkiu ir naudotojo įvesties masyvu, gauname rezultatą, kuris vėl praleidžimas per magnify() funkcija.

-> Hash'as sugeneruotas

Problemos:
Pakeitus "mažą" dalį įvesties hash'as nepasikeičia kardinaliai. T.y. Matomi pasikartojantys byte'ai. Visgi, hash'as nėra tas pats.
