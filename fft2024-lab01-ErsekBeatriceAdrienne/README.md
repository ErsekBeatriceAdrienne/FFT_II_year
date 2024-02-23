# Labor 01

A tantárgy keretén belül, objektum orientált módon felépített grafikus felületű, egy-, illetve többablakos, több rétegű, eseményvezérelt alkalmazások készítésével fogunk foglalkozni. Azzal is megismerkedünk, hogy milyen elvek szerint tervezzük és vitelezzük ki ezeket a felületeket.

Az [eseményvezérelt programozásban](https://wiki.prog.hu/wiki/Eseményvezérelt_programozás) a program egyes részei, ágai nem szekvenciális és előre meghatározható sorrendben futnak le, hanem a vezérlés lefutását bizonyos külső, illetve belső események határozzák meg. A program egésze nem más, mint események bekövetkezésére válaszul végrehajtott szubrutinok (ún. eseménykezelők) laza halmaza, amelyek nagyrészt egymástól függetlenül dolgoznak és működtetik a program egészét.

Az eseményvezérelt modellben külső események alatt tipikusan a felhasználói bevitelt (billentyű lenyomása, egérművelet), valamint a hardvertől származó eseményeket (pl. az időzítőáramkor vagy periférfia által kiváltott megszakítás, visszahívás) szokás érteni, míg a belső eseményeket a program más részeitől - vagy akár más programoktól - származó üzenetek képezik.

Az eseményvezérelt programok egyetlen szekvenciális részeit a program az események begyűjtését és szétosztását (dispatch) végző főciklusa, valamint az egyes eseményeket kezelő szubrutinok képezik, amelyek azonban maguk is válhatnak további események kiváltójává és forrásává.

Eseményvezérelt program szinte bármilyen programozási nyelvben készíthető, mi C++-t és Qt-t fogunk tanulni és használni. A Qt egy többplatformos (nemcsak asztali, de akár mobil vagy beágyazott alkalmazások is fejleszthetők) alkalmazás-fejlesztési keretrendszer, amely egy komplett osztálykönyvtárat biztosít számos platformon történő alkalmazás-fejlesztésre elsősorban C++-ban. Jelmondatai: "One framework. One codebase. Any platform." és "Code less. Create more. Deploy everywhere.".

Az első laboron, az ingyenes Qt Creator - Open Source Qt Use ([letöltés](https://www.qt.io/download-open-source)) Integrált fejlesztői környezettel fogunk megismerkedni. Ennek a kézikönyve [itt](https://doc.qt.io/qtcreator/index.html) böngészhető.

# Feladatok

1. Telepítsük a Qt-t és a hozzá tartozó IDE-t. A telepítéshez, projektek létrehozásához a Google Classroomban találtok útmutatót.

2. Milyen [típusú projekteket](https://doc.qt.io/qtcreator/creator-project-creating.html) lehet létrehozni?

3. Hozzunk létre egy Qt Widgets Application típusú projektet, amely futtatáskor kiírja az aktuális dátumot (ÉÉÉÉ-HH-NN formátumban). Használjuk a [`QDate`](https://doc.qt.io/qt-6/qdatetime.html) osztályt.

4. Hozzunk létre egy Qt Widgets Applicationt, amelyben megvalósítunk egy egyszerűsített "számológépet". Tartalmazzon két szövegdobozt, amelybe be a két értéket be lehet írni, és egy harmadikat, amely az eredményt jeleníti meg. A felület ezen kívül tartalmazzon még négy gombot, amelyek a műveleteket jelölik; a gombnyomásukra jelenítődjön meg az eredmény a harmadik szövegdobozban. Ezt ne engedjük a felhasználó által szerkeszteni (legyen read-only).

<p align="center">
  <img src="https://i.imgur.com/DQinS7Z.png" alt="Egyszerűsített számológép"/>
</p>
