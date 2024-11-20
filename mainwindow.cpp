#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QStandardItemModel *model = new QStandardItemModel(this);
    model->setColumnCount(4);


    model->setHorizontalHeaderLabels({"ID", "Task", "Deadline", "Assigned To"});


    QStringList ids = {"task 1", "task 2", "task 3", "task 4"};
    QStringList tasks = {"Clean my room", "Do the dishes", "Study KSN :(", "play bs"};
    QStringList deadlines = {"2024-01-01", "2024-02-02", "2024-03-03", "2024-04-04"};
    QStringList assignees = {"Donald Duck", "Adem", "Chris", "Erik"};


    for (int i = 0; i < ids.size(); ++i) {
        QList<QStandardItem*> row;
        row.append(new QStandardItem(ids[i]));
        row.append(new QStandardItem(tasks[i]));
        row.append(new QStandardItem(deadlines[i]));
        row.append(new QStandardItem(assignees[i]));
        model->appendRow(row);  // Zeile zum Modell hinzufügen
    }


    ui->tableView->setModel(model);


    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;  // Speicher freigeben, um Speicherlecks zu vermeiden
}
