#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), width(ui->resultShow->width())
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

    connect(ui->pushButtonSign,       SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButtonPercentage, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButtonSub, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButtonMul, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButtonDiv, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButtonDiv->setCheckable(true);
    ui->pushButtonMul->setCheckable(true);
    ui->pushButtonSub->setCheckable(true);
    ui->pushButtonAdd->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    auto button = static_cast<QPushButton*> (sender());
    QString newLabel;

    if (ui->resultShow->text().contains(".") and button->text() == "0") {
        newLabel = ui->resultShow->text() + button->text();
    }

    else {
        auto AllNumbers = (ui->resultShow->text() + button->text()).toDouble();
        newLabel = QString::number(AllNumbers, 'g', 15);
    }

    ui->resultShow->setText(newLabel);
}

void MainWindow::operations()
{
    auto button = static_cast<QPushButton*> (sender());
    double AllNumbers = 0;

    if (button->text() == "+/-") {
        AllNumbers = (ui->resultShow->text()).toDouble();
        AllNumbers *= -1;
    }

    else if (button->text() == "%") {
        AllNumbers = (ui->resultShow->text()).toDouble();
        AllNumbers *= 0.01;
    }

    ui->resultShow->setText(QString::number(AllNumbers, 'g', 15));
}


void MainWindow::math_operations()
{
    auto button = static_cast<QPushButton*> (sender());

    button->setChecked(true);
    numFirst = ui->resultShow->text().toDouble();

    ui->resultShow->setText("");
}


void MainWindow::on_pushButtonDot_clicked()
{
    if (!(ui->resultShow->text().contains('.')))
        ui->resultShow->setText(ui->resultShow->text() + '.');
}


void MainWindow::on_pushButtonClear_clicked()
{
    ui->pushButtonAdd->setChecked(false);
    ui->pushButtonSub->setChecked(false);
    ui->pushButtonMul->setChecked(false);
    ui->pushButtonDiv->setChecked(false);

    ui->resultShow->setText("0");
}


void MainWindow::on_pushButtonEqual_clicked()
{
    double labelNumber = 0, numSecond = 0;
    QString newLabel = ui->resultShow->text();

    numSecond = ui->resultShow->text().toDouble();

    if (ui->pushButtonAdd->isChecked()) {
        labelNumber = numFirst + numSecond;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->pushButtonAdd->setChecked(false);
    }

    else if (ui->pushButtonSub->isChecked()) {
        labelNumber = numFirst - numSecond;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->pushButtonSub->setChecked(false);
    }

    else if (ui->pushButtonMul->isChecked()) {
        labelNumber = numFirst * numSecond;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->pushButtonMul->setChecked(false);
    }

    else if (ui->pushButtonDiv->isChecked()) {
        if (numSecond == 0) {
            newLabel = "NaN";
        } else {
            labelNumber = numFirst / numSecond;
            newLabel = QString::number(labelNumber, 'g', 15);
        }
        ui->pushButtonDiv->setChecked(false);
    }

    ui->resultShow->setText(newLabel);
}

