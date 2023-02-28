#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers() {
    auto button = static_cast<QPushButton*> (sender());

    auto AllNumbers = (ui->resultShow->text() + button->text()).toDouble();

    ui->resultShow->setText(QString::number(AllNumbers, 'g', 15));
}
