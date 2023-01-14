#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QStringList>
#include <QString>
#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->newTableFrame->setHidden(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNewTable_triggered()
{
    ui->newTableFieldGroup->setHidden(true);
    ui->newTableFrame->setHidden(false);
}


void MainWindow::on_newTableOkCancel_accepted()
{

}


void MainWindow::on_newTableOkCancel_rejected()
{
    if (!ui->keepNewTableEntryCheckBox->isChecked())
    {
        ui->ifNotExistsCheckBox->setChecked(false);
        ui->replaceExistingCheckBox->setChecked(false);
        ui->newTableNameText->setPlainText("");
    }
    ui->newTableFrame->setHidden(true);
}


void MainWindow::on_addTableFieldButton_clicked()
{
    if(!ui->newFieldTypeComboBox->count())
    {
        QStringList fieldTypes = {"INTEGER", "NUMERIC", "REAL", "TEXT", "BLOB"};
        ui->newFieldTypeComboBox->addItems(fieldTypes);
    }
    ui->newTableFieldGroup->setHidden(false);
}


void MainWindow::on_newFieldTypeComboBox_currentTextChanged(const QString &arg1)
{
//    if(arg1.toUpper() == "INTEGER")
//    {
//        ui->isPrimaryKeyCheckBox->setHidden(false);
//        return;
//    }

//    if(!ui->isPrimaryKeyCheckBox->isHidden())
//    {
//        ui->isPrimaryKeyCheckBox->setHidden(true);
//    }

}


void MainWindow::on_newFieldButtonBox_clicked(QAbstractButton *button)
{
    if(button->text() == "Save")
    {
        QString fieldSql = ui->newFieldNameText->toPlainText();
        fieldSql += " " + ui->newFieldTypeComboBox->currentText();
        if(ui->isPrimaryKeyCheckBox->isChecked())
        {
            fieldSql += " PRIMARY KEY AUTOINCREMENT";
        }
        m_newTableSql << fieldSql;
        ui->newTableSqlPreviewLabel->setText(m_newTableSql.join(""));
    }
}


void MainWindow::on_newTableNameText_textChanged()
{
    QString tableName = ui->newTableNameText->toPlainText();
    QString createTableSql = "CREATE TABLE " + tableName + " (";
    if(m_newTableSql.empty())
    {
        m_newTableSql.push_front(createTableSql);
    }
    auto it = m_newTableSql.begin();
    *it = createTableSql;
    ui->newTableSqlPreviewLabel->setText(m_newTableSql.join(""));
}

