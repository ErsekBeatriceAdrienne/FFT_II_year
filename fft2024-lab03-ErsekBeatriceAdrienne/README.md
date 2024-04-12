# Labor 03

A laboron a következőképp fogjuk használni a ```QMessageBox```-ot, de van más módja is, ahogyan használható/alkalmazható. Bővebb információ [itt](https://doc.qt.io/qt-5/qmessagebox.html). 

A 2-3. feladat során a következő szintaxist fogjuk használni: 
```QMessageBox::típus(Szülő, "Ablak neve", "Ablak szövege", Gombok, Alapértelemezett_gomb)```

A _gombok_ bináris vagy jellel (|) vannak összefűzve, például: Save, Discard, Cancel stb. _Alapértelmezett gombnál_ pedig megadhatjuk, hogy mi történjen (vagyis melyik gomb reagáljon) ha entert nyom a felhasználó. Az utolsó kettő paraméter opcionális.

_QMessageBox-típusok_ a következők lehetnek fordított súlyossági sorrendben:
* ```Question``` - ennek jele egy kérdőjel, alapértelmezett gombjai az **Igen** és **Nem**
* ```Information``` - ennek jele egy i betű, alapértelmezett gombja az **Ok**	
* ```Warning``` - ennek jele egy felkiáltójel, alapértelmezett gombja az **Ok**
* ```Critical``` - ennek jele egy x, alapértelmezett gombja az **Ok**

Van még ```About``` típus is, ennek nincs negyedik-ötödik paramétere, vagyis a gombok (tehát nem paraméterezhető, alapértelmezetten egy OK gombbal rendelkeznek csak). Illetve ott az ```AboutQt``` is, amely csak információkat jelenít meg a telepített Qt-nkről. Ennek sincs háromnál több paramétere. Értelemszerűen így visszatérítési értékük sincs (void függvények). Ezzel szemben a többi visszatéríti a lenyomott gomb értékét.


## Feladatok

1.	Írjunk egy GUI programot, mely egy 10-es számrendszerben megadott számot tetszőleges számrendszerbe alakít át. Karakterlánc -> szám átalakításra használjuk a 
```int QString::toInt(bool *ok = nullptr, int base = 10) const``` és ```QString QString::number(int n, int base = 10)``` függvényeket. Ha az átalakítás nem sikeres, az eredmény mezőben jelenítsünk meg egy hibaüzenetet. Minta az elkészítendő felületre:

<p align="center">
  <img width="400" src="https://user-images.githubusercontent.com/78269344/108048993-63439480-7050-11eb-8fb9-71c25f44d9cb.png" alt="gui számrendszer"/>
</p>

2.	Módosítsuk az előző programot úgy, hogy a számrendszert egy legördülő menüből (```QComboBox```, dokumentáció [itt](https://doc.qt.io/qt-5/qcombobox.html)) kelljen kiválasztani. Az eredmény címke (label) és mező (field) csak akkor legyen látható, ha van helyes eredmény. A hibaüzenet egy felugró ablakban jelenjen meg (```QMessageBox::critical```, dokumentáció [itt](https://doc.qt.io/qt-5/qmessagebox.html)). 

3.	Írjunk egy GUI alkalmazást mely megold egy másodfokú egyenletet. Negatív delta esetében figyelmezteti a felhasználót (```QMessageBox::warning``` segítségével). Minta az elkészítendő felületre:

<p align="center">
  <img width="500" src="https://i.ibb.co/tKrmpNp/qes.png" alt="gui"/>
</p>

