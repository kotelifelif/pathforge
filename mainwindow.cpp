#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QWidgetAction>
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Path Forge"));

    createMenus();
    createPanels();
    createBottomButtons();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createMenus() {
    QMenu *files = menuBar()->addMenu(tr("Файлы"));
    QMenu *selection = menuBar()->addMenu(tr("Выделение"));
    QMenu *commands = menuBar()->addMenu(tr("Команды"));
    QMenu *network = menuBar()->addMenu(tr("Сеть"));
    QMenu *view = menuBar()->addMenu(tr("Вид"));
    QMenu *configuration = menuBar()->addMenu(tr("Конфигурация"));
    QMenu *launch = menuBar()->addMenu(tr("Запуск"));
    QMenu *reference = menuBar()->addMenu(tr("Справка"));

    files->addAction(tr("Изменить атрибуты"));
    files->addAction(tr("Упаковать"));
    files->addAction(tr("Распаковать"));
    files->addAction(tr("Протестировать архив(ы)"));
    files->addAction(tr("Сравнить по содержимому"));
    files->addAction(tr("Системные файловые ассоциации"));
    files->addAction(tr("Внутренние ассоциации (только ТС)"));
    files->addAction(tr("Показать диалог свойств"));
    files->addAction(tr("Подсчитать занимаемое место"));
    files->addAction(tr("Групповое переименование"));
    files->addAction(tr("Комментарий к файлу"));
    QMenu *help = files->addMenu(tr("Печать"));
    help->addAction(tr("Список файлов"));
    help->addAction(tr("Список файлов с подкаталогами"));
    help->addAction(tr("Содержимое файлов"));
    files->addAction(tr("Разбить файл"));
    files->addAction(tr("Собрать файлы"));
    files->addAction(tr("Декодировать (MIME, UUE, XXE, BinHex, yEnc"));
    files->addAction(tr("Посчитать CRC-суммы (SHA, MD5 и пр)"));
    files->addAction(tr("Проверить CRC-суммы (SHA, MD5 и пр)"));
    files->addSeparator();
    files->addAction(tr("Выход"));

    selection->addAction(tr("Выделить группу"));
    selection->addAction(tr("Снять выделение группы"));
    selection->addAction(tr("Выделить всё"));
    selection->addAction(tr("Снять всё выделение"));
    selection->addAction(tr("Инвертировать выделение"));
    selection->addAction(tr("Выделить файлы/папки по расширению"));
    selection->addSeparator();
    selection->addAction(tr("Сохранить выделение"));
    selection->addAction(tr("Восстановить выделение"));
    selection->addAction(tr("Сохранить выделение в файл"));
    selection->addAction(tr("Загрузить выделение из файла"));
    selection->addSeparator();
    selection->addAction(tr("Копировать имена файлов в буфер"));
    selection->addAction(tr("Копировать имена файлов с путями"));
    selection->addAction(tr("Копировать содержимое всех колонок"));
    selection->addAction(tr("Копировать все колонки (полные пути)"));
    selection->addSeparator();
    selection->addAction(tr("Сравнить каталоги"));
    selection->addAction(tr("Сравнить, скрыв одинаковые файлы"));

    commands->addAction(tr("Дерево каталогов"));
    commands->addAction(tr("Поиск файлов"));
    commands->addAction(tr("Поиск файлов отдельным процессом"));
    commands->addAction(tr("Метка диска"));
    commands->addAction(tr("Информация о системе"));
    commands->addAction(tr("Синхронизировать каталоги"));
    commands->addAction(tr("Избранные каталоги"));
    commands->addAction(tr("Назад"));
    commands->addSeparator();
    commands->addAction(tr("Открыть командную консоль"));
    commands->addSeparator();
    commands->addAction(tr("Показать все файлы без подкаталогов"));
    commands->addAction(tr("Открыть папку «Рабочий стол»"));
    commands->addAction(tr("Диспетчер фоновой пересылки"));
    commands->addSeparator();
    commands->addAction(tr("Поменять местами панели (активные вкладки)"));
    commands->addAction(tr("Получатель = Источнику"));

    network->addAction(tr("Подключить сетевой диск"));
    network->addAction(tr("Отключить сетевой диск"));
    network->addAction(tr("Открыть общий доступ к каталогу"));
    network->addAction(tr("Закрыть общий доступ к каталогу"));
    network->addAction(tr("Показать ресурсы администратора"));
    network->addSeparator();
    network->addAction(tr("Соединиться с FTP-сервером"));
    network->addAction(tr("Новое FTP-соединение"));
    network->addAction(tr("Разорвать FTP-соединение"));
    network->addAction(tr("Показывать скрытые файлы на сервере"));
    network->addAction(tr("Загрузка по списку"));
    network->addAction(tr("Установить соединение через LPT/USB-порт"));

    view->addAction(tr("Краткий"));
    view->addAction(tr("Подробный"));
    view->addAction(tr("Комментарии"));
    QMenu *userColumns = view->addMenu(tr("Пользовательский набор колонок"));
    userColumns->addAction(tr("Настроить наборы колонок"));
    QMenu *userStyle = view->addMenu(tr("Пользовательский стиль оформления"));
    userStyle->addAction(tr("<По умолчанию>"));
    userStyle->addSeparator();
    userStyle->addAction(tr("Настроить стили оформления"));
    view->addAction(tr("Дерево каталогов"));
    view->addAction(tr("Дерево в отдельной панели"));
    view->addAction(tr("Просмотр эскизов"));
    view->addAction(tr("Быстрый просмотр"));
    view->addAction(tr("Панели одна над другой"));
    view->addAction(tr("Новая вкладка для текущей папки"));
    view->addSeparator();
    view->addAction(tr("Все файлы"));
    view->addAction(tr("Программы"));
    view->addAction(tr("*.*"));
    view->addAction(tr("Фильтр..."));
    view->addAction(tr("Показать только выделенные объекты"));
    view->addSeparator();
    view->addAction(tr("По имени"));
    view->addAction(tr("По типу"));
    view->addAction(tr("По дате/времени"));
    view->addAction(tr("По размеру"));
    view->addAction(tr("Без сортировки"));
    view->addSeparator();
    view->addAction(tr("В обратном порядке"));
    view->addSeparator();
    view->addAction(tr("Обновить содержимое панели"));

    configuration->addAction(tr("Настройка"));
    configuration->addAction(tr("Главная панель инструментов"));
    configuration->addAction(tr("Вертикальная панель инструментов"));
    configuration->addAction(tr("Редактировать файлы конфигурации"));
    configuration->addAction(tr("Тёмный<->Обычный"));
    configuration->addAction(tr("Сохранить положение окна"));
    configuration->addAction(tr("Сохранить настройки"));

    launch->addAction(tr("Изменить меню Запуск"));
    launch->addAction(tr("Изменить главное меню"));

    reference->addAction(tr("Содержание"));
    reference->addAction(tr("Клавиатурные сочетания"));
    reference->addAction(tr("О регистрации"));
    reference->addAction(tr("Посетить сайт программы"));
    reference->addAction(tr("Проверить обновления"));
    reference->addSeparator();
    reference->addAction(tr("О Total Commander"));
}

