# Labor 02

A Qt támogatja az esemény-orientált programozást. A szekvenciális programozáshoz képest a kód nemcsak fentről lefele futtatódik, hanem bizonyos változások is vezethetnek kód futtatáshoz. Például: ha megnyomunk egy gombot a felületen, akkor azonnal a hozzá tartozó kód futtatásra kerül. Ezt az esemény-orientált megközelítést a Qt-ban **signal-slot mechanizmusnak** nevezzük, megvalósítása pedig a `connect` függvény segítségével történik. A `signal` az az esemény, amely külső hatásra kiváltódott, és a `slot` az a függvény, amely erre az eseményre reakcióként meghívódik. Az esemény hordozhat magával különféle paramétereket is, amelyek több információt szolgáltatnak a bekövetkezett eseményről.

Ahhoz, hogy az eseményeket a kezelőjükhöz tudjuk rendelni, szükséges a `connect` függvényt használni (dokumentáció [itt](https://doc.qt.io/qt-6/signalsandslots.html) és [itt](https://wiki.qt.io/New_Signal_Slot_Syntax)). Ennek alapvetően négy paramétere van: 1) az objektum, amelyen kiváltódott az esemény; 2) maga az esemény; 3) a fogadó/kezelő objektum; 4) a fogadó meghívandó függvénye.

**QT 5-től használható szintaxis:**
Legyen a `Sender` osztályunknak van egy `valueChanged` signal típusú függvénye és a `Receiver` osztálynak pedig egy `updateValue` slot típusú függvénye. Akkor váltódik ki a `valueChanged` esemény, amikor a `sender` (a példány) értéke megváltozik.

```cpp
connect(
    sender, &Sender::valueChanged,
    receiver, &Receiver::updateValue
);
```

vagy

```cpp
connect(
    sender, &Sender::valueChanged,
    someFunction                             // ahol someFunction lehet akár lambda is
);
```

**Régi, makrókkal megoldott szintaxis:**

```cpp
connect(
    sender, SIGNAL( valueChanged(QString) ),
    receiver, SLOT( updateValue(QString) )    // ahol a sender és a receiver is QObject* típusúak (vagyis pointerek)
);
```

**_Ökölszabály_**: amennyiben paramétereket tartalmaznak a függvények, kell vigyázni arra, hogy a `SLOT`-ba írt függvény ne tartalmazzon több paramétert, mint amennyit a `SIGNAL`-ba írt függvénye szolgáltat

## Feladatok

1. A laborhoz csatolt projektben találunk egy programot, amely gombnyomásra kilép az alkalmazásból. Tanulmányozzuk a kódot.

2. Bővítsük ki az 1. feladat grafikus felületét:

   - egy új gombbal, amelyre ha rákattintunk, akkor magyarul is kiírja a köszöntő üzenetet (használjuk a `QLabel` `setText()` metódusát);

   - vezessünk be még egy gombot, melynek segítségével az üzenet láthatóságát tudjuk ki-be kapcsolni. Használjuk az `isVisible()`, `hide()`, `show()` metódusokat.

3. Készítsünk egy egyszerű alkalmazást, amelyben egy csuszkával (`QSlider`) állíthatunk egy digitális kijelzőn (`QLCDNumber`) megjelenő számot.

<p align="center">
  <img width="300" src="https://i.ibb.co/vq0tMxm/display.png"" alt="Egyszerűsített számológép"/>
</p>
