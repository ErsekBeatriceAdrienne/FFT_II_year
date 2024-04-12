# Labor 04

Signal-slot mechanizmusra [példa](https://doc.qt.io/qt-6/signalsandslots.html).

## Feladatok

1. Készítsünk egy nyomógomb (`QPushButton`) osztályt, mely csak a jobb egérgomb klikkre reagál (például nyisson meg egy felugró ablakot, amelyben kiírja, hogy "Jobb klikk"). Teszteljük a működését.

2. Hozzunk létre egy `Q Console Application`-t. Implementáljunk egy `TemperatureSensor` nevű osztályt, amely hőmérsékletméréseket szimulál. Definiáljunk egy eseményt (`void TemperatureSensor::temperatureExceeded(int)`), amely akkor következik be/váltódik ki, ha a hőmérséklet meghalad egy küszöbértéket (pl. 30°C). `QTimer` segítségével másodpercenként véletlenszerűen generáljunk hőmérséklet-leolvasásokat (20°C és 40°C között):

```cpp

TemperatureSensor::TemperatureSensor(QObject *parent = nullptr) : QObject(parent) {
        // QTimer az értékek periódikus generálására (1 másodpercenként)
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, [=](){
            // ide jön a számok generálása
        });
        timer->start(1000);
    }

```

Implementáljunk egy `CoolingSystem` nevű osztályt, amely feliratkozik a másik osztály eseményére (`void CoolingSystem::handleTemperatureExceeded(int temperature)`). Az esemény bekövetkezésekor írja ki `qDebug` segítségével a "Hőmérséklet túllépte a küszöbértéket: <temperature> °C!" üzenetet.

3. Hozzunk létre két osztályt: `MagicSlider` és `RewardBagDisplayer`. Az előző tartalmazzon egy `QSlider`t, az utóbbi pedig egy `QLCDNumber`t és ebből hozzunk majd létre több példányt is. A `RewardBagDisplayer` példányainkat iratkozassuk fel a slider `QSlider::valueChanged` eseményére. Amennyiben az kiváltódik, nézzük meg, hogy egyenlő-e a szám a displayer konstruktorában generált véletlen számmal (használjuk a `QRandomGenerator::bounded` függvényt a határérték generálására). Ha egyenlő, akkor állítsuk be ezt a számot a displayer értékének, és váltsunk ki egy `RewardBagDisplayer::rewardDisplayed` nevű saját eseményt. A `QMainWindow` ablakunkat iratkoztassuk fel minden `RewardBagDisplayer::rewardDisplayer` eseményre. Az esemény kiváltását használjuk fel arra, hogy megszámoljuk, hogy hány `RewardBagDisplayer` értékét találtuk ki. Amikor az összes `RewardBagDisplayer`-nek kitaláltuk az értékét, 2 másodperc múlva zárjuk be az ablakot egy `QTimer` segítségével.

<p align="center">
  <img width="700" src="https://i.imgur.com/ELdODVL.png" alt="gui"/>
</p>

4. (**Plusz pontra**) Implementálunk egy két személy által egymás ellen játszható (vagyis _local multiplayer_) [tic-tac-toe](https://hu.wikipedia.org/wiki/Tic-tac-toe) játékot (_kéthetes határidő, laboron be kell majd mutatni_).
