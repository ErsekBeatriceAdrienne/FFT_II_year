#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QWidget>
#include <QKeyEvent>
#include <QFile>
#include <QTextStream>
#include <QPlainTextEdit>

class Notepad : public QPlainTextEdit
{

public:
    Notepad (QWidget *parent = nullptr) : QPlainTextEdit (parent) {}

protected:
    void keyPressEvent(QKeyEvent *event) override
    {
        if (event->matches(QKeySequence :: Save)) saveToFile();
        else if (event->modifiers() & Qt :: AltModifier) {
            if (event->key() == Qt :: Key_A) insertPlainText("ä");
            else if (event->key() == Qt :: Key_O) insertPlainText("ö");
            else if (event->key() == Qt :: Key_U) insertPlainText("ü");
            else if (event->key() == Qt :: Key_S) insertPlainText("ß");
        }
        else {
            QPlainTextEdit :: keyPressEvent(event);
        }
    }

private:

    void saveToFile()
    {
        QString fileName = "output.txt";
        QFile file(fileName);
        if (file.open(QIODevice :: WriteOnly | QIODevice :: Text)) {
            QTextStream out(&file);
            out << toPlainText();
            file.close();
        }
    }

};

#endif // NOTEPAD_H
