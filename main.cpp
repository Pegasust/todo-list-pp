// main.cpp
#include <QApplication>
#include "ToDoListGUI.hpp"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  ToDoListGUI toDoList;
  toDoList.show();
  return app.exec();
}