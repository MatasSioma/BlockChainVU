#ifndef HASH_H
#define HASH_H

#include <vector>
#include <iostream>
#include <iomanip> 
#include <string>
#include <limits>
#include <bitset>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>
#include <algorithm>

using namespace std;

const string Strs[193] = {
    "9bAiYSzBGgDAUhfsbYlG701ZhEUiZycO",
    "HIGw0N2lGozEXs9623aWvV1VddZrcK4Q",
    "KFPdgdUemuNI1QZ7PpNSE7jEcxNHuzAO",
    "rL1137aZnGapnwshYPSYihoqQjW7WD6T",
    "JNRgouX19e7TmD5dPKLiTODwxR0iZLnp",
    "WAMwWZKpGdhTkkWUsTB6SjP382n5P0yd",
    "YP0mL4anpNeASZCxinPSqES39jfz07cg",
    "X9Qvsy2xZ5DcS531n9UQUiXlNKCUBrxU",
    "7qniTuIznrHR22vaEuEUltFvkdFp8Sx5",
    "aVmPuAGRMo4MVnAHnWmsBI6aJJa4yP4x",
    "PyKSvbMj7oMrLGPp7V2g2JDK4ZuOzyfA",
    "0i8lCWFtcTtDe9qjHKYcIjlWomCfU2xN",
    "Mo3yngwI8LiLAbEXhwWkCoXLrPAqnJoq",
    "u4zYHBN9iiPeHHkUACmBDNLk3iUq32Bk",
    "Ot4n0y5QcoF3xXumqvUVUhUyIyx4rQSB",
    "3a6oH2e5B2Rhm7lZ9EVtuNIsjuD8Wa1G",
    "ZLfSleOtvCXpW6FdGJnYBComrKYege52",
    "qnIR0hXQU3FfnX4S1KzMqU0GAC4DAikq",
    "GSuMxK4k1EqMexUfGXzPMXsfdpwkt8G4",
    "8Rd3EUSS6bSp82L60vpGVXzXL9RUgN6O",
    "AxpNdmzB8KbUNTW7LmJLC0L5kHVNuFky",
    "6dRvXIELEy0Akk8yHdNkZIHBCbC3KvpB",
    "ezQfHpXnl3wsImsed7tKOo7oIrGsRgwh",
    "wD17nGvTCaNuP5aZDPB6DmsM7f1DrekU",
    "eAchMg4Yfzwsk3qIG0ex7NEd0ZL2aJer",
    "lTFMZkXXbQ9iuFxS3rLcojr0XzT6TTIF",
    "XxOPb8cYHDvF8nnBVIIHisPNMxaM0rO0",
    "MKcaSgo5yLKqYieRJwytrEOOWPITjD3t",
    "oudx9G1kSxo9Ls8SAsB8ugWRR7Y5bCCN",
    "eVOy7hQfDJL7tVYesP3nMD20FgvZKGXs",
    "QvXjDYiWyif4rBJW0NQXHPQdZy3ymkmp",
    "p1mUxm82VBXKpmIuH1pN1IRlceFmyH3W",
    "daqBbMGBwrbDtpBqDLnR0u0dZ9xPIoY1",
    "6myQIwA8vKRF1eCjoWVL2slpFTPRTRDy",
    "HOutdsj5wdd7c9yYHrS2UayxOeXTz4o5",
    "fY7mte0U3b5ZWFdlpKmXLgDkfYqyhw0D",
    "xJ2v2HTZTo1YBWga0uq0GzcF1ow0BkpQ",
    "YHA0w6nupZ6Wqq4oHfZK9SXsbDBL7hCy",
    "1PbOG4qXh0LAF6b3e0KaJaVTX2nG2WQx",
    "0VwfyDg8tD9NhDASzcvr7QHz9lcPELON",
    "OEl0PWvcp2Zh9ggu1WARXqhZZ74UjYQN",
    "ay0KAixGHNDY9twt2e0oKmfgcCb5MHx3",
    "Wd3CgmvTO8w7EYBAT9Lg8DbtqonmJrmE",
    "TzZ0Iyz5173uXX9bsA6ecm8SzWkpjtoH",
    "7HNVK1TUxmvsxcb8uEGcNWnU2G51ZG6F",
    "e3pRt1jjgUUvqsL9xKTpMcXuh2zeVNSR",
    "rPRZJe8M8vpwPSO6B1uUvzOD9RTFfqcj",
    "TCzL9EUnaogUEtRLJJkLcAnJHngocLzr",
    "nmyuk0oYZgGZYCmGooEMFmMjsUhJSQ1W",
    "hrs3g3pfj8HtMhMg59icypNaOy2VpLHN",
    "UpolzuoxhnnrrNOwrj6Ao1B09BagXVdi",
    "lyvjEw9gcScm1SJ1aoEiuMTDq9ebIpnx",
    "g36LK4JI2yMwy1PO5sTHJ1ajqhk5JV19",
    "erwAkGtsSqDO8mCVlgxIxmaaYb2sm6xC",
    "dcMdxTApN4qcJtWZAwhq4RiWAVzJVh8W",
    "s7rypsX7v6KJ6uaV5OY6nkHBnjLoRhWB",
    "SGLCXEAZfl4Hb6oO8bNlElxJOWOKN5WP",
    "qIJhWaDoFpHEBPycjtaVLObMaLN2B3SZ",
    "n5gLj4qRigL8yovf9gVS6GiwELVCT64m",
    "SfEsgcYm1flP2fEbFlYR85MpTlpSJkcR",
    "IKUskxm6SU8dem2xJ11pUSYl8ohCk2Mb",
    "nH0EdvQugYTzHOKqvWpd6kqCV29wyd6l",
    "8dx7wbyHWQ6kwpXmVlsuA315Z2KUY3RN",
    "SUopTyrzUyqoyrZwr1W3Nm2M4XSjJ19m",
    "HdJyrgcL0NhpOn1PiZ9LZoLrVYoUjKnv",
    "dZ3tbAXlPyjvj423nkr4BmcCwNhF3XrE",
    "r8UInIixEeBJ1S2w97DppAPQIYsX2j8w",
    "hQkWsnUUp0zDgUqUA4fkTm2SxRTmcz4A",
    "DxtoIW6cd6fR8RWPpFga8q8TsbB8UX8E",
    "JzS8SEIvOLs1ZDSx6dxTjn5O3oFGGHEJ",
    "Hv3cTTsAeW4VUM1cW8D2RkfE32N1EQPE",
    "h4FZiuZM67eQZRb24FmmeJoVEayWoDW3",
    "Hw8I4jrWLuZEBeYkXnrGfTEwum3fPX6A",
    "VOQGj5QGnaCZYVWbacLIUmb4rMuMorVF",
    "zakHM5MGsyhdWVQu9eYXbksSrCoVFalO",
    "pPLdWNXs6uexFFznVHiizSaJfa7EbaDD",
    "8PzAvTRZHWfQF2vN1RqkXJevOu4qhplW",
    "Z4BJuHPnnqWrlhcI3sDzQTax35HskbO8",
    "sNHQbnYuKTUnx0yYqanxqajjpy8aUbma",
    "9L4GgJ6frgw2eJEqMB0Ay5P0p3kyciQ9",
    "Te0GaghFaMOrgbSIdJ4WF5dTDNrV03UC",
    "gH7NxCaICjtzoMC0c8XXE0cFWTkL1GLj",
    "mxzbvS0cERi0OIIaEQ0YyUrXzZDT7uCQ",
    "8xWShyVwRFiMucuQYwsSWIddiTYXy8Yh",
    "J2KnMYAoC3aFZzpdW6M94PGiF0djFj9E",
    "20Z5Prjtt4X5cK5hf82h2IPhp1CMyVEd",
    "moG00W4g8rTiBSrDcLTkEd9VO5vlw2MO",
    "VW0pZvq925nCc7th1uFrEju4ux232oDo",
    "YaJMTI71p2ySwZi1tpPAh0z7wSU0wtjc",
    "1IdyqLrVq2prqAOVMEYys6S6fCQzdwUF",
    "zCAaRMrBceIKXxYcDmy6sJ0nqdvpGR4X",
    "QHyeM81Zr0I7FoJnIo5WuArSdG3wrYmC",
    "xawkUqsJtFTO5bobTbNMPEB4UjCxGOwz",
    "UxDchbaTQgBb46z7iRfMERRcwjN9YtvV",
    "vTK7QO6oXiVQWylt6Cm0RD06tezgrXXo",
    "xZKjGmoD6jSTnFLO90y0sKWDahZvndIZ",
    "DiwUOcB34jmGDWPQbd0ZNrO4FgAYLbNr",
    "KaUU9CJQsMVknowgcttWcMt7qKJ1I5gV",
    "Y6Uuomwt2C28cNAvEjJNnDzY0btFB4KA",
    "oVfp1oghj0Mg2zwdVyosAj9tRcHooMAj",
    "pWWb3VqGPhQEEudiLBxwXmMoLWze6WFf",
    "pOUfgamZbruRwduq3oCmLGZCiw2Wyd9J",
    "NUVax7EsT78YCMAHgvCtEGHwkvZY23i9",
    "NaiW7VhGZC6Wsc475DWMJVHeSEeDoJfZ",
    "IhivIBGnvUUWUN6yz65NiQoRCACTXX3N",
    "XMPpk0aPZP0p1VAGtuXFfG0lMZD3iASw",
    "kwKaodveBp4gbaj89NP3y2JSr8MCj2mb",
    "SXVHGEpVEnbP7CkqWHMr7p7VWM40ShYd",
    "8W3iqR2ziNGSuOtp8gfHeYavE7qDhzHZ",
    "xE4eKpsUB0EoGDBWSF7nRRI7Ful1hGOB",
    "TzwQ5pFhrDmzmyFX8pm5YPrCSxgDc72G",
    "ZNF1POzCguDqSL2oBmsEPrpPXVrS8CxF",
    "eSyzLa8KEXVcnUMhlZMw4pqizu5TmQzF",
    "8WKSmqLN8zZmCsPG6mjvTcvBzAcLl624",
    "sUOe3xl3iCXVaSg9g5mK51sl9ulLIbSz",
    "oefuC5b106Dxl9v354ufyJLutnp3ILDQ",
    "zchMatHeZ37nMIdlt3IuKRp4KbfzG4mr",
    "tc4NR9RmwZkxNXNBFNJfu0RBN5VQl2M5",
    "ZkckpPI7UCHRQnBU7ur7Rr0gl4CFVw8Z",
    "L2K7HrDR1qmxzR97gRsZBwQKfSz0rrhr",
    "dq8mcJqtdDoobK8UHuKaWVfzBTcBCxI8",
    "QO36w3HaB4jxSpu9gz1wuQ51sAfCeN9Q",
    "kTOQqcogi3hAKgquHvZ5w47UfzkCnrXK",
    "y5IoG9LXTUzMgniHvzIju0ErCX2VAR8A",
    "Gt510MRN93c6z1vqzZp4WDif1ayxBjKw",
    "dmCMY788ZKfwgt40jG33KdJZEheQTDbk",
    "axGuQdEtNRqruNdIBDKs88faH5hUJyur",
    "z4lBAvphLop2ZZP747oeMtDiC3MUQPHn",
    "zeu4Y00wbZNKCyX9XfubB6zswYA9z35k",
    "ytbyVdItTs6CNv3NmlGeF0D6vrKD50fR",
    "p8GZJLlKZ06ij2n0b2cu6BRqltX88Kjx",
    "SmqhyPxr6nq6nF3gNaIAgzhamBHpOoIg",
    "XVStUbmvkR4EUbqPqa0rR7qBJRmwLJHE",
    "sZTglWu1o20HFg0dKU0UmerYE45gQW4o",
    "KrskvKhDXdjgiKcyrXA71WfOuM4RhDHP",
    "h2Lzge23DCbHmvjgf4QKKJOzE6u97njC",
    "4IK5z3zcm4EuG9OuGNHA18ghFQzljI27",
    "mYdMQ8j4dM5tT6WV2nUHUQknPVMxZi3r",
    "Ewgy137sRceETtyTea6cJjCtO6Gu8lzN",
    "9xJgj3Lo6u4YelQbZrXzKJcC5kdend4b",
    "aHfr003AqX219zXz2t4by48By5XaUicM",
    "5zlCYO5wjSBU7xba609L6haYWItzzb9X",
    "m7AbySRzpNg8fu4NQ1DCrzB68dfTB5yl",
    "VnqYBryXKD6Ysm2mGvjZbAK5mGvXQ1YJ",
    "6wjYVoeuPAxvTNwxEttiTc38BD0RIQOm",
    "WGi2uWfEkaXS0WkpkIcZJHWnLTYhAcgS",
    "i95I4DlGNAn90rjEvz51fPVVVDV8aR7Q",
    "3oMKvkCaPknKVN1J7fPdt5GLFBiVEhMX",
    "eYCQ9KdHdypPUSsODcw7kBtzEL7Ny99M",
    "IWP1J4r706uUxqCysu7JY9R0otVPMH9W",
    "WekoU0Oo2FYVWtgWmbEe8fJ02Uxnsuck",
    "lNRUziJvrj1EFqz4pTDVgfo072xRDVvl",
    "adzCSJkNDjPtrsSE9BpQFvEvTILMbhlr",
    "YeZDBj14pjnEyRlUefHAL451uAlOipQT",
    "2iOd2OyxBpatiQvT7tMsrVxxSzrOdAOA",
    "s1VVRq9XYJM4asw95V8X8KvUF4ni61HB",
    "xpyiwFsuk1aKHw3xOItJrBGmcwPRHQgn",
    "7OS4NT9AF0TDFXBFnWSbF4HxFyIntvLD",
    "yGw2GjlkeRQ8wFPBIW7Xtcm67bQ31Zcj",
    "TnBSgZnxoYXOsmvkrSGM0RwAn8TT4rw9",
    "PXLQDRDBWM2yD1yVm4LAoE7V5TS6F2xY",
    "wYEMXPYRTo2Edv78NbUs61l3qbda0AYU",
    "vmapIG8ATcWXO0UNGjzJZ9Y3CqCBw0uR",
    "Bf7t0YGVIvdaVpBgxtKHueZKWcCd9FU1",
    "fQIirFAiuoloFIrHVvV3IZSB8uTn6ni8",
    "KY4xk52LVeen4jkO5OWctdqAoByQXkaU",
    "LruBHilHkHt8J5w3TfUkHR1dIeIh9cEj",
    "oRRTgO3EKuoQmRVQIV9Z4USi0cVVGwZ0",
    "Nb4HOq9ttLj5uMQhQt6e9dq6nJk0EZJY",
    "0CAH4ssis8bOWOsSPEiakTIj0bDOr0r4",
    "kEiqF7MHkXqeJZo56j7z72QJfpbMyBvn",
    "cadNmLcja2bMMnRNvgHDhCaO9H8rWmJG",
    "1RAfj9XV5V90n066s3xSLZrjhxYc1vwv",
    "2kbX9iCVb0ON2vKghzEXXuKomgxVX1wP",
    "xnWIaNtV9C0n957rYLDW13MU1hl62IOL",
    "LRs60tkmTzdMJTQFEFGRZ5a5qNxzavqR",
    "NOkpCguCjp9aLELpY6IcPLSB0nTcF2VH",
    "QDLi6mcHTrtJZGw2cSWY0GQwrT4kVLjM",
    "xdNJdoVJHXy0YvcpeINZJs6BmFiMPOiU",
    "AGQnkRssxzmXYYyQzcUGM1sgeJeW7Lha",
    "pFID4h3sj41onfAz3R6JjfyBc2r83Npr",
    "hwmNtszUB7KLhpVJb92q5cRuK4OPYEfW",
    "mcjxsA57mLLhpN7P4clCR9run9bmlIuY",
    "pSzEUpGnS1yA5s9DwEkA5pqCQfQrTPsD",
    "tOqROFphaXt3fJMKlg0WhJzjP1w5g6nd",
    "PLQtxKs04Krdhd4YEmZzbTRzG54aPyDJ",
    "J3hij9Mdb15QHnDeJFhqh5BXgNJDunux",
    "hOUQVyD8YprNsmUKgc8ydyFFf8fQrLhh",
    "sz58xdcHXuogJTWIOtqdlexQr38VJOcu",
    "tb9DmYWkaijATjDOkzeLo2j7S1Buf6Ll",
    "GaiEyTgMflGRS2HMNv7zUOf9hIBFyoam",
    "jOTgEykrbwamjH6gD8qyzcA5qg6YrLIT",
    "5okjOiYpuSnSDq3wRGkt5jfpzfWwTp74",
};

void printHex(vector<bitset<8>> &input);
void printBin(vector<bitset<8>> &input);

void pasirinktiEiga(string msg, int* option, int max);
string getInputString();
string getKonstitucija(int lineNum);
void readInput(vector<bitset<8>> &arr, string inputText, unsigned int &k);

bitset<8> SBoxTransformation(bitset<8> &input);
vector<bitset<8>> TransformTo256(vector<bitset<8>> arr);
unsigned int magnify(vector<bitset<8>> &arr);
vector<bitset<8>> joinTwoArr(vector<bitset<8>> &arr, vector<bitset<8>> &arr2);

vector<bitset<8>> hashStr(string &userInputStr);

#endif