#include "mainwindow.h"
#include <QApplication>
#include <QHeaderView>
#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QTableView>
#include "delegate.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //构建一个4行，2列的项模型
    QStandardItemModel model(4, 2);
    //声明一个TableView
    QTableView tableView;
    //绑定模型
    tableView.setModel(&model);
    //声明一个委托
    SpinBoxDelegate delegate;
    //设定视图的委托
    tableView.setItemDelegate(&delegate);
    //ensuring that the view does not waste any of the space assigned to it for its header
    //最后一列全部填充View
    tableView.horizontalHeader()->setStretchLastSection(true);

    //初始化Model
    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 2; ++column) {
            QModelIndex index = model.index(row, column, QModelIndex());
            model.setData(index, QVariant((row+1) * (column+1)));
        }

    }


    tableView.setWindowTitle(QObject::tr("Spin Box Delegate"));
    tableView.show();

    return a.exec();
}
