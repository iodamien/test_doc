#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QTextDocument>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QDataStream>

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
    printer.setOutputFileName("test.pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    QFile currentFile("test.pdf");
    if( !currentFile.open( QIODevice::ReadOnly )) {
        return;
    }
    QDataStream dataStream(&currentFile);
    QFileDialog::saveFileContent(dataStream, "output.pdf");

    document.print(&printer);
}
