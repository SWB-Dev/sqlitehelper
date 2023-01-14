#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QAbstractButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNewTable_triggered();

    void on_newTableOkCancel_accepted();

    void on_newTableOkCancel_rejected();

    void on_addTableFieldButton_clicked();

    void on_newFieldTypeComboBox_currentTextChanged(const QString &arg1);

    void on_newFieldButtonBox_clicked(QAbstractButton *button);

    void on_newTableNameText_textChanged();

private:
    Ui::MainWindow *ui;
    QStringList m_newTableSql;
};
#endif // MAINWINDOW_H
