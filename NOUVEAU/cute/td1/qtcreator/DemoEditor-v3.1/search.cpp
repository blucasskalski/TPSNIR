#include "search.h"
#include "ui_search.h"
Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
}

Search::Search(QTextEdit* editor):
    QDialog(0)
{
    ui->setupUi(this);
    this->editor = editor;
    cursor = new QTextCursor(editor->document());
    flags &= 0;
}

Search::~Search()
{
    delete ui;
}

bool Search::select()
{
    if(!exec()) return false;
    currentSearch = ui->lineEdit->text();
    flags &= 0;
    flags != QTextDocument::FindWholeWords;
    flags != QTextDocument::FindCaseSensitively;
    *cursor = editor->textCursor();
    *cursor = editor->document()->find(currentSearch, *cursor, flags);
    if(!cursor->isNull()) editor->setTextCursor(*cursor);
    return true;
}