void MainWindow::createPanels() {
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    grid = new QGridLayout(central);
    QHBoxLayout *mainLayout = new QHBoxLayout;
    grid->addLayout(mainLayout, 0, 0);

    QVBoxLayout *mainLeftLayout = new QVBoxLayout;
    mainLayout->addLayout(mainLeftLayout);
    QHBoxLayout *infoLeftLayout = new QHBoxLayout;
    mainLeftLayout->addLayout(infoLeftLayout);

    fileModel = new QFileSystemModel(this);
    fileModel->setRootPath("C:/");

    QComboBox *discLeftBox = new QComboBox;
    discLeftBox->addItem("C");
    QLabel *infoLeftLabel = new QLabel;
    infoLeftLabel->setText("[Windows 11] 843 249 564 Кб из 1 000 084 476 Кб свободно");
    leftView = new QTreeView;
    leftView->setModel(fileModel);
    leftView->setRootIndex(fileModel->index("C:/"));
    leftView->setSortingEnabled(true);
    infoLeftLayout->addWidget(discLeftBox);
    infoLeftLayout->addWidget(infoLeftLabel);
    mainLeftLayout->addWidget(leftView);

    QVBoxLayout *mainRightLayout = new QVBoxLayout;
    mainLayout->addLayout(mainRightLayout);
    QHBoxLayout *infoRightLayout = new QHBoxLayout;
    mainRightLayout->addLayout(infoRightLayout);

    QComboBox *discRightBox = new QComboBox;
    discRightBox->addItem("C");
    QLabel *infoRightLabel = new QLabel;
    infoRightLabel->setText("[Windows 11] 843 249 564 Кб из 1 000 084 476 Кб свободно");
    rightView = new QTreeView;
    rightView->setModel(fileModel);
    rightView->setRootIndex(fileModel->index("C:"));
    rightView->setSortingEnabled(true);

    infoRightLayout->addWidget(discRightBox);
    infoRightLayout->addWidget(infoRightLabel);
    mainRightLayout->addWidget(rightView);
}

void MainWindow::createBottomButtons() {
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    grid->addLayout(buttonLayout, 1, 0);
    QToolButton *viewButton = new QToolButton;
    viewButton->setText(tr("F3 просмотр"));
    QToolButton *editingButton = new QToolButton;
    editingButton->setText(tr("F4 правка"));
    QToolButton *copyButton = new QToolButton;
    copyButton->setText(tr("F5 копирование"));
    QToolButton *moveButton = new QToolButton;
    moveButton->setText(tr("F6 перемещение"));
    QToolButton *catalogueButton = new QToolButton;
    catalogueButton->setText(tr("F7 каталог"));
    QToolButton *removeButton = new QToolButton;
    removeButton->setText(tr("F8 удаление"));
    QToolButton *exitButton = new QToolButton;
    exitButton->setText(tr("Alt+F4 выход"));
    buttonLayout->addWidget(viewButton);
    buttonLayout->addWidget(editingButton);
    buttonLayout->addWidget(copyButton);
    buttonLayout->addWidget(moveButton);
    buttonLayout->addWidget(catalogueButton);
    buttonLayout->addWidget(removeButton);
    buttonLayout->addWidget(exitButton);
}
