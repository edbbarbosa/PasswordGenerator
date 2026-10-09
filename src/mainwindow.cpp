#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "passwordgenerator.h"

#include <QVBoxLayout>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Password Generator");
    //setFixedSize(200, 115);

    button = new QPushButton("Generate password");
    label = new QLabel;
    spinBox = new QSpinBox;

    spinBox->setRange(1,99);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    QHBoxLayout *hlayout = new QHBoxLayout;

    layout->addWidget(label);
    layout->addLayout(hlayout);
    hlayout->addWidget(new QLabel("Number of characters: "));
    hlayout->addWidget(spinBox);
    layout->addWidget(button);

    setCentralWidget(centralWidget);
    adjustSize();

    connect(button, &QPushButton::clicked, this, &MainWindow::showPassword);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showText(){
    PasswordGenerator passwordGenerator(spinBox->value());
    label->setText(QString::fromStdString(passwordGenerator.password()));
}

void MainWindow::showPassword(){
    QDialog *newWindow = new QDialog(this);
    newWindow->setWindowTitle("Password");

    QVBoxLayout *layout = new QVBoxLayout(newWindow);
    QLabel *label = new QLabel;

    PasswordGenerator passwordGenerator(spinBox->value());
    label->setText(QString::fromStdString(passwordGenerator.password()));

    layout->addWidget(label);

    QPushButton *closeButton = new QPushButton("Close", newWindow);
    connect(closeButton, &QPushButton::clicked, newWindow, &QDialog::accept);
    layout->addWidget(closeButton);

    newWindow->setAttribute(Qt::WA_DeleteOnClose);
    newWindow->show();

}
