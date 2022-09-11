//
// Authors: Hung Tran, Rick Mercer
//
#ifndef TODOLIST_MYMODEL_H
#define TODOLIST_MYMODEL_H
// mymodel.h
#include <QAbstractTableModel>
#include <QString>
#include "LinkedPriorityList.hpp"
using namespace std;

class MyModel : public QAbstractListModel {

private:
  LinkedPriorityList<QString> list;

public:
  MyModel(QObject *parent = nullptr);
  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  int columnCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
  LinkedPriorityList<QString> * getList();
  void listChanged();
};

#endif // TODOLIST_MYMODEL_H
