#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeView>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void createMenus();
    void createPanels();
    void createBottomButtons();

    QFileSystemModel *fileModel = nullptr;

    QTreeView *leftView = nullptr;
    QTreeView *rightView = nullptr;

    QComboBox *leftDiskBox = nullptr;
    QComboBox *rightDiskBox = nullptr;

    QLabel *leftInfoLabel = nullptr;
    QLabel *rightInfoLabel = nullptr;

    QGridLayout *grid = nullptr;
};

#endif
