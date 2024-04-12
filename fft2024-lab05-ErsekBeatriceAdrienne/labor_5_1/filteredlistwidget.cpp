#include "filteredlistwidget.h"
#include "ui_filteredlistwidget.h"

FilteredListWidget :: FilteredListWidget(QWidget *parent) : QMainWindow(parent)
{
    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Szűrés",this);

    filter_edit = new QLineEdit(this);
    filter_edit->setPlaceholderText("Filter..");
    words_list = new QListWidget(this);
    load_words_button = new QPushButton(tr("Fájl megnyitása"),this);

    layout->addWidget(label);
    //text box
    layout->addWidget(filter_edit);
    //text show
    layout->addWidget(words_list);
    layout->addWidget(load_words_button);
    window->setLayout(layout);

    QObject :: connect(load_words_button,SIGNAL(clicked()),this,SLOT(loadWordsFromFile()));

    // Szűrés az QLineEdit textChanged eseményére
    QObject :: connect(filter_edit, &QLineEdit :: textEdited, [&](const QString &filterText) {
        words_list->clear();
        for (const QString &word : words) {
            if (word.contains(filterText, Qt::CaseInsensitive)) {
                words_list->addItem(word);
            }
        }
    });

    window->setWindowTitle("Szűrés listára");
    window->show();
}

FilteredListWidget :: ~FilteredListWidget() {}

void FilteredListWidget :: loadWordsFromFile()
{
    // Fájlválasztó ablak megjelenítése a felhasználónak
    QString fileName = QFileDialog :: getOpenFileName(nullptr, "Select a File", "", "Text Files (*.txt)");

    // Ellenőrizzük, hogy a felhasználó választott-e fájlt
    if (!fileName.isEmpty()) {
        // Fájl megnyitása
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);

            // Fájl sorainak beolvasása és szavak listájának feltöltése
            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList lineWords = line.split(" ", Qt::SkipEmptyParts);
                words.append(lineWords);
            }

            // A beolvasott szavak kiírása
            for (const QString &word : words) {
                //konzolra irja
                //qDebug().noquote() << word;
                words_list->addItem(word);
            }

            file.close();
        }
        else {
            qDebug() << "Failed to open file:" << fileName;
        }
    }
    else {
        qDebug() << "File selection canceled.";
    }
}
