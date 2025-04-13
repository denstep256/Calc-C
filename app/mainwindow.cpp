#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_proc, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_umnog, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_del->setCheckable(true);
    ui->pushButton_umnog->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if (ui->rezult_show->text().contains(".") && button->text() == "0") {
        new_label = ui->rezult_show->text() + button->text();
    } else {
    all_numbers = (ui->rezult_show->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 15);
    }
    ui->rezult_show->setText(new_label);

}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->rezult_show->text().contains('.')))
        ui->rezult_show->setText(ui->rezult_show->text() + ".");

}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(button->text() == "+/-") {

        all_numbers = (ui->rezult_show->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->rezult_show->setText(new_label);
    } else if(button->text() == "abs") {

        all_numbers = (ui->rezult_show->text()).toDouble();
        all_numbers = abs(all_numbers);
        new_label = QString::number(all_numbers, 'g', 15);

        ui->rezult_show->setText(new_label);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();

    num_first = (ui->rezult_show->text()).toDouble();
    ui->rezult_show->setText("");
    button->setChecked(true);
}


void MainWindow::on_pushButton_ac_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_del->setChecked(false);
    ui->pushButton_umnog->setChecked(false);

    ui->rezult_show->setText("0");

}


void MainWindow::on_pushButton_ravno_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = (ui->rezult_show->text()).toDouble();


    if(ui->pushButton_plus->isChecked()) {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->rezult_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);

    } else if (ui->pushButton_minus->isChecked()) {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->rezult_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);

    } else if (ui->pushButton_del->isChecked()) {
        if (num_second == 0) {
            ui->rezult_show->setText("0");
        } else {
            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber, 'g', 15);

            ui->rezult_show->setText(new_label);
        }
        ui->pushButton_del->setChecked(false);

    } else if (ui->pushButton_umnog->isChecked()) {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->rezult_show->setText(new_label);
        ui->pushButton_umnog->setChecked(false);

    }
}

