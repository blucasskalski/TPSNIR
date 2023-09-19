#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include <QTextEdit>
#include <QTextCursor>

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();
    Search(QTextEdit* editor);
    bool select();

private:
    Ui::Search *ui;
    QTextEdit* editor;
    QTextDocument::FindFlags flags;
    QTextCursor* cursor;
    QString currentSearch;
};

#endif // SEARCH_H
