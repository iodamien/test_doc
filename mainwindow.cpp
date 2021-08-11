#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QTextDocument>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::exportPDF);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exportPDF() {
    QString txt = ui->textEdit->toPlainText();
    qDebug() << txt;

    QTextDocument document;
    document.setHtml(txt);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("/Users/irouvad/test_exo.pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    document.print(&printer);
}
