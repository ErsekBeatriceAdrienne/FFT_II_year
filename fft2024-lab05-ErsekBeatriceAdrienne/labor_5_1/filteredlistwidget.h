#ifndef FILTEREDLISTWIDGET_H
#define FILTEREDLISTWIDGET_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QListWidget>
#include <QTextStream>
#include <QPushButton>
#include <QStringList>
#include <QLineEdit>
#include <QFileDialog>
#include <QDebug>
#include <QLabel>
#include <QString>
#include <QMouseEvent>
#include <QEvent>
#include <QFile>

class FilteredListWidget : public QMainWindow
{
    Q_OBJECT

public:
    FilteredListWidget(QWidget *parent = nullptr);
    ~FilteredListWidget();

private:
    QStringList words;
    QLineEdit *filter_edit;
    QListWidget * words_list;
    QPushButton * load_words_button;

public slots:
    void loadWordsFromFile();
};

#endif // FILTEREDLISTWIDGET_H
