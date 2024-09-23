userInput := getInputString()
Iš vartotojo paprašo įvesties konsolėje arba failo pavadimo iš kur imti informaciją, kurią reikia hashuoti.

arrOfBinData := readInput(&userInputData, userInput)
Gavus string tipo kintamaji, kiekviena raidė paverčiama į binary jos forma ir populiuojamas vector masyvas (userInputData).

main(userInputData, readInput("aePcvgOuOJ1ubrOKwUZZUemayZPeGwtp"))
Iteruoja per userInputData vectorių
    apverčia byte'ą (0 -> 1, 1 -> 0)
    byte'ą padaugina iš vartotojo ivesties bit'ų skaičiaus ir užtikrina, kad gautas skaičius neviršija 255 (8 bitų)